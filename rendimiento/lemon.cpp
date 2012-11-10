
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <list>
#include "Grafo.h"

//devolverAdyacentes(int origen, list<Arco> & adyacentes) const;

using namespace std;

int main(){

	Grafo<string> grafo1;
	string c, c2, c3;

	int i, j, k, cant_clases = 300, cant_instancias = 830; 
	string nombre;
	

	cout << "Creando las " << cant_clases << " Clases..." << endl;	
	for(i = 1; i <= cant_clases ; i++){ 
		stringstream s1;
		s1 << i;
		c = "Clase" + s1.str();	
		grafo1.agregarVertice( c );
	}
	
	//cout << grafo1.existeVertice("Clase3")<< endl;	
	
	
	cout << "Conectando las clases... "<< endl;

	i = 1;
	while(i <= 149){
		stringstream s1, s2, s3;
		s1 << i;
		c = "Clase" + s1.str();

		s2 << i*2;
		c2 = "Clase" + s2.str();

		s3 << (i*2)+1;
		c3 = "Clase" + s3.str();

		grafo1.agregarArco(c, c2, 1);
		grafo1.agregarArco(c, c3, 1);

		i+=1;
	}

	//cout<< "Existe " << grafo1.existeArco(2,4)<< endl;

	cout << "Verificando si existe caminos todas las clases contra todas... "<< endl;

	i = 1;
	while(i <= cant_clases){
		stringstream s1;
		s1 << i;
		c = "Clase" + s1.str();
		j = 1;
		while(j <= cant_clases){
			stringstream s2;
			s2 << j;
			c2 = "Clase" + s2.str();		
			grafo1.hayCamino(c, c2);
			j+=1;		
		}
		i+=1;
	}

	cout << "Creando las " << cant_instancias << " instancias..." << endl;	

	i = 1;
	while(i <= cant_clases){
		stringstream s1;
		s1 << i;
		c = "Clase" + s1.str();
		j = 1;
		while(j <= cant_instancias){
			stringstream s2;
			s2 << j;
			c2 = "Instancia" + s2.str() + "_" + c;
			grafo1.agregarVertice( c2 );
			grafo1.agregarArco(c, c2, 1);
			j+=1;
		}
		i+=1;
	}

	cout << "Verificar si hay un camino desde todas las clases a sus respectivas instancias"<< endl;
	i = 1;
	while(i <= cant_clases){
		stringstream s1;
		s1 << i;
		c = "Clase" + s1.str();
		j = 1;
		while(j <= cant_instancias){
			stringstream s2;
			s2 << j;
			c2 = "Instancia" + s2.str() + "_" + c;;
			grafo1.hayCamino(c, c2);
			j+=1;
		}
		i+=1;
	}
	
	return EXIT_SUCCESS;
}
