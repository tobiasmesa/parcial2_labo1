/*
 * Arcade.h
 *
 *  Created on: 26 jun. 2022
 *      Author: tobic
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NATIONALITY 100
#define MONO 0
#define ESTEREO 1
#define MAX_COINS 10000
#define MAX_PLAYERS  100
typedef struct {
	int id;
	char nationality[LEN_NATIONALITY];
	int typeSound;
	int maxPlayers;
	int maxCoins;
	int idSalon;
	int idJuego;
} Arcade;

// REALIZAR TODAS LAS FUNCIONES BASICAS DE ABM Y ARCHIVOS Y ID LUEGO INFORMES
int Arcade_loadLastId(char* path);

Arcade* Arcade_new();
Arcade* Arcade_newParametros(char* idStr,char* nationalitytr, char* typeSoundStr, char* maxPlayersStr, char* maxCoinsStr, char* idSalonStr, char* idJuegoStr); // alta forzada - Completar con los parametros // alta forzada - Completar con los parametros

void Arcade_delete(Arcade* this);
int Arcade_printOne(Arcade* this);

int Arcade_setId(Arcade* this, int id);
int Arcade_getId(Arcade* this, int* id);

int Arcade_setNationality(Arcade* this,char* nationality);
int Arcade_getNationality(Arcade* this,char* nationality);

int Arcade_setTypeSound(Arcade* this, int typeSound);
int Arcade_getTypeSound(Arcade* this, int* typeSound);

int Arcade_setMaxPlayers(Arcade* this, int maxPlayers);
int Arcade_getMaxPlayers(Arcade* this, int* maxPlayers);

int Arcade_setMaxCoins(Arcade* this, int maxCoins);
int Arcade_getMaxCoins(Arcade* this, int* maxCoins);


int Arcade_setIdJuego(Arcade* this, int idJuego);
int Arcade_getIdJuego(Arcade* this, int* idJuego);

int Arcade_setIdSalon(Arcade* this, int idSalon);
int Arcade_getIdSalon(Arcade* this, int* idSalon);


int Arcade_TypeSoundInt(char* typeArcade);
int Arcade_TypeSoundChar(int typeArcade, char* typeSoundStr);



#endif /* ARCADE_H_ */
