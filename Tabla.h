#ifndef Tabla_H_
#define Tabla_H_
#define C 15000
#define I 15000
#define P 15000
#define E 15000

#include <iostream>
#include <kcstashdb.h>
#include <string.h>

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
	
		return &(a[0]);
	}

# endif
