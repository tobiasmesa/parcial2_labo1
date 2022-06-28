/*
 * Salon.h
 *
 *  Created on: 24 jun. 2022
 *      Author: tobic
 */

#ifndef SALON_H_
#define SALON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NAME 50

#define MAX_ID 1000000
#define SHOPPING 0
#define LOCAL 1
#define LEN_TYPE 50
#define LEN_ADDRESS 50


typedef struct {
	 int id;
	char name[LEN_NAME];
	char address[LEN_ADDRESS];
	int type;
} Salon;

int Salon_loadLastId(char* path);


Salon* Salon_new();
Salon* Salon_newParametros(char* idStr,char* nameStr, char* addressStr, char* typeSalonStr); // alta forzada - Completar con los parametros // alta forzada - Completar con los parametros

void Salon_delete(Salon* this);
int Salon_printOne(Salon* this);

int Salon_setId(Salon* this, int id);
int Salon_getId(Salon* this, int* id);

int Salon_setName(Salon* this,char* name);
int Salon_getName(Salon* this,char* name);

int Salon_setAddress(Salon* this, char* address);
int Salon_getAddress(Salon* this,char* address);

int Salon_setType(Salon* this, int type);
int Salon_getType(Salon* this, int* type);

int Salon_SalonTypeInt(char* typeSalon);
int Salon_SalonTypeChar(int typeSalon, char*);


#endif /* SALON_H_ */
