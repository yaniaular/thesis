all:
	g++ -ggdb -g -Wno-write-strings -trigraphs -I/usr/local/include -o main main.cpp -L OA.h Propiedad.h Instancia.h Tabla.h evaluate.h Clase.h -L/usr/local/lib -lkyotocabinet -lz -lstdc++ -lrt -lpthread -lm -lc
