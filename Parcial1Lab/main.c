#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define TAMMASC 10
#define TAMRAZA 4
int main()
{
    int respuesta;
    int crearId = 5;

    eMascota listaMascotas[TAMMASC];
    eRaza listaRazas[TAMRAZA];

    if(inicializarMascotas(listaMascotas,TAMMASC) != -1)
    {
        hardCodearMascotas(listaMascotas);
        hardCodearRazas(listaRazas);

        do
        {
            switch(menu())      //Menu que devuelve la opcion elegida
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
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                    mostrarRaza(listaRazas,listaMascotas,TAMMASC,TAMRAZA); //Prueba de mostrar
                break;

                case 4:
                    respuesta = confirmar();
                break;

            }

            system("pause");
            system("cls");
        }while(respuesta != 's');       //Mientras el usario no responda "s" continua el programa
    }
    return 0;
}
