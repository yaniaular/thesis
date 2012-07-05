#ifndef Evento_H_
#define Evento_H_
#include <iostream>
#include <map>
#define P 15000
#define ENTERO 1
#define REAL 2
#define CHAR 3
//#include "Propiedad.h"
//#include "Clase.h"

struct valor_r {
	int ival;
	double rval;
	char *cvar;
	int tipo;
};


using namespace std;

class Evento{

	private:
		string nombre;
		int num_prop_activas;
		map<int, string> *prop_activas;//Nombre de la propiedad, y su posicion en el arreglo general de OA menos 1
		struct valor_r *(valores[P]);
		string expresion;
			
	public:
		Evento(string nom, string pA, int valor, string e);
		Evento(string nom, string pA, double valor, string e);
		Evento(string nom, string pA, char *valor, string e);
		int get_num_prop_act();
		string get_expresion();
		string get_nombre();
		string get_nombre_propiedad(int pos);
		valor_r* get_valor_nuevo(int pos);
		map<int, string>* get_propiedades();
		
		
};
 
 	Evento::Evento(string nom, string pA, int valor, string e){
		num_prop_activas = 0;
		nombre = nom;
		expresion = e;
		prop_activas = new map<int, string>();
		(*prop_activas)[num_prop_activas + 1] = pA;//Le sumo 1 para no generar confusiones, porque cuando la propiedad no existe devuelve un valor de 0, y la posicion 0 tambien existe. Entonces cuando una propiedad no exista, devolvera -1
		valores[num_prop_activas] = new valor_r();
		valores[num_prop_activas]->tipo = ENTERO;
		valores[num_prop_activas]->ival = valor;
		num_prop_activas= num_prop_activas + 1;
		
	}

	int Evento::get_num_prop_act(){
		return num_prop_activas;	
	}

	string Evento::get_expresion(){
		return expresion;
	}
	
	string Evento::get_nombre(){
		return nombre;
	}

	string Evento::get_nombre_propiedad(int pos){
		return (*prop_activas)[pos + 1];
	
	}
	
	valor_r* Evento::get_valor_nuevo(int pos){
		return valores[pos];
	
	}
	
	map<int, string>* Evento::get_propiedades(){
		return prop_activas;
	}

# endif
