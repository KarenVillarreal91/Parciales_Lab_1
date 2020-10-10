#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED

typedef struct
{
    int idMascota;
    char nombre[51];
    int edad;
    char sexo;
    char tipo[51];
    int isEmpty;
    int idRaza;
}eMascota;

typedef struct
{
    char descripcion[51];
    char tamanio[51];
    char pais[51];
    int idRaza;
}eRaza;

int menu();
int inicializarMascotas(eMascota list[], int len);
char confirmar();
int buscarLibre(eMascota list[],int len);
void hardCodearMascotas(eMascota listado[]);
void hardCodearRazas(eRaza listado[]);
eRaza sacarRazaPorId(eRaza list[], int id, int len);
void ordenarPorPais(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza);
void mostrarMascotas(eMascota listMascota[], eRaza listRaza[], int lenRaza, int lenMasc);
void mostrarUnaMascota(eMascota listMascota, eRaza listRaza);
int buscarMascota(eMascota list[], int len);
int borrarMascota(eMascota list[], int len);

int agregarMascota(eMascota lista[], int len, char nombre[],int edad,char sexo,char tipo[],int idMascota,int idRaza);
int crearUnaMascota(eMascota list[],eRaza listRaza[],int id,int lenMasc,int lenRaza);
void mostrarRaza(eRaza listRaza[],eMascota listMascota[],int lenMasc,int lenRaza);
