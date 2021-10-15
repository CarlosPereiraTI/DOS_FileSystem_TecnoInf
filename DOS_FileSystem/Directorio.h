#ifndef DIRECTORIOS_H_INCLUDED
#define DIRECTORIOS_H_INCLUDED

#include "ListaArchivos.h"
#include "Archivo.h"

struct _directorio;
typedef _directorio *Directorio;

Directorio crearDirectorio(Cadena nomDir);
//Crea e inicializa y retorna un directorio nuevo de nombre 'nomDir'.

bool existeArchivoDirectorio(Directorio dir, Cadena nombre);
//Devuelve true si existe un archivo de nombre 'nombre' en el directorio 'dir' y false en caso contrario.

ListaArchivos crearArchivoDirectorio(Directorio dir, Cadena nombre);
//Crea un archivo de Lectura/Escritura de nombre 'nombre' en el directorio 'dir'.

void eliminarArchivoDirectorio(Directorio dir, Cadena nombre);
//Elimina el archivo de nombre 'nombre' del directorio 'dir'.

Archivo obtenerArchivoDirectorio(Directorio dir, Cadena nombre);
//Devuelve el archivo de nombre 'nombre' del directorio 'dir'.

void listarDirectorio(Directorio dir);
//Lista los contenidos del directorio 'dir'.

void eliminarDirectorio(Directorio &dir);
//Libera la memoria ocupada por le directorio 'dir' y lo deja apuntando a NULL

Cadena obtenerNombreDirectorio(Directorio d);
//Devuelve el nombre del directorio.

ListaArchivos obtenerListaArchivosDirectorio(Directorio dir);
//Devuelve la lista de archivos del directorio actual.

#endif // DIRECTORIOS_H_INCLUDED
