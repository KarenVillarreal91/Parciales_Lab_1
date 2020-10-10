#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Funciones.h"
#define VACIO 0
#define OCUPADO 1

int menu()
{
    int op;
        printf("------------- Menu principal -------------\n");
        printf("1- Cargar una mascota.\n");
        printf("2- Borrar una mascota.\n");
        printf("3- Mostrar mascotas.\n");
        printf("4- Salir.\n");
        printf("------------------------------------------\n");
        utn_getEntero(&op,1,"Ingrese la opcion: ","\nError! Opcion invalida.\n\n",1,10);

    return op;
}

int inicializarMascotas(eMascota list[], int len)
{
    int i;
    int retorno = -1;

    for(i = 0; i < len; i++)        //Recorre el cupo de mascotas seteado en VACIO
    {
        list[i].isEmpty = VACIO;

        retorno = 0;
    }

    return retorno;
}

char confirmar()
{
    char resp;

    utn_getCaracter(&resp,"\nDesea continuar? s/n: ","\n\nError! Ingrese una respuesta valida (s/n).\n\n",'n','s',0);

    return resp;
}

int buscarLibre(eMascota list[],int len)
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

int buscarMascota(eMascota list[], int len)
{
    int i;
    int id;
    int retorno = -1;

    if(utn_getEntero(&id,1,"\n\nIngrese la ID del empleado: ","\n\nError! ID invalido.\n",1,5) == 0)      //Pide la ID y valida
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].idMascota == id && list[i].isEmpty == OCUPADO)    //Si lo encuentra asigna el retorno
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int borrarMascota(eMascota list[], int len)
{
    int retorno = -1;
    char respuesta;
    int indice = buscarMascota(list,len);     //Busca el indice mediante la ID

    if(indice != -1)        //Si la funcion encuentra el indice continua
    {
        respuesta = confirmar();        //Confirma que el usario esta seguro de eliminar

        if(respuesta == 's')        //Si responde "s" lo asigna a VACIO
        {
            list[indice].isEmpty = VACIO;
            retorno = 0;
            printf("\n\nEliminado correctamente.\n\n");
        }
        else
        {
            printf("\n\nNo se eliminara a la mascota.\n\n");
        }
    }
    else
    {
        printf("\nNo se encontro a una mascota con esa ID.\n\n");
    }

    return retorno;
}


eRaza sacarRazaPorId(eRaza list[], int id, int len)
{
    int i;

    eRaza raza;

    for(i = 0; i < len; i++)
    {
        if(list[i].idRaza == id)
        {
            raza = list[i];
        }
    }

    return raza;
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

            if(strcmp(auxRaza[i].pais,auxRaza[j].pais) > 0)     //Compara por pais
            {
                auxMascota = listMascota[i];
                listMascota[i] = listMascota[j];
                listMascota[j] = auxMascota;
            }
        }
    }
}

void mostrarMascotas(eMascota listMascota[], eRaza listRaza[], int lenRaza, int lenMasc)
{
    int i;

    eRaza raza;

    ordenarPorPais(listMascota,listRaza,lenMasc,lenRaza);

    printf("\n%92s\n","--------------------------------- Listado de mascotas ---------------------------------");
    printf("%9s %10s %9s %9s %10s %15s %11s\n","ID","Nombre","Edad","Sexo","Tipo","Descripcion","Pais");
    printf("%92s\n","---------------------------------------------------------------------------------------");

    for(i = 0; i < lenMasc; i++)
    {
        if(listMascota[i].isEmpty == OCUPADO)
        {
            raza = sacarRazaPorId(listRaza,listMascota[i].idRaza,lenRaza);
            mostrarUnaMascota(listMascota[i],raza);
        }
    }
}


void mostrarUnaMascota(eMascota listMascota, eRaza listRaza)
{
    printf("%9d      %-11s %-10d %-8c %-10s %-14s %-12s\n",listMascota.idMascota,listMascota.nombre,listMascota.edad,listMascota.sexo,
            listMascota.tipo,listRaza.descripcion,listRaza.pais);
}

/*void mostrarRaza(eRaza listRaza[],eMascota listMascota[],int lenMasc,int lenRaza)
{
    int iMascota;
    int iRaza;

    //printf("\n%20s\n","------ Listado de razas ------");
    //printf("%12s %5s\n","ID-Raza","Raza");
    //printf("%20s","------------------------------");

    for(iRaza = 0; iRaza < lenRaza; iRaza++)
    {
        printf("\n\n%10d %-20s",listRaza[iRaza].idRaza,listRaza[iRaza].descripcion);

        for(iMascota = 0; iMascota < lenMasc; iMascota++)
        {
            if(listMascota[iMascota].idRaza == listRaza[iRaza].idRaza && listMascota[iMascota].isEmpty == 1)
            {
                printf("\n          %-14s",listMascota[iMascota].nombre);
            }
        }
    }
}*/

void mostrarRaza(eRaza listRaza[],eMascota listMascota[],int lenMasc,int lenRaza)
{
    int iMascota;
    int iRaza;

    printf("\n%60s\n","------------------- Listado de razas -------------------");
    printf("%9s %16s %10s %14s\n","ID-Raza","Raza","Nombre","Tipo");
    printf("%60s\n","--------------------------------------------------------");

    for(iRaza = 0; iRaza < lenRaza; iRaza++)
    {
        for(iMascota = 0; iMascota < lenMasc; iMascota++)
        {
            if(listMascota[iMascota].idRaza == listRaza[iRaza].idRaza && listMascota[iMascota].isEmpty == 1)
            {
                printf("%10d      %-16s %-12s %-12s\n",listRaza[iRaza].idRaza,listRaza[iRaza].descripcion,listMascota[iMascota].nombre,listMascota[iMascota].tipo);
            }
        }
    }
}

int agregarMascota(eMascota lista[], int len, char nombre[],int edad,char sexo,char tipo[],int idMascota,int idRaza)
{
    int retorno = -1;
    char resp;
    int indice = buscarLibre(lista,len);

    if(indice != -1)
    {
        resp = confirmar();         //Confirma que el usario esta seguro de agregar a la mascota

        if(resp == 's')         //Si reponde "s" continua y asigna los valores ingresados
        {
            strcpy(lista[indice].nombre,nombre);
            lista[indice].edad = edad;
            lista[indice].sexo = sexo;
            strcpy(lista[indice].tipo,tipo);
            lista[indice].idMascota = idMascota;
            lista[indice].idRaza = idRaza;
            lista[indice].isEmpty = OCUPADO;

            retorno = 0;
        }
    }
    else
    {
        printf("\nYa no hay espacio libre para agregar una nueva mascota.\n\n");
    }

    return retorno;
}

int crearUnaMascota(eMascota list[],eRaza listRaza[],int id,int lenMasc,int lenRaza)
{
    char nombre[51];
    int edad;
    char sexo;
    char tipo[51];
    int idRaza;

    int retorno = -1;

    if(utn_getCadena(nombre,51,3,"Ingrese el nombre: ","\nError! Nombre invalido.\n") == 0)       //Pide todos los datos, verifica y continua
    {
        if(utn_getEntero(&edad,3,"Ingrese la edad: ","\nError! Edad invalida (0 a 25).\n",0,25) == 0)
        {
            if(utn_getCaracter(&sexo,"Ingrese el sexo (f o m): ","\nError! Sexo invalido.\n",'f','m',3) == 0)
            {
                if(sexo == 'f' || sexo == 'm')
                {
                    if(pedirTipo(tipo,51,3,"Ingrese el tipo (Perro, Gato o Raro): ","\nError! Tipo invalido.\n") == 0)
                    {
                        mostrarRaza(listRaza,list,lenMasc,lenRaza);

                        if(utn_getEntero(&idRaza,3,"Ingrese el ID de la raza: ","\nError! Raza invalida.\n",101,104) == 0)
                        {
                            retorno = agregarMascota(list,lenMasc,nombre,edad,sexo,tipo,id,idRaza);      //Asigna los valores ingresados al empleado nuevo

                            if(retorno == 0)        //Si se asigno correctamente informa y finaliza
                            {
                                printf("\nMascota agregada correctamente.\n\n");
                            }
                            else
                            {
                                printf("\nNo se registrara a la mascota.\n\n");
                            }
                        }
                    }
                }
                else
                {
                    printf("\nError! Sexo invalido.\n");
                }
            }
        }
    }

    return retorno;
}

void hardCodearMascotas(eMascota listado[])
{
    char arrayNombre[5][51]={"Jorge","Carlos","Tufo","Michi","Froty"};
    int arrayEdad[5]={10,2,4,6,12};
    char arraySexo[5]={'m','m','m','f','f'};
    char arrayTipo[5][51]={"Perro","Perro","Gato","Gato","Perro"};
    int isEmpty[5] = {1,1,1,1,1};
    int idMascota[5] = {1,2,3,4,5};
    int idRaza[5] = {104,102,103,101,102};

    int i;

    for(i = 0; i < 5; i++)
    {
        strcpy(listado[i].nombre,arrayNombre[i]);
        listado[i].edad = arrayEdad[i];
        listado[i].sexo = arraySexo[i];
        strcpy(listado[i].tipo,arrayTipo[i]);
        listado[i].isEmpty = isEmpty[i];
        listado[i].idMascota = idMascota[i];
        listado[i].idRaza = idRaza[i];
    }
}

void hardCodearRazas(eRaza listado[])
{
    char arrayDescripcion[4][51]={"Siames","Doberman","Persa","Pastor Belga"};
    char arrayTamanio[4][51]={"Chico","Grande","Mediano","Grande"};
    char arrayPais[4][51]={"Tailandia","Alemania","Persia","Belgica"};
    int idRaza[4] = {101,102,103,104};

    int i;

    for(i = 0; i < 4; i++)
    {
        strcpy(listado[i].descripcion,arrayDescripcion[i]);
        strcpy(listado[i].tamanio,arrayTamanio[i]);
        strcpy(listado[i].pais,arrayPais[i]);
        listado[i].idRaza = idRaza[i];
    }
}
