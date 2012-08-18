#ifndef OA_H_
#define OA_H_
#include "Instancia.h"
#include "Propiedad.h"

using namespace kyotocabinet;

class OA{

	private:
		int num_clases;//Cantidad de clases
		int num_instancias;//Cantidad de instancias
		int num_propiedades;//Cantidad de propiedades
		int num_eventos;
		Clase *(clases[C]); //Todas las clases existentes en la BD
		Instancia *(instancias[I]);//Todas las instancias en la BD
		Propiedad *(propiedades[P]);//Todas las propiedades de la BD
		Evento *(eventos[E]);
		StashDB *cla, *ins, *prop, *event;//Indices de las clases, instancias y propiedades
				
	public:
		OA(); //Constructor 
		bool crear_clase(string nom_clase);
		bool inicializar_instancia(int tipo_propiedad, string nom_clase, string nom_instancia, string nom_propiedad);
		bool crear_instancia(string nom_instancia, string nom_clase);
		bool crear_propiedad(string nom_clase, string nom_propiedad, int tipo_propiedad);
		
		bool crear_evento(string nom_clase, string nom_evento, string nom_propActiva, int valor_futuro, string expresion);
		bool crear_evento(string nom_clase, string nom_evento, string nom_propActiva, double valor_futuro, string expresion);
		bool crear_evento(string nom_clase, string nom_evento, string nom_propActiva, string valor_futuro, string expresion);
		
		Clase* get_clase(int pos); //La uso solo para pruebas
		Clase* get_clase(string nombre);//Retorna la clase con proporcionar su nombre
		
		Instancia* get_instancia(int pos);//La uso solo para pruebas
		Instancia* get_instancia(string clase, string nombre);
		
		Propiedad* get_propiedad(int pos);//La uso solo para pruebas
		Propiedad* get_propiedad(string nombre);//Retorna la propiedad con proporcionar su nombre
		int get_pos_propiedad(string nombre);
		
		Evento* get_evento(string nombre);//Retorna el evento con proporcionar su nombre
		
		int get_num_clases();//Numero de clases existentes en la base de datos
		int get_num_instancias();//Numero de instancias existentes en la base de datos
		int get_num_propiedades();//Numero de propiedades existentes en la base de datos
		
		bool agregar_subclase(string nom_clase, string nom_padre); //n_clase sera subclase de n_padre
		bool agregar_subpropiedad(string nom_propiedad, string nom_padre);
		bool agregar_subevento(string nom_evento, string nom_padre);
		bool es_subclase_de(string nom_clase, string nom_clase_padre); //Ver si n_clase es subclase de n_clase_padre
		bool es_subpropiedad_de(string nom_propiedad, string nom_propiedad_padre);
		bool es_subevento_de(string nom_evento, string nom_evento_padre);
		bool agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, int valor);
		bool agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, double valor);
		bool agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, string valor);
		
		string consultar_propiedad_instancia(string nom_clase, string nom_instancia, string nom_propiedad);
		
		bool activar_eventos(string nom_clase, string nom_evento);
		bool existencia_consulta_reactiva(map<string, string> *eventosHash, int n, string clase);
};
  
	
	OA::OA(){
		num_clases = 0;
		num_instancias = 0;
		num_propiedades = 0;
		num_eventos = 0;
		
		cla = new StashDB();
		ins = new StashDB();
		prop = new StashDB();
		event = new StashDB();
					
		if( !cla->open("cofre.kch", StashDB::OWRITER | StashDB::OCREATE) ){
			cout << "Error al crear el cofre: " << cla->error().name() << endl;
		}
		if(!ins->open("instancias.kch", StashDB::OWRITER | StashDB::OCREATE)){
			cout << "Error al crear el cofre: " << ins->error().name() << endl;
		}
		if(!prop->open("propiedades.kch", StashDB::OWRITER | StashDB::OCREATE)){
			cout << "Error al crear el cofre: " << prop->error().name() << endl;
		}
		if(!event->open("eventos.kch", StashDB::OWRITER | StashDB::OCREATE)){
			cout << "Error al crear el cofre: " << event->error().name() << endl;
		}
	}

	//Ver si "nombre" no lo esta ocupado otra clase
	
	bool OA::crear_clase(string nombre){
		bool se_creo = false;
			
		if( get_clase(nombre) == NULL && num_clases < C ){		
			
			if( !(cla->set(nombre, EnteroAString( num_clases ) )) ){
				cout << "Error creando clase: " << cla->error().name() << endl;
			}
			else{
				clases[num_clases] = new Clase(nombre);
				num_clases+=1;
				se_creo = true;
			}
		}
		return se_creo;
	}
	
	bool OA::inicializar_instancia(int tipo_propiedad, string nom_clase, string nom_instancia, string nom_propiedad){
		bool band = false;
		
			if(tipo_propiedad == ENTERO){	
				//~ cout << "Entero Propiedad " << nom_propiedad << endl;
				agregar_valorApropiedad(nom_clase, nom_instancia, nom_propiedad, INT_MIN);//Inicializo
				band = true;
			}
			else if(tipo_propiedad == REAL){
				//~ cout << "Real Propiedad " << nom_propiedad << endl;
				agregar_valorApropiedad(nom_clase, nom_instancia, nom_propiedad, DBL_MIN);
				band = true;
			}
			else if(tipo_propiedad == CADENA){
				//~ cout << "Cadena Propiedad " << nom_propiedad << endl;
				agregar_valorApropiedad(nom_clase, nom_instancia, nom_propiedad, "");
				band = true;
			}
			return band;
		
		}
	
	bool OA::crear_instancia(string nom_instancia, string nom_clase){
		bool se_creo = false;
		Clase *cl = get_clase(nom_clase);
		int tipo_propiedad;
		
		//Para poder tener nombres de instancias iguales pero en diferentes clases
		
		if( cl != NULL && get_instancia(nom_clase, nom_instancia) == NULL && num_instancias < I ){//Si existe la clase y no existe la instancia, crear

				//Se guarda el nombre de la instancia junto con el nombre de la clase
				//Para que se diferencie con otras instancias del mismo nombres pero de
				//otras clases
				if( !ins->set(nom_instancia + "_" + nom_clase, EnteroAString(num_instancias) ) ){
					cout << "Error creando instancia: " << ins->error().name() << endl;
				}
				else{
					instancias[num_instancias] = new Instancia(nom_instancia, cl );
					
					//Agregar las propiedades de la superclase a la clase
					map<string, int>::const_iterator it; //Iterador
					map<string, int> *portMap; //apuntador a hash
					portMap = cl->get_propiedades(); //consulto tabla hash de las propiedades del padre
					for(it = portMap->begin(); it != portMap->end(); ++it){//Iterando
					//Voy agregando las propiedades del padre al hijo
    				tipo_propiedad = get_propiedad( (string)it->first )->get_tipo();
    				inicializar_instancia(tipo_propiedad, nom_clase, nom_instancia, (string)it->first);

					}
					cl->agregar_instancia(nom_instancia, num_instancias);
					num_instancias+=1;
					se_creo = true;
				}
			
		}
		return se_creo;
	}
	

	
	bool OA::crear_propiedad(string nom_clase, string nom_propiedad, int tipo_propiedad){
		bool band = false;
		int i;
		Clase *cl = get_clase(nom_clase);
		
		//Si existe la clase y si la propiedad no existe -> agregar 
		if(cl != NULL && get_propiedad(nom_propiedad) == NULL && num_propiedades < P){
			if( !prop->set(nom_propiedad, EnteroAString(num_propiedades) ) ){
				cout << "Error creando propiedad: " << prop->error().name() << endl;
			}
			else{
				//Creo la propiedad
				propiedades[num_propiedades] = new Propiedad( nom_propiedad, cl, tipo_propiedad );
				//Agrego la propiedad a la clase
				cl->agregar_propiedad(nom_propiedad, num_propiedades);
				
				//Inicializar nueva propiedad a las instancias de la clase
				map<string, int>::const_iterator it; //Iterador
				map<string, int> *portMap; //apuntador a hash
				portMap = cl->get_instancias(); //consulto tabla hash de las instancias
				for(it = portMap->begin(); it != portMap->end(); ++it){//Iterando
					inicializar_instancia(tipo_propiedad, nom_clase, (string)it->first, nom_propiedad);
				
				}
				
				int num_hijos = cl->get_num_hijos();
				if(num_hijos > 0){
					for(i = 0; i < num_hijos; i++){
						Clase *p = cl->get_hijo(i);
						p->agregar_propiedad(nom_propiedad, num_propiedades);
						//Inicializar nueva propiedad a las instancias de la clase
						portMap = p->get_instancias(); //consulto tabla hash de las propiedades del padre
						for(it = portMap->begin(); it != portMap->end(); ++it){//Iterando
							inicializar_instancia(tipo_propiedad, p->get_nombre(), (string)it->first, nom_propiedad);
						}
					}
				}
				num_propiedades = num_propiedades + 1;
				band = true;
			}
		}
		return band;
	}
	

	bool OA::crear_evento(string nom_clase, string nom_evento, string nom_propActiva, int valor_futuro, string expresion){
		bool band = false;
		int c_v = 0;
		string variables[P]; //Aqui se guardan el nombre de las variables de la expresion.

		Clase *cl = get_clase(nom_clase);
		
		//Si el evento ya existe y la prop_Activa es la misma, agregar la expresion al evento existente
		if( cl->existe_propiedad(nom_propActiva) && get_evento(nom_evento) == NULL && get_propiedad(nom_propActiva) != NULL && num_eventos < E){
			if( !event->set(nom_evento, EnteroAString(num_eventos) ) ){
				cout << "Error creando clase: " << event->error().name() << endl;
			}
			else{
				//validar que la expresion sea correcta							
				if( cl->comprobar_expresion(expresion, variables, &c_v)==0 ){
					
					eventos[num_eventos] = new Evento(nom_evento, nom_propActiva, valor_futuro, expresion);
					//Descomponer expresion y ver que variables tiene para agregar el evento a esas propiedades
					//Esto se hacia con el fin de que al cambiar el valor de una propiedad, se verificara
					// los eventos que dependian de esa propiedad en la clase Propiedad.h
					// y luego activar dichos eventos
					/*for(int i = 0; i < c_v; i++){
						//~ cout << "La propiedad " << variables[i]<< " esta en la condicion" << endl;
						(get_propiedad( variables[i] ))->agregar_evento( eventos[num_eventos] );
					}*/
					
					num_eventos = num_eventos + 1;
					band = true;
				}
			}
	
		}
		return band;
	}

	bool OA::crear_evento(string nom_clase, string nom_evento, string nom_propActiva, double valor_futuro, string expresion){
		bool band = false;
		int c_v = 0;
		string variables[P]; 

		Clase *cl = get_clase(nom_clase);
		
		//Si el evento ya existe y la prop_Activa es la misma, agregar la expresion al evento existente
		if( cl->existe_propiedad(nom_propActiva) && get_evento(nom_evento) == NULL && get_propiedad(nom_propActiva) != NULL && num_eventos < E){
			if( !event->set(nom_evento, EnteroAString(num_eventos) ) ){
				cout << "Error creando clase: " << event->error().name() << endl;
			}
			else{
				//validar que la expresion sea correcta							
				if( cl->comprobar_expresion(expresion, variables, &c_v)==0 ){
					eventos[num_eventos] = new Evento(nom_evento, nom_propActiva, valor_futuro, expresion);
					//Descomponer expresion y ver que variables tiene para agregar el evento a esas propiedades
					/*for(int i = 0; i < c_v; i++){
						//~ cout << "La propiedad " << variables[i]<< " esta en la condicion" << endl;
						(get_propiedad( variables[i] ))->agregar_evento( eventos[num_eventos] );
					}*/
					num_eventos = num_eventos + 1;
					band = true;
				}
			}
	
		}
		
		return band;
	}
	
		bool OA::crear_evento(string nom_clase, string nom_evento, string nom_propActiva, string valor_futuro, string expresion){
		bool band = false;
		int c_v = 0;
		string variables[P]; 

		Clase *cl = get_clase(nom_clase);
		
		//Si el evento ya existe y la prop_Activa es la misma, agregar la expresion al evento existente
		if( cl->existe_propiedad(nom_propActiva) && get_evento(nom_evento) == NULL && get_propiedad(nom_propActiva) != NULL && num_eventos < E){
			if( !event->set(nom_evento, EnteroAString(num_eventos) ) ){
				cout << "Error creando clase: " << event->error().name() << endl;
			}
			else{
				//validar que la expresion sea correcta
								
				if( cl->comprobar_expresion(expresion, variables, &c_v)==0 ){
					eventos[num_eventos] = new Evento(nom_evento, nom_propActiva, valor_futuro, expresion);
					//Descomponer expresion y ver que variables tiene para agregar el evento a esas propiedades
					/*for(int i = 0; i < c_v; i++){
						//~ cout << "La propiedad " << variables[i]<< " esta en la condicion" << endl;
						(get_propiedad( variables[i] ))->agregar_evento( eventos[num_eventos] );
					}*/
					num_eventos = num_eventos + 1;
					band = true;
				}
				else{
					cout << "La expresion no es correcta, puede que tenga alguna propiedad que no exista en la clase o la expresion este mal formulada" << endl;
					}
			}
		}
		
		return band;
	}
	
	Clase* OA::get_clase(int pos){
		if( pos < num_clases ){
			return clases[pos];
		}
		return NULL;
	}
	
	Clase* OA::get_clase(string nombre){
		Clase *r = NULL;
		string valor;
		if( cla->get(nombre, &valor) ){
			int n ;
			istringstream ( valor ) >> n;//Transformo el string en int
			r = clases[n];
		}
		
		return r;
	}


	Instancia* OA::get_instancia(int pos){
		if( pos < num_instancias ){
			return instancias[pos];
		}
		return NULL;
	}

	Instancia* OA::get_instancia(string clase, string nombre){
		Instancia *i = NULL;
		
		string valor;
		nombre = nombre + "_" + clase;
		if( ins->get(nombre, &valor) ){
			int n;
			istringstream ( valor ) >> n;//Transformo el string en int
			i = instancias[n];
		}
		
		return i;
	}

	Propiedad* OA::get_propiedad(int pos){
		if( pos < num_propiedades ){
			return propiedades[pos];
		}
		return NULL;
	}

	Propiedad* OA::get_propiedad(string nombre){
		Propiedad *i = NULL;
		string valor;
		if( prop->get(nombre, &valor) ){
			int n;
			istringstream ( valor ) >> n;//Transformo el string en int
			i = propiedades[n];
		}
		return i;
	}
	
	int OA::get_pos_propiedad(string nombre){
		int n = -1;
		string valor;
		if( prop->get(nombre, &valor) ){
			istringstream ( valor ) >> n;//Transformo el string en int
		}
		return n;
	}

	Evento* OA::get_evento(string nombre){
		Evento *i = NULL;
		string valor;
		if( event->get(nombre, &valor) ){
			int n;
			istringstream ( valor ) >> n;//Transformo el string en int
			i = eventos[n];
		}
		return i;
	}

	int OA::get_num_clases(){
		return num_clases;
	}

	int OA::get_num_instancias(){
		return num_instancias;
	}

	int OA::get_num_propiedades(){
		return num_propiedades;
	}

	//Si devuelve verdadero se agrego el padre, sino, no se pudo
	bool OA::agregar_subclase(string nom_clase, string nom_padre){
		//Ver si existe n_clase y n_padre y devolver el puntero
		int tipo_propiedad;
		bool todo_bien = false;
		Clase *hijo = get_clase(nom_clase);
		Clase *padre = get_clase(nom_padre);
		if( hijo!=NULL && padre!=NULL && !es_subclase_de(nom_clase, nom_padre) &&  !es_subclase_de(nom_padre, nom_clase) ){	
			hijo->agregar_padre(padre); //Agregar padre al hijo
			int num_padres = padre->get_num_padres(); //Consultar ancestros del padre
			if(num_padres > 0){
				for(int i = 0; i < num_padres; i++){//Agregar los ancestros del padre al hijo
					Clase *p = padre->get_padre(i);
					hijo->agregar_padre( p );
					p->agregar_hijo( hijo );
				}
			}
			padre->agregar_hijo(hijo);//Agregar hijo al padre
			int num_hijos = hijo->get_num_hijos();//Consultar descendientes del hijo
			if(num_hijos > 0){
				for(int i = 0; i < num_hijos; i++){//Agregar los descendientes del hijo al padre
					Clase *h = hijo->get_hijo(i);
					padre->agregar_hijo( h );
					h->agregar_padre( padre );
				}
			}
			
			//Agregar las propiedades de la superclase a la clase
			map<string, int>::const_iterator it; //Iterador
			map<string, int> *portMap; //apuntador a hash
			portMap = padre->get_propiedades(); //consulto tabla hash de las propiedades del padre
			for(it = portMap->begin(); it != portMap->end(); ++it){//Iterando
				//Voy agregando las propiedades del padre al hijo
    			hijo->agregar_propiedad(it->first, it->second);//Agrego propiedad al hijo, y abajo a sus descendientes
    			tipo_propiedad = get_propiedad( (string)it->first )->get_tipo();
    			
    			//Inicializar nueva propiedad a las instancias de la clase
				map<string, int>::const_iterator ins; //Iterador
				map<string, int> *portMap_ins; //apuntador a hash
				portMap_ins = hijo->get_instancias(); //consulto tabla hash de las instancias
				for(ins = portMap_ins->begin(); ins != portMap_ins->end(); ++ins){//Iterando
					inicializar_instancia(  tipo_propiedad  , nom_clase, (string)ins->first, (string)it->first);
				
				}
    			
    			
    			//Tambien agrego las propiedades a los descendientes del hijo
				for(int i = 0; i < num_hijos; i++){//Agregar propiedades del padre a los descendientes del hijo
					Clase *h = hijo->get_hijo(i);
					h->agregar_propiedad(it->first, it->second);//Clave y Valor
				
					 //Inicializar nueva propiedad a las instancias de la clase
					portMap_ins = h->get_instancias(); //consulto tabla hash de las instancias
					for(ins = portMap_ins->begin(); ins != portMap_ins->end(); ++ins){//Iterando
						inicializar_instancia(  tipo_propiedad  , h->get_nombre(), (string)ins->first, (string)it->first);
					
					}
				}
			}
			todo_bien = true;
		}
		return todo_bien;
	}

	bool OA::agregar_subpropiedad(string nom_propiedad, string nom_padre){
		//Ver si existe n_clase y n_padre y devolver el puntero
		bool todo_bien = false;
		Propiedad *hijo = get_propiedad(nom_propiedad);
		Propiedad *padre = get_propiedad(nom_padre);
		
		if( hijo!=NULL && padre!=NULL && !es_subpropiedad_de(nom_propiedad, nom_padre) &&  !es_subpropiedad_de(nom_padre, nom_propiedad) ){	
			hijo->agregar_padre(padre);
			int num_padres = padre->get_num_padres();
			if(num_padres > 0){
				for(int i = 0; i < num_padres; i++){//Agregar los ancestros del padre al hijo
					Propiedad *p = padre->get_padre(i);
					hijo->agregar_padre( p );
					p->agregar_hijo( hijo );
				}
			}
			padre->agregar_hijo(hijo);
			int num_hijos = hijo->get_num_hijos();//Consultar descendientes del hijo
			if(num_hijos > 0){
				for(int i = 0; i < num_hijos; i++){//Agregar los descendientes del hijo al padre
					Propiedad *h = hijo->get_hijo(i);
					padre->agregar_hijo( h );
					h->agregar_padre( padre );
				}
			}
			todo_bien = true;			
		}
		return todo_bien;
	}

	bool OA::agregar_subevento(string nom_evento, string nom_padre){
		//Ver si existe n_clase y n_padre y devolver el puntero
		
		bool todo_bien = false;
		Evento *hijo = get_evento(nom_evento);
		Evento *padre = get_evento(nom_padre);
		
		if( hijo!=NULL && padre!=NULL && !es_subevento_de(nom_evento, nom_padre) &&  !es_subevento_de(nom_padre, nom_evento) ){	
			hijo->agregar_padre(padre);
			int num_padres = padre->get_num_padres();
			if(num_padres > 0){
				for(int i = 0; i < num_padres; i++){//Agregar los ancestros del padre al hijo
					Evento *p = padre->get_padre(i);
					hijo->agregar_padre( p );
					p->agregar_hijo( hijo );
				}
			}
			padre->agregar_hijo(hijo);
			int num_hijos = hijo->get_num_hijos();//Consultar descendientes del hijo
			if(num_hijos > 0){
				for(int i = 0; i < num_hijos; i++){//Agregar los descendientes del hijo al padre
					Evento *h = hijo->get_hijo(i);
					padre->agregar_hijo( h );
					h->agregar_padre( padre );
				}
			}
			todo_bien = true;			
		}
		return todo_bien;
	}

	bool OA::es_subclase_de(string nom_clase, string nom_clase_padre){
		bool es_subclase = false;
		Clase *clase = get_clase( nom_clase );
		Clase *padre = get_clase( nom_clase_padre );
		
		if( clase!=NULL && padre!=NULL ){//Si existen ambas clases, procedemos a comprobar si nom_clase es subclase de nom_clase_padre
			int num_padres = clase->get_num_padres();
			int i = 0;
			while(i < num_padres && !es_subclase){
				if( (clase->get_padre(i))->get_nombre() == nom_clase_padre ){
					es_subclase = true;
				}
				i+=1;
			}
		}
		return es_subclase;
	}

	bool OA::es_subpropiedad_de(string nom_propiedad, string nom_propiedad_padre){
		bool es_subpropiedad = false;
		
		Propiedad *propiedad = get_propiedad( nom_propiedad );
		Propiedad *padre = get_propiedad( nom_propiedad_padre );
		
		if( propiedad!=NULL && padre!=NULL ){
			
			int num_padres = propiedad->get_num_padres();
			int i = 0;
			while(i < num_padres && !es_subpropiedad){
				if( (propiedad->get_padre(i))->get_nombre() == nom_propiedad_padre ){
					es_subpropiedad = true;
				}
				i+=1;
			}
		}
		return es_subpropiedad;
	}

	bool OA::es_subevento_de(string nom_evento, string nom_evento_padre){
		bool es_subevento = false;
		
		Evento *evento = get_evento( nom_evento );
		Evento *padre = get_evento( nom_evento_padre );
		
		if( evento!=NULL && padre!=NULL ){
			
			int num_padres = evento->get_num_padres();
			int i = 0;
			while(i < num_padres && !es_subevento){
				if( (evento->get_padre(i))->get_nombre() == nom_evento_padre ){
					es_subevento = true;
				}
				i+=1;
			}
		}
		return es_subevento;
	}

	bool OA::agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, int valor){
		Instancia *i;
		Clase *c;
		bool band = false, existe_propiedad_en_la_clase, entrar = false;
		
		
		c = get_clase(nom_clase); //Obtengo apuntador a la clase	
		
		if( c != NULL){ //Si existe la clase
			existe_propiedad_en_la_clase = c->existe_propiedad(nom_propiedad);
			if( existe_propiedad_en_la_clase ){ //Si existe la propiedad en esa clase
				i = get_instancia(nom_clase, nom_instancia);
				if( i != NULL) //Si existe la instancia en esa clase
					entrar = true;
			}
		}
		
		if( entrar ){ //Si existe la instancia, la propiedad y la clase
			//~ cout << "nom_propiedad " << nom_propiedad << " get_propiedad(nom_propiedad)->get_tipo() " << get_propiedad(nom_propiedad)->get_tipo() << " valor " << valor << endl;
			band = i->agregar_valor_propiedad(nom_propiedad,get_propiedad(nom_propiedad)->get_tipo() , valor);//Si se agrega el valor correctamente
			//Antes se activaban aqui los eventos			
		}
		else{
			cout << "NO existe la propiedad, la instancia o la clase" << endl;
		}
		
		return band;
	}

	bool OA::agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, double valor){
		Instancia *i;
		Clase *c;
		bool band = false, existe_propiedad_en_la_clase, entrar = false;
		
		
		c = get_clase(nom_clase); //Obtengo apuntador a la clase	
		
		if( c != NULL){ //Si existe la clase
			existe_propiedad_en_la_clase = c->existe_propiedad(nom_propiedad);
			if( existe_propiedad_en_la_clase ){ //Si existe la propiedad en esa clase
				i = get_instancia(nom_clase, nom_instancia);
				if( i != NULL) //Si existe la instancia en esa clase
					entrar = true;
			}
		}
		
		if( entrar ){ //Si existe la instancia, la propiedad y la clase
			//~ cout << "nom_propiedad " << nom_propiedad << " get_propiedad(nom_propiedad)->get_tipo() " << get_propiedad(nom_propiedad)->get_tipo() << " valor " << valor << endl;
			band = i->agregar_valor_propiedad(nom_propiedad, get_propiedad(nom_propiedad)->get_tipo(),valor );//Si se agrega el valor correctamente
			//Antes se activaban aqui los eventos			
		}
		else{
			cout << "NO existe la propiedad, la instancia o la clase" << endl;
		}
		
		return band;
	}

	bool OA::agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, string valor){
		Instancia *i;
		Clase *c;
		bool band = false, existe_propiedad_en_la_clase, entrar = false;
		
		
		c = get_clase(nom_clase); //Obtengo apuntador a la clase	
		
		if( c != NULL){ //Si existe la clase
			existe_propiedad_en_la_clase = c->existe_propiedad(nom_propiedad);
			if( existe_propiedad_en_la_clase ){ //Si existe la propiedad en esa clase
				i = get_instancia(nom_clase, nom_instancia);
				if( i != NULL) //Si existe la instancia en esa clase
					entrar = true;
			}
		}
		
		if( entrar ){ //Si existe la instancia, la propiedad y la clase
			//~ cout << "nom_propiedad " << nom_propiedad << " get_propiedad(nom_propiedad)->get_tipo() " << get_propiedad(nom_propiedad)->get_tipo() << " valor " << valor << endl;
			band = i->agregar_valor_propiedad(nom_propiedad, get_propiedad(nom_propiedad)->get_tipo(), valor);
			//Antes se activaban aqui los eventos			
		}
		else{
			cout << "NO existe la propiedad, la instancia o la clase" << endl;
		}
		
		return band;
	}

	//Pre:Comprobar que existe propiedad i->existe_propiedad()
	string OA::consultar_propiedad_instancia(string nom_clase, string nom_instancia, string nom_propiedad){
		Instancia *i;
		string v = "";
		i = get_instancia(nom_clase, nom_instancia);
		//Retornar los valores de las propiedad que se consulten, pero en formato string
		if( i->existe_propiedad(nom_propiedad) ){
			struct var *valor;
			valor = i->get_valor_propiedad(nom_propiedad);
			
			if(valor->val.type == ENTERO){
				//~ cout << "Valor de "<< nom_propiedad << " " << valor->val.ival << endl;
				v = EnteroAString( valor->val.ival  );
				
				}
			if(valor->val.type == REAL){
				//~ cout << "Valor de "<< nom_propiedad << " " << valor->val.rval << endl;
				v = DoubleAString( valor->val.rval );
				}
			if(valor->val.type == CADENA){
				//~ cout << "Valor de "<< nom_propiedad << " " << valor->val.cval << endl;
				v = string( valor->val.cval );
			
			}
		}
		else{
			cout << "No se encontro la propiedad "<< nom_propiedad << " en la clase "<< nom_clase << endl;
			}

		return v;
	}

	
	bool OA::activar_eventos(string nom_clase, string nom_evento){
	
		bool band = true;
		Clase *cl;
		Instancia *i;
		Evento *e, *evento;
		valor_r *va;
		int k;
				
		cl = get_clase(nom_clase); //Obtengo el apuntador a la clase donde se activarán los eventos
		evento = get_evento(nom_evento); //Obtengo el apuntador al evento que se activará
		
		
		map<string, int>::const_iterator it; //Iterador
		map<string, int> *portMap; //apuntador a hash
		portMap = cl->get_instancias(); //consulto las instancias de esa clase
		
		for(it = portMap->begin(); it != portMap->end(); ++it){//Iterando por todas las instancias de la clase
		/***Validar que el evento padre pertenezca a la misma clase ***/
			
			i = get_instancia(nom_clase, (string)it->first); //Obtengo el apuntador a la instancia en donde se investigara si existe el evento
					
			cout << "Instancia: " << it->first << ", Posicion: " << instancias[(int)it->second - 1]->get_nombre() << endl;//Clave y Valor
    		
    		int eventos_padres = evento->get_num_padres(); //Numero de padres del evento principal
    		int e_padres = 0;
    		
    		e = get_evento(nom_evento); //El evento principal se activa primero
    		do{
    			if( e != NULL && i != NULL){
					/***Aqui ira un for con todas las expresiones del evento que se podrian cumplir***/
										
					if( i->validar_expresion( e->get_expresion()) ) {

						for(k = 0; k < e->get_num_prop_act() ; k++){
							va = e->get_valor_nuevo(k);
							
							if(va->tipo == ENTERO){
								i->agregar_valor_propiedad( e->get_nombre_propiedad(k), get_propiedad(e->get_nombre_propiedad(k))->get_tipo(), va->ival );
							}
							else if(va->tipo == REAL){
								i->agregar_valor_propiedad( e->get_nombre_propiedad(k), get_propiedad(e->get_nombre_propiedad(k))->get_tipo(), va->rval );
							}
							else if(va->tipo == CADENA){
							i->agregar_valor_propiedad( e->get_nombre_propiedad(k), get_propiedad(e->get_nombre_propiedad(k))->get_tipo(), va->cval );
							}
						}
						cout << "Cumple con la condicion" << endl << endl;
					}
					else{
						cout << "NO Cumple con la condicion" << endl << endl;
					}
				
				}
				else{
					cout << "El evento es NULL o La instancia es NULL" << endl;		
				}
			
				e = evento->get_padre(e_padres);//Continuo con los eventos padres del evento principal
				e_padres+=1;
			
			}while( e_padres <= eventos_padres );
		}

		return band;
		/*
			p = get_propiedad(nom_propiedad);//Obtengo el apuntador a la propiedad
			n_e = p->get_num_eventos();//Consulto el numero de eventos que tienen a dicha propiedad en su condicion booleana
			if( band && n_e > 0){ //Si se agrego correctamente el valor a la propiedad de la instancia, y esta propiedad esta en alguna condicion booleana
				
				
			}
			else{
				cout << "NO esta en ninguna condicion booleana" << endl;
			}
	*/
	
	
	}
	
	bool OA::existencia_consulta_reactiva(map<string, string> *eventosHash, int n, string cl){
		bool band = true;
		map<string, string>::const_iterator it; //Iterador
		
		if(get_clase(cl)== NULL){
			band = false;
			cout << "La clase especificada no existe" << endl;		
		}
		
		it = eventosHash->begin();
		while(it != eventosHash->end() ){ //Recorro todos los eventos nombrados en la consulta reactiva
			if( get_evento( (string)it->first ) == NULL ){//Si el evento es NULL no existe
				band = false;
				cout <<"El evento " << (string)it->first << " no existe" << endl;
			}
			++it;
		}
		cout << endl;
		return band;
	}

# endif
