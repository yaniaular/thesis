#ifndef Instancia_H_
#define Instancia_H_
#include "Clase.h"


//using namespace std;

class Instancia{

	private:
		string nombre;//Nombre de la clase
		Clase *clase; //Clase a la que pertenece la instancia
		struct vartable *vt;
		struct val *(valores[P]);
		int num_var;
				
	public:
		Instancia(string n, Clase *c);
		string get_nombre();
		Clase* get_clase();
		bool existe_propiedad(string nom_propiedad);
		int get_valor_propiedad(string nom_propiedad);
		bool validar_expresion(string exp);
		
		
		bool agregar_valor_propiedad(string propiedad, int valor);
		bool agregar_valor_propiedad(string propiedad, float valor);
		bool agregar_valor_propiedad(string propiedad, string valor);
};
 
 	Instancia::Instancia(string n, Clase *c){
 		nombre = n + "_" + c->get_nombre();
		clase = c;
		vt = create_vartable();
		num_var = 0;
	}

	string Instancia::get_nombre(){
		return nombre;
	}

	Clase* Instancia::get_clase(){
		return clase;
		
	}

	bool Instancia::existe_propiedad(string nom_propiedad){
		struct var *v;
		if ((v = get_var(vt, StringAChar(nom_propiedad) ))) {
			return true;
		}
		return false;
	}

	int Instancia::get_valor_propiedad(string nom_propiedad){
		struct var *v;
		v = get_var(vt, StringAChar(nom_propiedad) );
    	return v->val.ival;
    	
	}
	
	bool Instancia::validar_expresion(string exp){
		bool band = false;
		struct val result;
		
		if( evaluate(StringAChar(exp), &result, vt)==0 ){
			if(result.ival == 1){
				band = true;
			}
		}
		return band;
	}


	//Validar que la propiedad pertenezca a la clase de la instancia
	//Hacer que se pueda consultar la posicion de una propiedad en la
	//clase, para tener un orden en los valores del vector
	//ES decir, si la clase tiene 2 propiedades (dia, mes) en ese orden
	//entonces en la instancia solo se asigno el mes.. tener el arrelgo
	//ordenado de la siguiente forma [dia = null, mes = 04] y no como
	//esta ahorita, lo que se vaya asignando se va a agregando
	// [mes = 04]
	bool Instancia::agregar_valor_propiedad(string propiedad, int valor){
		struct var *v;
		bool band = false;
				
		if( get_var(vt, StringAChar(propiedad) )  ){//Si la propiedad ya existe (ya ha obtenido su primer valor) actualizo su valor
			v = get_var(vt, StringAChar(propiedad));
 			v->val.ival = valor;		   		
			band = true;
		}
		else{
			if( clase->existe_propiedad(propiedad) ){ //Si la propiedad pertenece a la clase, se agrega valor por primera vez
				valores[num_var] = new val(); //Se crea el registro del valor
				valores[num_var]->type = T_INT; //Se asigna el tipo de dato
				valores[num_var]->ival = valor; //Se guarda el valor
				put_var(vt, StringAChar(propiedad), valores[num_var]);//Se introduce el registro en la tabla de valores
				num_var = num_var + 1; //Se incrementa el contador de valores
				band = true;
			}
		}
				
		return band;
	}

	bool Instancia::agregar_valor_propiedad(string propiedad, float valor){
		return true;
	}
	
	bool Instancia::agregar_valor_propiedad(string propiedad, string valor){
		return true;
	}	

#endif
