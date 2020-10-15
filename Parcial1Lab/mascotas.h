#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

#endif // MASCOTAS_H_INCLUDED

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

/** \brief Hardcodea 5 mascotas
 *
 * \param listado[] eMascota    Listado de mascotas
 * \return void
 *
 */
void hardCodearMascotas(eMascota listado[]);

/** \brief Busca el primer lugar libre que encuentra y devuelve el indice
 *
 * \param list[] eMascota   Listado de mascotas
 * \param len int   Cupo de mascotas
 * \return int  Indice de la mascota
 *
 */
int buscarLibreMascota(eMascota list[],int len);

/** \brief Pide la ID y busca la mascota mediante este
 *
 * \param list[] eMascota   Listado de mascotas
 * \param len int   Cupo de mascotas
 * \return int  Indice de la mascota
 *
 */
int buscarMascota(eMascota list[], int len);

/** \brief Muestra una mascota
 *
 * \param listMascota eMascota  Listado de mascotas
 * \return void
 *
 */
void mostrarUnaMascota(eMascota listMascota);

/** \brief Pide un ID y borra la mascota
 *
 * \param list[] eMascota   Listado de mascotas
 * \param len int   Cupo de mascotas
 * \return int  Retorna 0 si lo borro y -1 si no lo borro
 *
 */
int borrarMascota(eMascota list[], int len);

/** \brief Asigna los valores ingresados para agregar la mascota
 *
 * \param lista[] eMascota  Listado de mascotas
 * \param len int   Cupo de mascotas
 * \param nombre[] char    Nombre ingresado
 * \param edad int     Edad ingresada
 * \param sexo char    Sexo ingresado
 * \param tipo[] char   Tipo de mascota ingresado
 * \param idMascota int    ID creado
 * \param idRaza int    ID de raza ingresada
 * \return int    Retorna 0 si lo asigno y -1 si no lo asigno
 *
 */
int agregarMascota(eMascota lista[], int len, char nombre[],int edad,char sexo,char tipo[],int idMascota,int idRaza);

/** \brief Permite el ingreso de datos para crear una mascota
 *
 * \param list[] eMascota   Listado de mascotas
 * \param listRaza[] eRaza    Listado de razas
 * \param id int   ID creada
 * \param lenMasc int   Cupo de mascotas
 * \param lenRaza int   Cupo de razas
 * \param idRazaMaximo int    ID maxima creada
 * \return int  Retorna 0 si se creo y -1 si no se creo
 *
 */
int crearUnaMascota(eMascota list[],eRaza listRaza[],int id,int lenMasc,int lenRaza,int idRazaMaximo);

/** \brief Modifica una mascota pidiendo la ID
 *
 * \param listMascota[] eMascota    Listado de mascotas
 * \param listRaza[] eRaza     Listado de razas
 * \param lenMascota int    Cupo de mascotas
 * \param lenRaza int   Cupo de razas
 * \param idMaximo int     ID maxima de raza creada
 * \return void
 *
 */
void modificarMascota(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza,int idMaximo);


