#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <list>
#include "Grafo.h"

//devolverAdyacentes(int origen, list<Arco> & adyacentes) const;

using namespace std;

int main(){

	Grafo<int> grafo1;
	

	int i, j, cant_clases = 300; 
	string nombre;
	
	cout << "Creando las " << cant_clases << " Clases..." << endl;	
	for(i = 1; i <= cant_clases ; i++){ //15000
		grafo1.agregarVertice( i );
	}
	
	i = 0;
	while(i <= 149){
		
		grafo1.agregarArco(i, i*2, 1);
		grafo1.agregarArco(i, (i*2)+1, 1);

		i+=1;
	}

	//cout<< "Existe " << grafo1.existeArco(2,4)<< endl;

	i = 0;
	
	while(i <= 300){
		j = 0;		
		while(j <= 300){
		cout<< "Camino " << grafo1.hayCamino(i, j) << endl;
			j+=1;		
		}
		i+=1;
	}

	/*grafo1.agregarVertice(1);
	grafo1.agregarVertice(2);
	grafo1.agregarVertice(3);
	grafo1.agregarVertice(4);
	grafo1.agregarVertice(5);
	grafo1.agregarVertice(6);
	grafo1.agregarVertice(7);
	grafo1.agregarVertice(8);
	grafo1.agregarArco(1, 2, 11); // parametros: (vertice 1, vertice 2, costo arco)
	grafo1.agregarArco(1, 7, 9);
	grafo1.agregarArco(1, 4, 23);
	grafo1.agregarArco(2, 6, 14);
	grafo1.agregarArco(3, 5, 3);
	grafo1.agregarArco(4, 2, 5);
	grafo1.agregarArco(4, 7, 4);
	grafo1.agregarArco(5, 6, 5);
	grafo1.agregarArco(5, 4, 10);
	grafo1.agregarArco(7, 3, 21);
	grafo1.agregarArco(7, 8, 17);*/
	//cout << grafo1 << endl;

	/*ListDigraph g;

	ListDigraph::Node u = g.addNode();
	ListDigraph::Node v = g.addNode();
	ListDigraph::Arc  a = g.addArc(u, v);

	cout << "Hello World! This is LEMON library here." << endl;
	cout << "We have a directed graph with " << countNodes(g) << " nodes " << "and " << countArcs(g) << " arc." << endl;
*/


	return EXIT_SUCCESS;
}
