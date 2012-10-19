//Se compila: g++ -ggdb -o main main.cpp -L Clase.h
	
	// -Wtrigraphs -Wwrite-strings
	//Para ver todos los avisos -Wall
	
//#include <sys/types.h>
#include <regex.h>
#include <vector>
#include <cctype>
#include "OA.h"

#include <new>
using std::set_new_handler;
#include <cstdlib>
using std::abort;

void mensaje_error(){
	cerr << "Error de memoria, bad_alloc";
	abort();
}

//Funcion que recibe un string, y elimina los espacios en blanco del mismo
string Trim(string cadena)
{
	string::const_iterator i = cadena.begin(); 
	string::const_iterator f = cadena.end();
	
     string::const_iterator it;
     string buff;
     for (it = i; it != f; ++it)
     {
         if (*it != ' ') buff += *it;
     }

     return buff;    
}

string StringToUpper(string myString)
{
  const int length = myString.length();
  for(int i=0; i!=length ; ++i)
  {
    myString[i] = toupper(myString[i]);
  }
  return myString;
}

int main(){


	set_new_handler( mensaje_error ); //Llama al metodo cuando hay una sobrecarga de memoria, mensaje personalizado

	typedef int T;
	int i, j, n, cont;
	string c, in, h1, h2;
	Clase *x;
	Instancia *is;
	string buffer;
	 
	OA *oa_bd = new OA();
/*


	cout << "******** oa_bd->crear_clase( huracan )" << endl;
		cout << oa_bd->crear_clase( "huracan" ) << endl;
	cout << "******** oa_bd->crear_clase( fenMeteorologico )" << endl;
		cout << oa_bd->crear_clase( "fenMeteorologico" )<< endl;
	cout << "******** oa_bd->crear_clase( fenClimatico )" << endl;
		cout << oa_bd->crear_clase( "fenClimatico" )<< endl;
	cout << "******** oa_bd->crear_clase( fenAtmosferico )" << endl;
		cout << oa_bd->crear_clase( "fenAtmosferico" )<< endl;
	cout << "******** oa_bd->crear_clase( fenNatural )" << endl;
		cout << oa_bd->crear_clase( "fenNatural" )<< endl;
	cout << "******** oa_bd->crear_clase( fenomeno )" << endl;
		cout << oa_bd->crear_clase( "fenomeno" )<< endl;
	cout << "******** oa_bd->crear_clase( Lluvia )" << endl;
		cout << oa_bd->crear_clase( "Lluvia" )<< endl;

	cout << "******** oa_bd->crear_propiedad(fenomeno, NumMuertos, ENTERO)" << endl;
		cout << oa_bd->crear_propiedad("fenomeno", "NumMuertos", ENTERO)<< endl;	
	cout << "******** oa_bd->crear_propiedad(fenomeno, HuboPerdidaHumana, CADENA)" << endl;	
		cout << oa_bd->crear_propiedad("fenomeno", "HuboPerdidaHumana", CADENA)<< endl;
	cout << "******** oa_bd->crear_propiedad(fenomeno, AlertarA, CADENA)" << endl;
		cout << oa_bd->crear_propiedad("fenomeno", "AlertarA", CADENA)<< endl;
	cout << "******** oa_bd->crear_propiedad(fenAtmosferico, velocidadViento, ENTERO)" << endl;
		cout << oa_bd->crear_propiedad("fenAtmosferico", "velocidadViento", ENTERO)<< endl;
	cout << "******** oa_bd->crear_propiedad(huracan, intensidad, ENTERO)" << endl;
		cout << oa_bd->crear_propiedad( "huracan", "intensidad", ENTERO )<< endl;
	cout << "******** oa_bd->crear_propiedad(huracan, categoria, ENTERO)" << endl;
		cout << oa_bd->crear_propiedad( "huracan", "categoria", ENTERO )<< endl; //Propiedad Padre
	
	cout << "******** oa_bd->agregar_subpropiedad(intensidad, categoria)" << endl;
		cout << oa_bd->agregar_subpropiedad("intensidad", "categoria") << endl;

	cout << "******** oa_bd->agregar_subclase(huracan, fenMeteorologico)" << endl;
		cout << oa_bd->agregar_subclase("huracan", "fenMeteorologico") << endl;
	cout << "******** oa_bd->agregar_subclase(fenMeteorologico, fenClimatico)" << endl;
		cout << oa_bd->agregar_subclase("fenMeteorologico", "fenClimatico") << endl;
	cout << "******** oa_bd->agregar_subclase(fenMeteorologico, fenAtmosferico)" << endl;
		cout << oa_bd->agregar_subclase("fenMeteorologico", "fenAtmosferico") << endl;	
	cout << "******** oa_bd->agregar_subclase(fenAtmosferico, fenomeno)" << endl;
		cout << oa_bd->agregar_subclase("fenAtmosferico", "fenomeno") << endl;	
	cout << "******** oa_bd->agregar_subclase(fenClimatico, fenNatural)" << endl;	
		cout << oa_bd->agregar_subclase("fenClimatico", "fenNatural") << endl;	
	cout << "******** oa_bd->agregar_subclase(fenNatural, fenomeno)" << endl;
		cout << oa_bd->agregar_subclase("fenNatural", "fenomeno") << endl;
	cout << "******** oa_bd->agregar_subclase(Lluvia, fenClimatico)" << endl;
		cout << oa_bd->agregar_subclase("Lluvia", "fenClimatico") << endl;
	

	cout << "******** oa_bd->crear_instancia( ike, huracan )" << endl;
		cout << oa_bd->crear_instancia( "ike", "huracan" ) << endl;
	cout << "******** oa_bd->crear_instancia( vince, huracan )" << endl;
		cout << oa_bd->crear_instancia( "vince", "huracan" ) << endl;	
	cout << "******** oa_bd->crear_instancia( desastreVargas, Lluvia )" << endl;	
		cout << oa_bd->crear_instancia( "desastreVargas", "Lluvia" ) << endl;
	cout << "******** oa_bd->crear_evento(fenomeno, HuboMuerte, HuboPerdidaHumana, Si,NumMuertos > 0)" << endl;	
		cout << oa_bd->crear_evento("fenomeno", "HuboMuerte", "HuboPerdidaHumana", "Si","NumMuertos > 0") << endl;
	
	cout << "******** oa_bd->crear_evento(huracan, aumentoViento, intensidad, 5,velocidadViento >= 250)" << endl;
		cout << oa_bd->crear_evento("huracan", "aumentoViento", "intensidad", 5,"velocidadViento >= 250") << endl;
	
	cout << "******** oa_bd->get_evento(aumentoViento)->agregar_expresion(4, velocidadViento >= 210 & velocidadViento <= 249)" << endl;
		oa_bd->get_evento("aumentoViento")->agregar_expresion(4, "velocidadViento >= 210 && velocidadViento <= 249");
	cout << "******** oa_bd->get_evento(aumentoViento)->agregar_expresion(3, velocidadViento >= 178 & velocidadViento <= 209)" << endl;
		oa_bd->get_evento("aumentoViento")->agregar_expresion(3, "velocidadViento >= 178 && velocidadViento <= 209");
	cout << "******** oa_bd->get_evento(aumentoViento)->agregar_expresion(2, velocidadViento >= 154 & velocidadViento <= 177)" << endl;
		oa_bd->get_evento("aumentoViento")->agregar_expresion(2, "velocidadViento >= 154 && velocidadViento <= 177");
	cout << "******** oa_bd->get_evento(aumentoViento)->agregar_expresion(1, velocidadViento >= 119 & velocidadViento <= 153)" << endl;
		oa_bd->get_evento("aumentoViento")->agregar_expresion(1, "velocidadViento >= 119 && velocidadViento <= 153");
	
	cout << "******** oa_bd->crear_evento(fenomeno, OcurreDesastreNatural, AlertarA, CruzRoja, 1)" << endl;
		cout << oa_bd->crear_evento("fenomeno", "OcurreDesastreNatural", "AlertarA", "CruzRoja", "1") << endl; //Evento que se activa con activarse aumentoviento y hubomuerte, la condicion es siempre True, ya que la unica forma de activarse es por sus subeventos, y al activarse algunos de sus subevento, ya el evento OcurreDesastreNatural es verdadero.
	
	cout << "******** oa_bd->agregar_subevento(HuboMuerte, OcurreDesastreNatural)" << endl;
		cout << oa_bd->agregar_subevento("HuboMuerte", "OcurreDesastreNatural") << endl;
	cout << "******** oa_bd->agregar_subevento(aumentoViento, OcurreDesastreNatural)" << endl;	
		cout << oa_bd->agregar_subevento("aumentoViento", "OcurreDesastreNatural") << endl;

	cout << "******** oa_bd->consultar_propiedad_instancia(Lluvia, desastreVargas, NumMuertos)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("Lluvia", "desastreVargas", "NumMuertos") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(Lluvia, desastreVargas, HuboPerdidaHumana)" << endl;	
		cout << oa_bd->consultar_propiedad_instancia("Lluvia", "desastreVargas", "HuboPerdidaHumana") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(Lluvia, desastreVargas, AlertarA)" << endl;	
		cout << oa_bd->consultar_propiedad_instancia("Lluvia", "desastreVargas", "AlertarA") << endl;
	
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, ike, NumMuertos)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "ike", "NumMuertos") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, ike, HuboPerdidaHumana)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "ike", "HuboPerdidaHumana") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, ike, AlertarA)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "ike", "AlertarA") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, ike, velocidadViento)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "ike", "velocidadViento") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, ike, intensidad)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "ike", "intensidad") << endl;

	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, vince, NumMuertos)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "vince", "NumMuertos") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, vince, HuboPerdidaHumana)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "vince", "HuboPerdidaHumana") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, vince, AlertarA)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "vince", "AlertarA") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, vince, velocidadViento)" << endl;	
		cout << oa_bd->consultar_propiedad_instancia("huracan", "vince", "velocidadViento") << endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, vince, intensidad)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "vince", "intensidad") << endl;

	cout << "******** oa_bd->agregar_valorApropiedad(huracan, vince, NumMuertos, 280)" << endl;
		cout << oa_bd->agregar_valorApropiedad("huracan", "vince", "NumMuertos", 280)<< endl;
	cout << "******** oa_bd->agregar_valorApropiedad(huracan, vince, velocidadViento, 260)" << endl;
		cout << oa_bd->agregar_valorApropiedad("huracan", "vince", "velocidadViento", 260)<< endl;
	
	cout << "******** oa_bd->consultar_propiedad_instancia( huracan, vince, velocidadViento)" << endl;	
		cout << oa_bd->consultar_propiedad_instancia("huracan", "vince", "velocidadViento") << endl;

	cout << "******** oa_bd->agregar_valorApropiedad(huracan, ike, velocidadViento, 125)" << endl;
		cout << oa_bd->agregar_valorApropiedad("huracan", "ike", "velocidadViento", 125)<< endl;
	cout << "******** oa_bd->consultar_propiedad_instancia(huracan, ike, velocidadViento)" << endl;
		cout << oa_bd->consultar_propiedad_instancia("huracan", "ike", "velocidadViento") << endl;
		
	cout << "******** oa_bd->activar_eventos(huracan, HuboMuerte)" << endl;
		cout << oa_bd->activar_eventos("huracan", "HuboMuerte") << endl;
	cout << "******** oa_bd->activar_eventos(huracan, aumentoViento)" << endl;
		cout << oa_bd->activar_eventos("huracan", "aumentoViento") << endl;
	//cout << "******** oa_bd->activar_eventos(huracan, OcurreDesastreNatural)" << endl;
	//	cout << oa_bd->activar_eventos("huracan", "OcurreDesastreNatural") << endl;
	//cout << oa_bd->agregar_valorApropiedad("huracan", "vince", "intensidad", 3)<< endl;

	cout << "******** intensidad: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "intensidad") << endl;
	cout << "******** HuboPerdidaHumana: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "HuboPerdidaHumana") << endl;
	cout << "******** AlertarA: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "AlertarA") << endl;
	cout << "******** categoria: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "categoria") << endl;
	cout << "******** valor1: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor1") << endl;
	cout << "******** valor2: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor2") << endl;

	cout << endl;
	cout << "******** intensidad: " << oa_bd->consultar_propiedad_instancia("huracan", "ike", "intensidad") << endl;
	cout << "******** HuboPerdidaHumana: " << oa_bd->consultar_propiedad_instancia("huracan", "ike", "HuboPerdidaHumana") << endl;
	cout << "******** AlertarA: " << oa_bd->consultar_propiedad_instancia("huracan", "ike", "AlertarA") << endl;
	cout << "******** categoria: " << oa_bd->consultar_propiedad_instancia("huracan", "ike", "categoria") << endl;
	cout << "******** valor1: " << oa_bd->consultar_propiedad_instancia("huracan", "ike", "valor1") << endl;
	cout << "******** valor2: " << oa_bd->consultar_propiedad_instancia("huracan", "ike", "valor2") << endl;	

	cout << "******** oa_bd->es_subpropiedad_de(intensidad, categoria)" << endl;
		cout << oa_bd->es_subpropiedad_de("intensidad", "categoria") << endl;
	cout << "******** oa_bd->es_subpropiedad_de(HuboMuerte, OcurreDesastreNatural)" << endl;	
		cout << oa_bd->es_subevento_de("HuboMuerte", "OcurreDesastreNatural") << endl;

	cout << "******** oa_bd->pertenece_a(ike, fenomeno)" << endl;
		cout << oa_bd->pertenece_a("ike", "fenomeno") << endl;
	cout << "******** oa_bd->pertenece_a(ike, huracan)" << endl;
		cout << oa_bd->pertenece_a("ike", "huracan") << endl;
	cout << "******** oa_bd->pertenece_a(ike, Lluvia)" << endl;	
		cout << oa_bd->pertenece_a("ike", "Lluvia") << endl;
	cout << "******** oa_bd->pertenece_a(ike, fenNatural)" << endl;
		cout << oa_bd->pertenece_a("ike", "fenNatural") << endl;

	//////////////////////////////////////////////////////////////		


	cout << endl;
	cout << oa_bd->crear_propiedad( "huracan", "valor1", ENTERO )<< endl;
	cout << oa_bd->crear_propiedad( "huracan", "valor2", ENTERO )<< endl;
	cout << oa_bd->agregar_subpropiedad("intensidad", "valor1") << endl; //////////	
	cout << oa_bd->agregar_subpropiedad("categoria", "valor2") << endl; ///////////

	cout << oa_bd->agregar_valorApropiedad("huracan", "vince", "valor1", 89)<< endl; ///////
	cout << "******** intensidad: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "intensidad") << endl;
	cout << "******** categoria: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "categoria") << endl;
	cout << "******** valor1: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor1") << endl;
	cout << "******** valor2: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor2") << endl;
	
	cout << oa_bd->agregar_valorApropiedad("huracan", "vince", "valor2", 100)<< endl; ///////
	cout << "******** intensidad: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "intensidad") << endl;
	cout << "******** categoria: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "categoria") << endl;
	cout << "******** valor1: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor1") << endl;
	cout << "******** valor2: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor2") << endl;

	cout << oa_bd->agregar_valorApropiedad("huracan", "vince", "categoria", 999)<< endl; ///////
	cout << "******** intensidad: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "intensidad") << endl;
	cout << "******** categoria: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "categoria") << endl;
	cout << "******** valor1: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor1") << endl;
	cout << "******** valor2: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor2") << endl;

	cout << oa_bd->agregar_valorApropiedad("huracan", "vince", "intensidad", 777)<< endl; ///////
	cout << "******** intensidad: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "intensidad") << endl;
	cout << "******** categoria: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "categoria") << endl;
	cout << "******** valor1: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor1") << endl;
	cout << "******** valor2: " << oa_bd->consultar_propiedad_instancia("huracan", "vince", "valor2") << endl;

*/
		
	
	int cant_clases = 300; //500
	int cant_prop = 500; //300
	int cant_even = 150;
	int cant_instancias = 830; //200	
	int opcion = 0, b;	

	while(opcion != 20){
		
		cout << "1. Consultar cantidad de clases, instancias, propiedades y eventos" << endl;
		cout << "2. Crear 300 clases" << endl;
		cout << "3. Crear 249000 instancias" << endl;
		cout << "4. Verificar que existan las 300 clases" << endl;
		cout << "5. Verificar que existan las 249000 instancias" << endl;
		cout << "6. Conectar las 300 clases" << endl;
		cout << "7. Hacer consultas arbitrarias" << endl;
		cout << "8. Crear 9 propiedades especializadas" << endl;
		cout << "9. Crear 491 propiedades" << endl;
		cout << "10. Crear 4 eventos especializados" << endl;
		cout << "11. Crear 146 eventos" << endl;
		cout << "12. Consultar valores de algunas propiedades" << endl;
		cout << "13. Asignar algunos valores" << endl;
		cout << "14. Asignar algunos valores" << endl;
		cout << "15. Activar evento OcurreDesastreNatural" << endl;
		cout << "16. Asignar a Velocidad el valor de 1.0 a todas las instancias" << endl;
		cout << "17. Activar Evento1 en la Clase1 para verificar que se activaran todos y modificaran intensidad" << endl;
		cout << "18. Consultar de valores varios" << endl;
		cout << "19. Leer los eventos por archivo y activarlos" << endl;
		cout << "20. Salir" << endl;
		cout << "Escribe tu opcion : ";
		cin >> opcion;
		system("clear");
			switch( opcion ){

			case 1:
				cout << endl;
				cout <<"Numero de clases: "<< oa_bd->get_num_clases() << endl;
				cout <<"Numero de instancias: " << oa_bd->get_num_instancias() << endl;
				cout <<"Numero de propiedades: " << oa_bd->get_num_propiedades() << endl;
				cout <<"Numero de eventos: " << oa_bd->get_num_eventos() << endl << endl;
			break;

			case 2:
				//Crear 300 clases
				cont = 0;
				cout << "Creando las " << cant_clases << " Clases..." << endl;	
				for(i = 1; i <= cant_clases ; i++){ //15000
					stringstream ss;
					ss << i;
					c = "Clase" + ss.str();		
					cont+=oa_bd->crear_clase( c );
				}
				if(cont == cant_clases)
					cout << "Se crearon todas las clases" << endl;
				else
					cout << "Faltaron " << (cant_clases - cont) << " clases" << endl;	
				
				cout << endl;
		
			break;
	
			case 3:
				//Crear 2 instancias para cada una de las primeras 7500 clases, 50
				cont = 0;
				cout << "Creando las " << cant_clases*cant_instancias << " instancias..." << endl;	
				for(j = 1; j <=  cant_clases ; j++){ //7500
					stringstream ff;
					ff << j;	
					for(i = 1; i <= cant_instancias ; i++){//50
						stringstream ss;
						ss << i;
		
						in = "Instancia" + ss.str() ;	
						c = "Clase" + ff.str();
						cont+=oa_bd->crear_instancia( in, c );	
					
					}
				}

				if(cont == cant_instancias*cant_clases)
					cout << "Se crearon todas las instancias" << endl;
				else
					cout << "Faltaron " <<  (cant_instancias*cant_clases - cont) << " instancias" << endl;
				cout << endl;
			break;

			case 4:
				i = 1;
				b = true;
				cont = 0;
				while(i <=  cant_clases && b){ //15000
					stringstream ss;
					ss << i;
					c = "Clase" + ss.str();		
					if( oa_bd->get_clase(c) == NULL){
						b = false;
						cout << "Hay una clase que no existe: "<< c << endl;
						cont+=1;
					}
					i++;
				}
				if(cont == 0)
					cout << "Se crearon todas las clases" << endl;
				else
					cout << "Faltaron " <<  cont << " clases" << endl;
				cout << endl;			
			break;

			case 5:
				j = 1;
				b = true;
				cont = 0;
				while(j <=  cant_clases && b){ //7500
					stringstream ff;
					ff << j;
					i = 1;	
					while( i <= cant_instancias && b){//50
						stringstream ss;
						ss << i;
		
						in = "Instancia" + ss.str() ;	
						c = "Clase" + ff.str();
			
						if( oa_bd->get_instancia(c, in) == NULL ){
							b = false;
							cout << "Hay una instancia que no existe: "<< in << " "<< c << endl;
							cont+=1;
						}

	
						i++;				
					}
					j++;
				}
				if(cont == 0)
					cout << "Se crearon todas las instancias" << endl;
				else
					cout << "Faltaron " <<  cont << " instancias" << endl;
				cout << endl;	
			break;

			case 6:
				i = 1;
				cont = 0;
				// hallar un 2^x ~ cant_clases
				cout << "Creando conexion entre las " << cant_clases << " Clases..." << endl;
				while(i <= 149){
					stringstream ss,s2,s3;
					ss << i;
					c = "Clase" + ss.str();
			
					s2 << (i*2);
					h1 = "Clase" + s2.str();

					s3 << ((i*2)+1);
					h2 = "Clase" + s3.str();
		
					cont+=oa_bd->agregar_subclase(h1, c);
					cont+=oa_bd->agregar_subclase(h2, c);
		
					i+=1;
				}
				if(cont == 149*2)
					cout << "Se crearon todas las conexiones" << endl;
				else
					cout << "Faltaron " <<  149*2 - cont << " conexiones" << endl;
				cout << endl;
			break;
			//cout << INT_MAX << endl; //2147483647


			//Cuando se consulta una instancia o una clase y no existe, devuelve NULL, y al imprimir NULL crea violacion del segmento
			//Al tener 15000 clases con 15000 instancias cada una, dice que la instancia 1 de la clase 3 no existen	

			case 7:
				is = oa_bd->get_instancia("Clase3", "Instancia1");
				if( is != NULL ){
					cout << "Instancia: " << is->get_nombre() << endl;
				}
				else{
					cout << "No existe la instancia Instancia1 en la Clase3" << endl;
				}
		
				x = oa_bd->get_clase(2);
				if( x != NULL ){
					cout << "Si existe la clase: " << x->get_nombre() << endl;
				}
				else{
					cout << "No existe la clase Clase2" << endl;
				}
	
				x = oa_bd->get_clase(14999);
				if( x != NULL ){
					cout << "Clase: " << x->get_nombre() << endl;
				}
				else{
					cout << "No existe la clase Clase14999"<< endl;
				}
	
				x = oa_bd->get_clase(15000);
				if( x != NULL ){
					cout << "Clase: " << x->get_nombre() << endl;
				}
				else{
					cout << "No existe la clase Clase15000" << endl;
				}
			break;
	
			//CREAR VARIABLES
	

			case 8:
				//cout << "************************* CREAR PROPIEDADES *************************************" <<endl;
				//Se crean las propiedades y se inicializan
				cout << "Creando las Propiedades..." << endl;
				cout << oa_bd->crear_propiedad("Clase1", "HayComida", ENTERO) << endl;
				cout << oa_bd->crear_propiedad("Clase1", "Recursos", ENTERO) << endl;
				cout << oa_bd->crear_propiedad("Clase1", "AumentarPresion", ENTERO) << endl;
				cout << oa_bd->crear_propiedad("Clase1", "LlamarBombero", ENTERO) << endl;
				cout << oa_bd->crear_propiedad("Clase1", "huboPerdidaHumana", ENTERO) << endl;
				cout << oa_bd->crear_propiedad("Clase1", "NumMuertes", ENTERO) << endl;
				cout << oa_bd->crear_propiedad("Clase1", "Velocidad", REAL) << endl;
				cout << oa_bd->crear_propiedad("Clase1", "AlertarA", CADENA)<< endl;
				cout << oa_bd->crear_propiedad("Clase1", "intensidad", ENTERO)<< endl;
				cout << oa_bd->crear_propiedad("Clase3", "Nombre", CADENA) << endl;
				cout << oa_bd->crear_propiedad("Clase3", "Apellido", CADENA)<< endl;
			break;
	
			case 9:
				cont = 0;
				for(i = 1; i <= cant_prop - 11 ; i++){ //15000
					stringstream ss;
					ss << i;
					c = "Propiedad" + ss.str();		
					cont+=oa_bd->crear_propiedad("Clase1", c, ENTERO);
				}
				if( cont ==  cant_prop - 11 )
					cout << "Se crearon todas las propiedades" << endl;
				else
					cout << "Faltaron "<< cant_prop - 11 - cont << endl;
			break;


			case 10:
				//CREAR EVENTO
				cout << "**************************** CREAR EVENTO **********************************" <<endl;
				cout << oa_bd->crear_evento("Clase2", "DonanComida", "HayComida", 1,"Recursos == 0") << endl << endl;
				cout << oa_bd->crear_evento("Clase2", "RecogerRecursos", "Recursos", 1,"HayComida == 0") << endl << endl;

				cout << oa_bd->crear_evento("Clase2", "EcharAgua", "AumentarPresion", 1,"LlamarBombero == 1") << endl << endl;
				cout << oa_bd->crear_evento("Clase2", "BomberosActivados", "LlamarBombero", 1,"AlertarA == \"CruzRoja\" ") << endl << endl;
				cout << oa_bd->crear_evento("Clase2", "OcurreDesastreNatural", "AlertarA", "CruzRoja","Velocidad > 500 || huboPerdidaHumana == 1") << endl << endl;
				cout << oa_bd->crear_evento("Clase2", "huboMuerte", "huboPerdidaHumana", 1,"NumMuertes > 0") << endl << endl;

			break;

			case 11:
				cout << "Creando los " << cant_even << " Eventos" << endl;
				for(i = 1; i <= cant_even - 6; i++){ //15000
					stringstream ss;
					ss << i;
					c = "Evento" + ss.str();
					h1 = "Velocidad == " + ss.str() + ".0";		
					if( oa_bd->crear_evento("Clase1", c, "intensidad", i, h1)==0 ){
						cout << "No se creo el evento " << c << ", ";
					}
				}
				cout << endl;

				cout << oa_bd->agregar_subevento("Evento1", "DonanComida") << endl;
				cout << oa_bd->agregar_subevento("Evento1", "huboMuerte") << endl;
				cout << oa_bd->agregar_subevento("huboMuerte", "EcharAgua") << endl;
				cout << oa_bd->agregar_subevento("huboMuerte", "BomberosActivados") << endl;
				//cout << oa_bd->agregar_subevento("DonanComida", "RecogerRecursos") << endl; //Con este hay ciclos
				cout << oa_bd->agregar_subevento("DonanComida", "OcurreDesastreNatural") << endl;
			break;


			//  || Nombre == \"HOLA\" 
	
			case 12:
				//CONSULTAR VALORES
				cout << "****************************  CONSULTAR VALORES ***********************************" <<endl;
			///Al tener 15000 clases con 15000 instancias cada una, sa violacion de segmento por aca
	
				cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "NumMuertes") << endl;
				cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
				cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "AlertarA") << endl;
				cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Apellido") << endl;
				cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia("Clase2", "Instancia1", "Nombre") << endl;
			break;

			case 13:
				//ASIGNAR VALORES
				cout << "*************************** ASIGNAR VALORES ************************************" <<endl;
				cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Nombre", (string)"Yanina Gabriela")<< endl;
				cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Apellido", (string)"Aular Osorio")<< endl;	
				cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "AlertarA", (string)"Nadie")<< endl;
				cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "NumMuertes", 0)<< endl;
				cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia1", "Velocidad", 800.5)<< endl;
			break;

			case 14:
			//ASIGNAR VALORES 2
			cout << "*************************** ASIGNAR VALORES 2 ************************************" <<endl;
			cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "Nombre", (string)"Nombre_2")<< endl;
			cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "Apellido", (string)"Apellido_2")<< endl;	
			cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "AlertarA", (string)"Nadie")<< endl;
			cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "NumMuertes", 0)<< endl;
			cout << oa_bd->agregar_valorApropiedad("Clase2", "Instancia2", "Velocidad", 3)<< endl;
			cout << oa_bd->agregar_valorApropiedad("Clase3", "Instancia7", "NumMuertes", 13)<< endl;
			break;
	
			case 15:
			//ACTIVAR EVENTO
			cout << "***************************** ACTIVAR EVENTO **********************************" <<endl;
			oa_bd->activar_eventos("Clase3", "OcurreDesastreNatural");
			break;

			case 16:
			for(i = 1; i <= cant_instancias ; i++){ //15000
				stringstream ss;
				ss << i;
				c = "Instancia" + ss.str();		
				cout << oa_bd->agregar_valorApropiedad("Clase1", c , "Velocidad", 1.0) << ", ";
			}
			break;

			case 17:
			if( oa_bd->activar_eventos("Clase1", "Evento1") ){
			
				for(i = 1; i <= cant_instancias ; i++){ //15000
					stringstream ss;
					ss << i;
					c = "Instancia" + ss.str();		
				cout << "Consultando intensidad de "<< c <<" = " << oa_bd->consultar_propiedad_instancia("Clase1", c, "intensidad") << endl;
				}
			}
			else{
				cout << "No se activo el Evento1 en la Clase1 "<< endl;
			}
			break;
	


			case 18:
				for(j = 2; j <= 3 ; j++){ //7500
					stringstream ff;
					ff << j;	
					cout << "******************** MAS CONSULTA DE VALORES "<< ff.str() <<" ********************" <<endl;
		
					for(i = 1; i <= 7 ; i++){//50
						stringstream ss;
						ss << i;
		
						in = "Instancia" + ss.str() ;	
						c = "Clase" + ff.str();
				cout << in << " " << c << endl;
	
				if(oa_bd->get_clase(c) != NULL){
					if( (oa_bd->get_clase(c))->existe_propiedad( "NumMuertes" ) )
						cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia(c, in, "NumMuertes") << endl;
				}
				else{
					cout << "La clase " << c << " es NULL" << endl;

				}

				if(oa_bd->get_clase(c) != NULL){
					if( (oa_bd->get_clase(c))->existe_propiedad( "Velocidad" ) )
						cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia(c, in, "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}
	
				if(oa_bd->get_clase(c) != NULL){
					if( (oa_bd->get_clase(c))->existe_propiedad( "AlertarA" ) )
						cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia(c, in, "AlertarA") << endl;
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}

				if(oa_bd->get_clase(c) != NULL){	
					cout << endl;
					if( (oa_bd->get_clase(c))->existe_propiedad( "Nombre" ) )
						cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia(c, in, "Nombre") << endl;
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}
	
				if(oa_bd->get_clase(c) != NULL){
					if( (oa_bd->get_clase(c))->existe_propiedad( "Apellido" ) )
						cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia(c, in, "Apellido") << endl << endl;
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}	
				
					}
				}

			///Hay una violacion de segmento aqui cuando se crean 15000 clases y 50 instancias para las primeras 1000 clases

				c = "Clase2";
				in =  "INSTANCIA_NUEVA";
				oa_bd->crear_instancia( in, c );

				cout << "Comenzo " << endl;

				if(oa_bd->get_clase(c) != NULL){
					if( (oa_bd->get_clase(c))->existe_propiedad( "NumMuertes" ) )
						cout << "Consultando NumMuertes = " << oa_bd->consultar_propiedad_instancia(c, in, "NumMuertes") << endl;
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}

				if(oa_bd->get_clase(c) != NULL){
					if( (oa_bd->get_clase(c))->existe_propiedad( "Velocidad" ) )
						cout << "Consultando Velocidad = " << oa_bd->consultar_propiedad_instancia(c, in, "Velocidad") << endl; //Hay que Comprobar que existe la propiedad y la propiedad existe en esa instancias
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}

				if(oa_bd->get_clase(c) != NULL){
				if( (oa_bd->get_clase(c))->existe_propiedad( "AlertarA" ) )
				cout << "Consultando AlertarA = " << oa_bd->consultar_propiedad_instancia(c, in, "AlertarA") << endl;
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}

				if(oa_bd->get_clase(c) != NULL){
				if( (oa_bd->get_clase(c))->existe_propiedad( "Nombre" ) )
				cout << "Consultando Nombre = " << oa_bd->consultar_propiedad_instancia(c, in, "Nombre") << endl;
				}else{
					cout << "La clase " << c << " es NULL" << endl;

				}

				if(oa_bd->get_clase(c) != NULL){
				if( (oa_bd->get_clase(c))->existe_propiedad( "Apellido" ) )
				cout << "Consultando Apellido = " << oa_bd->consultar_propiedad_instancia(c, in, "Apellido") << endl << endl;
				 }else{
					cout << "La clase " << c << " es NULL" << endl;

				}
	
			break;






		
		/**  Se hace la lectura por archivos de las consultas reactivas:
		 *  Se verifica la correctitud de la sintaxis
		 *  No deben haber eventos repetidos
		 *  Se comprueba la existencia de la clase donde se activara el o los eventos
		 *  
		*/

			case 19:
			ifstream entrada("consultas_reactivas.in");
			int reti;
			regex_t regex; //Variable para la expresion regular
			string exp;
			char * pattern ="^\\((S|s|p|P),\\[([A-Za-z0-9])+(([,])([A-Za-z0-9])+)*\\],([A-Za-z0-9])+\\)$"; //Patron de la expresion regular

			/**
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

				reti = regcomp (&regex, pattern, REG_EXTENDED);//Compilo el patrón
				while( getline (entrada,exp) ){//Leo una linea del archivo
					exp = Trim(exp);//Quitar espacios de la expresion
					cout << exp << " " << endl;
					reti = regexec (&regex, &exp[0], (size_t)0, NULL, 0); //Se verifica que la consulta reactiva cumpla con el patrón
					if( reti == REG_NOMATCH ){ //Error de sintaxis en la consulta reactiva
						puts("Error de sintaxis");
					}
					else{ //Si es 0, entonces la consulta reactiva cumple con el patrón
		
						// Se obtienen los eventos dentro del corchete
						int    status;
						regex_t    re;
						regmatch_t rm;
						char *patter = "\\[([A-Za-z0-9])+(([,])([A-Za-z0-9])+)*\\]";
						string eventos, tipo, tabla;
						int num_eventos;
						map<string,string> *eventosHash;//Tabla Hash con los eventos de la consulta-reactiva
						string eventoArreglo[100];						
						string eve;
						bool band;
			
						eventosHash = new map<string, string>();
						
						//Se compila la expresión regular y se verifica si tiene algún error
						if (regcomp(&re, patter, REG_EXTENDED) != 0) {
							cout << "Patrón erróneo";
						}
		
						status = regexec(&re, &exp[0], 1, &rm, 0); //Se verifica que el grupo de eventos de la consulta reactiva cumpla con el patrón
						regfree(&re); //Libera la memoria asignada por regcomp()
		
						if (status != 0) { //Si el estado no devuelve 0, entonces no cumple el patrón
							cout << "No coincide";
							cout << status << endl;
						}
						else{
							// Extraigo el rango de los eventos
							eventos = exp.substr( (int)rm.rm_so, (int)rm.rm_eo - 3);
							tipo = exp.substr(1, (int)rm.rm_so - 2); //Tipo de ejecucion de ventos
							tabla = exp.substr((int)rm.rm_eo + 1 , exp.size() ); //Clase donde se ejecutaran los eventos
							tabla.erase(tabla.size() - 1 , 2);
							eventos = eventos.substr( 1, eventos.size());
							eventos[ eventos.size()-1 ] = ',';
						}
			
						cout << "Modo de activacion: "<< tipo<< ", Clase: " << tabla << endl;
						// Se obtienen los nombres de los eventos y se verifica que no hayan repetidos
						num_eventos = 0;
						band = true;
			
						if( StringToUpper( tipo ) == "P"){ //Se verifica si es paralelo para no permitir eventos repetidos
							do{
								int f;
								f = eventos.find(","); //Busco la posicion de la coma mas cercana
								eve = eventos.substr(0, f); //Extraigo un evento de la lista
				
								if( (*eventosHash)[eve] != ""  ){//Reviso si es evento es repetido
									band = false;
								}
								else{
									(*eventosHash)[eve] = eve; //Guardo el evento en la tabla hash
									eventoArreglo[num_eventos] = eve;
									num_eventos+=1; //Contador de eventos
									eventos = eventos.substr( f+1, eventos.size()-1);//Elimino el evento que se agrego de la cadena original
								}
							}while( eventos.size() > 1 && band );
						}
						if(!band){
							cout << "Hay uno o más eventos repetidos" << endl;
						}
						else{
							//Verificar que existen los eventos y la clase en donde se activaran		
							if( oa_bd->existencia_consulta_reactiva(eventoArreglo, num_eventos, tabla) &&
								oa_bd->organizar_eventos(eventoArreglo, num_eventos, tabla) ){
								cout << "ACTIVA! " << endl;
								/***************************************************************/
								//oa_fbd->activar_eventos(nom_evento, nom_);
							}
						}
			
					}
					cout << endl;		 
				}
				regfree (&regex);
				entrada.close();
			break;
	

			}
	}

	return EXIT_SUCCESS;
}
