/*
 * Controller.h
 *
 *  Created on: 24 jun. 2022
 *      Author: tobic
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arcade.h"
#include "utn.h"
#include "Linkedlist.h"
#include "Juego.h"
#include "Salon.h"


#define LEN_NAME 50
#define LEN_COMPANY 50

#define LEN_ADDRESS  50
#define LEN_COMPANY 50

int controller_saveAsTextSalon(char* path , LinkedList* pArrayListSalon);
int controller_loadFromTextSalon(char* path , LinkedList* pArrayListSalon);
int controller_addSalon(LinkedList* pArrayListSalon);
int controller_editSalon(LinkedList* pArrayListSalon);
int controller_removeSalon(LinkedList* pArrayListSalon);
int controller_ListSalon(LinkedList* pArrayListSalon);
int controller_sortSalon(LinkedList* pArrayListSalon);
void controller_ListLastSalon(LinkedList* pArrayListSalon);
int controller_getIndexbyIdSalon(LinkedList* pArrayListSalon, int id);

/*---------------------------------------------------------------------------*/

int controller_addJuego(LinkedList* pArrayListJuego);
int controller_saveAsTextJuego(char* path , LinkedList* pArrayListJuego);
int controller_loadFromTextJuego(char* path , LinkedList* pArrayListJuego);
int controller_ListJuego(LinkedList* pArrayListJuego);
void controller_ListLastJuego(LinkedList* pArrayListJuego);
int controller_getIndexbyIdJuego(LinkedList* pArrayList, int id);
int controller_removeJuego(LinkedList* pArrayListJuego);

/*---------------------------------------------------------------------------*/


int controller_addArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalones, LinkedList* pArrayListJuegos);
int controller_saveAsTextArcade(char* path , LinkedList* pArrayListArcade);
int controller_loadFromTextArcade(char* path , LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade);
void controller_ListLastArcade(LinkedList* pArrayListArcade);
int controller_getIndexbyIdArcade(LinkedList* pArrayListArcade, int id);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_sortArcade(LinkedList* pArrayListArcade);

#endif /* CONTROLLER_H_ */
