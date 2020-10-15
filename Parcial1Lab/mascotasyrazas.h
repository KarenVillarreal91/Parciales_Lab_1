#ifndef MASCOTASYRAZAS_H_INCLUDED
#define MASCOTASYRAZAS_H_INCLUDED

#include "utn.h"
#include "razas.h"
#include "mascotas.h"

#endif // MASCOTASYRAZAS_H_INCLUDED


/** \brief Asigna VACIO a las dos listas
 *
 * \param listMascota[] eMascota    Listado de mascotas
 * \param listRaza[] eRaza     Listado de razas
 * \param lenMascota int    Cupo de mascotas
 * \param lenRaza int   Cupo de razas
 * \return int  Retorna 0 si se inicializo y -1 si no se inicializo
 *
 */
int setearEnVacio(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza);

/** \brief  Ordena/Desordena las mascotas por pais
 *
 * \param listMascota[] eMascota    Listado de mascotas
 * \param listRaza[] eRaza     Listado de razas
 * \param lenMascota int    Cupo de mascotas
 * \param lenRaza int   Cupo de razas
 * \return void
 *
 */
void ordenarPorPais(eMascota listMascota[],eRaza listRaza[], int lenMascota, int lenRaza);

/** \brief Muestra una mascota con su raza
 *
 * \param listMascota eMascota  Listado de mascotas
 * \param listRaza eRaza    Listado de razas
 * \return void
 *
 */
void mostrarUnaMascotaConRaza(eMascota listMascota, eRaza listRaza);

/** \brief Muestra las razas con sus mascotas
 *
 * \param listRaza[] eRaza  Listado de razas
 * \param listMascota[] eMascota   Listado de mascotas
 * \param lenMasc int   Cupo de mascotas
 * \param lenRaza int   Cupo de razas
 * \return void
 *
 */
void mostrarRazaConMascotas(eRaza listRaza[],eMascota listMascota[],int lenMasc,int lenRaza);

/** \brief Muestra el listado completo de mascotas
 *
 * \param listMascota[] eMascota   Listado de mascotas
 * \param listRaza[] eRaza  Listado de razas
 * \param lenRaza int   Cupo de razas
 * \param lenMasc int   Cupo de mascotas
 * \return void
 *
 */
void mostrarMascotas(eMascota listMascota[], eRaza listRaza[], int lenRaza, int lenMasc);

/** \brief Muestra el pais de origen con mas mascotas
 *
 * \param listRaza[] eRaza  Listado de razas
 * \param listMascota[] eMascota    Listado de mascotas
 * \param lenRaza int   Cupo de razas
 * \param lenMascota int    Cupo de mascotas
 * \return void
 *
 */
void paisDeOrigen(eRaza listRaza[],eMascota listMascota[],int lenRaza,int lenMascota);
