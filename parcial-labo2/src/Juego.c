
/*
 * Juego.c
 *
 *  Created on: 24 jun. 2022
 *      Author: tobic
 */

#include "Juego.h"

int Juego_loadLastId(char* path)
{
	int rtn = -1;
	int id;
	FILE* pArchivo = fopen(path, "r");
	if(pArchivo != NULL)
	{
		do
		{
		fscanf(pArchivo, "%d", &id);
		} while(!feof(pArchivo));
		fclose(pArchivo);
	}
	id = id + 1;

	FILE* pArchivo2 = fopen(path, "w");
	if(pArchivo2 != NULL)
	{
		fprintf(pArchivo2,"%d\n", id);
		rtn = id;
	}
	fclose(pArchivo2);
	return rtn;
}

Juego* Juego_new()
{
	Juego* aux = NULL;
	aux = (Juego*)malloc(sizeof(Juego));
	return aux;
}

Juego* Juego_newParametros(char* idStr,char* nameStr, char* companyNameStr, char* typeJuegoStr)
{
	Juego *aux = Juego_new();

	int typeJuego = Juego_JuegoTypeInt(typeJuegoStr);
	if (aux != NULL) {
		if (Juego_setId(aux, atoi(idStr)) && Juego_setName(aux, nameStr)
				&& Juego_setcompanyName(aux, companyNameStr)
				&& Juego_setType(aux, typeJuego)) {
			return aux;
		}
	}
	return NULL;
}

int Juego_printOne(Juego *this) {
	int rtn = -1;
	int id;
	char name[LEN_NAME];
	char companyName[LEN_COMPANY];
	int type;
	char typeStr[LEN_TYPE];
	if (this != NULL) {
		if (Juego_getId(this, &id) && Juego_getName(this, name)
				&& Juego_getcompanyName(this, companyName) && Juego_getType(this, &type)
				&& Juego_JuegoTypeChar(type, typeStr)) {
				printf("%4d %12s %12s %12s\n", id, name, companyName, typeStr);
		}
	}
	return rtn;
}

void Juego_delete(Juego* this)
{
	free(this);
}

int Juego_setId(Juego* this, int id)
{
	int rtn = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 1;
	}
	return rtn;
}

int Juego_getId(Juego* this, int* id)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && id != NULL)
	{
		rtn = 1;
		*id = this->id;
	}

	return rtn;

}

int Juego_setName(Juego* this, char* name)
{
	int rtn = 0;
	if(this != NULL && name != NULL)
	{
		strcpy(this->name,name);
		rtn = 1;
	}
	return rtn;
}

int Juego_getName(Juego *this, char* name) {
	int rtn = 0; //RETORNA FALSO
	if (this != NULL && name != NULL) {
		rtn = 1;
		strcpy(name, this->name);
	}
	return rtn;
}

int Juego_setcompanyName(Juego* this, char* companyName)
{
	int rtn = 0;
	if(this != NULL && companyName != NULL)
	{
		strcpy(this->companyName,companyName);
		rtn = 1;
	}
	return rtn;
}
int Juego_getcompanyName(Juego* this,char* companyName)
{
	int rtn = 0; //RETORNA FALSO
	if (this != NULL && companyName != NULL) {
		rtn = 1;
		strcpy(companyName, this->companyName);
	}
	return rtn;
	}

int Juego_setType(Juego* this, int type)
{
	int rtn = 0;
	if(this != NULL && type >= 0)
	{
		this->type = type;
		rtn = 1;
	}
	return rtn;
}
int Juego_getType(Juego* this, int* type)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && type != NULL)
	{
		rtn = 1;
		*type = this->type;
	}

	return rtn;

}


int Juego_JuegoTypeInt(char* typeJuego)
{
	int rtn = -1;
		if(typeJuego != NULL)
		{
			if(strcmp(typeJuego,"Plataforma") == 0)
			{
				return PLATAFORMA;
			}
			if(strcmp(typeJuego,"Laberinto") == 0)
			{
				return LABERINTO;
			}
			if(strcmp(typeJuego,"Aventura") == 0)
			{
				return AVENTURA;
			}
			if(strcmp(typeJuego,"Otro") == 0)
			{
				return OTRO;
			}
		}
		return rtn;
}


int Juego_JuegoTypeChar(int typeJuego, char* type)
{

	int rtn = -1;
	if (typeJuego > -1 && type != NULL) {
		if (typeJuego == PLATAFORMA) {
			strcpy(type, "Plataforma");
			rtn = 1;
		}
		if (typeJuego == LABERINTO) {
			strcpy(type, "Laberinto");
			rtn = 1;
		}
		if (typeJuego == AVENTURA) {
			strcpy(type, "Aventura");
			rtn = 1;
		}
		if (typeJuego == OTRO) {
			strcpy(type, "Otro");
			rtn = 1;
		}
	}
	return rtn;

}
