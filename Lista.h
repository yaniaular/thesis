// Fig. 20.4: Lista.h
// Definici�n de la plantilla de clase Lista.
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;

#include "NodoLista.h" // definici�n de la clase NodoLista

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
   NodoLista< TIPONODO > *ultimoPtr; // apuntador al �ltimo nodo

   // funci�n utilitaria para asignar un nuevo nodo
   NodoLista< TIPONODO > *obtenerNuevoNodo( const TIPONODO & );
}; // fin de la clase Lista

// constructor predeterminado
template< class TIPONODO >
Lista< TIPONODO >::Lista() 
   : primeroPtr( 0 ), ultimoPtr( 0 ) 
{ 
   // cuerpo vac�o
} // fin del constructor de Lista

// destructor
template< class TIPONODO >
Lista< TIPONODO >::~Lista()
{
   if ( !estaVacia() ) // la Lista no est� vac�a
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

   if ( estaVacia() ) // la Lista est� vac�a
      primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista s�lo tiene un nodo
   else // la Lista no est� vac�a
   {
      nuevoPtr->siguientePtr = primeroPtr; // apunta el nuevo nodo al nodo que antes era el primero
      primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
   } // fin de else
} // fin de la funci�n insertarAlFrente

// inserta un nodo al final de la lista
template< class TIPONODO >
void Lista< TIPONODO >::insertarAlFinal( const TIPONODO &valor )
{
   NodoLista< TIPONODO > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo

   if ( estaVacia() ) // la Lista est� vac�a
      primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista s�lo tiene un nodo
   else // la Lista no est� vac�a
   {
      ultimoPtr->siguientePtr = nuevoPtr; // actualiza el nodo que antes era el �ltimo
      ultimoPtr = nuevoPtr; // nuevo �ltimo nodo
   } // fin de else
} // fin de la funci�n insertarAlFinal

// elimina un nodo de la parte frontal de la lista
template< class TIPONODO >
bool Lista< TIPONODO >::eliminarDelFrente( TIPONODO &valor )
{
   if ( estaVacia() ) // la Lista est� vac�a
      return false; // la eliminaci�n no tuvo �xito
   else 
   {
      NodoLista< TIPONODO > *tempPtr = primeroPtr; // contiene tempPtr a eliminar

      if ( primeroPtr == ultimoPtr )
         primeroPtr = ultimoPtr = 0; // no hay nodos despu�s de la eliminaci�n
      else
         primeroPtr = primeroPtr->siguientePtr; // apunta al nodo que antes era el segundo

      valor = tempPtr->datos; // devuelve los datos que se van a eliminar
      delete tempPtr; // reclama el nodo que antes era el primero
      return true; // la eliminaci�n tuvo �xito
   } // fin de else
} // fin de la funci�n eliminarDelFrente

// elimina un nodo de la parte final de la lista
template< class TIPONODO >
bool Lista< TIPONODO >::eliminarDelFinal( TIPONODO &valor )
{
   if ( estaVacia() ) // la Lista est� vac�a
      return false; // la eliminaci�n no tuvo �xito
   else 
   {
      NodoLista< TIPONODO > *tempPtr = ultimoPtr; // contiene tempPtr a eliminar

      if ( primeroPtr == ultimoPtr ) // la Lista tiene un elemento
         primeroPtr = ultimoPtr = 0; // no hay nodos despu�s de la eliminaci�n
      else 
      {
         NodoLista< TIPONODO > *actualPtr = primeroPtr;

         // localiza el pen�ltimo elemento 
         while ( actualPtr->siguientePtr != ultimoPtr )    
            actualPtr = actualPtr->siguientePtr; // se desplaza al siguiente nodo

         ultimoPtr = actualPtr; // elimina el �ltimo nodo
         actualPtr->siguientePtr = 0; // ahora �ste es el �ltimo nodo
      } // fin de else

      valor = tempPtr->datos; // devuelve el valor del nodo que antes era el �ltimo
      delete tempPtr; // reclama el nodo que antes era el �ltimo
      return true; // la eliminaci�n tuvo �xito
   } // fin de else
} // fin de la funci�n eliminarDelFinal

// �est� la Lista vac�a?
template< class TIPONODO > 
bool Lista< TIPONODO >::estaVacia() const 
{ 
   return primeroPtr == 0; 
} // fin de la funci�n estaVacia

// devuelve el apuntador al nodo reci�n asignado
template< class TIPONODO >
NodoLista< TIPONODO > *Lista< TIPONODO >::obtenerNuevoNodo( 
   const TIPONODO &valor )
{
   return new NodoLista< TIPONODO >( valor );
} // fin de la funci�n obtenerNuevoNodo

// muestra el contenido de la Lista
template< class TIPONODO >
void Lista< TIPONODO >::imprimir() const
{
   if ( estaVacia() ) // la Lista est� vac�a
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
} // fin de la funci�n imprimir




template< class TIPONODO >
const TIPONODO& Lista< TIPONODO >::consultar(int j)
{
	int i = 0;

   if ( estaVacia() ) // la Lista est� vac�a
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
	

} // fin de la funci�n consultar


#endif

/**************************************************************************
 * (C) Copyright 1992-2007 por Deitel & Associates, Inc. y                *
 * Pearson Education, Inc. Todos los derechos reservados.                 *
 *                                                                        *
 * RENUNCIA: Los autores y el editor de este libro han realizado su mejor *
 * esfuerzo para preparar este libro. Esto incluye el desarrollo, la      *
 * investigaci�n y prueba de las teor�as y programas para determinar su   *
 * efectividad. Los autores y el editor no hacen ninguna garant�a de      *
 * ning�n tipo, expresa o impl�cita, en relaci�n con estos programas o    *
 * con la documentaci�n contenida en estos libros. Los autores y el       *
 * editor no ser�n responsables en ning�n caso por los da�os conseguentes *
 * en conexi�n con, o que surjan de, el suministro, desempe�o o uso de    *
 * estos programas.                                                       *
 *************************************************************************/
