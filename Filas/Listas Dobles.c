#include <stdio.h>
#include <stdlib.h>
#include "Listas Dobles.h" /*Es el header librerias de Listas Dobles*/
#include "string.h"
const char nombre_del_archivo_donde_se_guarda_la_lista [n]= {"lista.bin"};
nodo2* inic_nodo ()
{
    return NULL;
}

nodo2* inic_lista ()
{
    return NULL;
}

nodo2* crear_nodo (nodo_archivo2 datos_para_crear_el_nodo)
{
    nodo2* nuevo_nodo=(nodo2*)malloc(sizeof(nodo2));
    nuevo_nodo->campos=datos_para_crear_el_nodo;
    nuevo_nodo->siguiente =inic_nodo();
    nuevo_nodo->anterior=inic_nodo();
    return nuevo_nodo;
}

nodo_archivo2 cargar_nodo ()
{
    nodo_archivo2 datos;
    printf("Ingrese el nombre\n");
    fflush(stdin);
    gets(datos.nombre);
    printf("Ingrese la edad\n");
    fflush(stdin);
    scanf("%d", &datos.edad);

    return datos;
}

void mostrar_nodo (nodo2* a_mostrar)
{
    if (a_mostrar != inic_nodo())
    {
        printf("%s\n", a_mostrar->campos.nombre);
        printf("%d\n", a_mostrar->campos.edad);

    }
    else
        printf("NULL\n");
}

void recorrer_y_mostrar (nodo2* lista)
{
    if (lista != inic_lista())
    {

        nodo2* seguidora=lista;
        while (seguidora != inic_lista())
        {
            mostrar_nodo(seguidora);
            seguidora=seguidora->siguiente;
        }
    }
    else
    {
        printf("Lista vacia\n");
    }
}


nodo2* agregar_al_principio_de_esta (nodo2* lista, nodo2* este_nodo)
{
    if (lista == inic_lista())
    {
        lista=este_nodo; ///Sino hay nodos, lo agrego al principio directamente.
    }
    else
    {
        este_nodo->siguiente=lista;
        este_nodo->anterior=inic_nodo();
        lista->anterior=este_nodo;
        lista=este_nodo;
    }
    return lista;
}

nodo2* ultimo_nodo_de_esta (nodo2* lista)
{
    nodo2* seguidora=lista;
    if (seguidora == inic_lista())
    {
        printf("La lista esta vacia\n");
    }
    else
    {
        while (seguidora->siguiente != inic_lista())
        {
            seguidora=seguidora->siguiente;
        }
    }
    return seguidora;
}


nodo2* agregar_al_final_de_esta(nodo2* lista,nodo2* este_nodo)
{
    if (lista == inic_lista())
        lista=este_nodo;
    else
    {
        nodo2* seguidora=ultimo_nodo_de_esta(lista);
        este_nodo->anterior=seguidora;
        seguidora->siguiente=este_nodo;

    }
    return lista;
}

nodo2* agregar_en_orden_en_esta (nodo2* lista, nodo2* este_nodo)
{

    if (lista == inic_lista() || este_nodo->campos.edad<lista->campos.edad)
    {
        lista=agregar_al_principio_de_esta(lista, este_nodo);
    }
    else
    {
        nodo2* seguidora= lista;
        while (seguidora != inic_lista() && seguidora->campos.edad < este_nodo->campos.edad)
        {
            seguidora=seguidora->siguiente;
        }
        if (seguidora != inic_lista())
        {
            nodo2* aux = seguidora->anterior;
            aux->siguiente=este_nodo;
            este_nodo->siguiente=seguidora;
            seguidora->anterior=este_nodo;
            este_nodo->anterior=aux;
        }
        else
        {
            lista=agregar_al_final_de_esta(lista, este_nodo);
        }
    }
    return lista;
}

nodo2* eliminar_primer_nodo_de_esta (nodo2* lista)
{
    if (lista != inic_lista())
    {
        nodo2* seguidora=lista;
        lista=lista->siguiente;
        lista->anterior=inic_nodo();
        free(seguidora);
    }
    else
    {
        printf("La lista esta vacia\n");
    }

    return lista;
}

nodo2* eliminar_ultimo_nodo_de_esta(nodo2* lista)
{
    if (lista != inic_lista())
    {
        nodo2* seguidora=ultimo_nodo_de_esta(lista);
        nodo2* aux=seguidora->anterior;
        aux->siguiente=inic_nodo();
        free(seguidora);
    }
    else
    {
        printf("La lista esta vacia\n");
    }
    return lista;
}

nodo2* borrar_nodo_de_esta (nodo2* lista, int con_este_campo)
{
    if (lista==inic_lista() || con_este_campo == lista->campos.edad)
    {
        lista=eliminar_primer_nodo_de_esta(lista);
    }
    else
    {
        nodo2* seguidora=lista;
        while (seguidora != inic_lista() && con_este_campo != seguidora->campos.edad)
        {
            seguidora=seguidora->siguiente;
        }
        if (seguidora != inic_lista())
        {
            nodo2* aux=seguidora->anterior;
            aux->siguiente=seguidora->siguiente;
            nodo2* aux2=seguidora->siguiente;
            aux2->anterior=seguidora->anterior;
            free(seguidora);
        }
        else
        {
            printf("El nodo no existe en esta lista\n");
        }
        return lista;
    }


}

nodo2* borrar_lista (nodo2* lista)
{
    nodo2* seguidora=lista;
    nodo2* anterior=seguidora;
    while (seguidora != inic_lista())
    {
        anterior=seguidora;
        seguidora=seguidora->siguiente;
        free(anterior);
    }
    lista=inic_lista();
    return lista;
}

nodo2* buscar_nodo_en_esta (nodo2* lista, int con_este_campo )
{
    nodo2* seguidora=lista;
    if (lista != inic_lista())
    {

        while (seguidora != inic_lista() && con_este_campo != seguidora->campos.edad)
        {
            seguidora=seguidora->siguiente;
        }
        if (seguidora == inic_lista())
        {
            printf("El nodo no existe en esta lista\n");
        }
    }
    else
    {
        printf("La lista esta vacia\n");
    }
    return seguidora; ///devuelvo la direccion del nodo  o null si no esta, de topdas formas son valores validos y si la lista est vcia no l modifica
}

int sumar_campo_del_los_nodos_de_esta (nodo2* lista)
{
    int sumatoria=0;
    nodo2* seguidora= lista;
    if(lista != inic_lista())
    {
        while (seguidora != inic_lista())
        {
            sumatoria=sumatoria+seguidora->campos.edad;
            seguidora=seguidora->siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia, sumatoria es igual 0\n");
    }
    return sumatoria;
}

void guardar_en_un_archivo_esta (nodo2* lista)
{
    if (lista != inic_lista())
    {
        nodo_archivo2 variable_para_guardar_los_nodos_en_un_archivo;
        nodo2* seguidora=lista;
        FILE* puntero_al_archivo=fopen( nombre_del_archivo_donde_se_guarda_la_lista, "wb"); ///sobrescribo para asi actualizar la lista en el archivo
        while (seguidora != inic_lista())
        {
            variable_para_guardar_los_nodos_en_un_archivo=seguidora->campos;
            fwrite(&variable_para_guardar_los_nodos_en_un_archivo, sizeof(nodo_archivo2), 1, puntero_al_archivo );
            seguidora=seguidora->siguiente;
        }
        fclose(puntero_al_archivo);
    }
    else
    {
        printf("La lista esta vacia\n");
    }

}
nodo2* recuperar_lista_del_archivo()
{
    nodo2* lista_nueva=inic_lista();
    nodo_archivo2 variable_para_rearmar_la_lista;
    FILE* puntero_al_archivo=fopen(nombre_del_archivo_donde_se_guarda_la_lista, "rb");
    nodo2* nuevo_nodo;
    if (puntero_al_archivo != NULL)
    {
        while (fread(&variable_para_rearmar_la_lista, sizeof (nodo_archivo2), 1, puntero_al_archivo)>0)
        {
            nuevo_nodo=crear_nodo(variable_para_rearmar_la_lista);
            lista_nueva=agregar_al_final_de_esta(lista_nueva, nuevo_nodo);
        }

    }
    else
    {
        printf("Error al acceder al archivo de la lista\n");
    }
    fclose(puntero_al_archivo);

    return lista_nueva;
}

nodo2* cargar_datos_al_primer_nodo_de_esta (nodo2* lista)
{
    lista->campos=cargar_nodo();
    return lista;
}

nodo2* cargar_datos_al_ultimo_nodo_de_esta(nodo2* lista)
{
    nodo2* seguidora=ultimo_nodo_de_esta(lista);
    seguidora->campos=cargar_nodo();
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

nodo2* invertir_lista (nodo2* lista)
{
    nodo2* lista_invertida=inic_lista();
    nodo2* proximo=lista;

    if (lista != inic_lista())
    {
        while (proximo != inic_lista())
        {
            lista_invertida=agregar_al_principio_de_esta(lista_invertida, sacar_copia_de_este(proximo));

            proximo=proximo->siguiente;
        }

    }
    else
    {
        printf("La lista esta vacia.\n");
    }

    return lista_invertida;
}

nodo2* sacar_copia_de_este (nodo2* este_nodo)
{
    nodo2* copia=inic_nodo();
    if (este_nodo != inic_nodo())
    {
        copia=crear_nodo(este_nodo->campos);
    }
    return copia;
}

nodo2* crear_lista_ordenada ()
{
    nodo2* lista=inic_lista();
    nodo_archivo2 datos;
    char control='s';
    do
    {
        datos=cargar_nodo();
        lista=agregar_en_orden_en_esta(lista, crear_nodo(datos));
        printf("Desea cargar otro nodo? s/n\n");
        fflush(stdin);
        control=getchar();
    }while (control=='s');
    return lista;
}












