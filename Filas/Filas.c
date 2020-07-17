#include <stdio.h>
#include <stdlib.h>
#include "Filas.h"

fila inic_fila (fila nueva)
{
    nueva.lista=inic_lista();
    nueva.fin_lista=inic_lista();

    return nueva;
}

int fila_vacia (fila acalificar)
{
    if (acalificar.lista == inic_lista() && acalificar.fin_lista == acalificar.lista)
        return 1;
    else
        return 0;
}




fila agregar_en_esta (fila _fila, nodo2* este_nodo)
{
    _fila.lista=agregar_al_final_de_esta(_fila.lista, este_nodo);
    _fila.fin_lista=este_nodo;
    return _fila;
}

fila eliminar_elemento_de_la (fila esta)
{
    if (esta.lista ==esta.fin_lista)
    {
        esta.lista=inic_lista();
        esta.fin_lista=inic_lista();
    }
    else
    {
    esta.lista=eliminar_primer_nodo_de_esta(esta.lista);

    }
    return esta;
}

void mostrar_fila (fila amostrar)
{
    if (!fila_vacia(amostrar))
    {
        recorrer_y_mostrar(amostrar.lista);
    }
    else
    {
        printf("Vacia/n");
    }
}






