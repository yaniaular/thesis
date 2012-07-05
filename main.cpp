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
	string c, c2, h1, h2;
	Clase *x;

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

	//Crear 15000 clases
	for(i = 1; i <=50 ; i++){ //15000
		stringstream ss;
		ss << i;
		c = "Clase" + ss.str();		
		oa_bd->crear_clase( c );
	}

	//Crear 2 instancias para cada una de las primeras 7500 clases
	for(j = 1; j <= 50 ; j++){ //7500
		stringstream ff;
		ff << j;	
		for(i = 1; i <= 2 ; i++){
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
	cout << "Instancia: "  << oa_bd->get_instancia("Clase3", "Instancia1")->get_nombre() << endl;
	
	
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
	for(i = 0; i < n; i++ ){
		cout << "La clase " << i << " tiene por nombre "<< (oa_bd->get_clase(i))->get_nombre() << endl;
	}
*/

//	cout << "El nombre es: ";
//	cout << (oa_bd->get_clase("Clase14000"))->get_nombre() << endl;
//	cout << (oa_bd->get_clase("Clase10000"))->get_nombre() << endl;
//	cout << (oa_bd->get_clase("Clase5000"))->get_nombre() << endl;
//	oa_bd->agregar_padre("Clase4567", "Clase6789");
//	oa_bd->agregar_padre("Clase1000", "Clase6789");

	
	//Crear arbol de clases
	i = 1;
	
	// hallar un 2^x ~ cant_clases
	//7499
	while(i <= 24){
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

	//Probar las subclases 
	cout << oa_bd->crear_propiedad("Clase2", "NumMuertes") << endl;
	cout << oa_bd->crear_propiedad("Clase2", "Velocidad") << endl;
	cout << oa_bd->crear_propiedad("Clase2", "AlertarA")<< endl << endl;
	
	//No acepta variables con "_"
	cout << oa_bd->agregar_subclase("Clase50", "Clase2") << endl << endl;//subclase - clasepadre

	cout << oa_bd->es_subclase_de("Clase1000","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase1001","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase4567","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase8000", "Clase4000") << endl;
	cout << oa_bd->es_subclase_de("Clase11356", "Clase5678") << endl;
	cout << oa_bd->es_subclase_de("Clase8001", "Clase2000") << endl;
	cout << oa_bd->es_subclase_de("Clase8000", "Clase4001") << endl;
	cout << oa_bd->es_subclase_de("Clase44", "Clase5") << endl;
	cout << oa_bd->es_subclase_de("Clase37", "Clase2") << endl;
	cout << oa_bd->es_subclase_de("Clase6537", "Clase1") << endl;
	cout << oa_bd->es_subclase_de("Clase6537", "Clase2") << endl;
	cout << oa_bd->es_subclase_de("Clase6537", "Clase3") << endl << endl;

	cout << oa_bd->crear_evento("Clase2", "OcurreDesastreNatural", "AlertarA", 1,"NumMuertes > 0 || Velocidad > 35") << endl << endl;
	
	
	//INICIALIZAR LOS VALORES DE LAS INSTANCIAS,para poder evaluar las expresiones
	oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", -1);
	oa_bd->agregar_valorApropiedad("Clase2","Instancia1", "Velocidad", -1);
	oa_bd->agregar_valorApropiedad("Clase2","Instancia1", "AlertarA", -1);
	
	
	cout << "Consultando " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl;
	
	cout << "Agregando valores a las propiedades" << endl;
	cout << "(" << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 5)<< endl;
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 89)<< endl;
	
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 2)<< endl;
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 56)<< endl;
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 0)<< endl;
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 13)<< endl<< endl;
	
	
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Propiedadqnoexiste", 34)<< endl<< endl;


	cout << "Consultando " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "NumMuertes") << endl;
	cout << "Consultando " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad") << endl << endl; //Comprobar que existe la propiedad y la propiedad existe en esa instancias
	cout << "Consultando " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl;

	//oa_bd->crear_propiedad("Clase16000", "HuboPerdidaHumanaa");
	
/*	list<Clase> lst;	
	Clase c("yani");
	cout << c.get_nombre();
	lst.insert(0,c);
*/

	return EXIT_SUCCESS;
}
