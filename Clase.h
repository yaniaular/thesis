#ifndef Clase_H_
#define Clase_H_
#include <iostream>
#include <fstream>
#include <kcstashdb.h>
#define C 15000
#define I 500
#define P 500

using namespace std;
using namespace kyotocabinet;

class Clase{

	private:
		string nombre;
		int num_padres;
		int num_hijos;
		int num_propiedades;
		Clase *( padres[C]);
		Clase *( hijos[C] );
//		StashDB propiedades;

	public:
		Clase();			//Constructor
		Clase(string n);	//Constructor 
		string get_nombre();
		Clase* get_padres();
		Clase* get_padre(int n);
		Clase* get_hijo(int n);
		int get_numpadres();
		int get_numhijos();
		void set_nombre(string n);
		void agregar_padre(Clase *nuevo_padre);
		void agregar_hijo(Clase *nuevo_hijo);
};
 
	Clase::Clase(){
		num_padres = 0;
		num_hijos = 0;
		num_propiedades = 0;
	}
 	Clase::Clase(string n){
		nombre = n;
		num_padres = 0;
		num_hijos = 0;
	}

	string Clase::get_nombre(){
		return nombre;
	}

	//No se esta usando
	Clase* Clase::get_padres(){
		return padres[C];

	}

	Clase* Clase::get_padre(int n){
		return padres[n];
	}

	Clase* Clase::get_hijo(int n){
		return hijos[n];
	}

	int Clase::get_numpadres(){
		return num_padres;
	}

	int Clase::get_numhijos(){
		return num_hijos;
	}

	void Clase::set_nombre(string n){
		nombre = n;
	}  

	void Clase::agregar_padre(Clase *nuevo_padre){
	//Ver primero si el padre a conectar existe 
		padres[num_padres] = nuevo_padre;
		num_padres+=1;
	}

	void Clase::agregar_hijo(Clase *nuevo_hijo){
	//Ver primero si el padre a conectar existe 
		hijos[num_hijos] = nuevo_hijo;
		num_hijos+=1;
	}
# endif
