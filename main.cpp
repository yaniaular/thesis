//Se compila: g++ -ggdb -o main main.cpp -L Clase.h
	
	// -Wtrigraphs -Wwrite-strings
	//Para ver todos los avisos -Wall

//#include <iostream>
//#include <fstream>
//#include <cstdlib>
#include <limits.h>
#include "OA.h"

using namespace std;

int main(){
	typedef int T;
	int i, j, n;
	string c, h1, h2;

	OA *oa_bd = new OA();
/*
	oa_bd->crear_clase( "fenMeteorologico" );
	oa_bd->crear_clase( "fenAtmosferico" );
	oa_bd->crear_clase( "fenNatural" );
	oa_bd->crear_clase( "fenClimatico" );
	oa_bd->crear_clase( "fenomeno" );
	oa_bd->crear_clase( "fenTropical" );
	oa_bd->crear_clase( "lluvias" );
	oa_bd->crear_clase( "huracan" );
*/

	for(i = 1; i <=14000 ; i++){
		stringstream ss;
		ss << i;
		c = "Clase" + ss.str();		
		oa_bd->crear_clase( c );
	}
/***
	for(i = 1; i <=100 ; i++){
		stringstream ss;
		ss << i;
		c = "Instancia" + ss.str();		
		oa_bd->crear_instancia( c, "Clase1" );
	}

	n = oa_bd->num_clases();

	cout <<"Numero de clases: "<< n << endl;
	cout <<"Numero de instancias: " << oa_bd->num_instancias() << endl;
***/

	//Cuando se consulta una instancia o una clase y no existe, devuelve NULL, y al imprimir NULL crea violacion del segmento
/***
	cout << "Instancia: "  << oa_bd->get_instancia("Instancia100")->get_nombre() << endl;
	cout << "Clase: " << oa_bd->get_clase(16999)->get_nombre() << endl;
****/

/*
	for(i = 1; i <= n; i++ ){
		cout << "La clase " << i << " tiene por nombre "<< (oa_bd->get_clase(i))->get_nombre() << endl;
	}
*/

//	cout << "El nombre es: ";
//	cout << (oa_bd->get_clase("Clase14000"))->get_nombre() << endl;
//	cout << (oa_bd->get_clase("Clase10000"))->get_nombre() << endl;
//	cout << (oa_bd->get_clase("Clase5000"))->get_nombre() << endl;


//	oa_bd->agregar_padre("Clase4567", "Clase6789");
//	oa_bd->agregar_padre("Clase1000", "Clase6789");
/***
	i = 1;
	
	
	while(i <= 7494){
		stringstream ss,s2,s3;
		ss << i;
		c = "Clase" + ss.str();
	
		
		s2 << (i*2);
		h1 = "Clase" + s2.str();

		s3 << ((i*2)+1);
		h2 = "Clase" + s3.str();
		
		oa_bd->agregar_subclase(h1, c);
		oa_bd->agregar_subclase(h2, c);
		
		i+=1;
	}

	
	cout << oa_bd->es_subclase_de("Clase1000","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase1001","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase4567","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase8000", "Clase4000") << endl;
	cout << oa_bd->es_subclase_de("Clase11356", "Clase5678") << endl;
	cout << oa_bd->es_subclase_de("Clase8001", "Clase2000") << endl;
	cout << oa_bd->es_subclase_de("Clase8000", "Clase4001") << endl;
	cout << oa_bd->es_subclase_de("Clase44", "Clase5") << endl;
	cout << oa_bd->es_subclase_de("Clase37", "Clase2") << endl;
*******/
	
//	Clase c("fenMeteorologico");

/*	list<Clase> lst;	
	Clase c("yani");
	cout << c.get_nombre();
*/

//	lst.insert(0,c);

	return EXIT_SUCCESS;
}
