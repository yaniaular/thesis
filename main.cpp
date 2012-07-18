//Se compila: g++ -ggdb -o main main.cpp -L Clase.h
	
	// -Wtrigraphs -Wwrite-strings
	//Para ver todos los avisos -Wall

//#include <iostream>
//#include <fstream>
//#include <cstdlib>
#include <limits.h>

#include <sys/types.h>
#include <regex.h>
#include <fstream>

//#include <boost/regex.hpp>

#include "OA.h"

//using namespace std;


string Trim(string::const_iterator i, string::const_iterator f)
{
     string::const_iterator it;
     string buff;
     for (it = i; it != f; ++it)
     {
         if (*it != ' ') buff += *it;
     }

     return buff;    
}



int main(){
	typedef int T;
	int i, j, n;
	string c, c2, h1, h2;
	Clase *x;
	Instancia *is;
	string buffer;
	 
	OA *oa_bd = new OA();


/*
		int     retval = 0;
        regex_t   re;
        char *patter = ",";
        string ex = "(s,[eve1,eve2,eve3],tabla)";

        while( !retval ){
                       
		 	if( regcomp( &re, patter, REG_EXTENDED) != 0 ){
		 		retval = regcomp( &re, patter, REG_EXTENDED);
		 	}
		 	else{
		 		retval = regexec( &re, &ex[0], 0, NULL, 0);
		 	}
            
            
            if(retval == 0){
                  printf("Match found \n");
            }
        }*/

/*
	oa_bd->crear_clase( "fenMeteorologico" );
	oa_bd->crear_clase( "fenAtmosferico" );
	oa_bd->crear_clase( "fenNatural" );
	oa_bd->crear_clase( "fenClimatico" );
	oa_bd->crear_clase( "fenomeno" );
	oa_bd->crear_clase( "fenTropical" );
	oa_bd->crear_clase( "lluvias" );
	oa_bd->crear_clase( "huracan" );
*/

	//Crear 15000 clases
	for(i = 1; i <=50 ; i++){ //15000
		stringstream ss;
		ss << i;
		c = "Clase" + ss.str();		
		oa_bd->crear_clase( c );
	}

	//Crear 2 instancias para cada una de las primeras 7500 clases
	for(j = 1; j <= 50 ; j++){ //7500
		stringstream ff;
		ff << j;	
		for(i = 1; i <= 2 ; i++){
			stringstream ss;
			ss << i;
		
			c = "Instancia" + ss.str() ;	
			c2 = "Clase" + ff.str();
			oa_bd->crear_instancia( c, c2 );	
					
		}
	}

	n = oa_bd->get_num_clases();

	cout <<"Numero de clases: "<< n << endl;
	cout <<"Numero de instancias: " << oa_bd->get_num_instancias() << endl;


	//Cuando se consulta una instancia o una clase y no existe, devuelve NULL, y al imprimir NULL crea violacion del segmento
	is = oa_bd->get_instancia("Clase3", "Instancia1");
	if( is != NULL ){
		cout << "Instancia: " << is->get_nombre() << endl;
	}
	else{
		cout << "No existe la instancia" << endl;
	}
	
	x = oa_bd->get_clase(14999);
	if( x != NULL ){
		cout << "Clase: " << x->get_nombre() << endl;
	}
	else{
		cout << "No existe la clase" << endl;
	}
	
	x = oa_bd->get_clase(15000);
	if( x != NULL ){
		cout << "Clase: " << x->get_nombre() << endl;
	}
	else{
		cout << "No existe la clase" << endl;
	}
	
	


//	for(i = 0; i < n; i++ ){
//		cout << "La clase " << i << " tiene por nombre "<< (oa_bd->get_clase(i))->get_nombre() << endl;	}


//	cout << "El nombre es: ";
//	cout << (oa_bd->get_clase("Clase14000"))->get_nombre() << endl;
//	cout << (oa_bd->get_clase("Clase10000"))->get_nombre() << endl;
//	cout << (oa_bd->get_clase("Clase5000"))->get_nombre() << endl;
//	oa_bd->agregar_padre("Clase4567", "Clase6789");
//	oa_bd->agregar_padre("Clase1000", "Clase6789");

	
	//Crear arbol de clases
	i = 1;
	
	// hallar un 2^x ~ cant_clases
	//7499
	while(i <= 24){
		stringstream ss,s2,s3;
		ss << i;
		c = "Clase" + ss.str();
			
		s2 << (i*2);
		h1 = "Clase" + s2.str();

		s3 << ((i*2)+1);
		h2 = "Clase" + s3.str();
		
		oa_bd->agregar_subclase(h1, c);
		oa_bd->agregar_subclase(h2, c);
		
		i+=1;
	}

	//Probar las subclases 
	cout << oa_bd->crear_propiedad("Clase2", "NumMuertes") << endl;
	cout << oa_bd->crear_propiedad("Clase2", "Velocidad") << endl;
	cout << oa_bd->crear_propiedad("Clase2", "AlertarA")<< endl << endl;
	
	//No acepta nombre de variables con "_"
	cout << oa_bd->agregar_subclase("Clase50", "Clase2") << endl << endl;//subclase - clasepadre

	cout << oa_bd->es_subclase_de("Clase1000","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase1001","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase4567","Clase6789") << endl;
	cout << oa_bd->es_subclase_de("Clase8000", "Clase4000") << endl;
	cout << oa_bd->es_subclase_de("Clase11356", "Clase5678") << endl;
	cout << oa_bd->es_subclase_de("Clase8001", "Clase2000") << endl;
	cout << oa_bd->es_subclase_de("Clase8000", "Clase4001") << endl;
	cout << oa_bd->es_subclase_de("Clase44", "Clase5") << endl;
	cout << oa_bd->es_subclase_de("Clase37", "Clase2") << endl;
	cout << oa_bd->es_subclase_de("Clase6537", "Clase1") << endl;
	cout << oa_bd->es_subclase_de("Clase6537", "Clase2") << endl;
	cout << oa_bd->es_subclase_de("Clase6537", "Clase3") << endl << endl;

	cout << oa_bd->crear_evento("Clase2", "OcurreDesastreNatural", "AlertarA", 1,"NumMuertes > 0 || Velocidad > 35") << endl << endl;
	
	
	//INICIALIZAR LOS VALORES DE LAS INSTANCIAS,para poder evaluar las expresiones
cout << "Inicializando NumMuertes ";
cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", -1) << endl;
cout << "Inicializando Velocidad ";
cout << oa_bd->agregar_valorApropiedad("Clase2","Instancia1", "Velocidad", -1) << endl;
cout << "Inicializando AlertarA ";
cout << oa_bd->agregar_valorApropiedad("Clase2","Instancia1", "AlertarA", -1) << endl << endl;
	
	//CONSULTAR VALORES
	cout << "Consultando AlertarA = ";
	cout << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl << endl;

	//CAMBIANDO VALORES	
	cout << "Asignando valores a las propiedades:" << endl;
	
	cout << "Velocidad en 5: ";
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 5)<< endl;
	
	cout << "Velocidad en 89: ";
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 89)<< endl;
	
	cout << "NumMuertes en 2: ";
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 2)<< endl;
	
	cout << "NumMuertes en 56: ";
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 56)<< endl;
	
	cout << "NumMuertes en 0: ";
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 0)<< endl;
	
	cout << "Velocidad en 13: ";
	cout << "( " << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 13)<< endl<< endl;
	
	cout << "Propiedadqnoexiste en 34: ";
	cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Propiedadqnoexiste", 34)<< endl<< endl;

	//MAS CONSULTA DE VALORES
	cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "NumMuertes") << endl;
	cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
	cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl;




ifstream entrada("exp.txt");
int reti;
regex_t regex; //Variable para la expresion regular
string exp;
char * pattern ="^\\((S|s|p|P),\\[([A-Za-z0-9])+(([,])([A-Za-z0-9])+)*\\],([A-Za-z0-9])+\\)$"; //Patron de la expresion regular
/*
^ Indica el inicio de la frase
\\(   Agrega el parentesis
(S|s|p|P) debe haber cualquiera de las letras que esta entre parentesis
, Debe haber siempre una coma
\\[ Agrega el corchete
([A-Za-z0-9])+ 1 o mas palabras que contengan letras y numeros
(([,])([A-Za-z0-9])+)* expresion formada por una coma seguido y 1 palabra que contenga letras y numeros (Puede haber 0 o mas expresiones)
\\] Agrega corchete
, Debe haber siempre una coma
([A-Za-z0-9])+ 1 o mas palabras que contengas letras y numeros
\\) Agrega el parentesis
$ indica el final de la frase
*/


	reti = regcomp (&regex, pattern, REG_EXTENDED);//Agrego el patron a regex
	
	while( getline (entrada,exp) ){//Leo una linea del archivo
	
		exp = Trim(exp.begin(), exp.end());//Quitar espacios de la expresion
		cout << exp << " ";
	
		reti = regexec (&regex, &exp[0], (size_t)0, NULL, 0);
		
		
		
		if( reti == REG_NOMATCH ){ //Si es 1, hay error de sintaxis
			puts("Error de sintaxis");
		}
		else{ //Si es 0, esta todo bien
		
			int    status;
			regex_t    re;
			regmatch_t rm;
			char *patter = "\\[([A-Za-z0-9])+(([,])([A-Za-z0-9])+)*\\]";
			string eventos;
			
			if (regcomp(&re, patter, REG_EXTENDED) != 0) {
				cout << "Bad pattern";
			}
		
			status = regexec(&re, &exp[0], 1, &rm, 0);
			regfree(&re);
		
			if (status != 0) {
				cout << "No Match";
				cout << status << endl;
			}
			else{
				eventos = exp.substr( (int)rm.rm_so, (int)rm.rm_eo-3);
				eventos = eventos.substr( 1, eventos.size());
				eventos[ eventos.size()-1 ] = ',';
			}
			
			do{
		
				int f;
				f = eventos.find(",");
				
				cout << eventos.substr( 0, f) << endl;
				eventos = eventos.substr( f+1, eventos.size()-1);
				
			}while( eventos.size() > 1 );
		
		
		
			//oa_bd->activar_eventos(nom_evento, nom_);
		
		}		 
	}
	regfree (&regex);
	entrada.close();


	//oa_bd->crear_propiedad("Clase16000", "HuboPerdidaHumanaa");
/*	list<Clase> lst;	
	Clase c("yani");
	cout << c.get_nombre();
	lst.insert(0,c);
*/

	return EXIT_SUCCESS;
}
