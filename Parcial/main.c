#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

typedef struct
{
    int id;
    float precio;
    char estadoProceso[51];
}eProducto;

int negativoPositivoOCero(int numero);
int reemplazarCaracteres(char paramCaracter, char paramCadena[]);
int sumarLosPrecios(eProducto list[], int valor, int len);

int main()
{
    eProducto productos[TAM];

    int numeroEntero = 1;
    int retornoNegPosCer = negativoPositivoOCero(numeroEntero);

    char caracter = 'a';
    char arrayCaracteres[21] = {"Karen"};
    int retornoCaracteres = reemplazarCaracteres(caracter,arrayCaracteres);

    int valor = 234;

    int arrayId[TAM] = {1,2,3};
    float arrayPrecio[TAM] = {123,3455,2334};
    char arrayEstadoProceso[TAM][51] = {"Comenzado","No terminado","Terminado"};

    for(int i = 0; i < TAM; i++)
    {
        productos[i].id = arrayId[i];
        productos[i].precio = arrayPrecio[i];
        strcpy(productos[i].estadoProceso,arrayEstadoProceso[i]);
    }

    int retornoSumarProductos = sumarLosPrecios(productos,valor,TAM);

    if(retornoNegPosCer == -1)
    {
        printf("Es negativo.");
    }
    else
    {
        if(retornoNegPosCer == 1)
        {
            printf("Es positivo.");
        }
        else
        {
            printf("Es cero.");
        }
    }

    printf("\n\nLa cantidad de veces que se reemplazo el caracter fue: %d", retornoCaracteres);

    if(retornoSumarProductos > 0)
    {
        printf("\n\nLa suma de los productos es: %d",retornoSumarProductos);

        printf("\n\n%53s\n","--------------- Datos del producto ---------------");
        printf("%8s %14s %10s \n","ID","Precio","Estado");
        printf("%51s","----------------------------------------------\n");

        for(int i = 0; i < TAM; i++)
        {
            if(productos[i].precio > valor)
            {
                printf("%8d %15.3f %11s \n",productos[i].id,productos[i].precio,productos[i].estadoProceso);
            }
        }
    }

    return 0;
}


int negativoPositivoOCero(int numero)
{
    int retorno;

    if(numero < 0)
    {
        retorno = -1;
    }
    else
    {
        if(numero > 0)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int reemplazarCaracteres(char paramCaracter, char paramCadena[])
{
    int i;
    int contador = 0;

    for(i = 0; i < 21; i++)
    {
        if(paramCadena[i] == paramCaracter)
        {
            paramCadena[i] = '*';
            contador++;
        }
    }

    return contador;
}

int sumarLosPrecios(eProducto list[], int valor, int len)
{
    int sumar = 0;
    int i;

    for(i = 0; i < len; i++)
    {
        if(list[i].precio > valor)
        {
            sumar += list[i].precio;
        }

        strcpy(list[i].estadoProceso,"Terminado");
    }

    return sumar;
}
