#ifndef ARBOLDIRECTORIOS_H_INCLUDED
#define ARBOLDIRECTORIOS_H_INCLUDED

#include "Directorio.h"

struct _nodoDirectorio;
typedef _nodoDirectorio* ArbolDirectorios;

ArbolDirectorios crearArbolDirectorios();
//Crea, inicializa y retorna un arbol de directorios vacio.

ArbolDirectorios insertarRaiz(ArbolDirectorios &ad, Cadena nombreDirectorio);
//Inserta la raiz en el arbol vacio.

void crearRaiz(ArbolDirectorios &, Cadena);
//Inserta el directorio 'd' en el arbol 'ad'.

ArbolDirectorios buscarDirectorioArbolDirectorios(ArbolDirectorios ad, Cadena nombre);
//Devuelve true si existe un directorio de nombre 'nombre' en el arbol de directorios 'ad' y false en caso contrario.

Directorio obtenerDirectorioArbolDirectorios(ArbolDirectorios ad);
//Devuelve el directorio de nombre 'nombre' del arbol de directorios 'ad'.

bool esVacioArbolDirectorios(ArbolDirectorios ad);
//Devuelve true si el arbol de directorios no tiene elementos y false en caso contrario

Directorio raiz(ArbolDirectorios ad);
//Devuelve el directorio que se encuentra en la raiz del arbol

ArbolDirectorios primerhijo(ArbolDirectorios ad);
//Devuelve el Directorio hijo de la raiz del arbol de directorios 'ad' que se encuentra mas a la izquierda en la estructura

ArbolDirectorios hermano(ArbolDirectorios ad);
//Devuelve el Directorio hermano de la raiz del arbol de directorios 'ad' que se encuentra inmediatamente a la derecha en la estructura

ArbolDirectorios padre(ArbolDirectorios ad);
//Devuelve el árbol padre de 'ad'

ArbolDirectorios eliminarDirectorioArbolDirectorios(ArbolDirectorios ad, Cadena nombreDirectorio);
//Elimina el directorio de nombre 'nombreDirectorio' del arbol 'ad'.

void eliminarArbolDirectorios(ArbolDirectorios &ad);
//Libera la memoria ocupada por todo el arbol de directorios y lo deja con valor NULL.

ArbolDirectorios insertarPrimerHijo(ArbolDirectorios,ArbolDirectorios,Cadena);

void listarDirectoriosHijos(ArbolDirectorios);

void imprimeArbolPreOrden(ArbolDirectorios ad);

void destruirArbol(ArbolDirectorios aux);

void setHijo(ArbolDirectorios &,ArbolDirectorios);

ArbolDirectorios insertaDirectorioOrdenado(ArbolDirectorios,ArbolDirectorios,Cadena);

Cadena obtenerRutaDirectorio(ArbolDirectorios ad);


#endif // ARBOLDIRECTORIOS_H_INCLUDED
