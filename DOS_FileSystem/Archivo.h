#ifndef ARCHIVO_H
#define	ARCHIVO_H

#include "Tools.h"

struct _archivo;
typedef _archivo* Archivo;

Archivo crearArchivo(Cadena nombreArchivo);
//CREA EL ARCHIVO CON NOMBRE 'nombreArchivo'

Cadena obtenerNombreArchivo(Archivo arch);
//RETORNA EL NOMBRE DEL ARCHIVO

Cadena obtenerContenidoArchivo(Archivo arch);
//RETORNA EL CONTENIDO DEL ARCHIVO

bool esArchivoSoloLectura(Archivo arch);
//RETORNA TRUE EN CASO QUE EL ARCHIVO SEA SOLO LECTURA Y FALSE EN CASO CONTRARIO

void setPermisoEscritura(Archivo arch, bool atr);
//MODIFICA LOS PERMISOS DEL ARCHIVO

void setContenido(Archivo arch, Cadena contenido);
//MODIFICA EL CONTENIDO DEL ARCHIVO

void imprimeDatos(Archivo arch);
//IMPRIME LOS DATOS DEL ARCHIVO

bool obtenerAtributoArchivo(Archivo arch);
//RETORNA EL ATRIBUTO DEL ARCHIVO "TRUE" SOLO LECTURA Y "FALSE" LECTURA/ESCRITURA

Cadena concContenido(Archivo a, Cadena texto);
//CONCATENA EL CONTENIDO DEL ARCHIVO

#endif	/* ARCHIVO_H */
