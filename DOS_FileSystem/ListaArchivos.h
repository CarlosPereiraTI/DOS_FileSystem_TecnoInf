#ifndef LISTAARCHIVOS_H
#define	LISTAARCHIVOS_H

#include "Archivo.h"

struct _listaArchivos;
typedef _listaArchivos* ListaArchivos;

ListaArchivos crearListaArchivos();
//Crea, inicializa y retorna una nueva lista de archivos.

ListaArchivos insertaPrimero(ListaArchivos &lista, Cadena nombreArchivo);
//Inserta el archivo 'archivo' en la lista 'lista'.

ListaArchivos insertOrd(ListaArchivos &lista, Cadena nombreArchivo);
//Inserta los archivos creados de forma ordenada.

bool existeArchivoListaArchivos(ListaArchivos lista, Cadena nombre);
//Devuelve true si existe un archivo de nombre 'nombre' en la lista 'lista' y false en caso contrario.

Archivo obtenerArchivoListaArchivos(ListaArchivos lista, Cadena nombre);
//Devuelve el archivo de nombre 'nombre' de la lista 'lista'.

bool esVaciaLista(ListaArchivos lista);
//Devuelve true si la lista no tiene elementos y false en caso contrario

Archivo primero(ListaArchivos lista);
//Devuelve el primer elemento de la lista 'lista'

ListaArchivos resto(ListaArchivos lista);
//Devuelve la lista formada por todos menos el primer elemento.

ListaArchivos eliminarArchivoListaArchivos(ListaArchivos &lista, Cadena nombreArchivo);
//Elimina el archivo de nombre 'nombreArchivo' de la lista 'lista'.

void listarArchivos(ListaArchivos lista);
//Imprime los archivos existentes

void listarArchivosFormato(ListaArchivos,Cadena);

ListaArchivos destruirListaArchivos(ListaArchivos lista);
//Destruye toda la lista de archivos

#endif	/* LISTAARCHIVOS_H */

