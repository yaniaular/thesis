#ifndef Tabla_H_
#define Tabla_H_
#include <iostream>
#include <kcstashdb.h>
#include <string.h>
#include <map>

#define C 15000
#define I 15000
#define P 15000
#define E 15000

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
		char* StringAChar(string a);
};
 
 	Tabla::Tabla(){
			
	}

	string EnteroAString(int a){
		stringstream ss;
		ss << a;
		return ss.str();
	}
	
	char* StringAChar(string a){
	
		char *i,*p = &a[0];
		i = new char[strlen(p)+1];
		strcpy(i, p);
		return i;
	
	
		//return &(a[0]);
	}

# endif
