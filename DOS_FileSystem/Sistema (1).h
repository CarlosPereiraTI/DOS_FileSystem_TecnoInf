#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include "Tools.h"
#include "ArbolDirectorios.h"

struct _sistema;
typedef _sistema* Sistema;

TipoRet DIR (Sistema &s, Cadena parametro);
TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo);
TipoRet DELETE (Sistema &s, Cadena nombreArchivo);
TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro);
TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto);
TipoRet DF (Sistema &s, Cadena nombreArchivo, int k);
TipoRet TYPE (Sistema &s, Cadena nombreArchivo);

TipoRet CD(Sistema &s, Cadena nombreDirectorio);
TipoRet MKDIR(Sistema &s, Cadena nombreDirectorio);
TipoRet RMDIR(Sistema &s, Cadena nombreDirectorio);
TipoRet CREARSISTEMA(Sistema &s);
TipoRet DESTRUIRSISTEMA(Sistema &s);

#endif // SISTEMA_H_INCLUDED
