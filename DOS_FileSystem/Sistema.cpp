#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "Sistema.h"

using namespace std;

struct _sistema{
    ArbolDirectorios raiz;
    ArbolDirectorios actual;

};

TipoRet DIR (Sistema &s, Cadena parametro){
    TipoRet ret = NO_IMPLEMENTADA;
    if(strcmp(parametro,"/S") == 0 || strcmp(parametro,"/s") == 0){
        cout << obtenerRutaDirectorio(s->actual) << endl;
        listarArchivosFormato(obtenerListaArchivosDirectorio(obtenerDirectorioArbolDirectorios(s->actual)),obtenerRutaDirectorio(s->actual));
        imprimeArbolPreOrden(primerhijo(s->actual));
        ret = OK;
    }else{
        if(!esVacioArbolDirectorios(s->actual)){
            if(esVacioArbolDirectorios(primerhijo(s->actual)) && esVaciaLista(obtenerListaArchivosDirectorio(obtenerDirectorioArbolDirectorios(s->actual)))){
                cout << obtenerRutaDirectorio(s->actual) << endl;
                //cout << obtenerNombreDirectorio(obtenerDirectorioArbolDirectorios(s->actual)) << "/" << endl;
                cout << "No hay archivos ni directorios." << endl << endl;
            }else{
                cout << obtenerRutaDirectorio(s->actual) << endl;
                //cout << obtenerNombreDirectorio(obtenerDirectorioArbolDirectorios(s->actual)) << "/" << endl;
                listarArchivos(obtenerListaArchivosDirectorio(obtenerDirectorioArbolDirectorios(s->actual)));
                listarDirectoriosHijos(primerhijo(s->actual));
            }
            ret = OK;
        }
    }
    return ret;
}


TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        if(!existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo) && (strlen(nombreArchivo) <= MAX_NOMBRE)){
            crearArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo);
            cout << "OK!" << endl;
            return OK;
        }else if(existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            cout << "ERROR: El archivo ya existe." << endl;
            ret = ERROR;
        }else if(strlen(nombreArchivo) > MAX_NOMBRE){
            cout << "ERROR: El nombre supera la cantidad maxima de caracteres." << endl;
            ret = ERROR;
        }else{
                return ERROR;
        }
    }
    return ret;
}


TipoRet DELETE (Sistema &s, Cadena nombreArchivo){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        Archivo archaux = obtenerArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo);
        if(existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            if(obtenerAtributoArchivo(archaux) == false){
                eliminarArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo);
                cout << "OK!" << endl;
                ret = OK;
            }else{
                cout << "ERROR: El archivo solo tiene permisos de Lectura" << endl;
                ret = ERROR;
            }
        }else{
            cout << "ERROR: El archivo no existe" << endl;
            ret = ERROR;
        }
    }
    return ret;
}


TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        if(existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            if(strcmp(parametro,"+W") == 0 || strcmp(parametro,"+w") == 0){
                setPermisoEscritura(obtenerArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo),0);
            }else if(strcmp(parametro,"-W") == 0 || strcmp(parametro,"-w") == 0){
                setPermisoEscritura(obtenerArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo),1);
            }
            cout << "OK!" << endl;
            ret = OK;
        }else if(!existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            cout << "ERROR: el archivo no existe.\n\n" << endl;
            ret = ERROR;
        }
    }
    return ret;
}


TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        if(existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            Archivo aux = obtenerArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo);
            if(esArchivoSoloLectura(aux)){
                cout << "ERROR: El archivo es de solo lectura." << endl;
                ret = ERROR;
            }else{
                Cadena cadaux = obtenerContenidoArchivo(aux);
                int tamtxt = strlen(cadaux) + strlen(texto);
                if(tamtxt > TEXTO_MAX){
                    cout << "ERROR: El texto es mayor al soportado por el archivo." << endl;
                    ret = ERROR;
                }else{
                    Cadena cad = new char[TEXTO_MAX];
                    strcpy(cad,obtenerContenidoArchivo(aux));
                    setContenido(aux,texto);
                    concContenido(aux,cad);
                    cout << "OK!" << endl;
                    ret = OK;
                }
            }
        }else{
            cout << "ERROR: El archivo no existe." << endl;
            ret = ERROR;
        }
    }
    return ret;
}


TipoRet DF (Sistema &s, Cadena nombreArchivo, int k){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        if (existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            Archivo aux = obtenerArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo);
            if(esArchivoSoloLectura(aux)){
                cout << "ERROR: El archivo es de solo lectura." << endl;
                ret = ERROR;
            }else{
                if((strlen(obtenerContenidoArchivo(aux)) - k) <= 0){
                    setContenido(aux,(Cadena)"");
                }else{
                    setContenido(aux,obtenerContenidoArchivo(aux)+k);
                }
                cout << "OK!" << endl;
                ret = OK;
            }
        }else{
            cout << "ERROR: El archivo no existe." << endl;
            ret = ERROR;
        }
    }
    return ret;
}


TipoRet TYPE (Sistema &s, Cadena nombreArchivo){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        if(existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            Archivo aux = obtenerArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo);
            if(strlen(obtenerContenidoArchivo(aux)) == 0){
                cout << "Archivo sin contenido" << endl;
            }else{
                cout << obtenerContenidoArchivo(aux) << endl;
            }
            ret = OK;
        }else if(!existeArchivoDirectorio(obtenerDirectorioArbolDirectorios(s->actual),nombreArchivo)){
            cout << "ERROR: El archivo no existe.\n\n";
            ret = ERROR;
        }
    }
    return ret;
}


TipoRet CD(Sistema &s, Cadena nombreDirectorio){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        ArbolDirectorios aux = buscarDirectorioArbolDirectorios(primerhijo(s->actual),nombreDirectorio);
        if(!esVacioArbolDirectorios(aux)){
            s->actual = aux;
            ret = OK;
        }else if(strcmp(nombreDirectorio,"..") == 0){
            if(strcmp(obtenerNombreDirectorio(obtenerDirectorioArbolDirectorios(s->actual)),"RAIZ") == 0){
                cout << "ERROR: Ud se encuentra posicionado en la raiz" << endl;
                ret = ERROR;
            }else{
                s->actual = padre(s->actual);
                ret = OK;
            }
        }else if(strcmp(nombreDirectorio,"raiz") == 0 || strcmp(nombreDirectorio,"RAIZ") == 0){
            s->actual = s->raiz;
            ret = OK;
        }else{
            cout << "ERROR: No existe directorio con ese nombre.\n\n" << endl;
            ret = ERROR;
        }
    }
    return ret;
}


TipoRet MKDIR(Sistema &s, Cadena nombreDirectorio){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(s->actual)){
        ArbolDirectorios aux = buscarDirectorioArbolDirectorios(primerhijo(s->actual),nombreDirectorio);
        if(esVacioArbolDirectorios(aux)){
            ArbolDirectorios aux = insertaDirectorioOrdenado(primerhijo(s->actual),s->actual,nombreDirectorio);
            setHijo(s->actual,aux);
            cout << "OK!" << endl;
            ret = OK;
        }else{
            cout << "ERROR: Ya existe un directorio con ese nombre.\n\n" << endl;
            ret = ERROR;
        }
    }
    return ret;
}


TipoRet RMDIR(Sistema &s, Cadena nombreDirectorio){
    TipoRet ret = NO_IMPLEMENTADA;
    if(!esVacioArbolDirectorios(buscarDirectorioArbolDirectorios(primerhijo(s->actual),nombreDirectorio))){
        ArbolDirectorios aux = eliminarDirectorioArbolDirectorios(primerhijo(s->actual),nombreDirectorio);
        setHijo(s->actual,aux);
        cout << "OK!" << endl;
        ret = OK;
    }else{
        cout << "ERROR: No existe un directorio con ese nombre.\n\n" << endl;
        ret = ERROR;
    }
    return ret;
}


TipoRet CREARSISTEMA(Sistema &s){
    TipoRet ret = NO_IMPLEMENTADA;
    s = new _sistema;
    s->raiz = crearArbolDirectorios();
    crearRaiz(s->raiz,"RAIZ");
    s->actual = s->raiz;
    ret = OK;
    return ret;
}


TipoRet DESTRUIRSISTEMA(Sistema &s){
    TipoRet ret = NO_IMPLEMENTADA;
    destruirArbol(s->raiz);
    delete s;
    return ret;
}
