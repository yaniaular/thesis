#ifndef OA_H_
#define OA_H_
//#include <iostream>
//#include <fstream>
//#include <string>
#include <cstdlib>
#include <kcstashdb.h>
#include "Instancia.h"
#include "Propiedad.h"

//using namespace std;
using namespace kyotocabinet;

class OA{

	private:
		int cant_clases;
		int cant_instancias;
		int cant_propiedades;
		Clase *(clases[C]);
		Instancia *(instancias[I]);
		Propiedad *(propiedades[P]);
		StashDB bd, ins, prop;

	public:
		OA(); //Constructor 
		void crear_clase(string nombre);
		void crear_instancia(string n, string c);
		Clase* get_clase(int n); //La uso solo para pruebas
		Clase* get_clase(string nombre);
		//bool existe_clase(string nombre);
		Instancia* get_instancia(int n);
		Instancia* get_instancia(string nombre);
		int num_clases();
		int num_instancias();
		int num_propiedades();
		bool agregar_subclase(string n_clase, string n_padre);
		bool es_subclase_de(string c, string p);
		//void agregar_propiedad(Clase c, String nombre_prop_nueva);
		
};
  
	
	OA::OA(){
		cant_clases = 0;
		cant_instancias = 0;
		cant_propiedades = 0;
		if(!bd.open("cofre.kch", StashDB::OWRITER | StashDB::OCREATE)){
			cout << "Error al crear el cofre: " << bd.error().name() << endl;
		}
		if(!ins.open("instancias.kch", StashDB::OWRITER | StashDB::OCREATE)){
			cout << "Error al crear el cofre: " << ins.error().name() << endl;
		}
		if(!prop.open("propiedades.kch", StashDB::OWRITER | StashDB::OCREATE)){
			cout << "Error al crear el cofre: " << prop.error().name() << endl;
		}
	}

	//Ver si "nombre" no lo esta ocupado otra clase
	
	void OA::crear_clase(string nombre){
		stringstream ss;
		ss << cant_clases;
		if( !bd.set(nombre, ss.str() )){
			cout << "Error creando clase: " << bd.error().name() << endl;
		}
		else{
			clases[cant_clases] = new Clase(nombre);
			cant_clases+=1;
		}
	}
	
	void OA::crear_instancia(string n, string c){
		stringstream ss;
		ss << cant_instancias;
		Clase *cl = get_clase(c);

		if(cl != NULL){
			if( !ins.set(n, ss.str() ) ){
				cout << "Error creando clase: " << ins.error().name() << endl;
			}
			else{
				instancias[cant_instancias] = new Instancia( n, cl );
				cant_instancias+=1;
			}
		}
	}
	
	//Ver si la clase existe
	//No la uso
	Clase* OA::get_clase(int n){
		return clases[n];
	}

	
	Clase* OA::get_clase(string nombre){
		Clase *r;
		string valor;
		if( bd.get(nombre, &valor) ){
			int n ;
			istringstream ( valor ) >> n;//Transformo el string en int
			r = clases[n];
		}
		else{
			//cout << "Error consultando: " << bd.error().name() << endl;
			r = NULL;
		}
		return r;
	}


	Instancia* OA::get_instancia(int n){
		return instancias[n];
	}

	Instancia* OA::get_instancia(string nombre){
		Instancia *i;
		string valor;
		if( ins.get(nombre, &valor) ){
			int n;
			istringstream ( valor ) >> n;//Transformo el string en int
			i = instancias[n];
		}
		else{
			//cout << "Error consultando: " << bd.error().name() << endl;
			i = NULL;
		}
		return i;
	}

	//No la estoy usando
	/*bool OA::existe_clase(string nombre){
		bool band;
		string valor;
		
		if(bd.get(nombre, &valor)){
			band = true;
		}
		else{
			band = false;
		}
		return band;
		

	}*/

	int OA::num_clases(){
		return cant_clases;
	}

	int OA::num_instancias(){
		return cant_instancias;
	}

	int OA::num_propiedades(){
		return cant_propiedades;
	}

	//Si devuelve verdadero se agrego el padre, sino no se pudo
	bool OA::agregar_subclase(string n_clase, string n_padre){
		//Ver si existe n_clase y n_padre y devolver el puntero
		bool todo_bien = true;
		Clase *hijo = get_clase(n_clase);
		Clase *padre = get_clase(n_padre);
		if( hijo!=NULL && padre!=NULL ){	
			hijo->agregar_padre(padre);
			int num_padres = padre->get_numpadres();
			if(num_padres > 0){
				for(int i = 0; i < num_padres; i++){
					Clase *p = padre->get_padre(i);
					hijo->agregar_padre( p );
					p->agregar_hijo( hijo );
				}
			}
			padre->agregar_hijo(hijo);
			int num_hijos = hijo->get_numhijos();
			if(num_hijos > 0){
				for(int i = 0; i < num_hijos; i++){
					Clase *h = hijo->get_hijo(i);
					padre->agregar_hijo( h );
					h->agregar_padre( padre );
				}
			}
		}
		else{
			todo_bien = false;
		}
		return todo_bien;
	}

	bool OA::es_subclase_de(string c, string p){
		bool todo_bien = false;
		Clase *clase = get_clase( c );
		Clase *padre = get_clase( p );
		
		if( clase!=NULL && padre!=NULL ){	
			int num_padres = clase->get_numpadres();
			int i = 0;
			while(i < num_padres && !todo_bien){
				if( (clase->get_padre(i))->get_nombre() == p ){
					todo_bien = true;
				}
				i+=1;
			}
		}
		return todo_bien;
	}


# endif
