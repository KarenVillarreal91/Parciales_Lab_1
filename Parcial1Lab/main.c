#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define TAMMASC 10
#define TAMRAZA 20

int main()
{
    char respuesta;
    int crearIdMascota = 5;
    int crearIdRaza = 104;
    int flagOrdenado = 0;

    eMascota listaMascotas[TAMMASC];
    eRaza listaRazas[TAMRAZA];
    ePaisMasMascotas listaPais[TAMRAZA];

    inicializarPais(listaPais,TAMRAZA);

    if(setearEnVacio(listaMascotas,listaRazas,TAMMASC,TAMRAZA) != -1)
    {
        hardCodearMascotas(listaMascotas);
        hardCodearRazas(listaRazas);

        do
        {
            switch(menu(flagOrdenado))      //Menu que devuelve la opcion elegida
            {
                case 1:
                    crearIdMascota++;      //Se suma 1 cada vez que ingrese a la opcion 1

                    if(crearUnaMascota(listaMascotas,listaRazas,crearIdMascota,TAMMASC,TAMRAZA,crearIdRaza) != 0)    //Comprueba que se creo correctamente
                    {
                        crearIdMascota--;      //Si no se completo el ingreso se resta 1
                    }
                break;

                case 2:
                    crearIdRaza++;      //Se suma 1 cada vez que ingrese a la opcion 2

                    if(crearRaza(listaRazas,crearIdRaza,TAMRAZA) != 0)    //Comprueba que se creo correctamente
                    {
                        crearIdRaza--;      //Si no se completo el ingreso se resta 1
                    }
                break;

                case 3:
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                    borrarMascota(listaMascotas,TAMMASC);
                break;

                case 4:
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                    modificarMascota(listaMascotas,listaRazas,TAMMASC,TAMRAZA,crearIdRaza);
                break;

                case 5:
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

                case 6:
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                break;

                case 7:
                    mostrarRazaConMascotas(listaRazas,listaMascotas,TAMMASC,TAMRAZA);
                break;

                case 8:
                    paisDeOrigen(listaRazas,listaMascotas,TAMRAZA,TAMMASC);
                break;

                case 9:
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
