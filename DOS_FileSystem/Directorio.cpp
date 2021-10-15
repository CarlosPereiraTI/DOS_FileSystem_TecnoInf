#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#include "Directorio.h"
#include "ListaArchivos.h"

struct _directorio{
    Cadena nombre;
    ListaArchivos arch;
};

Directorio crearDirectorio(Cadena nomDir){
    Directorio d = new _directorio;
    d->nombre = new char[MAX_NOMBRE];
    strcpy(d->nombre,nomDir);
    d->arch = NULL;
    return d;
}

bool existeArchivoDirectorio(Directorio dir, Cadena nombre){
    if(esVaciaLista(dir->arch)){
        return false;
    }
    else if(existeArchivoListaArchivos(dir->arch,nombre)){
        return true;
    }else{
        return false;
    }
}

ListaArchivos crearArchivoDirectorio(Directorio dir, Cadena nombre){
    if(!existeArchivoDirectorio(dir,nombre)){
        return insertOrd(dir->arch,nombre);
    }
}

void eliminarArchivoDirectorio(Directorio dir, Cadena nombre){
    if(esVaciaLista(dir->arch)){
        cout << "El directorio está vacio.\n\n" << endl;
    }else{
        eliminarArchivoListaArchivos(dir->arch,nombre);
    }
}

Archivo obtenerArchivoDirectorio(Directorio dir, Cadena nombre){
    if(esVaciaLista(dir->arch)){
        return NULL;
    }else{
        return obtenerArchivoListaArchivos(dir->arch,nombre);
    }
}

void listarDirectorio(Directorio dir){
    listarArchivos(dir->arch);
}

Cadena obtenerNombreDirectorio(Directorio d){
    return d->nombre;
}

bool esVacioDirectorio(Directorio dir){
    return dir == NULL;
}

ListaArchivos obtenerListaArchivosDirectorio(Directorio dir){
    return dir->arch;
}
