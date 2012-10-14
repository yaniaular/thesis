// Fig. 20.5: Fig20_05.cpp
// Programa de prueba de la clase Lista.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Lista.h" // definición de la clase Lista


// muestra las instrucciones del programa al usuario
void instrucciones()
{
   cout << "Escriba una de las siguentes opciones:\n"
      << "  1 para insertar al principio de la lista\n" 
      << "  2 para insertar al final de la lista\n" 
      << "  3 para eliminar del principio de la lista\n" 
      << "  4 para eliminar del final de la lista\n" 
      << "  5 para terminar el procesamiento de la lista\n";
} // fin de la función instrucciones

// función para evaluar una Lista
template< typename T >
void probarLista( Lista< T > &objetoLista, const string &nombreTipo )
{
   cout << "Prueba de una Lista de valores tipo " << nombreTipo << "\n";
 
   int opcion; // almacena la opción del usuario
   T valor; // almacena el valor de entrada
	int num;
   do // realiza las acciones seleccionadas por el usuario
   {
    	instrucciones();
	  cout << "? ";
      cin >> opcion;
	
      switch ( opcion ) 
      {
         case 1: // inserta al principio
            cout << "Escriba " << nombreTipo << ": ";
            cin >> valor;
            objetoLista.insertarAlFrente( valor );
            objetoLista.imprimir();
            break;
         case 2: // inserta al final
            cout << "Escriba " << nombreTipo << ": ";
            cin >> valor;
            objetoLista.insertarAlFinal( valor );
            objetoLista.imprimir();
            break;
         case 3: // elimina del principio
            if ( objetoLista.eliminarDelFrente( valor ) )
               cout << valor << " se elimino de la lista\n";

            objetoLista.imprimir();
            break;
         case 4: // elimina del final
            if ( objetoLista.eliminarDelFinal( valor ) )
               cout << valor << " se elimino de la lista\n";

            objetoLista.imprimir();
            break;

         case 5: // elimina del final
            cout << "Escriba una posicion:";
            cin >> num;

            cout << "El valor de la posicion " << num << " es: " << objetoLista.consultar(num);
			objetoLista.imprimir();
            break;

      } // fin de switch
   } while ( opcion != 6 ); // fin de do...while

   cout << "Fin de la prueba de la lista\n\n";
} // fin de la función probarLista


int main()
{
   // prueba Lista de valores int
   Lista< int > listaEnteros;
   probarLista( listaEnteros, "entero" ); 

   // prueba Lista de valores double
   Lista< double > listaDouble;
   probarLista( listaDouble, "double" ); 
   return 0;
} // fin de main

/**************************************************************************
 * (C) Copyright 1992-2007 por Deitel & Associates, Inc. y                *
 * Pearson Education, Inc. Todos los derechos reservados.                 *
 *                                                                        *
 * RENUNCIA: Los autores y el editor de este libro han realizado su mejor *
 * esfuerzo para preparar este libro. Esto incluye el desarrollo, la      *
 * investigación y prueba de las teorías y programas para determinar su   *
 * efectividad. Los autores y el editor no hacen ninguna garantía de      *
 * ningún tipo, expresa o implícita, en relación con estos programas o    *
 * con la documentación contenida en estos libros. Los autores y el       *
 * editor no serán responsables en ningún caso por los daños conseguentes *
 * en conexión con, o que surjan de, el suministro, desempeño o uso de    *
 * estos programas.                                                       *
 *************************************************************************/
