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
    int isEmpty;
    int idRaza;
}eRaza;

typedef struct
{
    int isEmpty;
    char pais[51];
    int idRaza;
    int cantidad;
}ePaisMasMascotas;

void hardCodearRazas(eRaza listado[]);
void hardCodearMascotas(eMascota listado[]);

int setearEnVacio(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza);

int menu(int flagOrdenado);
char confirmar();

int buscarLibreMascota(eMascota list[],int len);
int buscarLibreRaza(eRaza list[],int len);
int buscarMascota(eMascota list[], int len);
eRaza sacarRazaPorId(eRaza list[], int id, int len);

int ordenarPorPais(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza);

void mostrarUnaRaza(eRaza listRaza);
void mostrarUnaMascota(eMascota listMascota);
void mostrarUnaMascotaConRaza(eMascota listMascota, eRaza listRaza);
void mostrarRazaConMascotas(eRaza listRaza[],eMascota listMascota[],int lenMasc,int lenRaza);
void mostrarRazas(eRaza listRaza[],int lenRaza);
void mostrarMascotas(eMascota listMascota[], eRaza listRaza[], int lenRaza, int lenMasc);

int borrarMascota(eMascota list[], int len);
int agregarMascota(eMascota lista[], int len, char nombre[],int edad,char sexo,char tipo[],int idMascota,int idRaza);
int crearUnaMascota(eMascota list[],eRaza listRaza[],int id,int lenMasc,int lenRaza,int idRazaMaximo);
void modificarMascota(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza,int idMaximo);

int agregarRaza(eRaza listRaza[],int lenRaza,char descripcion[], char tamanio[],char pais[],int idRaza);
int crearRaza(eRaza listRaza[],int idRaza,int lenRaza);

void paisDeOrigen(eRaza listRaza[],eMascota listMascota[],int lenRaza,int lenMascota);
//void paisDeOrigen(eRaza listRaza[],eMascota listMascota[], ePaisMasMascotas listPais[],int lenRaza,int lenMascota);
void inicializarPais(ePaisMasMascotas listPais[],int lenRaza);
