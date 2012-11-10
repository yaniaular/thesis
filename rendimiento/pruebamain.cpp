#include "OA.h"

int main(){


	int i, j, n, k;
	string c, c2, h1, h2;
	 
	OA *oa_bd = new OA();

	
	int cant_clases = 300, cant_instancias = 830;

	cout << "Creando las " << cant_clases << " Clases..." << endl;	
	for(i = 1; i <= cant_clases ; i++){
		stringstream ss;
		ss << i;
		c = "Clase" + ss.str();		
		oa_bd->crear_clase( c );
	}

	i = 1;
	cout << "Creando conexion entre las " << cant_clases << " Clases..." << endl;
	while(i <= 149){
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
	
	cout << "Verificando si existe caminos todas las clases contra todas... "<< endl;
	i = 1;
	while(i <= cant_clases){
		stringstream s1, s2;
		s1 << i;
		c = "Clase" + s1.str();
		j = 1;
		while(j <= cant_clases){
			stringstream s2;
			s2 << j;
			c2 = "Clase" + s2.str();		
			oa_bd->es_subclase_de(c, c2);
			j+=1;		
		}
		i+=1;
	}
	
	cout << "Creando las " << cant_instancias << " instancias..." << endl;	
	for(j = 1; j <=  cant_clases ; j++){ 
		stringstream ff;
		ff << j;
		c = "Clase" + ff.str();	
		for(i = 1; i <=  cant_instancias; i++){
			stringstream ss;
			ss << i;
			c2 = "Instancia" + ss.str() + "_" + c;	
			oa_bd->crear_instancia( c2, c );	
		
		}
	}

	cout << "Verificar si hay un camino desde todas las clases a sus respectivas instancias"<< endl;
	i = 1;
	while(i <= cant_clases){
		stringstream s1;
		s1 << i;
		c = "Clase" + s1.str();
		j = 1;
		while(j <= cant_instancias){
			stringstream s2;
			s2 << j;
			c2 = "Instancia" + s2.str()+ "_" + c;
			oa_bd->pertenece_a(c2, c);
			j+=1;
		}
		i+=1;
	}

	return EXIT_SUCCESS;
}
