#ifndef Clase_H_
#define Clase_H_
#include "evaluate.h"
#include "Tabla.h"

class Clase{

	private:
		string nombre;
		int num_padres;
		int num_hijos;
		int num_propiedades;
		int num_instancias;
		Clase *( padres[C]);//Padres de la clase
		Clase *( hijos[C] );//Hijos de la clase
		map<string, int> *propi;
		map<string, int> *instancias;
		struct vartable *vt;
		struct val x;
		
	public:
		Clase(string n);	//Constructor 
		string get_nombre();
		Clase* get_padres();
		Clase* get_padre(int n);
		Clase* get_hijo(int n);
		map<string, int>* get_propiedades();//Tiene el nombre de la propiedad y la posicion en la tabla general en la clase OA menos 1
		map<string, int>* get_instancias();//Tiene el nombre de la instancia (sin el "_" + nom_clase) y la posicion en la tabla general en la clase OA menos 1
		int get_num_padres();
		int get_num_hijos();
		int get_num_propiedades();
		string get_pos_propiedad(string p);
		bool existe_propiedad(string p);
		bool existe_instancia(string i);
		void set_nombre(string n);
		void agregar_padre(Clase *nuevo_padre);
		void agregar_hijo(Clase *nuevo_hijo);
		void agregar_propiedad(string n_p, int posicion);
		void agregar_instancia(string n_i, int posicion);
		int comprobar_expresion(string expresion, string variables[P], int *cant_var);
};

 	Clase::Clase(string n){
		nombre = n;
		num_padres = 0;
		num_hijos = 0;
		num_propiedades = 0;
		num_instancias = 0;
		propi = new map<string, int>();
		instancias = new map<string, int>();
		vt = create_vartable();
		x.type = T_INT; x.ival = 6;
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

	map<string, int>* Clase::get_propiedades(){
		return propi;
	}

	map<string, int>* Clase::get_instancias(){
		return instancias;
	}

	int Clase::get_num_padres(){
		return num_padres;
	}

	int Clase::get_num_hijos(){
		return num_hijos;
	}

	int Clase::get_num_propiedades(){
		return num_propiedades;
	}

	//Ver posicion de la propiedad en el arreglo principal en OA.h
	//Si es -1, no existe la propiedad en esta clase
	string Clase::get_pos_propiedad(string p){
		return EnteroAString((*propi)[p]-1);
	}

	bool Clase::existe_propiedad(string p){
		return ( !( ((*propi)[p]-1) == -1) );
	
	}

	bool Clase::existe_instancia(string i){
		return ( !( ((*instancias)[i]-1) == -1) );
	
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
	
	void Clase::agregar_propiedad(string n_p, int posicion){
		put_var(vt, StringAChar(n_p), &x);
		(*propi)[n_p] = posicion + 1; //le sumo 1, porque cuando la pos es 0, y la propiedad no exista, lanzara 0 igual, y se presta para confusiones
		num_propiedades = num_propiedades + 1;
	}
	
	void Clase::agregar_instancia(string n_i, int posicion){
		(*instancias)[n_i] = posicion + 1; //le sumo 1, porque cuando la pos es 0, y la propiedad no exista, lanzara 0 igual, y se presta para confusiones
		num_instancias = num_instancias + 1;
	}
	
	int Clase::comprobar_expresion(string expresion, string variables[P], int *cant_var){
		struct val result;
		return evaluate(StringAChar(expresion), &result, vt, variables, cant_var);
	}
	
# endif
