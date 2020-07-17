#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED
#define m 30
#define n 15

typedef struct
{
    char nombre [m];
    unsigned int edad;
}nodo_archivo2;

typedef struct
{
    nodo_archivo2 campos;
    struct nodo2* siguiente;
    struct nodo2* anterior;
}nodo2;

nodo2* inic_nodo ();
nodo2* inic_lista ();
nodo2* crear_nodo (nodo_archivo2);
nodo_archivo2 cargar_nodo ();
nodo2* agregar_al_principio_de_esta (nodo2*, nodo2* );
nodo2* agregar_al_final_de_esta(nodo2*, nodo2*);
nodo2* agregar_en_orden_en_esta (nodo2* , nodo2* );
nodo2* eliminar_primer_nodo_de_esta (nodo2* );
nodo2* borrar_nodo_de_esta (nodo2*, int);
nodo2* borrar_lista (nodo2*);
int sumar_campo_del_los_nodos_de_esta (nodo2*);
void guardar_en_un_archivo_esta (nodo2* );
nodo2* recuperar_lista_del_archivo();
nodo2* cargar_datos_al_primer_nodo_de_esta (nodo2*);
nodo2* cargar_datos_al_ultimo_nodo_de_esta(nodo2* );
int menu ();
nodo2* invertir_lista (nodo2* );
nodo2* sacar_copia_de_este (nodo2* );
nodo2* crear_lista_ordenada ();






#endif // LISTAS_DOBLES_H_INCLUDED
