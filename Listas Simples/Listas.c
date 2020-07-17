#include <stdio.h>
#include <stdlib.h>
#define m 10
#include "Listas.h"
const char ruta_al_archivo_de_la_lista [m]= {"lista"};


nodo* inic_nodo ()
{
    nodo* aux=NULL;
    return aux;
}

nodo* crear_nodo (nodo_archivo valores /*y cualquier otro campo que tengo el nodo*/)
{
    nodo* nuevo_nodo=(nodo*)malloc(sizeof (nodo));
    nuevo_nodo->campos=valores;
    nuevo_nodo->siguiente=inic_nodo();

    return nuevo_nodo;
}
nodo* sacar_copia_de (nodo* este)
{
    nodo* copia =crear_nodo(este->campos);
    return copia;
}
nodo* inic_lista ()
{
    nodo* retorno=NULL;
    return retorno;
}

nodo* agregar_al_principio_de_esta (nodo* lista, nodo* este_nodo)
{
    if (lista == inic_lista()) ///Si la lista ya esta vacia, simplemente ingreso el nodo.
    {
        lista=este_nodo;
    }
    else ///sino engancho el segundo a mi nuevo primer nodo, y ahora lista apunta este ultimo.
    {
        este_nodo->siguiente=lista;
        lista=este_nodo;
    }
    return lista; ///actualizo la informcion de la lista.
}



nodo* borrar_nodo (nodo* lista, int valor /*o cualquier otra cosa como criterio de busqueda*/)
{
    if (lista != inic_lista())
    {
        nodo* seguidora=lista;
        nodo* anterior=seguidora;
        if (lista->campos.valor == valor)
        {
            lista=lista->siguiente;
            free(seguidora);
        }
        else
        {
            while (seguidora != inic_nodo() && seguidora->campos.valor != valor)
            {
                anterior=seguidora;
                seguidora=seguidora->siguiente;
            }
            if (seguidora != inic_nodo())
            {
                anterior->siguiente=seguidora->siguiente;
                free(seguidora);
            }
            else
            {
                printf("No existe dicho nodo\n");
            }


        }

    }
    else
    {
        printf("La lista esta vacia\n");
    }
    return lista;
}


nodo* buscar_nodo (nodo* en_esta_lista, int con_este_valor)
{
    nodo* a_devolver=inic_lista();
    if (en_esta_lista == inic_lista())
        printf("La lista esta vacia\n");
    else
    {
        nodo* seguidora=en_esta_lista;
        while (seguidora != inic_nodo() && seguidora->campos.valor != con_este_valor)
        {
            seguidora=seguidora->siguiente;
        }
        if (seguidora == inic_nodo())
            printf("No existe nodo con ese valor\n");
        else
        {
            a_devolver=seguidora;
        }


    }
    return a_devolver;
}

nodo* ultimo_nodo (nodo* lista)
{
    nodo* seguidora=lista;
    while (seguidora != inic_lista() && seguidora->siguiente != inic_lista())
    {
        seguidora=seguidora->siguiente;
    }
    return seguidora;
}

nodo* agregar_al_final_de_esta (nodo* lista, nodo* este_nodo)
{

    if (lista != inic_lista())
    {
        nodo* seguidora=ultimo_nodo(lista);
        seguidora->siguiente=este_nodo;
    }
    else
    {
        lista=este_nodo;
    }

    return lista;
}

nodo* agregar_en_orden_en_esta (nodo* lista, nodo* este_nodo)
{
    if (lista == inic_lista() )
        lista=este_nodo;
    else
    {
        if (este_nodo->campos.valor < lista->campos.valor)
        {
            lista=agregar_al_principio_de_esta(lista, este_nodo);

        }
        else
        {
            nodo* seguidora=lista;
            nodo* anterior=seguidora;
            while (seguidora != inic_lista() && este_nodo->campos.valor > seguidora->campos.valor)
            {
                anterior=seguidora;
                seguidora=seguidora->siguiente;
            }
            if (seguidora != inic_lista())
            {
                anterior->siguiente=este_nodo;
                este_nodo->siguiente=seguidora;

            }
            else
            {
                lista=agregar_al_final_de_esta(lista, este_nodo);
            }

        }
    }

    return lista;

}

nodo* borrar_lista (nodo* esta)
{

    nodo* seguidora=esta;
    nodo* anterior=seguidora;
    if (esta==inic_lista())
        printf("La lista ya esta vacia\n");
    else
    {

        while (seguidora != inic_lista())
        {
            seguidora=seguidora->siguiente;
            free(anterior);
            anterior=seguidora;
        }
    }

    return seguidora;
}

nodo* sumar_campo_de_esta_ (nodo* lista)
{
    int suma=0;
    nodo* seguidora=lista;
    while (seguidora != inic_lista())
    {
        suma=suma+seguidora->campos.valor;
        seguidora=seguidora->siguiente;
    }


    return suma;
}

nodo* eliminar_primer_nodo_de_esta (nodo* lista)
{
    nodo* seguidora=lista;
    lista=lista->siguiente;
    free(seguidora);

    return lista;
}

nodo* eliminar_ultimo_nodo_de_esta(nodo* lista)
{
    nodo* seguidora=lista;
    nodo* anterior=seguidora;
    if (lista != inic_lista())
    {

        while (seguidora->siguiente != inic_lista() )
        {
            anterior=seguidora;
            seguidora=seguidora->siguiente;
        }
        anterior->siguiente=inic_nodo();
        free(seguidora);
    }

    return lista;
}

void mostrar_nodo (nodo* a_mostrar)
{
    if (a_mostrar != inic_nodo())
        printf ("| %i |", a_mostrar->campos.valor);

}

void recorrer_y_mostrar (nodo* lista)
{
    nodo* seguidora=lista;
    printf(">");
    while (seguidora != inic_lista())
    {
        mostrar_nodo(seguidora);
        seguidora=seguidora->siguiente;
    }
    printf("<\n");
}


nodo* cargar_datos_al_final_de_esta (nodo* lista)
{
    nodo* seguidora=ultimo_nodo(lista);
    seguidora->campos=cargar_nodo();

    return lista;

}


nodo_archivo cargar_nodo ()
{
    nodo_archivo nuevos_valores;
    printf ("Ingrese un valor entero\n");
    scanf ("%i", &nuevos_valores.valor);

    return nuevos_valores;
}

nodo* cargar_datos_al_principio_de_esta(nodo* lista)
{
    lista->campos=cargar_nodo();

    return lista;
}

void guardar_lista_en_un_archivo (nodo* lista)
{
    nodo* seguidora=lista;
    FILE* puntero_al_archivo=fopen (ruta_al_archivo_de_la_lista, "wb");
    while (seguidora != inic_lista())
    {
        fwrite (&seguidora->campos, sizeof(nodo_archivo), 1, puntero_al_archivo);
        seguidora=seguidora->siguiente;
    }
}

nodo* recuperar_lista_del_archivo ()
{
    nodo_archivo registro;
    nodo* nuevo_nodo;
    nodo* lista=inic_lista();
    FILE* puntero_al_archivo=fopen (ruta_al_archivo_de_la_lista, "rb");
    while (fread(&registro, sizeof(nodo_archivo), 1, puntero_al_archivo)>0)
    {
        nuevo_nodo=crear_nodo(registro);
        lista=agregar_al_final_de_esta(lista, nuevo_nodo);
    }

    return lista;
}

nodo* crear_lista_ordenada ()
{
    char control='s';
    nodo* lista=inic_lista();
    while (control!= 'n')
    {
        lista=agregar_en_orden_en_esta(lista, crear_nodo(cargar_nodo()));
        printf ("\nDesea cargar otro nodo? s/n\n");
        fflush (stdin);
        scanf("%c", &control);
    }

    return lista;
}

int menu ()
{
    int operacion;
    printf("1. Crear lista ordenada (borra la anterior)\n"
           "2. Agregar nodo al principio\n"
           "3. Agregar nodo al final\n"
           "4. Mostrar la lista\n"
           "5. Guardar la lista\n"
           "6. Borrar primer nodo\n"
           "7. Borrar ultimo nodo\n"
           "8. Borrar nodo por dato\n"
           "9. Sobrescribir TODOS los campos de un nodo\n"
           "0. Salir\n");
    printf("Seleccione una opcion:\t");
    scanf("%i", &operacion);
    system("pause");
    system("cls");
    return operacion;
}

nodo* invertir_lista(nodo* lista)
{
    nodo* seguidora=lista;
    nodo* lista_invertida=inic_lista();
    while (seguidora != inic_lista())
    {
        lista_invertida=agregar_al_principio_de_esta(lista_invertida, sacar_copia_de(seguidora));
        seguidora=seguidora->siguiente;
    }
    return lista_invertida;
}

