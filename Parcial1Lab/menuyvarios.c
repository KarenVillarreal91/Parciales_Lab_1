#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "menuyvarios.h"


int menu(int flagOrdenado)
{
    int op;
        printf("------------- Menu principal -------------\n");
        printf(" 1- Cargar una mascota.\n");
        printf(" 2- Cargar una raza.\n");
        printf(" 3- Borrar una mascota.\n");
        printf(" 4- Modificar una mascota.\n");
        if(flagOrdenado % 2 == 0)       //Si es par o impar muestra si esta ordenado o no
        {
            printf(" 5- Ordenar por pais de origen.\n");
            printf(" 6- Listado completo.\n");
        }
        else
        {
            printf(" 5- Desornar lista.\n");
            printf(" 6- Listado completo. (Ordenado)\n");
        }
        printf(" 7- Listado de razas con sus mascotas.\n");
        printf(" 8- Mostrar el Pais de origen con mayor\n    cantidad de mascotas en la veterinaria.\n");
        printf(" 9- Salir.\n");
        printf("------------------------------------------\n");
        utn_getEntero(&op,1,"\nIngrese la opcion: ","\nError! Opcion invalida.\n\n",1,9);
        system("cls");

    return op;
}

char confirmar()
{
    char resp;

    utn_getCaracter(&resp,"\nDesea continuar? s/n: ","\n\nError! Ingrese una respuesta valida (s/n).\n\n",'n','s',0);

    return resp;
}
