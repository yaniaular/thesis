#include "OA.h"

int main(){


	int i, j, n;
	string c, c2, h1, h2;
	 
	OA *oa_bd = new OA();

	
	int cant_clases = 300;

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

	n = oa_bd->get_num_clases();

	
	while(i <= 300){
		stringstream ss,s2;
		ss << i;
		c = "Clase" + ss.str();

		j = 0;		
		while(j <= 300){
			s2 << j;
			c2 = "Clase" + s2.str();
			//cout << "Camino " << oa_bd->es_subclase_de(c, c2)<< endl;
			j+=1;		
		}
		i+=1;
	}


	return EXIT_SUCCESS;
}
