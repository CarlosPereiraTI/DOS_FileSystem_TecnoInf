#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "Tools.h"
#include "Sistema.h"
#include "ArbolDirectorios.h"

using namespace std;

int main(){
    Cadena comando = new char[MAX_NOMBRE];
    Cadena parametro = new char[MAX_NOMBRE];
    Cadena atributo = new char[BUFFER];
    bool fin = false;
    TipoRet retorno;
    Sistema sis;
    retorno = CREARSISTEMA(sis);
    int k;

    cout << endl;
    cout << " =================================================================================================" << endl;
    cout << "                                              BIENVENIDO" << endl;
    cout << " =================================================================================================" << endl;
    cout << endl;
    cout << " Este es un mini sistema de directorios y archivos, los comandos aceptados son los siguientes:" << endl;
    cout << endl;
    cout << " [1[ CD + 'nombre de directorio': Se mueve al directorio hijo." << endl;
    cout << " [2] CD + '..': Vuelve al directorio padre." << endl;
    cout << " [3] MKDIR + 'nombre de directorio': Crea un directorio nuevo." << endl;
    cout << " [4] RMDIR + 'nombre de directorio': Elimina el directorio y su contenido." << endl;
    cout << " [5] DIR: Lista los directorios y archivos alojados en /RAIZ." << endl;
    cout << " [6] CREATEFILE + 'nombre de archivo': Crea archivo con nombre 'nombre de archivo'." << endl;
    cout << " [7] DELETE + 'nombre de archivo': borra archivo con nombre 'nombre de archivo'." << endl;
    cout << " [8] ATTRIB + 'nombre de archivo' + [+W/-W]: Cambia los permisos del archivo." << endl;
    cout << " [9] IF + 'nombre de archivo' + 'texto': Agrega contenido al archivo." << endl;
    cout << " [10] DF + 'nombre de archivo' + 'entero':  Elimina cantidad 'entero'  de  caracteres del archivo" << endl;
    cout << " [11] TYPE + 'nombre de archivo': Imprime en pantalla el contenido del archivo." << endl;
    cout << " [12] DESTRUIRSISTEMA: Elimina el sistema creado en el punto [1]." << endl;
    cout << endl;
    cout << " [=== ATENCION ===] Usar el comando EXIT para salir de la aplicacion." << endl;
    cout << endl;

    while(!fin){
        cout << " [Obligatorio-2-2016]> ";
        cin >> comando;

/*
DIR
*/
        if(strcmp(comando,"DIR") == 0 || strcmp(comando,"dir") == 0){
            cin >> parametro;
            retorno = DIR(sis,parametro);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n" << endl;
            }
        }
/*
CREATEFILE
*/
        else if(strcmp(comando,"CREATEFILE") == 0 || strcmp(comando,"createfile") == 0){
            cin >> parametro;
            retorno = CREATEFILE(sis,parametro);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n" << endl;
            }
        }
/*
DELETE
*/
        else if(strcmp(comando,"DELETE") == 0 || strcmp(comando,"delete") == 0){
            cin >> parametro;
            retorno = DELETE(sis,parametro);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n" << endl;
            }
        }
/*
ATTRIB
*/
        else if(strcmp(comando,"ATTRIB") == 0 || strcmp(comando,"attrib") == 0){
            cin >> parametro >> atributo;
            retorno = ATTRIB(sis,parametro,atributo);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n" << endl;
            }
        }
/*
IF
*/
        else if(strcmp(comando,"IF") == 0 || strcmp(comando,"if") == 0){
            cin >> parametro;
            cin.getline(atributo,TEXTO_MAX,'\n');
            retorno = IF(sis,parametro,atributo);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n";
            }
        }
/*
DF
*/
        else if(strcmp(comando,"DF") == 0 || strcmp(comando,"df") == 0){
            cin >> parametro >> k;
            retorno = DF(sis,parametro,k);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n";
            }
        }
/*
TYPE
*/
        else if(strcmp(comando,"TYPE") == 0 || strcmp(comando,"type") == 0){
            cin >> parametro;
            retorno = TYPE(sis,parametro);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n";
            }
        }
/*
CD
*/
        else if(strcmp(comando,"CD") == 0 || strcmp(comando,"cd") == 0){
            cin >> parametro;
            retorno = CD(sis,parametro);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n" << endl;
            }
        }
/*
MKDIR
*/
        else if(strcmp(comando,"MKDIR") == 0 || strcmp(comando,"mkdir") == 0){
            cin >> parametro;
            retorno = MKDIR(sis,parametro);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n" << endl;
            }
        }
/*
RMDIR
*/
        else if(strcmp(comando,"RMDIR") == 0 || strcmp(comando,"rmdir") == 0){
            cin >> parametro;
            retorno = RMDIR(sis,parametro);
            if(retorno == NO_IMPLEMENTADA){
                cout << "No implementada.\n\n" << endl;
            }
        }
/*
EXIT
*/
        else if(strcmp(comando,"EXIT") == 0 || strcmp(comando,"exit") == 0){
            cout << endl;
            cout << "Saliendo..." << endl << endl;
            fin = true;
        }else{
            cout << endl;
            cout << "No se reconoce el comando." << endl << endl;
        }
    }
    DESTRUIRSISTEMA(sis);
    return 0;
}
