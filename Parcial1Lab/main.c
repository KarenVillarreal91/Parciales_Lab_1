#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define TAMMASC 10
#define TAMRAZA 4
int main()
{
    char respuesta = 'n';
    int crearId = 5;
    int flagOrdenado = 0;

    eMascota listaMascotas[TAMMASC];
    eRaza listaRazas[TAMRAZA];

    if(inicializarMascotas(listaMascotas,TAMMASC) != -1)
    {
        hardCodearMascotas(listaMascotas);
        hardCodearRazas(listaRazas);

        do
        {
            switch(menu(flagOrdenado))      //Menu que devuelve la opcion elegida
            {
                case 1:
                    crearId++;      //Se suma 1 cada vez que ingrese a la opcion 1

                    if(crearUnaMascota(listaMascotas,listaRazas,crearId,TAMMASC,TAMRAZA) != 0)    //Comprueba que se creo correctamente
                    {
                        crearId--;      //Si no se completo el ingreso se resta 1
                    }
                break;

                case 2:
                    borrarMascota(listaMascotas,TAMMASC);
                break;

                case 3:
                    if(ordenarPorPais(listaMascotas,listaRazas,TAMMASC,TAMRAZA) == 0)
                    {
                        flagOrdenado++;

                        if(flagOrdenado % 2 == 0)
                        {
                            printf("\n     Se desordeno la lista.");
                        }
                        else
                        {
                            printf("\n     Se ordeno la lista.");
                        }
                    }
                break;

                case 4:
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                break;

                case 5:
                    mostrarRazaConMascotas(listaRazas,listaMascotas,TAMMASC,TAMRAZA);
                break;

                case 6:
                    respuesta = confirmar();
                break;

            }
            printf("\n\n");
            system("pause");
            system("cls");
        }while(respuesta != 's');       //Mientras el usario no responda "s" continua el programa
    }
    return 0;
}
