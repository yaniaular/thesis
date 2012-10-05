#ifndef Tabla_H_
#define Tabla_H_
#include <iostream>
#include <kcstashdb.h>
#include <string.h>
#include <map>
#include <fstream>
#include <limits.h>
#include <float.h>
#include <cstdlib>
#include <list>

#define C 500 //500
#define I 240000 //240000
#define P 3001 //3001
#define E 501 // 501

#define ENTERO 0
#define REAL 1
#define CADENA 2

using namespace kyotocabinet;
using namespace std;

typedef std::map< string, int, std::less<string> > Cuadro; //Crear tabla de hash

class Tabla{

	private:
			
	public:
		Tabla();
		~Tabla();
		string EnteroAString(int a);
		string DoubleAString(double a);
		char* StringAChar(string a);
};
 
 	Tabla::Tabla(){
			
	}

 	Tabla::~Tabla(){
			
	}

	string EnteroAString(int a){
		stringstream ss;
		ss << a;
		return ss.str();
	}

	string DoubleAString(double a){
		stringstream ss;
		ss << a;
		return ss.str();
	}
	
	char* StringAChar(string a){
	
		char *i,*p = &a[0];
		i = new char[strlen(p)+1];
		strcpy(i, p);
		return i;

	}

# endif
