#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotasyrazas.h"
#define VACIO 0
#define OCUPADO 1


int buscarLibreRaza(eRaza list[],int len)
{
    int i;
    int retorno = -1;

    for(i = 0; i < len; i++)        //Recorre el cupo y asigna el indice
    {
        if(list[i].isEmpty == VACIO)       //Verifica que el espacio este vacio
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

eRaza sacarRazaPorId(eRaza list[], int id, int len)
{
    int i;

    eRaza raza;

    for(i = 0; i < len; i++)
    {
        if(list[i].idRaza == id && list[i].isEmpty == OCUPADO)      //Busca comparando la ID ingresada
        {
            raza = list[i];     //Lo encuentra y asigna
        }
    }

    return raza;
}

void mostrarRazas(eRaza listRaza[],int lenRaza)
{
    int i;

    printf("\n%57s\n","-------------- Listado de Razas ---------------");
    printf("%14s %10s %14s %10s\n","ID","Raza","Tamanio","Pais");
    printf("%57s\n","-----------------------------------------------");

    for(i = 0; i < lenRaza; i++)
    {
        if(listRaza[i].isEmpty == OCUPADO)
        {
            mostrarUnaRaza(listRaza[i]);
        }
    }
}

void mostrarUnaRaza(eRaza listRaza)
{
   printf("%14d     %-14s %-10s %-12s\n",listRaza.idRaza,listRaza.descripcion,listRaza.tamanio,listRaza.pais);
}

int agregarRaza(eRaza listRaza[],int lenRaza,char descripcion[], char tamanio[],char pais[],int idRaza)
{
    int retorno = -1;
    char resp;
    int indice = buscarLibreRaza(listRaza,lenRaza);

    if(indice != -1)
    {
        resp = confirmar();         //Confirma que el usario esta seguro de agregar a la raza

        if(resp == 's')         //Si reponde "s" continua y asigna los valores ingresados
        {
            strcpy(listRaza[indice].descripcion,descripcion);
            strcpy(listRaza[indice].tamanio,tamanio);
            strcpy(listRaza[indice].pais,pais);
            listRaza[indice].idRaza = idRaza;
            listRaza[indice].isEmpty = OCUPADO;

            retorno = 0;
        }
    }
    else
    {
        printf("\nYa no hay espacio libre para agregar una nueva raza.\n\n");
    }

    return retorno;
}

int crearRaza(eRaza listRaza[],int idRaza,int lenRaza)
{
    char descripcion[51];
    char tamanio[51];
    char pais[51];

    int retorno = -1;

    if(utn_getCadena(descripcion,51,0,"Ingrese el nombre de la Raza: ","\n\nError! Nombre invalido\n") == 0)
    {
        if(pedirTipo(tamanio,51,0,"Ingrese el tamanio (Chico, Mediano, Grande): ","\n\nError! Tamanio invalido\n","Chico","Mediano","Grande") == 0)
        {
            if(utn_getCadena(pais,51,0,"Ingrese el pais de origen: ","\n\nError! Pais invalido\n") == 0)
            {
                retorno = agregarRaza(listRaza,lenRaza,descripcion,tamanio,pais,idRaza);    //Llama a funcion para asignar los datos

                if(retorno == 0)        //Si se asigno correctamente informa y finaliza
                {
                    printf("\nRaza agregada correctamente.\n\n");
                }
                else
                {
                    printf("\nNo se registrara a la raza.\n\n");
                }
            }
        }
    }

    return retorno;
}

void hardCodearRazas(eRaza listado[])
{
    char arrayDescripcion[4][51]={"Siames","Doberman","Persa","Pastor Belga"};
    char arrayTamanio[4][51]={"Chico","Grande","Mediano","Grande"};
    char arrayPais[4][51]={"Tailandia","Alemania","Persia","Belgica"};
    int isEmpty[4] = {1,1,1,1};
    int idRaza[4] = {101,102,103,104};

    int i;

    for(i = 0; i < 4; i++)
    {
        strcpy(listado[i].descripcion,arrayDescripcion[i]);
        strcpy(listado[i].tamanio,arrayTamanio[i]);
        strcpy(listado[i].pais,arrayPais[i]);
        listado[i].isEmpty = isEmpty[i];
        listado[i].idRaza = idRaza[i];
    }
}
