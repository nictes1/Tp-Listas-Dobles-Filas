#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "ListasDobles.h"


typedef struct{
     persona dato;
     struct nodoDoble * anterior;
     struct nodoDoble * siguiente;
} nodoDoble;

nodoDoble * CrearNodoDoble(persona datos);
nodoDoble * BuscarUltimoNodoIterativo (nodoDoble * lista);
nodoDoble * BuscarUltimoNodoRecursivo (nodoDoble * lista);
nodoDoble * Agregar_Final_Doble (nodoDoble * lista, nodoDoble * nuevo);
void MostarListasDobles (nodoDoble * lista);
void MostarNodoDoble (nodoDoble * lista);                 ///REVISAR
nodoDoble * BorrarPrimeroNodoDoble (nodoDoble * lista);

nodoDoble * BuscarNodoEspecifico(nodoDoble * lista, int dato);

nodoDoble * BorrarNodoBuscadoChar(nodoDoble * lista, char nombre[]);

nodoDoble * BorrarNodoBuscado(nodoDoble * lista,int dato);

nodoDoble * Agregar_En_Orden_Doble (nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * BuscarUltimoNodoIterativo (nodoDoble * lista);
nodoDoble * Agregar_Principio_Doble (nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * IncializarListaDoble();


#endif // LISTASDOBLES_H_INCLUDED
