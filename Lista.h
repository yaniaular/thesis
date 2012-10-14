// Fig. 20.4: Lista.h
// Definición de la plantilla de clase Lista.
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;

#include "NodoLista.h" // definición de la clase NodoLista

template< class TIPONODO >
class Lista 
{
public:
   Lista(); // constructor
   ~Lista(); // destructor
   void insertarAlFrente( const TIPONODO & );
   void insertarAlFinal( const TIPONODO & );
   bool eliminarDelFrente( TIPONODO & );
   bool eliminarDelFinal( TIPONODO & );
   bool estaVacia() const;
   void imprimir() const;
   const TIPONODO& consultar(int j);
private:
   NodoLista< TIPONODO > *primeroPtr; // apuntador al primer nodo
   NodoLista< TIPONODO > *ultimoPtr; // apuntador al último nodo

   // función utilitaria para asignar un nuevo nodo
   NodoLista< TIPONODO > *obtenerNuevoNodo( const TIPONODO & );
}; // fin de la clase Lista

// constructor predeterminado
template< class TIPONODO >
Lista< TIPONODO >::Lista() 
   : primeroPtr( 0 ), ultimoPtr( 0 ) 
{ 
   // cuerpo vacío
} // fin del constructor de Lista

// destructor
template< class TIPONODO >
Lista< TIPONODO >::~Lista()
{
   if ( !estaVacia() ) // la Lista no está vacía
   {    
      cout << "Destruyendo nodos ...\n";

      NodoLista< TIPONODO > *actualPtr = primeroPtr;
      NodoLista< TIPONODO > *tempPtr;

      while ( actualPtr != 0 ) // elimina los nodos restantes
      {  
         tempPtr = actualPtr;
         cout << tempPtr->datos << '\n';
         actualPtr = actualPtr->siguientePtr;
         delete tempPtr;
      } // fin de while
   } // fin de if

   cout << "Se destruyeron todos los nodos\n\n";
} // fin del destructor de Lista

// inserta un nodo al frente de la lista
template< class TIPONODO >
void Lista< TIPONODO >::insertarAlFrente( const TIPONODO &valor )
{
   NodoLista< TIPONODO > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo

   if ( estaVacia() ) // la Lista está vacía
      primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
   else // la Lista no está vacía
   {
      nuevoPtr->siguientePtr = primeroPtr; // apunta el nuevo nodo al nodo que antes era el primero
      primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
   } // fin de else
} // fin de la función insertarAlFrente

// inserta un nodo al final de la lista
template< class TIPONODO >
void Lista< TIPONODO >::insertarAlFinal( const TIPONODO &valor )
{
   NodoLista< TIPONODO > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo

   if ( estaVacia() ) // la Lista está vacía
      primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
   else // la Lista no está vacía
   {
      ultimoPtr->siguientePtr = nuevoPtr; // actualiza el nodo que antes era el último
      ultimoPtr = nuevoPtr; // nuevo último nodo
   } // fin de else
} // fin de la función insertarAlFinal

// elimina un nodo de la parte frontal de la lista
template< class TIPONODO >
bool Lista< TIPONODO >::eliminarDelFrente( TIPONODO &valor )
{
   if ( estaVacia() ) // la Lista está vacía
      return false; // la eliminación no tuvo éxito
   else 
   {
      NodoLista< TIPONODO > *tempPtr = primeroPtr; // contiene tempPtr a eliminar

      if ( primeroPtr == ultimoPtr )
         primeroPtr = ultimoPtr = 0; // no hay nodos después de la eliminación
      else
         primeroPtr = primeroPtr->siguientePtr; // apunta al nodo que antes era el segundo

      valor = tempPtr->datos; // devuelve los datos que se van a eliminar
      delete tempPtr; // reclama el nodo que antes era el primero
      return true; // la eliminación tuvo éxito
   } // fin de else
} // fin de la función eliminarDelFrente

// elimina un nodo de la parte final de la lista
template< class TIPONODO >
bool Lista< TIPONODO >::eliminarDelFinal( TIPONODO &valor )
{
   if ( estaVacia() ) // la Lista está vacía
      return false; // la eliminación no tuvo éxito
   else 
   {
      NodoLista< TIPONODO > *tempPtr = ultimoPtr; // contiene tempPtr a eliminar

      if ( primeroPtr == ultimoPtr ) // la Lista tiene un elemento
         primeroPtr = ultimoPtr = 0; // no hay nodos después de la eliminación
      else 
      {
         NodoLista< TIPONODO > *actualPtr = primeroPtr;

         // localiza el penúltimo elemento 
         while ( actualPtr->siguientePtr != ultimoPtr )    
            actualPtr = actualPtr->siguientePtr; // se desplaza al siguiente nodo

         ultimoPtr = actualPtr; // elimina el último nodo
         actualPtr->siguientePtr = 0; // ahora éste es el último nodo
      } // fin de else

      valor = tempPtr->datos; // devuelve el valor del nodo que antes era el último
      delete tempPtr; // reclama el nodo que antes era el último
      return true; // la eliminación tuvo éxito
   } // fin de else
} // fin de la función eliminarDelFinal

// ¿está la Lista vacía?
template< class TIPONODO > 
bool Lista< TIPONODO >::estaVacia() const 
{ 
   return primeroPtr == 0; 
} // fin de la función estaVacia

// devuelve el apuntador al nodo recién asignado
template< class TIPONODO >
NodoLista< TIPONODO > *Lista< TIPONODO >::obtenerNuevoNodo( 
   const TIPONODO &valor )
{
   return new NodoLista< TIPONODO >( valor );
} // fin de la función obtenerNuevoNodo

// muestra el contenido de la Lista
template< class TIPONODO >
void Lista< TIPONODO >::imprimir() const
{
   if ( estaVacia() ) // la Lista está vacía
   {
      cout << "La lista esta vacia\n\n";
      return;
   } // fin de if

   NodoLista< TIPONODO > *actualPtr = primeroPtr;

   cout << "La lista es: ";

   while ( actualPtr != 0 ) // obtiene los datos del elemento
   {
      cout << actualPtr->datos << ' ';
      actualPtr = actualPtr->siguientePtr;
   } // fin de while

   cout << "\n\n";
} // fin de la función imprimir




template< class TIPONODO >
const TIPONODO& Lista< TIPONODO >::consultar(int j)
{
	int i = 0;

   if ( estaVacia() ) // la Lista está vacía
   {
      cout << "La lista esta vacia\n\n";
   
   } // fin de if

   NodoLista< TIPONODO > *actualPtr = primeroPtr;



   while ( actualPtr != 0 && i < j) 
   {
      actualPtr = actualPtr->siguientePtr;
		i++;
   } // fin de while

 	return actualPtr->datos;
	

} // fin de la función consultar


#endif

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
