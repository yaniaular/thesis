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

#define C 700
#define I 700000
#define P 3001
#define E 501

#define ENTERO 0
#define REAL 1
#define CADENA 2

using namespace kyotocabinet;
using namespace std;

class Tabla{

	private:
			
	public:
		Tabla();
		string EnteroAString(int a);
		string DoubleAString(double a);
		char* StringAChar(string a);
};
 
 	Tabla::Tabla(){
			
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
