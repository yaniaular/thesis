#ifndef OA_H_
#define OA_H_
#include <cstdlib>
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
		StashDB *bd, *ins, *prop, *event;//Indices de las clases, instancias y propiedades
				
	public:
		OA(); //Constructor 
		bool crear_clase(string nom_clase);
		bool crear_instancia(string nom_instancia, string nom_clase);
		bool crear_propiedad(string nom_clase, string nom_propiedad);
		
		bool crear_evento(string nom_clase, string nom_evento, string nom_propActiva, int valor_futuro, string expresion);
		bool crear_evento(string nom_clase, string nom_evento, string nom_propActiva, double valor_futuro, string expresion);
		bool crear_evento(string nom_clase, string nom_evento, string nom_propActiva, string valor_futuro, string expresion);
		
		Clase* get_clase(int pos); //La uso solo para pruebas
		Clase* get_clase(string nombre);//Retorna la clase con proporcionar su nombre
		
		Instancia* get_instancia(int pos);
		Instancia* get_instancia(string clase, string nombre);
		
		Propiedad* get_propiedad(int pos);
		Propiedad* get_propiedad(string nombre);
		int get_pos_propiedad(string nombre);
		
		Evento* get_evento(string nombre);
		
		int get_num_clases();
		int get_num_instancias();
		int get_num_propiedades();
		
		bool agregar_subclase(string nom_clase, string nom_padre); //n_clase sera subclase de n_padre
		bool es_subclase_de(string nom_clase, string nom_clase_padre); //Ver si n_clase es subclase de n_clase_padre
		bool agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, int valor);
		int consultar_propiedad_instancia(string nom_clase, string nom_instancia, string nom_propiedad);
};
  
	
	OA::OA(){
		num_clases = 0;
		num_instancias = 0;
		num_propiedades = 0;
		num_eventos = 0;
		
		bd = new StashDB();
		ins = new StashDB();
		prop = new StashDB();
		event = new StashDB();
					
		if( !bd->open("cofre.kch", StashDB::OWRITER | StashDB::OCREATE) ){
			cout << "Error al crear el cofre: " << bd->error().name() << endl;
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
			
			if( !(bd->set(nombre, EnteroAString( num_clases ) )) ){
				cout << "Error creando clase: " << bd->error().name() << endl;
			}
			else{
				clases[num_clases] = new Clase(nombre);
				num_clases+=1;
				se_creo = true;
			}
		}
		return se_creo;
	}
	
	bool OA::crear_instancia(string nom_instancia, string nom_clase){
		bool se_creo = false;
		Clase *cl = get_clase(nom_clase);
		
		//Para poder tener nombres de instancias iguales pero en diferentes clases
		
		if( cl != NULL && get_instancia(nom_clase, nom_instancia) == NULL && num_instancias < I ){//Si no existe la instancia, crear

			if(cl != NULL){
				if( !ins->set(nom_instancia + "_" + nom_clase, EnteroAString(num_instancias) ) ){
					cout << "Error creando clase: " << ins->error().name() << endl;
				}
				else{
					instancias[num_instancias] = new Instancia(nom_instancia, cl );
					num_instancias+=1;
					se_creo = true;
				}
			}
			
		}
		return se_creo;
	}
	
	bool OA::crear_propiedad(string nom_clase, string nom_propiedad){
		bool band = false;
		int i;
		Clase *cl = get_clase(nom_clase);
		
		//Si existe la clase y si la propiedad no existe -> agregar 
		if(cl != NULL && get_propiedad(nom_propiedad) == NULL && num_propiedades < P){
			if( !prop->set(nom_propiedad, EnteroAString(num_propiedades) ) ){
				cout << "Error creando clase: " << prop->error().name() << endl;
			}
			else{
				propiedades[num_propiedades] = new Propiedad( nom_propiedad, cl );
				cl->agregar_propiedad(nom_propiedad, num_propiedades);
				int num_hijos = cl->get_num_hijos();
				
				if(num_hijos > 0){
					for(i = 0; i < num_hijos; i++){
						Clase *p = cl->get_hijo(i);
						p->agregar_propiedad(nom_propiedad, num_propiedades);
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
		int i, c_v = 0;
		string variables[P]; 

		Clase *cl = get_clase(nom_clase);
		
		//Sii el evento ya existe y la prop_Activa es la misma, agregar la expresion al evento existente
		
		if( get_evento(nom_evento) == NULL && get_propiedad(nom_propActiva) != NULL && num_eventos < E){
			if( !event->set(nom_evento, EnteroAString(num_propiedades) ) ){
				cout << "Error creando clase: " << prop->error().name() << endl;
			}
			else{
				//validar que la expresion sea correcta							
				if( cl->comprobar_expresion(expresion, variables, &c_v)==0 ){
				
					
					eventos[num_eventos] = new Evento(nom_evento, nom_propActiva, valor_futuro, expresion);
					//Descomponer expresion y ver que variables tiene para agregar el evento a esas propiedades
					for(int i = 0; i < c_v; i++){
						cout << "&" << variables[i] << endl;
						(get_propiedad( variables[i] ))->agregar_evento( eventos[num_eventos] );
					
					}
					num_eventos = num_eventos + 1;
					band = true;
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
		if( bd->get(nombre, &valor) ){
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

	//Si devuelve verdadero se agrego el padre, sino no se pudo
	bool OA::agregar_subclase(string nom_clase, string nom_padre){
		//Ver si existe n_clase y n_padre y devolver el puntero
		bool todo_bien = false;
		Clase *hijo = get_clase(nom_clase);
		Clase *padre = get_clase(nom_padre);
		if( hijo!=NULL && padre!=NULL ){	
			hijo->agregar_padre(padre);
			int num_padres = padre->get_num_padres();
			if(num_padres > 0){
				for(int i = 0; i < num_padres; i++){
					Clase *p = padre->get_padre(i);
					hijo->agregar_padre( p );
					p->agregar_hijo( hijo );
				}
			}
			padre->agregar_hijo(hijo);
			int num_hijos = hijo->get_num_hijos();
			if(num_hijos > 0){
				for(int i = 0; i < num_hijos; i++){
					Clase *h = hijo->get_hijo(i);
					padre->agregar_hijo( h );
					h->agregar_padre( padre );
				}
			}
			
			//Agregar las propiedades de la superclase a la clase
			map<string, int>::const_iterator it;
			map<string, int> *portMap;
			portMap = padre->get_propiedades();
			for(it = portMap->begin(); it != portMap->end(); ++it){
    			hijo->agregar_propiedad(it->first, it->second);//Clave y Valor
    			
			}
			todo_bien = true;
		}
		return todo_bien;
	}

	bool OA::es_subclase_de(string nom_clase, string nom_clase_padre){
		bool todo_bien = false;
		Clase *clase = get_clase( nom_clase );
		Clase *padre = get_clase( nom_clase_padre );
		
		if( clase!=NULL && padre!=NULL ){	
			int num_padres = clase->get_num_padres();
			int i = 0;
			while(i < num_padres && !todo_bien){
				if( (clase->get_padre(i))->get_nombre() == nom_clase_padre ){
					todo_bien = true;
				}
				i+=1;
			}
		}
		return todo_bien;
	}

	bool OA::agregar_valorApropiedad(string nom_clase, string nom_instancia, string nom_propiedad, int valor){
		Instancia *i;
		Propiedad *p;
		Evento *e;
		int j, k, n_e;
		bool band = false;
		valor_r *va;
			
		i = get_instancia(nom_clase, nom_instancia);
		if( i !=NULL && get_pos_propiedad(nom_propiedad) != -1 ){ //Si existe la instancia y la propiedad
			
			band = i->agregar_valor_propiedad(nom_propiedad, valor);//Si se agrega el valor correctamente
			p = get_propiedad(nom_propiedad);//Obtengo el apuntador a la propiedad
			n_e = p->get_num_eventos();//Consulto el numero de eventos que tienen a dicha propiedad en su condicion booleana
			
			if( band && n_e > 0){ //Si existe la propiedad, y esta en alguna condicion booleana
				
				for(j = 0; j < n_e; j++){
					e = p->get_evento( j );
					//aQUI va un for con todas las expresiones del evento que se podrian cumplir
					if( i->validar_expresion( e->get_expresion()) ) {
						/*
						map<string, int>::const_iterator it;
						map<string, int> *portMap;
						portMap = e->get_propiedades();
						for(it = portMap->begin(); it != portMap->end(); ++it){
							hijo->agregar_propiedad(it->first, it->second);//Clave y Valor
					
						}*/
						
						for(k = 0; k < e->get_num_prop_act() ; k++){
							va = e->get_valor_nuevo(k);
						
							if(va->tipo == ENTERO){
								i->agregar_valor_propiedad( e->get_nombre_propiedad(k), va->ival );
							}
							else if(va->tipo == REAL){
								///////////////////////
							}
							else if(va->tipo == CHAR){
								//////////////////////
							}
						}
						cout << "Cumple con la condicion )" << endl;
				
					}
					else{
						cout << "NO Cumple con la condicion )" << endl;
					}
				}
			}
		}
		return band;
	}

	//Pre:Comprobar que existe propiedad i->existe_propiedad()
	int OA::consultar_propiedad_instancia(string nom_clase, string nom_instancia, string nom_propiedad){
		Instancia *i;
		
		i = get_instancia(nom_clase, nom_instancia);
		return i->get_valor_propiedad(nom_propiedad);
	}

# endif
