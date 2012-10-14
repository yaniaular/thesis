// Fig. 20.3: NodoLista.h
// Definici�n de la plantilla de clase NodoLista.
#ifndef NODOLISTA_H
#define NODOLISTA_H

// declaraci�n anticipada de la clase Lista, requerida para anunciar que la clase 
// Lista existe y poder utilizarla en la declaraci�n friend de la l�nea 13
template< class TIPONODO > class Lista;                            

template< class TIPONODO >
class NodoLista 
{

   friend class Lista< TIPONODO >; // hace de Lista una amiga

public:
   NodoLista( const TIPONODO & ); // constructor
   TIPONODO obtenerDatos() const; // devuelve los datos en el nodo
private:
   TIPONODO datos; // datos
   NodoLista< TIPONODO > *siguientePtr; // siguiente nodo en la lista
}; // fin de la clase NodoLista

// constructor
template< class TIPONODO >
NodoLista< TIPONODO >::NodoLista( const TIPONODO &info )
   : datos( info ), siguientePtr( 0 ) 
{ 
   // cuerpo vac�o
} // fin del constructor de NodoLista

// devuelve una copia de los datos en el nodo
template< class TIPONODO >
TIPONODO NodoLista< TIPONODO >::obtenerDatos() const 
{ 
   return datos; 
} // fin de la funci�n obtenerDatos

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
