#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotasyrazas.h"
#define VACIO 0
#define OCUPADO 1

int buscarLibreMascota(eMascota list[],int len)
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

    if(utn_getEntero(&id,1,"\n\nIngrese la ID de la mascota: ","\n\nError! ID invalido.\n",1,len) == 0)      //Pide la ID y valida
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

void mostrarUnaMascota(eMascota listMascota)
{
    printf("%13d      %-12s %-9d %-8c %-12s\n",listMascota.idMascota,listMascota.nombre,listMascota.edad,listMascota.sexo,listMascota.tipo);
}

int agregarMascota(eMascota lista[], int len, char nombre[],int edad,char sexo,char tipo[],int idMascota,int idRaza)
{
    int retorno = -1;
    char resp;
    int indice = buscarLibreMascota(lista,len);

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

int crearUnaMascota(eMascota list[],eRaza listRaza[],int id,int lenMasc,int lenRaza,int idRazaMaximo)
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
                    if(pedirTipo(tipo,51,3,"Ingrese el tipo (Perro, Gato o Raro): ","\nError! Tipo invalido.\n","Perro","Gato","Raro") == 0)
                    {
                        mostrarRazas(listRaza,lenRaza);

                        if(utn_getEntero(&idRaza,3,"\n\nIngrese el ID de la raza: ","\nError! Raza invalida.\n",101,idRazaMaximo) == 0)
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

void modificarMascota(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza,int idMaximo)
{
    int indice = buscarMascota(listMascota,lenMascota);         //Busca el indice mediante la ID ingresada por el usuario
    int opcion;
    char respuesta;
    char respuestaSalir;

    eMascota mascotaModificada;
    eRaza raza;

    if(indice != -1)        //Si lo encontro correctamente continua
    {
        do
        {
            system("pause");
            system("cls");

            printf("\n%92s\n","--------------------------------- Datos de la mascota ---------------------------------");
            printf("%9s %11s %8s %7s %8s %16s %11s %8s\n","ID","Nombre","Edad","Sexo","Tipo","Descripcion","Tamanio","Pais");
            printf("%92s\n","---------------------------------------------------------------------------------------");

            raza = sacarRazaPorId(listRaza,listMascota[indice].idRaza,lenRaza);
            mostrarUnaMascotaConRaza(listMascota[indice],raza);

            //Pregunta al usuario que desea modificar mediante opciones y verifica
            if(utn_getEntero(&opcion,0,"\nQue desea modificar?\n 1. Nombre.\n 2. Edad.\n 3. Sexo.\n 4. Tipo.\n 5. Raza.\n 6. Salir.\n\nSu opcion: ","\n\nError! Opcion invalida.\n\n",1,6) == 0)
            {
                switch(opcion)
                {
                    case 1:  //1. Modifica el nombre
                        if(utn_getCadena(mascotaModificada.nombre,51,0,"\nIngrese el nombre nuevo: ","\n\nError! Nombre invalido.\n\n") == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo nombre
                            {
                                strcpy(listMascota[indice].nombre,mascotaModificada.nombre);

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }
                    break;

                    case 2:  //2. Modifica la edad
                        if(utn_getEntero(&mascotaModificada.edad,0,"\nIngrese la edad nueva: ","\n\nError! Edad invalida.\n\n",0,25) == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna la nueva edad
                            {
                                listMascota[indice].edad = mascotaModificada.edad;

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }
                    break;

                    case 3:  //3. Modifica el sexo
                        if(utn_getCaracter(&mascotaModificada.sexo,"\nIngrese el sexo nuevo (f o m): ","\n\nError! Sexo invalido.\n\n",'f','m',0) == 0)
                        {
                            if(mascotaModificada.sexo == 'f' || mascotaModificada.sexo == 'm')
                            {
                                respuesta = confirmar();        //Confirma que esta seguro de modificar

                                if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo sexo
                                {
                                    listMascota[indice].sexo = mascotaModificada.sexo;

                                    printf("\n\nSe guardaron los cambios.\n\n");
                                }
                                else
                                {
                                    printf("\n\nNo se guardaran los cambios.\n\n");
                                }
                            }
                            else
                            {
                                printf("\n\nError! Sexo invalido.\n\n");
                            }
                        }

                    break;

                    case 4:  //4. Modifica el tipo
                        if(pedirTipo(mascotaModificada.tipo,51,3,"Ingrese el tipo (Perro, Gato o Raro): ","\nError! Tipo invalido.\n","Perro","Gato","Raro") == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo tipo
                            {
                                strcpy(listMascota[indice].tipo,mascotaModificada.tipo);

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }
                    break;

                    case 5:  //5. Modifica la Raza
                        mostrarRazas(listRaza,lenRaza);

                        if(utn_getEntero(&mascotaModificada.idRaza,0,"\n\nIngrese el ID de la raza: ","\nError! Raza invalida.\n",101,idMaximo) == 0)
                        {
                            respuesta = confirmar();        //Confirma que esta seguro de modificar

                            if(respuesta == 's')        //Si responde "s" continua y asigna el nuevo tipo
                            {
                                listMascota[indice].idRaza = mascotaModificada.idRaza;

                                printf("\n\nSe guardaron los cambios.\n\n");
                            }
                            else
                            {
                                printf("\n\nNo se guardaran los cambios.\n\n");
                            }
                        }
                    break;

                    case 6:  //5. Salida, confirma que desea salir
                        respuestaSalir = confirmar();
                    break;
                }
            }

        }while(respuestaSalir != 's');      //Mientras el usuario no elija la opcion 5 y confirme repite
    }
    else
    {
        printf("\nNo se encontro a un empleado con esa ID.\n\n");
    }
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
