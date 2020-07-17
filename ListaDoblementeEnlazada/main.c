#include <stdio.h>
#include <stdlib.h>
#include "Listas Dobles.h"

int main()
{
    nodo2* lista=inic_lista();
    lista=recuperar_lista_del_archivo();
    recorrer_y_mostrar(lista);

    return 0;
}
