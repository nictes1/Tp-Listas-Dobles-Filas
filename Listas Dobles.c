#include "ListasDobles.h"
#include "Persona.h"
#include <string.h>

///INICIALIZACION DE LA LISTA.
nodoDoble * IncializarListaDoble()
{
    return  NULL;
}


///FUNCION PARA CREAR NODO NUEVO
nodoDoble * CrearNodoDoble(persona datos)
{
    nodoDoble * aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato = datos;

    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

/// AGREGAR AL PRINCIPIO DE UN LISTA (POR EL INICIO)

nodoDoble * Agregar_Principio_Doble (nodoDoble * lista, nodoDoble * nuevo)
{
    nuevo->siguiente = lista;

    if(lista)
    {
        lista->anterior = nuevo;
    }

    return nuevo;
}

/// FUNCION QUE BUSCA EL ULTIMO NODO DE FORMA ITERATIVA

nodoDoble * BuscarUltimoNodoIterativo (nodoDoble * lista)   ///ANDUVO
{
    nodoDoble * aux = lista;

    if(aux)
    {
        while(aux->siguiente!=NULL)
        {
            aux = aux->siguiente;
        }
    }
    return aux;
}


///fUNCION PARA BUSACAR EL ULTIMO ELEMENTO DE FORMA RECURSIVA
nodoDoble * BuscarUltimoNodoRecursivo (nodoDoble * lista)    ////ANDUVO

{
    nodoDoble * aux;

    if(!lista)
    {
        aux = NULL;
    }
    else
    {
        if(!lista->siguiente)
        {
            aux = lista;
        }
        else
        {
            aux=BuscarUltimoNodoRecursivo(lista->siguiente);
        }
    }

    return aux;
}


//FUNCION PARA AGREGAR AL FINAL DE LA LISTA. (FONDO DE LA LISTA)
nodoDoble * Agregar_Final_Doble (nodoDoble * lista, nodoDoble * nuevo)
{
    nodoDoble * aux = lista;

    if(!aux)
    {
        aux = nuevo;
    }
    else
    {
        nodoDoble * ultimo = BuscarUltimoNodoIterativo(aux);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return aux;
}


///fUNCION DE AGREGAR DATOS EN ORDEN.

nodoDoble * Agregar_En_Orden_Doble (nodoDoble * lista, nodoDoble * nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        if(strcmp(nuevo->dato.nombre, lista->dato.nombre)<0)
        {
            lista = Agregar_Principio_Doble(lista, nuevo);
        }
        else
        {
            nodoDoble * ante = lista;
            nodoDoble * prox = lista->siguiente;

            while(lista && strcmp(nuevo->dato.nombre, lista->dato.nombre)>0)
            {
                ante = prox;
                prox = prox ->siguiente;
            }

            ante->siguiente = nuevo;
            nuevo->anterior = ante;
            nuevo->siguiente = prox;

            if(prox)
            {
                prox->anterior = nuevo;
            }
        }
    }

    return lista;
}

///FUNCION QUE BORRAR UN NODO DE LA LISTA, SE NECESITAN EN OS PARAMETROS EL NOMBRE DE LA PERSONA QUE SE DESEA ELIMIR DE LA LISTA.
nodoDoble * BorrarNodoBuscadoChar (nodoDoble * lista, char nombre[])
{

    nodoDoble * seg = lista;
    nodoDoble * aux;

        if(seg!= NULL && (strcmpi(seg->dato.nombre, nombre)==0))
        {
            aux = seg;
            seg = seg->siguiente;
            seg->anterior = NULL;

            free(aux);
        }
        else
        {
            nodoDoble * ante;

            while(seg->siguiente!=NULL && (strcmpi(seg->dato.nombre, nombre)!=0))
            {
                seg = seg->siguiente;
            }

                if(seg->siguiente!=NULL && (strcmpi(seg->dato.nombre, nombre)==0))
                {
                    aux = seg; /// se baja el dato

                    ante = seg->anterior; /// se copia el anterior de seg en ante
                    seg = seg->siguiente; /// muevo seg a su siguiente

                    ante->siguiente = seg;  /// Vinculo el siguiente del anterio con seg
                    seg->anterior = ante;   /// vinculo el anterior del siguiente que voy a borrar con ante.

                    free(aux); /// Borro el nodo.
                }
                else if(!seg->siguiente && (strcmpi(seg->dato.nombre, nombre)==0))
                {
                           ante=seg->anterior;
                           ante->siguiente = NULL;
                           free(seg);
                }
                else
                {
                    printf("\n No se encontro el dato.");
                }



        }

    return lista;
}

nodoDoble * BorrarNodoBuscado(nodoDoble * lista, int dato)
{
    if(lista != NULL && dato == lista->dato.edad)
    {
        nodoDoble * aux = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        free(aux);
    }
    else
    {
        nodoDoble * anterior;
        nodoDoble * seg = lista;
        while(seg != NULL && dato!=seg->dato.edad)
        {
            anterior = seg;
            seg = seg->siguiente;
        }

        if(seg)
        {
            nodoDoble * aux = seg;
            anterior->siguiente = seg->siguiente;
            seg->anterior = anterior;
            free(aux);
        }
    }

    return lista;
}


///BUSCAR EL NODO ESPECIFICO, RECIBE COMO PARAMETRO EL NOMBRE QUE SE DESEA BUSCAR EN LA LISTA
nodoDoble * BuscarNodoEspecifico(nodoDoble * lista, int dato)
{

    nodoDoble * buscado = lista;


        while(buscado!=NULL && buscado->dato.edad != dato)
        {
            buscado = buscado->siguiente;
        }

    return buscado;
}

///BORRAR EL PRIMER NODO DE UNA LISTA DOBLE
nodoDoble * BorrarPrimeroNodoDoble (nodoDoble * lista)
{
    nodoDoble * aux = lista;

    if(aux)
    {
        if(aux->siguiente)
        {
            lista->anterior = NULL;
            lista = lista->siguiente;
            free(aux);
        }

    }

    return lista;
}
//MOSTAR NODO UTILIZA LA FUNCION DE PERSONA

void MostarNodoDoble (nodoDoble * lista)
{
    mostrarPersonas(lista->dato); ///funcion
    printf(" siguiente->%i \n", lista->siguiente);
    printf(" anterior->%i \n\n", lista->anterior);
}
//MOSTRAR LA LISTA COMPLETA, UILIZA MOSTAR NODO
void MostarListasDobles (nodoDoble * lista)
{
    nodoDoble * aux = lista;

    if(aux)
    {
        while(aux!=NULL)
        {
            MostarNodoDoble(aux);  //funcion
            aux = aux->siguiente;
        }
    }
}
















































































































































