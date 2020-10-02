#include "TPListasDobles.h"
#include "ListasDobles.h"

//1-Modificar la función borrarNodo() de listas simples y transformarla para el caso de una lista doblemente vinculada.
//ya esta hecha en el tda

//2

//3 elminar nodo p medio
nodoDoble * EliminarNodoMedio(nodoDoble * lista)
{
    if(lista)
    {
        if(lista->siguiente == NULL)
        {
            free(lista);
            lista = InicializarListaDoble();
        }
        else
        {
            nodoDoble * inic = lista;
            nodoDoble * fin = BuscarUltimoNodoIterativo(lista);
            while(inic != fin && fin->siguiente != inic)
            {
                inic = inic->siguiente;
                fin = fin->anterior;
            }

            nodoDoble * ante = inic->anterior;
            ante->siguiente = inic->siguiente;

            if(inic->siguiente) //ult nodo
            {
                nodoDoble * seg = ante->siguiente; //!ultimo
                seg->anterior = ante;
            }
            free(inic);
        }
    }
    return lista;
}

