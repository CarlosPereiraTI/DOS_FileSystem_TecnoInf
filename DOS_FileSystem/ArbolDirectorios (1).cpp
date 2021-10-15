#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#include "ArbolDirectorios.h"

struct _nodoDirectorio{
    Directorio dir;
    Cadena ruta;
    _nodoDirectorio *padre;
    _nodoDirectorio *hijo;
    _nodoDirectorio *hermano;
};

ArbolDirectorios crearArbolDirectorios(){
    return NULL;
}

void crearRaiz(ArbolDirectorios &ad, Cadena nombreDirectorio){
    Directorio nuevoDirectorio = crearDirectorio(nombreDirectorio);
    ad = new _nodoDirectorio;
    ad->padre = NULL;
    ad->dir = nuevoDirectorio;
    ad->hijo = NULL;
    ad->hermano = NULL;
    ad->ruta = new char[BUFFER];
    strcpy(ad->ruta,nombreDirectorio);
}

ArbolDirectorios buscarDirectorioArbolDirectorios(ArbolDirectorios ad, Cadena nombre){
    if(esVacioArbolDirectorios(ad)){
        return NULL;
    }else{
        if(strcmp(nombre,obtenerNombreDirectorio(ad->dir)) == 0){
            return ad;
        }else{
            return buscarDirectorioArbolDirectorios(ad->hermano,nombre);
        }
    }
}

Directorio obtenerDirectorioArbolDirectorios(ArbolDirectorios ad){
    return ad->dir;
}

bool esVacioArbolDirectorios(ArbolDirectorios ad){
    if(ad == NULL){
        return true;
    }else{
        return false;
    }
}

Directorio raiz(ArbolDirectorios ad){
    if(ad->padre == NULL){
        return ad->dir;
    }
}

ArbolDirectorios padre(ArbolDirectorios ad){
    return ad->padre;
}

ArbolDirectorios primerhijo(ArbolDirectorios ad){
    return ad->hijo;
}

ArbolDirectorios hermano(ArbolDirectorios ad){
    return ad->hermano;
}

ArbolDirectorios insertarPrimerHijo(ArbolDirectorios hijo,ArbolDirectorios adPadre,Cadena nombreHijo){
    ArbolDirectorios aux = new _nodoDirectorio;
    aux->dir = crearDirectorio(nombreHijo);
    aux->ruta = new char[BUFFER];
    strcpy(aux->ruta,adPadre->ruta);
    strcat(aux->ruta,"/");
    strcat(aux->ruta,nombreHijo);
    aux->padre = adPadre;
    aux->hijo = NULL;
    aux->hermano = hijo;
    hijo = aux;
}

ArbolDirectorios insertaDirectorioOrdenado(ArbolDirectorios hijo, ArbolDirectorios adPadre, Cadena nombreArchivo){
    if(esVacioArbolDirectorios(hijo) || (strcmp(nombreArchivo,obtenerNombreDirectorio(hijo->dir)) < 0)){
        return insertarPrimerHijo(hijo,adPadre,nombreArchivo);
    }else{
        ArbolDirectorios aux = insertaDirectorioOrdenado(hijo->hermano,adPadre,nombreArchivo);
        hijo->hermano = aux;
        return hijo;
    }
}

void listarDirectoriosHijos(ArbolDirectorios ad){
    while(!esVacioArbolDirectorios(ad)){
        cout << obtenerNombreDirectorio(ad->dir) << endl;
        ad = hermano(ad);
    }
}

void imprimeArbolPreOrden(ArbolDirectorios ad){
    if(!esVacioArbolDirectorios(ad)){
        cout << obtenerRutaDirectorio(ad) << endl;
        listarArchivosFormato(obtenerListaArchivosDirectorio(obtenerDirectorioArbolDirectorios(ad)),obtenerRutaDirectorio(ad));
        imprimeArbolPreOrden(ad->hijo);
        imprimeArbolPreOrden(ad->hermano);
    }
}

ArbolDirectorios eliminarDirectorioArbolDirectorios(ArbolDirectorios ad, Cadena nombreDirectorio){
    if(esVacioArbolDirectorios(ad)){
        return NULL;
    }else if(strcmp(nombreDirectorio,obtenerNombreDirectorio(ad->dir)) == 0){
        ArbolDirectorios aux = new _nodoDirectorio;
        aux = ad;
        ad = ad->hermano;
        aux->hermano = NULL;
        destruirArbol(aux);
        return ad;
    }else{
        ad->hermano = eliminarDirectorioArbolDirectorios(ad->hermano,nombreDirectorio);
        return ad;
    }
}

void destruirArbol(ArbolDirectorios ad){
    if(!esVacioArbolDirectorios(ad)){
        destruirArbol(ad->hijo);
        destruirArbol(ad->hermano);
        destruirListaArchivos(obtenerListaArchivosDirectorio(ad->dir));
        delete ad;
    }
}

void setHijo(ArbolDirectorios &padre,ArbolDirectorios hijo){
    padre->hijo = hijo;
}

Cadena obtenerRutaDirectorio(ArbolDirectorios ad){
    return ad->ruta;
}
