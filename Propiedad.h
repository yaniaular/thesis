#ifndef Propiedad_H_
#define Propiedad_H_
//#include <iostream>
#include "Clase.h"

//using namespace std;

class Propiedad{

	private:
		string nombre;//Nombre de la propiedad
		int num_clases;
		int num_padres;
		int num_hijos;
		Clase *(clases_a_la_que_pertenece[C]);
		Propiedad *(prop_padres[P]);//Propiedades padre
		Propiedad *(prop_hijas[P]);//Propiedades hijas
		
	public:
		Propiedad(string n, Clase *c);
		string get_nombre();
};
 
 	Propiedad::Propiedad(string n, Clase *c){
		nombre = n;
		num_clases = 1;
		num_padres = 0;
		num_hijos = 0;
		clases_a_la_que_pertenece[0] = c;
		
		int n_hijos_clase = c->get_numhijos();
		
		for(int i = 0; i < n_hijos_clase ; i++){
			clases_a_la_que_pertenece[num_clases] = c->get_hijo(i);
			num_clases+=1;
		}
		
	}

	string Propiedad::get_nombre(){
		return nombre;
	}

# endif
