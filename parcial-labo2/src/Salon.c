/*
 * Salon.c
 *
 *  Created on: 24 jun. 2022
 *      Author: tobic
 */

#include "Salon.h"

int Salon_loadLastId(char* path)
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

Salon* Salon_new()
{
	Salon* aux = NULL;
	aux = (Salon*)malloc(sizeof(Salon));
	return aux;
}

Salon* Salon_newParametros(char* idStr,char* nameStr, char* addressStr, char* typeSalonStr)
{
	Salon *aux = Salon_new();

	int typeSalon = Salon_SalonTypeInt(typeSalonStr);
	if (aux != NULL) {
		if (Salon_setId(aux, atoi(idStr)) && Salon_setName(aux, nameStr)
				&& Salon_setAddress(aux, addressStr)
				&& Salon_setType(aux, typeSalon)) {
			return aux;
		}
	}
	return NULL;
}


int Salon_printOne(Salon *this) {
	int rtn = -1;
	int id;
	char name[LEN_NAME];
	char address[LEN_ADDRESS];
	int type;
	char typeStr[LEN_TYPE];
	if (this != NULL) {
		if (Salon_getId(this, &id) && Salon_getName(this, name)
				&& Salon_getAddress(this, address) && Salon_getType(this, &type)
				&& Salon_SalonTypeChar(type, typeStr)) {
				printf("%4d %12s %12s %12s\n", id, name, address, typeStr);
				rtn = 1;
		}
	}
	return rtn;
}

void Salon_delete(Salon* this)
{
	free(this);
}


int Salon_setId(Salon* this, int id)
{
	int rtn = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 1;
	}
	return rtn;
}

int Salon_getId(Salon* this, int* id)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && id != NULL)
	{
		rtn = 1;
		*id = this->id;
	}

	return rtn;

}

int Salon_setName(Salon* this, char* name)
{
	int rtn = 0;
	if(this != NULL && name != NULL)
	{
		strcpy(this->name,name);
		rtn = 1;
	}
	return rtn;
}

int Salon_getName(Salon *this, char* name) {
	int rtn = 0; //RETORNA FALSO
	if (this != NULL && name != NULL) {
		rtn = 1;
		strcpy(name, this->name);
	}
	return rtn;
}

int Salon_setAddress(Salon* this, char* address)
{
	int rtn = 0;
	if(this != NULL && address != NULL)
	{
		strcpy(this->address,address);
		rtn = 1;
	}
	return rtn;
}
int Salon_getAddress(Salon* this,char* address)
{
	int rtn = 0; //RETORNA FALSO
	if (this != NULL && address != NULL) {
		rtn = 1;
		strcpy(address, this->address);
	}
	return rtn;
	}

int Salon_setType(Salon* this, int type)
{
	int rtn = 0;
	if(this != NULL && type >= 0)
	{
		this->type = type;
		rtn = 1;
	}
	return rtn;
}
int Salon_getType(Salon* this, int* type)
{
	int rtn = 0; //RETORNA FALSO
	if(this != NULL && type != NULL)
	{
		rtn = 1;
		*type = this->type;
	}

	return rtn;

}

int Salon_SalonTypeInt(char* typeSalon)
{
	int rtn = -1;
		if(typeSalon != NULL)
		{
			if(strcmp(typeSalon,"Shopping") == 0)
			{
				return SHOPPING;
			}
			if(strcmp(typeSalon,"Local") == 0)
			{
				return LOCAL;
			}
		}
		return rtn;
}

int Salon_SalonTypeChar(int typeSalon, char* type)
{

	int rtn = -1;
	if (typeSalon > -1 && type != NULL) {
		if (typeSalon == SHOPPING) {
			strcpy(type, "Shopping");
			rtn = 1;
		}
		if (typeSalon == LOCAL) {
			strcpy(type, "Local");
			rtn = 1;
		}
	}
	return rtn;

}
