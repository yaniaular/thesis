// Fig. 20.3: NodoLista.h
// Definición de la plantilla de clase NodoLista.
#ifndef NODOLISTA_H
#define NODOLISTA_H

// declaración anticipada de la clase Lista, requerida para anunciar que la clase 
// Lista existe y poder utilizarla en la declaración friend de la línea 13
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
   // cuerpo vacío
} // fin del constructor de NodoLista

// devuelve una copia de los datos en el nodo
template< class TIPONODO >
TIPONODO NodoLista< TIPONODO >::obtenerDatos() const 
{ 
   return datos; 
} // fin de la función obtenerDatos

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
