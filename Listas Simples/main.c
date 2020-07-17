#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"

int main ()
{
    nodo* lista=inic_lista();
    lista=recuperar_lista_del_archivo();
    recorrer_y_mostrar(lista);
    //guardar_lista_en_un_archivo(lista);

    return 0;
}
