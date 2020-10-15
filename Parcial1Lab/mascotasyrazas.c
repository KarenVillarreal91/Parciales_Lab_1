#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotasyrazas.h"
#define VACIO 0
#define OCUPADO 1


int setearEnVacio(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza)
{
    int i;
    int j;
    int retorno = -1;

    for(i = 0; i < lenMascota; i++)        //Recorre el cupo de mascotas seteado en VACIO
    {
        listMascota[i].isEmpty = VACIO;

        for(j = 0; j < lenRaza; j++)        //Recorre el cupo de razas seteando en VACIO
        {
            listRaza[j].isEmpty = VACIO;
            retorno = 0;
        }
    }

    return retorno;
}

void ordenarPorPais(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza)
{
    int i;
    int j;

    eMascota auxMascota;
    eRaza auxRaza[lenMascota];

    for(i = 0; i < lenMascota-1; i++)
    {
        auxRaza[i] = sacarRazaPorId(listRaza,listMascota[i].idRaza,lenRaza);

        for(j = i+1; j < lenMascota; j++)
        {
            auxRaza[j] = sacarRazaPorId(listRaza,listMascota[j].idRaza,lenRaza);

            if(auxRaza[i].isEmpty == OCUPADO && auxRaza[j].isEmpty == OCUPADO)
            {
                if(strcmp(auxRaza[i].pais,auxRaza[j].pais) > 0)     //Compara por pais
                {
                    auxMascota = listMascota[i];
                    listMascota[i] = listMascota[j];
                    listMascota[j] = auxMascota;
                }
            }
        }
    }
}

void mostrarMascotas(eMascota listMascota[], eRaza listRaza[], int lenRaza, int lenMasc)
{
    int i;

    eRaza raza;

    printf("\n%92s\n","--------------------------------- Listado de mascotas ---------------------------------");
    printf("%9s %11s %8s %7s %8s %16s %11s %8s\n","ID","Nombre","Edad","Sexo","Tipo","Descripcion","Tamanio","Pais");
    printf("%92s\n","---------------------------------------------------------------------------------------");

    for(i = 0; i < lenMasc; i++)
    {
        if(listMascota[i].isEmpty == OCUPADO)
        {
            raza = sacarRazaPorId(listRaza,listMascota[i].idRaza,lenRaza);      //Obtiene la raza de la mascota
            mostrarUnaMascotaConRaza(listMascota[i],raza);
        }
    }
}

void mostrarRazaConMascotas(eRaza listRaza[],eMascota listMascota[],int lenMasc,int lenRaza)
{
    int iMascota;
    int iRaza;
    int flagAlmenosUno = 0;

    printf("\n%42s","| Listado de razas |");

    for(iRaza = 0; iRaza < lenRaza; iRaza++)
    {
        if(listRaza[iRaza].isEmpty == OCUPADO)
        {
            printf("\n\n%27s  %s  %s\n","----",listRaza[iRaza].descripcion,"----");     //Muestra el nombre de la raza
            printf("%14s %10s %9s %9s %9s\n","ID","Nombre","Edad","Sexo","Tipo");
            printf("%57s\n","-----------------------------------------------");

            for(iMascota = 0; iMascota < lenMasc; iMascota++)
            {
                if(listMascota[iMascota].idRaza == listRaza[iRaza].idRaza && listMascota[iMascota].isEmpty == OCUPADO)      //Compara por id
                {
                    mostrarUnaMascota(listMascota[iMascota]);       //Muestra las mascotas

                    flagAlmenosUno = 1;     //Se activa la flag si se muestra al menos 1
                }
            }

            if(flagAlmenosUno == 0)     //Si no se muestra ninguno informa
            {
                printf("%47s\n","No hay mascotas con esta raza.");
            }
        }

        flagAlmenosUno = 0;
    }
}

void mostrarUnaMascotaConRaza(eMascota listMascota, eRaza listRaza)
{
    printf("%9d      %-11s %-7d %-7c %-9s %-15s %-10s %-12s\n",listMascota.idMascota,listMascota.nombre,listMascota.edad,listMascota.sexo,
            listMascota.tipo,listRaza.descripcion,listRaza.tamanio,listRaza.pais);
}

void paisDeOrigen(eRaza listRaza[],eMascota listMascota[],int lenRaza,int lenMascota)
{
    int contador;
    int indiceMaximoActual = 0;
    int flagMax = 0;
    char arrayPais[20][51];
    int arrayCantidad[20];
    char maximoPais[51];
    int maximoCantidad;

    for(int i = 0; i < lenRaza; i++)
    {
        contador = 0;       //Cada vez que pasa una raza nueva se reinicia el contador

        for(int j = 0;j < lenMascota;j++)
        {
            if(listMascota[j].isEmpty == OCUPADO && listMascota[j].idRaza == listRaza[i].idRaza)    //Compara la id de la raza con la id de mascota
            {
                contador++;
            }
        }

        if(listRaza[indiceMaximoActual].isEmpty == OCUPADO)     //Si la raza esta ocupada asigna
        {
            strcpy(arrayPais[indiceMaximoActual],listRaza[i].pais);
            arrayCantidad[indiceMaximoActual] = contador;

            indiceMaximoActual++;
        }
    }

    for(int i = 0; i < indiceMaximoActual-1; i++)
    {
        for(int j = i+1; j < indiceMaximoActual; j++)
        {
            if(strcmp(arrayPais[i],arrayPais[j]) == 0)      //Compara si hay paises iguales
            {
                arrayCantidad[i] += arrayCantidad[j];       //Si son iguales suma las cantidades de mascotas
            }
        }
    }

    for(int k = 0; k < indiceMaximoActual; k++)
    {
            if(!flagMax)        //Si es la primera vez asigna los maximos
            {
                maximoCantidad = arrayCantidad[k];
                strcpy(maximoPais,arrayPais[k]);
                flagMax = 1;
            }
            else
            {
                if(arrayCantidad[k] > maximoCantidad)       //Compara, busca el maximo y asigna
                {
                    maximoCantidad = arrayCantidad[k];
                    strcpy(maximoPais,arrayPais[k]);
                }
            }

    }

    printf("\n              |Pais con mayor cantidad de animales|\n");
    printf("\n%45s\n","--------- Datos ---------");
    printf("%28s %13s","Pais","Cantidad");
    printf("\n%45s","-------------------------");
    printf("\n%30s %7d\n",maximoPais,maximoCantidad);
}
