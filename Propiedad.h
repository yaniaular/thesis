#ifndef Propiedad_H_
#define Propiedad_H_
//#include <iostream>
#include "Clase.h"

//using namespace std;

class Propiedad{

	private:
		string nombre;
//		Clase *(clases_a_la_que_pertenece[C]);
//		Propiedad *(prop_padres[P]);
//		Propiedad *(prop_hijos[P]);
		
	public:
		Propiedad(string n);
		string get_nombre();
};
 
 	Propiedad::Propiedad(string n){
		nombre = n;
	}

	string Propiedad::get_nombre(){
		return nombre;
	}

# endif
