#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED

#endif // RAZAS_H_INCLUDED

typedef struct
{
    char descripcion[51];
    char tamanio[51];
    char pais[51];
    int isEmpty;
    int idRaza;
}eRaza;

/** \brief Hardcodea 4 Razas
 *
 * \param listado[] eRaza   Listado de razas
 * \return void
 *
 */
void hardCodearRazas(eRaza listado[]);

/** \brief Busca el primer lugar libre que encuentra y devuelve el indice
 *
 * \param list[] eRaza  Listado de razas
 * \param len int   Cupo de razas
 * \return int  Indice de raza
 *
 */
int buscarLibreRaza(eRaza list[],int len);

/** \brief Busca el indice de una raza mediante el ID
 *
 * \param list[] eRaza  Listado de razas
 * \param id int    ID re la raza
 * \param len int   Cupo de razas
 * \return eRaza    Datos de una sola raza
 *
 */
eRaza sacarRazaPorId(eRaza list[], int id, int len);

/** \brief Muestra una raza
 *
 * \param listRaza eRaza    Listado de razas
 * \return void
 *
 */
void mostrarUnaRaza(eRaza listRaza);

/** \brief Muestra todas las razas
 *
 * \param listRaza[] eRaza  Listado de razas
 * \param lenRaza int   Cupo de razas
 * \return void
 *
 */
void mostrarRazas(eRaza listRaza[],int lenRaza);

/** \brief Asigna los valores ingresados para agregar la raza
 *
 * \param listRaza[] eRaza  Listado de raza
 * \param lenRaza int   Cupo de raza
 * \param descripcion[] char   Nombre de la raza ingresada
 * \param tamanio[] char   Tamanio ingresado
 * \param pais[] char   Pais ingresado
 * \param idRaza int   ID de la raza creado
 * \return int  Retorna 0 si lo asigno y -1 si no lo asigno
 *
 */
int agregarRaza(eRaza listRaza[],int lenRaza,char descripcion[], char tamanio[],char pais[],int idRaza);

/** \brief Permite el ingreso de datos para crear una raza
 *
 * \param listRaza[] eRaza  Listado de razas
 * \param idRaza int   ID de la raza creado
 * \param lenRaza int   Cupo de razas
 * \return int  Retorna 0 si se creo y -1 si no se creo
 *
 */
int crearRaza(eRaza listRaza[],int idRaza,int lenRaza);




