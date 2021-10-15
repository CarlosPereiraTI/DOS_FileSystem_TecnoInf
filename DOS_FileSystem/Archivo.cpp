#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#include "Tools.h"
#include "Archivo.h"

struct _archivo{
    Cadena nombre;
    Cadena contenido;
    bool atributo;
};

Archivo crearArchivo(Cadena nombreArchivo){
    Archivo aux = new _archivo;
    aux->nombre = new char[MAX_NOMBRE];
    aux->contenido = new char[TEXTO_MAX];
    strcpy(aux->contenido,"");
    strcpy(aux->nombre,nombreArchivo);
    aux->atributo = false;
    return aux;
}

Cadena obtenerNombreArchivo(Archivo arch){
    return arch->nombre;
}

Cadena obtenerContenidoArchivo(Archivo arch){
    return arch->contenido;
}

bool esArchivoSoloLectura(Archivo arch){
    if(arch->atributo == true){
        return true;
    }else{
        return false;
    }
}

void setPermisoEscritura(Archivo arch, bool atr){
    arch->atributo = atr;
}

void setContenido(Archivo arch, Cadena contenido){
    strcpy(arch->contenido,contenido);
}

void imprimeDatos(Archivo arch){
    cout << arch->nombre;
    if(arch->atributo == true){
        cout << "     Lectura";
    }else{
        cout << "     Lectura/Escritura";
    }
    cout << "\n";
}

bool obtenerAtributoArchivo(Archivo arch){
    return arch->atributo;
}

Cadena concContenido(Archivo a, Cadena texto){
    strcat(a->contenido,texto);
}
