/*
 * Juego.h
 *
 *  Created on: 26 jun. 2022
 *      Author: tobic
 */

#ifndef JUEGO_H_
#define JUEGO_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTRO 4

#define LEN_COMPANY 50
#define LEN_NAME 50
#define LEN_TYPE 50

typedef struct
{
	int id;
	char name[LEN_NAME];
	char companyName[LEN_COMPANY];
	int type;

} Juego;

int Juego_loadLastId(char* path);


Juego* Juego_new();
Juego* Juego_newParametros(char* idStr,char* nameStr, char* companyNameStr, char* typeJuegoStr); // alta forzada - Completar con los parametros // alta forzada - Completar con los parametros

void Juego_delete(Juego* this);
int Juego_printOne(Juego* this);

int Juego_setId(Juego* this, int id);
int Juego_getId(Juego* this, int* id);

int Juego_setName(Juego* this,char* name);
int Juego_getName(Juego* this,char* name);

int Juego_setcompanyName(Juego* this, char* companyName);
int Juego_getcompanyName(Juego* this,char* companyName);

int Juego_setType(Juego* this, int type);
int Juego_getType(Juego* this, int* type);

int Juego_JuegoTypeInt(char* typeJuego);
int Juego_JuegoTypeChar(int typeJuego, char*);



#endif /* JUEGO_H_ */
