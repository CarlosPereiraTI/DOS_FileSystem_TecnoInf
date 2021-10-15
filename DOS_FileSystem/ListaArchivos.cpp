#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#include "Archivo.h"
#include "ListaArchivos.h"

struct _listaArchivos{
    Archivo arch;
    _listaArchivos *sig;
};

ListaArchivos crearListaArchivos(){
    return NULL;
}

ListaArchivos insertaPrimero(ListaArchivos &lista, Cadena nombreArchivo){
    Archivo a = crearArchivo(nombreArchivo);
    ListaArchivos aux = new _listaArchivos;
    aux->arch = a;
    aux->sig = lista;
    lista = aux;
    return lista;
}

ListaArchivos insertOrd(ListaArchivos &lista, Cadena nombreArchivo){
    if(esVaciaLista(lista) || (strcmp(nombreArchivo,obtenerNombreArchivo(lista->arch)) < 0)){
        return insertaPrimero(lista,nombreArchivo);
    }else{
        return insertOrd(lista->sig,nombreArchivo);
    }
}

bool existeArchivoListaArchivos(ListaArchivos lista, Cadena nombre){
    if(esVaciaLista(lista)){
        return false;
    }else if(strcmp(nombre,obtenerNombreArchivo(lista->arch)) == 0){
            return true;
    }else{
        return existeArchivoListaArchivos(lista->sig,nombre);
    }
}

Archivo obtenerArchivoListaArchivos(ListaArchivos lista, Cadena nombre){
    if(esVaciaLista(lista)){
        return NULL;
    }else if(strcmp(nombre,obtenerNombreArchivo(lista->arch)) == 0){
        return lista->arch;
    }else{
        return obtenerArchivoListaArchivos(resto(lista),nombre);
    }
}

bool esVaciaLista(ListaArchivos lista){
    if(lista == NULL){
        return true;
    }else{
        return false;
    }
}

Archivo primero(ListaArchivos lista){
    return lista->arch;
}

ListaArchivos resto(ListaArchivos lista){
    return lista->sig;
}

ListaArchivos eliminarArchivoListaArchivos(ListaArchivos &lista, Cadena nombreArchivo){
    if(esVaciaLista(lista)){
        return NULL;
    }else if(strcmp(nombreArchivo,obtenerNombreArchivo(lista->arch)) == 0){
        ListaArchivos aux = new _listaArchivos;
        aux = lista;
        lista = lista->sig;
        delete aux;
        return lista;
    }else{
        lista->sig = eliminarArchivoListaArchivos(lista->sig,nombreArchivo);
        return lista;
    }
}

void listarArchivos(ListaArchivos lista){
    while(!esVaciaLista(lista)){
        imprimeDatos(lista->arch);
        lista = resto(lista);
    }
}

void listarArchivosFormato(ListaArchivos lista,Cadena ruta){
    if(!esVaciaLista(lista)){
        cout << ruta << "/" << obtenerNombreArchivo(lista->arch) << endl;
        listarArchivosFormato(resto(lista),ruta);
    }
}

ListaArchivos destruirListaArchivos(ListaArchivos lista){
    if(!esVaciaLista(lista)){
        setPermisoEscritura(lista->arch,false);
        ListaArchivos aux = new _listaArchivos;
        aux = lista;
        lista = resto(lista);
        delete aux;
    }
}
