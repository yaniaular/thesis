//Se compila: g++ -ggdb -o main main.cpp -L Clase.h
	
	// -Wtrigraphs -Wwrite-strings
	//Para ver todos los avisos -Wall
	
//#include <sys/types.h>
#include <regex.h>
#include <vector>
#include "OA.h"


//Funcion que recibe un string, y elimina los espacios en blanco del mismo
string Trim(string cadena)
{
	string::const_iterator i = cadena.begin(); 
	string::const_iterator f = cadena.end();
	
     string::const_iterator it;
     string buff;
     for (it = i; it != f; ++it)
     {
         if (*it != ' ') buff += *it;
     }

     return buff;    
}



int main(){
	typedef int T;
	int i, j, n;
	string c, in, h1, h2;
	Clase *x;
	Instancia *is;
	string buffer;
	 
	OA *oa_bd = new OA();

	//Crear 15000 clases
	for(i = 1; i <=50 ; i++){ //15000
		stringstream ss;
		ss << i;
		c = "Clase" + ss.str();		
		oa_bd->crear_clase( c );
	}

	//Crear 2 instancias para cada una de las primeras 7500 clases, 50
	for(j = 1; j <= 50 ; j++){ //7500
		stringstream ff;
		ff << j;	
		for(i = 1; i <= 50 ; i++){//50
			stringstream ss;
			ss << i;
		
			in = "Instancia" + ss.str() ;	
			c = "Clase" + ff.str();
			oa_bd->crear_instancia( in, c );	
					
		}
	}

	n = oa_bd->get_num_clases();

	cout <<"Numero de clases: "<< n << endl;
	cout <<"Numero de instancias: " << oa_bd->get_num_instancias() << endl;


	//Cuando se consulta una instancia o una clase y no existe, devuelve NULL, y al imprimir NULL crea violacion del segmento
	is = oa_bd->get_instancia("Clase3", "Instancia1");
	if( is != NULL ){
		cout << "Instancia: " << is->get_nombre() << endl;
	}
	else{
		cout << "No existe la instancia" << endl;
	}
	
	x = oa_bd->get_clase(14999);
	if( x != NULL ){
		cout << "Clase: " << x->get_nombre() << endl;
	}
	else{
		cout << "No existe la clase" << endl;
	}
	
	x = oa_bd->get_clase(15000);
	if( x != NULL ){
		cout << "Clase: " << x->get_nombre() << endl;
	}
	else{
		cout << "No existe la clase" << endl;
	}


/*
terminate called after throwing an instance of 'std::logic_error'
  what():  basic_string::_S_construct null not valid
Abortado (`core' generado)*/

	oa_bd->agregar_subclase("Clase3", "Clase2");

	//CREAR VARIABLES
	cout << "/************************* CREAR VARIABLES *************************************/" <<endl;
	//Se crean las propiedades y se inicializan
	cout << oa_bd->crear_propiedad("Clase2", "NumMuertes", ENTERO) << endl;
	cout << oa_bd->crear_propiedad("Clase2", "Velocidad", REAL) << endl;
	cout << oa_bd->crear_propiedad("Clase2", "AlertarA", CADENA)<< endl;
	cout << oa_bd->crear_propiedad("Clase4", "Nombre", CADENA) << endl;
	cout << oa_bd->crear_propiedad("Clase4", "Apellido", CADENA)<< endl;
	
	
	//CREAR EVENTO
	cout << "/**************************** CREAR EVENTO **********************************/" <<endl;
	cout << oa_bd->crear_evento("Clase2", "OcurreDesastreNatural", "AlertarA", "CruzRoja","NumMuertes > 0 || Velocidad > 500") << endl << endl;
	//  || Nombre == \"HOLA\" 
	
	//CONSULTAR VALORES
	cout << "/****************************  CONSULTAR VALORES ***********************************/" <<endl;
	
	cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "NumMuertes") << endl;
	cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
	cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl;
	cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Apellido") << endl;
	cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Nombre") << endl;

	//ASIGNAR VALORES
	cout << "/*************************** ASIGNAR VALORES ************************************/" <<endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Nombre", (string)"Yanina Gabriela")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "AlertarA", (string)"Nadie")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Apellido", (string)"Aular Osorio")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 0)<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 800.5)<< endl;

	//ASIGNAR VALORES 2
	cout << "/*************************** ASIGNAR VALORES 2 ************************************/" <<endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "Nombre", (string)"Nombre_2")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "AlertarA", (string)"Nadie")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "Apellido", (string)"Apellido_2")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "NumMuertes", 0)<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "Velocidad", 3)<< endl;

	
	cout << oa_bd->agregar_valorApropiedad("Clase3", "Instancia7", "NumMuertes", 13)<< endl;
	
	//ACTIVAR EVENTO
	cout << "/***************************** ACTIVAR EVENTO **********************************/" <<endl;
	oa_bd->activar_eventos("Clase3", "OcurreDesastreNatural");
	
	//MAS CONSULTA DE VALORES
	oa_bd->agregar_subclase("Clase5", "Clase4");
	oa_bd->agregar_subclase("Clase4", "Clase2");
	for(j = 2; j <= 3 ; j++){ //7500
		stringstream ff;
		ff << j;	
		cout << "/******************** MAS CONSULTA DE VALORES "<< ff.str() <<" ********************/" <<endl;
		
		for(i = 1; i <= 7 ; i++){//50
			stringstream ss;
			ss << i;
		
			in = "Instancia" + ss.str() ;	
			c = "Clase" + ff.str();
	cout << in << " " << c << endl;
	
	if( (oa_bd->get_clase(c))->existe_propiedad( "NumMuertes" ) )
	cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia(c, in, "NumMuertes") << endl;
	
	if( (oa_bd->get_clase(c))->existe_propiedad( "Velocidad" ) )
	cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia(c, in, "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
	
	if( (oa_bd->get_clase(c))->existe_propiedad( "AlertarA" ) )
	cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia(c, in, "AlertarA") << endl;
	
	if( (oa_bd->get_clase(c))->existe_propiedad( "Nombre" ) )
	cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia(c, in, "Nombre") << endl;
	
	if( (oa_bd->get_clase(c))->existe_propiedad( "Apellido" ) )
	cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia(c, in, "Apellido") << endl << endl;
	
				
		}
	}

		
/*  Se hace la lectura por archivos de las consultas reactivas:
 *  Se verifica la correctitud de la sintaxis
 *  No deben haber eventos repetidos
 *  Se comprueba la existencia de la clase donde se activara el o los eventos
 *  
*/


/*

ifstream entrada("consultas_reactivas.in");
int reti;
regex_t regex; //Variable para la expresion regular
string exp;
char * pattern ="^\\((S|s|p|P),\\[([A-Za-z0-9])+(([,])([A-Za-z0-9])+)*\\],([A-Za-z0-9])+\\)$"; //Patron de la expresion regular
*/
/*
^ Indica el inicio de la frase
\\(   Agrega el parentesis
(S|s|p|P) debe haber cualquiera de las letras que esta entre parentesis
, Debe haber siempre una coma
\\[ Agrega el corchete
([A-Za-z0-9])+ 1 o mas palabras que contengan letras y numeros
(([,])([A-Za-z0-9])+)* expresion formada por una coma seguido y 1 palabra que contenga letras y numeros (Puede haber 0 o mas expresiones)
\\] Agrega corchete
, Debe haber siempre una coma
([A-Za-z0-9])+ 1 o mas palabras que contengas letras y numeros
\\) Agrega el parentesis
$ indica el final de la frase
*/
/*
	reti = regcomp (&regex, pattern, REG_EXTENDED);//Compilo el patrón
	while( getline (entrada,exp) ){//Leo una linea del archivo
		exp = Trim(exp);//Quitar espacios de la expresion
		cout << exp << " " << endl;
		reti = regexec (&regex, &exp[0], (size_t)0, NULL, 0); //Se verifica que la consulta reactiva cumpla con el patrón
		if( reti == REG_NOMATCH ){ //Error de sintaxis en la consulta reactiva
			puts("Error de sintaxis");
		}
		else{ //Si es 0, entonces la consulta reactiva cumple con el patrón
		
			// Se obtienen los eventos dentro del corchete
			int    status;
			regex_t    re;
			regmatch_t rm;
			char *patter = "\\[([A-Za-z0-9])+(([,])([A-Za-z0-9])+)*\\]";
			string eventos, tipo, tabla;
			int num_eventos;
			map<string, string> *eventosHash;//Tabla Hash con los eventos de la consulta-reactiva
			string eve;
			bool band;
			
			eventosHash = new map<string, string>();
						
			//Se compila la expresión regular y se verifica si tiene algún error
			if (regcomp(&re, patter, REG_EXTENDED) != 0) {
				cout << "Patrón erróneo";
			}
		
			status = regexec(&re, &exp[0], 1, &rm, 0); //Se verifica que el grupo de eventos de la consulta reactiva cumpla con el patrón
			regfree(&re); //Libera la memoria asignada por regcomp()
		
			if (status != 0) { //Si el estado no devuelve 0, entonces no cumple el patrón
				cout << "No coincide";
				cout << status << endl;
			}
			else{
				// Extraigo el rango de los eventos
				eventos = exp.substr( (int)rm.rm_so, (int)rm.rm_eo - 3);
				tipo = exp.substr(1, (int)rm.rm_so - 2);
				tabla = exp.substr((int)rm.rm_eo + 1 , exp.size() );
				tabla.erase(tabla.size() - 1 , 2);
				eventos = eventos.substr( 1, eventos.size());
				eventos[ eventos.size()-1 ] = ',';
			}
			
			cout << "Modo de activacion: "<< tipo<< ", Clase: " << tabla << endl;
			// Se obtienen los nombres de los eventos y se verifica que no hayan repetidos
			num_eventos = 0;
			band = true;
			do{
				int f;
				f = eventos.find(","); //Busco la posicion de la coma mas cercana
				eve = eventos.substr(0, f); //Extraigo un evento de la lista
				
				if( (*eventosHash)[eve] != ""  ){//Reviso si es evento es repetido
					band = false;
				}
				else{
					(*eventosHash)[eve] = eve; //Guardo el evento en la tabla hash
					num_eventos+=1; //Contador de eventos
					eventos = eventos.substr( f+1, eventos.size()-1);//Elimino el evento que se agrego de la cadena original
				}
			}while( eventos.size() > 1 && band );
			
			if(!band){
				cout << "Hay uno o más eventos repetidos" << endl;
			}
			else{
				//Verificar que existen los eventos y la clase en donde se activaran		
				if( oa_bd->existencia_consulta_reactiva(eventosHash, num_eventos, tabla) ){
					//oa_bd->activar_eventos(nom_evento, nom_);
				}
			}
			
		}
		cout << endl;		 
	}
	regfree (&regex);
	entrada.close();
	*/
	return EXIT_SUCCESS;
}
