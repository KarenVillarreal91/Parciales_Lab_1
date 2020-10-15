#include <stdio.h>
#include <stdlib.h>
#include "mascotasyrazas.h"
#include "menuyvarios.h"

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

    if(setearEnVacio(listaMascotas,listaRazas,TAMMASC,TAMRAZA) != -1) //Se inicializan las dos estructuras en vacio
    {
        hardCodearMascotas(listaMascotas);
        hardCodearRazas(listaRazas);

        do
        {
            switch(menu(flagOrdenado))      //Menu que devuelve la opcion elegida
            {
                case 1: //1. Crea una mascota
                    crearIdMascota++;      //Se suma 1 cada vez que ingrese a la opcion 1

                    if(crearUnaMascota(listaMascotas,listaRazas,crearIdMascota,TAMMASC,TAMRAZA,crearIdRaza) != 0)    //Comprueba que se creo correctamente
                    {
                        crearIdMascota--;      //Si no se completo el ingreso se resta 1
                    }
                break;

                case 2: //2. Crea una raza
                    crearIdRaza++;      //Se suma 1 cada vez que ingrese a la opcion 2

                    if(crearRaza(listaRazas,crearIdRaza,TAMRAZA) != 0)    //Comprueba que se creo correctamente
                    {
                        crearIdRaza--;      //Si no se completo el ingreso se resta 1
                    }
                break;

                case 3: //3. Borra una mascota a eleccion
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                    borrarMascota(listaMascotas,TAMMASC);
                break;

                case 4: //4. Modifica una mascota a eleccion
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                    modificarMascota(listaMascotas,listaRazas,TAMMASC,TAMRAZA,crearIdRaza);
                break;

                case 5: //5. Ordena/Desordena las mascotas por pais
                    ordenarPorPais(listaMascotas,listaRazas,TAMMASC,TAMRAZA);

                    flagOrdenado++;         //Cada vez que ordene se suma 1

                    if(flagOrdenado % 2 == 0)       //Si es par o impar informa lo que se hizo
                    {
                        printf("\n     Se desordeno la lista.");
                    }
                    else
                    {
                        printf("\n     Se ordeno la lista.");
                    }
                break;

                case 6: //6. Muestra los datos completos de todas las mascotas con sus razas
                    mostrarMascotas(listaMascotas,listaRazas,TAMRAZA,TAMMASC);
                break;

                case 7: //7. Muestra todas las razas con sus mascotas
                    mostrarRazaConMascotas(listaRazas,listaMascotas,TAMMASC,TAMRAZA);
                break;

                case 8: //8. Muestra el pais de origen con mas mascotas
                    paisDeOrigen(listaRazas,listaMascotas,TAMRAZA,TAMMASC);
                break;

                case 9: //9. Confirma que quiere salir
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
