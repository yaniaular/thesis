//Se compila: g++ -ggdb -o main main.cpp -L Clase.h
	
	// -Wtrigraphs -Wwrite-strings
	//Para ver todos los avisos -Wall

#include <limits.h>
#include <sys/types.h>
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
	string c, c2, h1, h2;
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
		
			c = "Instancia" + ss.str() ;	
			c2 = "Clase" + ff.str();
			oa_bd->crear_instancia( c, c2 );	
					
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
	cout << oa_bd->crear_propiedad("Clase2", "Nombre", CADENA) << endl;
	cout << oa_bd->crear_propiedad("Clase2", "AlertarA", CADENA)<< endl;
	cout << oa_bd->crear_propiedad("Clase2", "Apellido", CADENA)<< endl;
	
	
	//CREAR EVENTO
	cout << "/**************************** CREAR EVENTO **********************************/" <<endl;
	cout << oa_bd->crear_evento("Clase2", "OcurreDesastreNatural", "AlertarA", "CruzRoja","NumMuertes > 0 || Nombre == \"HOLA\" ") << endl << endl;
	
	
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
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 89)<< endl;
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
	
	
	for(j = 2; j <= 3 ; j++){ //7500
		stringstream ff;
		ff << j;	
		cout << "/******************** MAS CONSULTA DE VALORES "<< ff.str() <<" ********************/" <<endl;
		
		for(i = 1; i <= 7 ; i++){//50
			stringstream ss;
			ss << i;
		
			c = "Instancia" + ss.str() ;	
			c2 = "Clase" + ff.str();
	cout << c << " " << c2 << endl; 	
	cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia(c2, c, "NumMuertes") << endl;
	cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia(c2, c, "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
	cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia(c2, c, "AlertarA") << endl;
	cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia(c2, c, "Nombre") << endl;
	cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia(c2, c, "Apellido") << endl << endl;

				
		}
	}
	

	return EXIT_SUCCESS;
}
