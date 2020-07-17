#include <stdio.h>
#include <stdlib.h>
#include "Filas.h"
int main()
{
    fila cola=inic_fila(cola);
    int i=0;
    for (i=0; i<5;i++)
    {
        nodo_archivo2 datos=cargar_nodo();
        cola=agregar_en_esta(cola, crear_nodo(datos));

    }
    while (!fila_vacia(cola))
    {
            getchar();
    system("cls");
    mostrar_fila(cola);
    cola=eliminar_elemento_de_la(cola);
    }
    system("cls");
    mostrar_fila(cola);

    return 0;
}
