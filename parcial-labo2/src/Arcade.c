/*
 * Arcade.c
 *
 *  Created on: 26 jun. 2022
 *      Author: tobic
 */


/*
 * RelacionesArcade.c
 *
 *  Created on: 26 jun. 2022
 *      Author: tobic
 */

#include "Arcade.h"

int Arcade_loadLastId(char* path)
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

Arcade* Arcade_new(){
	Arcade* aux = NULL;
	aux = (Arcade*)malloc(sizeof(Arcade));
	return aux;
}
Arcade* Arcade_newParametros(char* idStr,char* nationalitytr, char* typeSoundStr, char* maxPlayersStr, char* maxCoinsStr, char* idSalonStr, char* idJuegoStr)
{
	Arcade* aux = Arcade_new();
		int typeArcade = Arcade_TypeSoundInt(typeSoundStr);
		if (aux != NULL) {
			if (Arcade_setId(aux, atoi(idStr)) && Arcade_setNationality(aux, nationalitytr)
					&& Arcade_setTypeSound(aux, typeArcade) && Arcade_setMaxCoins(aux, atoi(maxCoinsStr)) && Arcade_setMaxPlayers(aux, atoi(maxPlayersStr))
							&& Arcade_setIdJuego(aux, atoi(idJuegoStr)) && Arcade_setIdSalon(aux, atoi(idSalonStr)))
			{
				return aux;
			}
		}
		return NULL;
}

void Arcade_delete(Arcade* this){
	free(this);
}
int Arcade_printOne(Arcade* this)
{
	int rtn = -1;
	int id;
	char nationality[LEN_NATIONALITY];
	int typeSound;
	int maxPlayers;
	int maxCoins;
	int idSalon;
	int idJuego;

	char typeSoundStr[50];

	if(Arcade_getId(this, &id))
	{
		if(Arcade_getIdSalon(this, &idSalon))
		{
			if(Arcade_getIdJuego(this, &idJuego))
			{
				if(Arcade_getMaxCoins(this, &maxCoins))
				{
					if(Arcade_getMaxPlayers(this, &maxPlayers))
					{
						if(Arcade_getNationality(this, nationality))
						{
							if(Arcade_getTypeSound(this, &typeSound))
							{
								if(Arcade_TypeSoundChar(typeSound, typeSoundStr))
								{
									printf("%4d |%12s |%10s |%10d |%10d |%10d |%10d\n", id, nationality, typeSoundStr, maxPlayers, maxCoins, idSalon, idJuego);
									rtn = 1;
								}
							}
						}
					}
				}
			}
		}
	}

	return rtn;
}

int Arcade_setId(Arcade* this, int id)
{
	int rtn = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 1;
	}
	return rtn;
}
int Arcade_getId(Arcade* this, int* id)
{
	int rtn = 0; //RETORNA FALSO
		if(this != NULL && id != NULL)
		{
			rtn = 1;
			*id = this->id;
		}

		return rtn;
}

int Arcade_setNationality(Arcade* this,char* nationality)
{
	int rtn = 0;
	if(this != NULL && nationality != NULL)
	{
		strcpy(this->nationality,nationality);
		rtn = 1;
	}
	return rtn;
}
int Arcade_getNationality(Arcade* this,char* nationality)
{
	int rtn = 0; //RETORNA FALSO
	if (this != NULL && nationality != NULL) {
		rtn = 1;
		strcpy(nationality, this->nationality);
	}
	return rtn;
}

int Arcade_setTypeSound(Arcade* this, int typeSound)
{
	int rtn = 0;
	if(this != NULL && typeSound >= 0)
	{
		this->typeSound = typeSound;
		rtn = 1;
	}
	return rtn;
}
int Arcade_getTypeSound(Arcade* this, int* typeSound)
{
		int rtn = 0; //RETORNA FALSO
		if(this != NULL && typeSound != NULL)
		{
			rtn = 1;
			*typeSound = this->typeSound;
		}

		return rtn;
}

int Arcade_setMaxPlayers(Arcade* this, int maxPlayers)
{
	int rtn = 0;
	if(this != NULL && maxPlayers > 0)
	{
		this->maxPlayers = maxPlayers;
		rtn = 1;
	}
	return rtn;
}
int Arcade_getMaxPlayers(Arcade* this, int* maxPlayers)
{
	int rtn = 0; //RETORNA FALSO
	if (this != NULL && maxPlayers != NULL) {
		rtn = 1;
		*maxPlayers = this->maxPlayers;
	}

	return rtn;
}

int Arcade_setMaxCoins(Arcade* this, int maxCoins)
{
	int rtn = 0;
	if(this != NULL && maxCoins > 0)
	{
		this->maxCoins = maxCoins;
		rtn = 1;
	}
	return rtn;
}
int Arcade_getMaxCoins(Arcade* this, int* maxCoins)
{
	int rtn = 0; //RETORNA FALSO
		if (this != NULL && maxCoins != NULL) {
			rtn = 1;
			*maxCoins = this->maxCoins;
		}

		return rtn;
}


int Arcade_setIdJuego(Arcade* this, int idJuego)
{
	int rtn = 0;
		if(this != NULL && idJuego > 0)
		{
			this->idJuego = idJuego;
			rtn = 1;
		}
		return rtn;
}
int Arcade_getIdJuego(Arcade* this, int* idJuego)
{
	int rtn = 0; //RETORNA FALSO
		if(this != NULL && idJuego != NULL)
		{
			rtn = 1;
			*idJuego = this->idJuego;
		}

		return rtn;
}

int Arcade_setIdSalon(Arcade* this, int idSalon)
{
	int rtn = 0;
		if(this != NULL && idSalon > 0)
		{
			this->idSalon = idSalon;
			rtn = 1;
		}
		return rtn;
}
int Arcade_getIdSalon(Arcade* this, int* idSalon)
{
	int rtn = 0; //RETORNA FALSO
		if(this != NULL && idSalon != NULL)
		{
			rtn = 1;
			*idSalon = this->idSalon;
		}

		return rtn;
}


int Arcade_TypeSoundInt(char* typeArcade)
{
	int rtn = -1;
		if(typeArcade != NULL)
		{
			if(strcmp(typeArcade,"Mono") == 0)
			{
				return MONO;
			}
			if(strcmp(typeArcade,"Estereo") == 0)
			{
				return ESTEREO;
			}
		}
		return rtn;
}
int Arcade_TypeSoundChar(int typeArcade, char* typeArcadeStr)
{
	int rtn = -1;
		if (typeArcade > -1 && typeArcadeStr != NULL) {
			if (typeArcade == MONO) {
				strcpy(typeArcadeStr, "Mono");
				rtn = 1;
			}
			if (typeArcade == ESTEREO) {
				strcpy(typeArcadeStr, "Estereo");
				rtn = 1;
			}
		}
		return rtn;

}
