all:
	g++ -ggdb -g -Wno-write-strings -trigraphs -I/usr/local/include -o main main.cpp -L OA.h Evento.h Propiedad.h Instancia.h Clase.h Tabla.h evaluate.h -L/usr/local/lib -lkyotocabinet -lz -lstdc++ -lrt -lpthread -lm -lc
clean:
	rm -r *~ main
	
