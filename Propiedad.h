#ifndef Propiedad_H_
#define Propiedad_H_
#include "Clase.h"
#include "Evento.h"

class Propiedad{

	private:
		string nombre;//Nombre de la propiedad
		int num_clases;
		int num_padres;
		int num_hijos;
		int num_eventos;
		int tipo;
		Clase *(clases_a_la_que_pertenece[C]);
		Propiedad *(prop_padres[P]);//Propiedades padre
		Propiedad *(prop_hijas[P]);//Propiedades hijas
		Evento *(eventos[E]);
		
	public:
		Propiedad(string n, Clase *c, int t);
		bool agregar_evento(Evento *e);
		string get_nombre();
		Evento* get_evento(int pos);
		int get_num_eventos();
		int get_tipo();

};
 
 	Propiedad::Propiedad(string n, Clase *c, int t){
		nombre = n;
		num_clases = 0;
		num_padres = 0;
		num_hijos = 0;
		num_eventos = 0;
		tipo = t;
		clases_a_la_que_pertenece[num_clases] = c;
		num_clases+=1;
		
		int n_hijos_clase = c->get_num_hijos();
		
		for(int i = 0; i < n_hijos_clase ; i++){
			clases_a_la_que_pertenece[num_clases] = c->get_hijo(i);
			num_clases+=1;
		}
		
	}

	bool Propiedad::agregar_evento(Evento *e){
		eventos[num_eventos] = e;
		num_eventos+=1;
	}

	string Propiedad::get_nombre(){
		return nombre;
	}
	
	Evento* Propiedad::get_evento(int pos){
		return eventos[pos];
	
	}
	
	int Propiedad::get_num_eventos(){
		return num_eventos;
	}

	int Propiedad::get_tipo(){
		return tipo;
	}

# endif
