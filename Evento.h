#ifndef Evento_H_
#define Evento_H_
#include "Tabla.h"

struct valor_r {
	int ival;
	double rval;
	char *cval;
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
		Evento *(padres[E]);//Eventos padre
		Evento *(hijos[E]);//Eventos hijas
		int num_padres;
		int num_hijos;
			
	public:
		Evento(string nom, string pA, int valor, string e);
		Evento(string nom, string pA, double valor, string e);
		Evento(string nom, string pA, string valor, string e);
		int get_num_padres();
		int get_num_hijos();
		
		int get_num_prop_act();
		string get_expresion();
		string get_nombre();
		
		Evento* get_padre(int n);
		Evento* get_hijo(int n);
		
		string get_nombre_propiedad(int pos);
		valor_r* get_valor_nuevo(int pos);
		map<int, string>* get_propiedades();
		
		void agregar_padre(Evento *nuevo_padre);
		void agregar_hijo(Evento *nuevo_hijo);
		
		
};
 
 	Evento::Evento(string nom, string pA, int valor, string e){
		num_prop_activas = 0;
		num_padres = 0;
		num_hijos = 0;
		nombre = nom;
		expresion = e;
		prop_activas = new map<int, string>();
		(*prop_activas)[num_prop_activas + 1] = pA;//Le sumo 1 para no generar confusiones, porque cuando la propiedad no existe devuelve un valor de 0, y la posicion 0 tambien existe. Entonces cuando una propiedad no exista, devolvera -1
		valores[num_prop_activas] = new valor_r();
		valores[num_prop_activas]->tipo = ENTERO;
		valores[num_prop_activas]->ival = valor;
		num_prop_activas= num_prop_activas + 1;
		
	}

 	Evento::Evento(string nom, string pA, double valor, string e){
		num_prop_activas = 0;
		nombre = nom;
		expresion = e;
		prop_activas = new map<int, string>();
		(*prop_activas)[num_prop_activas + 1] = pA;//Le sumo 1 para no generar confusiones, porque cuando la propiedad no existe devuelve un valor de 0, y la posicion 0 tambien existe. Entonces cuando una propiedad no exista, devolvera -1
		valores[num_prop_activas] = new valor_r();
		valores[num_prop_activas]->tipo = REAL;
		valores[num_prop_activas]->rval = valor;
		num_prop_activas= num_prop_activas + 1;
		
	}
	
	 Evento::Evento(string nom, string pA, string valor, string e){
		num_prop_activas = 0;
		nombre = nom;
		expresion = e;
		prop_activas = new map<int, string>();
		(*prop_activas)[num_prop_activas + 1] = pA;//Le sumo 1 para no generar confusiones, porque cuando la propiedad no existe devuelve un valor de 0, y la posicion 0 tambien existe. Entonces cuando una propiedad no exista, devolvera -1
		valores[num_prop_activas] = new valor_r();
		valores[num_prop_activas]->tipo = CADENA;
		valores[num_prop_activas]->cval = StringAChar(valor);
		
		num_prop_activas= num_prop_activas + 1;
		
	}

	int Evento::get_num_padres(){
		return num_padres;
	}

	int Evento::get_num_hijos(){
		return num_hijos;
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

	Evento* Evento::get_padre(int n){
		return padres[n];
	}

	Evento* Evento::get_hijo(int n){
		return hijos[n];
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
	
	void Evento::agregar_padre(Evento *nuevo_padre){
	//Ver primero si el padre a conectar existe 
		padres[num_padres] = nuevo_padre;
		num_padres+=1;
	}

	void Evento::agregar_hijo(Evento *nuevo_hijo){
	//Ver primero si el padre a conectar existe 
		hijos[num_hijos] = nuevo_hijo;
		num_hijos+=1;
	}


# endif
