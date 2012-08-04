//Se compila: g++ -ggdb -o main main.cpp -L Clase.h
	
	// -Wtrigraphs -Wwrite-strings
	//Para ver todos los avisos -Wall

#include <limits.h>
#include <sys/types.h>
#include <regex.h>
#include <fstream>
#include <vector>
#include <algorithm> //Incluye la función find()
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
	for(j = 1; j <= 2 ; j++){ //7500
		stringstream ff;
		ff << j;	
		for(i = 1; i <= 2 ; i++){//50
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


	//CREAR VARIABLES
	cout << "/***************************************************************/" <<endl << endl << endl;
	cout << oa_bd->crear_propiedad("Clase2", "NumMuertes", ENTERO) << endl;
	cout << oa_bd->crear_propiedad("Clase2", "Velocidad", REAL) << endl;
	cout << oa_bd->crear_propiedad("Clase2", "Nombre", CADENA) << endl;
	cout << oa_bd->crear_propiedad("Clase2", "AlertarA", CADENA)<< endl;
	cout << oa_bd->crear_propiedad("Clase2", "Apellido", CADENA)<< endl;
	cout << oa_bd->crear_propiedad("Clase2", "Velocidad2", REAL) << endl;
	
	
	//CREAR EVENTO
	cout << "/***************************************************************/" <<endl << endl << endl;
	cout << oa_bd->crear_evento("Clase2", "OcurreDesastreNatural", "AlertarA", "CruzRoja","NumMuertes > 0 || Nombre == \"HOLA\" ") << endl << endl;
	
	
	//CONSULTAR VALORES
	cout << "/***************************************************************/" <<endl << endl << endl;
	
	cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "NumMuertes") << endl;
	cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
	cout << "Consultando Velocidad2 = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad2") << endl;
	cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl;
	cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Apellido") << endl;
	cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Nombre") << endl;
	
	//ASIGNAR VALORES
	cout << "/***************************************************************/" <<endl << endl << endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Nombre", (string)"Yanina Gabriela")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "AlertarA", (string)"Nadie")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Apellido", (string)"Aular Osorio")<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 89)<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 800.5)<< endl;
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad2", 300.5)<< endl;
	
	//ACTIVAR EVENTO
	//cout << "/***************************************************************/" <<endl << endl << endl;
	//oa_bd->activar_eventos("Clase2", "OcurreDesastreNatural");
	
	//MAS CONSULTA DE VALORES
	cout << "/***************************************************************/" <<endl << endl << endl;
	cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "NumMuertes") << endl;
	cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
	cout << "Consultando Velocidad2 = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad2") << endl;
	cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl;
	cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Nombre") << endl;

	cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Apellido") << endl;
	return EXIT_SUCCESS;
}
