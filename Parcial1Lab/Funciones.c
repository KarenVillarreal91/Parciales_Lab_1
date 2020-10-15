#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Funciones.h"
#define VACIO 0
#define OCUPADO 1

int menu(int flagOrdenado)
{
    int op;
        printf("------------- Menu principal -------------\n");
        printf(" 1- Cargar una mascota.\n");
        printf(" 2- Cargar una raza.\n");
        printf(" 3- Borrar una mascota.\n");
        printf(" 4- Modificar una mascota.\n");
        if(flagOrdenado % 2 == 0)
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

int setearEnVacio(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza)
{
    int i;
    int j;
    int retorno = -1;

    for(i = 0; i < lenMascota; i++)        //Recorre el cupo de razas seteado en VACIO
    {
        listMascota[i].isEmpty = VACIO;

        for(j = 0; j < lenRaza; j++)
        {
            listRaza[j].isEmpty = VACIO;
            retorno = 0;
        }
    }

    return retorno;
}

char confirmar()
{
    char resp;

    utn_getCaracter(&resp,"\nDesea continuar? s/n: ","\n\nError! Ingrese una respuesta valida (s/n).\n\n",'n','s',0);

    return resp;
}

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

int buscarMascota(eMascota list[], int len)
{
    int i;
    int id;
    int retorno = -1;

    if(utn_getEntero(&id,1,"\n\nIngrese la ID de la mascota: ","\n\nError! ID invalido.\n",1,5) == 0)      //Pide la ID y valida
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
        if(list[i].idRaza == id && list[i].isEmpty == OCUPADO)
        {
            raza = list[i];
        }
    }

    return raza;
}

int ordenarPorPais(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza)
{
    int i;
    int j;
    int retorno = 0;

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

                    retorno = 0;
                }
            }
        }
    }

    return retorno;
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
            raza = sacarRazaPorId(listRaza,listMascota[i].idRaza,lenRaza);
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
            printf("\n\n%27s  %s  %s\n","----",listRaza[iRaza].descripcion,"----");
            printf("%14s %10s %9s %9s %9s\n","ID","Nombre","Edad","Sexo","Tipo");
            printf("%57s\n","-----------------------------------------------");

            for(iMascota = 0; iMascota < lenMasc; iMascota++)
            {
                if(listMascota[iMascota].idRaza == listRaza[iRaza].idRaza && listMascota[iMascota].isEmpty == 1)
                {
                    mostrarUnaMascota(listMascota[iMascota]);

                    flagAlmenosUno = 1;
                }
            }

            if(flagAlmenosUno == 0)
            {
                printf("%47s\n","No hay mascotas con esta raza.");
            }
        }

        flagAlmenosUno = 0;
    }
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

void mostrarUnaMascotaConRaza(eMascota listMascota, eRaza listRaza)
{
    printf("%9d      %-11s %-7d %-7c %-9s %-15s %-10s %-12s\n",listMascota.idMascota,listMascota.nombre,listMascota.edad,listMascota.sexo,
            listMascota.tipo,listRaza.descripcion,listRaza.tamanio,listRaza.pais);
}

void mostrarUnaMascota(eMascota listMascota)
{
    printf("%13d      %-12s %-9d %-8c %-12s\n",listMascota.idMascota,listMascota.nombre,listMascota.edad,listMascota.sexo,listMascota.tipo);
}

void mostrarUnaRaza(eRaza listRaza)
{
   printf("%14d     %-14s %-10s %-12s\n",listRaza.idRaza,listRaza.descripcion,listRaza.tamanio,listRaza.pais);
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
                retorno = agregarRaza(listRaza,lenRaza,descripcion,tamanio,pais,idRaza);

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

void inicializarPais(ePaisMasMascotas listPais[],int lenRaza)
{
    int i;

    for(i = 0; i < lenRaza; i++)        //Recorre el cupo de razas seteado en VACIO
    {
        listPais[i].isEmpty = VACIO;
    }
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
        contador = 0;

        for(int j = 0;j < lenMascota;j++)
        {
            if(listMascota[j].isEmpty == OCUPADO && listMascota[j].idRaza == listRaza[i].idRaza)
            {
                contador++;
            }
        }

        if(listRaza[indiceMaximoActual].isEmpty == OCUPADO)
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
                    if(strcmp(arrayPais[i],arrayPais[j]) == 0)
                    {
                        arrayCantidad[i] += arrayCantidad[j];
                    }
            }
    }

   for(int k = 0; k < indiceMaximoActual; k++)
    {
            if(!flagMax)
            {
                maximoCantidad = arrayCantidad[k];
                flagMax = 1;
            }
            else
            {
                if(arrayCantidad[k] > maximoCantidad)
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

    /*printf("\n\n\n%57s\n","------------ Mascotas con ese pais ------------");
    printf("%13s %11s %9s %9s %9s\n","ID","Nombre","Edad","Sexo","Tipo");
    printf("%57s\n","-----------------------------------------------");

    for(int i = 0; i < lenMascota; i++)
    {
        if(strcmp(maximoPais,))
        {
            mostrarUnaMascota(listMascota[i]);
        }
    }*/
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
