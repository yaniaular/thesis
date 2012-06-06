#ifndef Instancia_H_
#define Instancia_H_
//#include <iostream>
//#include <fstream>
#define CP 5000
#include "Clase.h"

//#include "evaluate.h"
//using namespace std;

class Instancia{

	private:
		string nombre;
		Clase *clase; //Clase a la que pertenece la instancia
//		struct vartable *vt;
//		struct val *(valores[CP]);
				
	public:
		Instancia(string n, Clase *c);
		string get_nombre();
		Clase* get_clase();
};
 
 	Instancia::Instancia(string n, Clase *c){
		nombre = n;
		clase = c;
		//vt = create_vartable();
		/*	
		for(int i = 0; i < CP; i++){
			put_var(vt, " ", valores[i]);
		}
		*/
		//y.type = T_INT; y.ival = 7;
		//nom.type = T_CHAR; nom.cval = "yanina aular";
		//n.type = T_CHAR; n.cval = "yani";
		//ape.type = T_CHAR; ape.cval = "aular";
 
	}

	string Instancia::get_nombre(){
		return nombre;
	}

	Clase* Instancia::get_clase(){
		return clase;
	}

#endif
