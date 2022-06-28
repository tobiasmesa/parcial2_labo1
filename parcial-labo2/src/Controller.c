/*
 * Controller.c
 *
 *  Created on: 24 jun. 2022
 *      Author: tobic
 */


#include "Controller.h"
#include "Linkedlist.h"
#include "Salon.h"
#include "parser.h"
#include "Arcade.h"

int controller_addSalon(LinkedList* pArrayListSalon)
{
	Salon* aux = Salon_new();
	int rtn = -1;
	int id;
	char name[LEN_NAME];
	char address[LEN_ADDRESS];
	int type;

			if(utn_getAlfaNum(name, LEN_NAME, "\nINGRESE NOMBRE DEL SALON: ", "\nERROR. REINGRESE:", 3))
			{
				if(utn_getAlfaNum(address, LEN_ADDRESS, "\nINGRESE DIRECCION DEL SALON:", "\nERROR. REINGRESE:", 3))
				{
					if(utn_getNumeroRange(&type, "\n[0] SHOPPING\n[1]LOCAL\nSELECCIONE UNO:", "\nERROR. REINGRESE:", 0, 1, 3))
					{
						if(Salon_setName(aux, name))
						{
							if(Salon_setAddress(aux, address))
							{
								if(Salon_setType(aux, type))
								{
									id = Salon_loadLastId("lastID_salon");
										if(Salon_setId(aux, id))
										{
											if(ll_add(pArrayListSalon, aux) == 0)
											{
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

int controller_saveAsTextSalon(char* path , LinkedList* pArrayListSalon)
{
	int rtn = -1;
	FILE* pFile = NULL;
	Salon* aux;
	 int id;
	char name[LEN_NAME];
	char address[LEN_ADDRESS];
	int type;
	char typeChar[LEN_TYPE];

	if(path != NULL && pArrayListSalon != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			fprintf(pFile,"id,name,address,type\n");
				for(int i = 0; i < ll_len(pArrayListSalon); i++)
				{
					aux = ll_get(pArrayListSalon, i);
					if(Salon_getId(aux, &id) && Salon_getName(aux, name) && Salon_getAddress(aux, address) &&
							Salon_getType(aux, &type)
							&& Salon_SalonTypeChar(type, typeChar))
					{
							fprintf(pFile,"%d,%s,%s,%s\n", id, name, address, typeChar);
					}
				}
				rtn = 1;
		}
	}
	fclose(pFile);
    return rtn;
}

int controller_loadFromTextSalon(char* path , LinkedList* pArrayListSalon)
{
	int rtn = 1; //
	if(path != NULL && pArrayListSalon != NULL)
	{
			FILE* pArchivo = fopen(path, "r");
			if(parser_SalonFromText(pArchivo, pArrayListSalon) == 0)
			{
				rtn = -1;
			}
			fclose(pArchivo);
	}

    return rtn;
}

int controller_ListSalon(LinkedList* pArrayListSalon)
{
	if(pArrayListSalon != NULL && pArrayListSalon > 0)
	{
		printf("%4s %12s %12s %10s\n","id","name","address","type");
		for(int i = 0; i < ll_len(pArrayListSalon); i++){
             Salon_printOne((Salon*)ll_get(pArrayListSalon, i));
		}
		return 1;
	}
    return 0;
}

void controller_ListLastSalon(LinkedList* pArrayListSalon)
{
	printf("%4s %12s %12s %10s\n","id","name","address","type");
	Salon_printOne(ll_get(pArrayListSalon, ll_len(pArrayListSalon)-1));
}

int controller_getIndexbyIdSalon(LinkedList* pArrayList, int id)
{
	int rtn = -1;
	int indexFounded;
	Salon* aux;

	for(int i = 0; i < ll_len(pArrayList); i++)
	{
		aux = (Salon*) ll_get(pArrayList, i);

		if(Salon_getId(aux, &indexFounded))
		{
			if(indexFounded == id)
			{
				rtn = ll_indexOf(pArrayList, aux);
				break;
			}
		}
	}
	return rtn;
}

int controller_removeSalon(LinkedList* pArrayListSalon)
{
	int rtn = -1;
	int id;
	int index;
	int response;
	if (pArrayListSalon != NULL) {
		if (utn_getNumeroRange(&id, "INGRESE ID A BORRAR: ",
				"ERROR. REINGRESE: ", 1, MAX_ID, 3)) {
			index = controller_getIndexbyIdSalon(pArrayListSalon, id);
			Salon *aux = ll_get(pArrayListSalon, index);
			if (aux != NULL && index != -1) {
				puts("\nSALON A BORRAR: ");
				Salon_printOne(aux);
				utn_getNumeroRange(&response,
						"\n¿ESTA SEGURO DE QUE DESEA ELIMINARLO? \n[0] N0\n[1]SI\nINGRESE UNA OPCION: ",
						"ERROR. REINGRESE: ", 0, 1, 3);
				if (response == 1) {
					if (ll_remove(pArrayListSalon, index)) {
						rtn = 1;
					}
				}

			}
		}
	}
	return rtn;
}
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
int controller_addJuego(LinkedList* pArrayListJuego)
{
	Juego* aux = Juego_new();
	int rtn = -1;
	int id;
	char name[LEN_NAME];
	char companyName[LEN_COMPANY];
	int type;

			if(utn_getAlfaNum(name, LEN_NAME, "\nINGRESE NOMBRE DEL JUEGO: ", "\nERROR. REINGRESE:", 3))
			{
				if(utn_getAlfaNum(companyName, LEN_COMPANY, "\nINGRESE COMPANIA DEL JUEGO:", "\nERROR. REINGRESE:", 3))
				{
					if(utn_getNumeroRange(&type, "\n[1] PLATAFORMA \n[2] LABERINTO \n[3] AVENTURA \n[4]OTRO\nSELECCIONE UNO:", "\nERROR. REINGRESE:", 1,4, 3))
					{
						if(Juego_setName(aux, name))
						{
							if(Juego_setcompanyName(aux, companyName))
							{
								if(Juego_setType(aux, type))
								{
									id = Juego_loadLastId("lastID_Juego");
										if(Juego_setId(aux, id))
										{
											if(ll_add(pArrayListJuego, aux) == 0)
											{
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

int controller_saveAsTextJuego(char* path , LinkedList* pArrayListJuego)
{
	int rtn = -1;
	FILE* pFile = NULL;
	Juego* aux;
	 int id;
	char name[LEN_NAME];
	char companyName[LEN_COMPANY];
	int type;
	char typeChar[LEN_TYPE];

	if(path != NULL && pArrayListJuego != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			fprintf(pFile,"id,name,companyName,type\n");
				for(int i = 0; i < ll_len(pArrayListJuego); i++)
				{
					aux = ll_get(pArrayListJuego, i);
					if(Juego_getId(aux, &id) && Juego_getName(aux, name) && Juego_getcompanyName(aux, companyName) &&
							Juego_getType(aux, &type)
							&& Juego_JuegoTypeChar(type, typeChar))
					{
							fprintf(pFile,"%d,%s,%s,%s\n", id, name, companyName, typeChar);
					}
				}
				rtn = 1;
		}
	}
	fclose(pFile);
    return rtn;
}

int controller_loadFromTextJuego(char* path , LinkedList* pArrayListJuego)
{
	int rtn = 1; //
	if(path != NULL && pArrayListJuego != NULL)
	{
			FILE* pArchivo = fopen(path, "r");
			if(parser_JuegoFromText(pArchivo, pArrayListJuego) == 0)
			{
				rtn = -1;
			}
			fclose(pArchivo);
	}

    return rtn;
}

int controller_ListJuego(LinkedList* pArrayListJuego)
{
	if(pArrayListJuego != NULL)
	{
		printf("%4s %12s %12s %10s\n","id","name","companyName","type");
		for(int i = 0; i < ll_len(pArrayListJuego); i++){
             Juego_printOne((Juego*)ll_get(pArrayListJuego, i));
		}
		return 1;
	}
    return 0;
}

void controller_ListLastJuego(LinkedList* pArrayListJuego)
{
	printf("%4s %12s %12s %10s\n","id","name","companyName","type");
	Juego_printOne(ll_get(pArrayListJuego, ll_len(pArrayListJuego)-1));
}

int controller_getIndexbyIdJuego(LinkedList* pArrayList, int id)
{
	int rtn = -1;
	int indexFounded;
	Juego* aux;

	for(int i = 0; i < ll_len(pArrayList); i++)
	{
		aux = (Juego*) ll_get(pArrayList, i);

		if(Juego_getId(aux, &indexFounded))
		{
			if(indexFounded == id)
			{
				rtn = ll_indexOf(pArrayList, aux);
				break;
			}
		}
	}
	return rtn;
}

int controller_removeJuego(LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int id;
	int index;
	int response;
	if (pArrayListJuego != NULL) {
		if (utn_getNumeroRange(&id, "INGRESE ID A BORRAR: ",
				"ERROR. REINGRESE: ", 1, MAX_ID, 3)) {
			index = controller_getIndexbyIdJuego(pArrayListJuego, id);
			Juego *aux = ll_get(pArrayListJuego, index);
			if (aux != NULL && index != -1) {
				puts("\nJuego A BORRAR: ");
				Juego_printOne(aux);
				utn_getNumeroRange(&response,
						"\n¿ESTA SEGURO DE QUE DESEA ELIMINARLO? \n[0] N0\n[1]SI\nINGRESE UNA OPCION: ",
						"ERROR. REINGRESE: ", 0, 1, 3);
				if (response == 1) {
					if (ll_remove(pArrayListJuego, index)) {
						rtn = 1;
					}
				}

			}
		}
	}
	return rtn;
}

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
int controller_loadFromTextArcade(char* path , LinkedList* pArrayListArcade)
{
	int rtn = -1; //
	if(path != NULL && pArrayListArcade != NULL)
	{
			FILE* pArchivo = fopen(path, "r");
			if(parser_ArcadeFromText(pArchivo, pArrayListArcade) != 0 && pArchivo != NULL)
			{
				rtn = 1;
				fclose(pArchivo);
			}

	}

    return rtn;
}

int controller_saveAsTextArcade(char* path , LinkedList* pArrayListArcade)
{
	int rtn = -1;
	FILE* pFile = NULL;
	Arcade* aux;
	int id;
	char nationality[LEN_NATIONALITY];
	int typeSound;
	int maxPlayers;
	int maxCoins;
	int idSalon;
	int idJuego;
	char typeSoundStr[100];

	if(path != NULL && pArrayListArcade != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			fprintf(pFile,"id,nacionalidad,sonido,maxjugadores,maxfichas,idsalon,idjuego\n");
				for(int i = 0; i < ll_len(pArrayListArcade); i++)
				{
					aux = ll_get(pArrayListArcade, i);
					if(Arcade_getId(aux, &id) && Arcade_getNationality(aux, nationality) && Arcade_getTypeSound(aux, &typeSound)
							&& Arcade_getMaxPlayers(aux, &maxPlayers) && Arcade_getMaxCoins(aux, &maxCoins) && Arcade_getIdJuego(aux, &idJuego)
							&& Arcade_getIdSalon(aux, &idSalon) && Arcade_TypeSoundChar(typeSound, typeSoundStr))
					{
							fprintf(pFile,"%d,%s,%s,%d,%d,%d,%d\n", id, nationality, typeSoundStr, maxPlayers, maxCoins, idSalon, idJuego);
					}
				}
				rtn = 1;
		}
	}
	fclose(pFile);
    return rtn;
}

int controller_addArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListSalones, LinkedList* pArrayListJuegos)
{
	Arcade* this = Arcade_new();
	int rtn = -1;
	int id;
	char nationality[LEN_NATIONALITY];
	int typeSound;
	int maxPlayers;
	int maxCoins;
	int idSalon;
	int idJuego;

	if (utn_getAlfaNum(nationality, LEN_NAME,
			"\nINGRESE LA NACIONALIDAD DEL ARCADE: ", "\nERROR. REINGRESE:",
			3)) {
		if (utn_getNumeroRange(&typeSound,
				"[0] MONO \n[1] ESTEREO \nSELECCIONE UNO:",
				"\nERROR. REINGRESE:", 0, 1, 3)
				&& utn_getNumeroRange(&maxPlayers,
						"\nINGRESE LA CANTIDAD DE JUGADORES DEL ARCADE: ",
						"\nERROR. REINGRESE: ", 0, MAX_PLAYERS, 3)
				&& utn_getNumeroRange(&maxCoins,
						"\nINGRESE EL MAXIMO DE FICHAS DEL ARCADE: ",
						"\nERROR. REINGRESE: ", 0, MAX_COINS, 3))
				{
			puts("--------------------------SALONES--------------------------");
			controller_ListSalon(pArrayListSalones);
			puts("----------------------------------------------------------");
			do
			{
				utn_getNumeroRange(&idSalon, "\nINGRESE ID EXISTENTE DEL SALON AL QUE AGREGARA EL ARCADE: ", "ERROR. REINGRESE: ", 0, MAX_ID, 3);

			} while (controller_getIndexbyIdSalon(pArrayListSalones, idSalon) == -1);


			puts("--------------------------JUEGOS--------------------------");
			controller_ListJuego(pArrayListJuegos);
			puts("----------------------------------------------------------");
			do
			{
				utn_getNumeroRange(&idJuego, "\nINGRESE ID EXISTENTE DEL JUEGO QUE AGREGARA AL ARCADE: ", "ERROR. REINGRESE: ", 0, MAX_ID, 3);
			} while (controller_getIndexbyIdJuego(pArrayListJuegos, idJuego) == -1);


			id = Arcade_loadLastId("lastID_ARCADE");
			if(id != -1)
			{
				if(Arcade_setId(this, id) && Arcade_setIdJuego(this, idJuego) && Arcade_setMaxCoins(this, maxCoins) && Arcade_setIdSalon(this, idSalon) &&
						Arcade_setMaxPlayers(this, maxPlayers)&& Arcade_setTypeSound(this, typeSound) && Arcade_setNationality(this, nationality))
				{
					printf("\n\n%4s |%10s |%10s |%10s |%10s |%10s |%10s\n","ID","NACIONALIDAD","SONIDO","MAX_JUG", "MAX_FICHAS", "ID SALON", "ID JUEGO");
					if(Arcade_printOne(this) == 1)
					{
						if(ll_add(pArrayListArcade, this) == 0)
						{
							rtn = 1;
						}

					}

				}
			}
		}
	}

	return rtn;
}

void controller_ListLastArcade(LinkedList* pArrayListArcade)
{
	printf("%4s %12s %10s %5s %5s %5s %5s\n","ID","nationality","typeSound","maxPlayers", "MaxCoins", "ID SALON", "ID JUEGO");
	Arcade_printOne(ll_get(pArrayListArcade, ll_len(pArrayListArcade)-1));
}

int controller_ListArcade(LinkedList* pArrayListArcade)
{
	int rtn = -1;
	if(pArrayListArcade != NULL && ll_len(pArrayListArcade) > 0)
	{
		printf("%4s |%12s |%10s |%10s |%10s |%10s |%10s\n","ID","nationality","typeSound","maxPlayers", "MaxCoins", "ID SALON", "ID JUEGO");
		for(int i = 0; i < ll_len(pArrayListArcade); i++)
		{
             Arcade_printOne((Arcade*)ll_get(pArrayListArcade, i));
		}
		 rtn = 1;
	}
    return rtn;
}

int controller_editArcade(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int idIngresado;
	int option;
	int newCapacityMax;
	int indexSalon;
	int idJuego;

	if(pArrayListArcade != NULL)
	{
		if(controller_ListArcade(pArrayListArcade) == 1)
		{
			if(utn_getNumeroRange(&idIngresado, "\nINGRESE EL ID DEL ARCADE A MODIFICAR: ", "ERROR. REINGRESE: ", 0, MAX_ID, 3))
			{
				do
				{
					utn_getNumeroRange(&idIngresado, "\nREINGRESE EL ID DEL ARCADE POR UNO EXISTENTE A MODIFICAR: ", "ERROR. REINGRESE: ", 0, MAX_ID, 3);
					indexSalon = controller_getIndexbyIdArcade(pArrayListArcade, idIngresado);
				} while (indexSalon == -1);

				Arcade* aux = (Arcade*)ll_get(pArrayListArcade, indexSalon);
				if(utn_getNumeroRange(&option, "\n[0] CAPACIDAD DE JUGADORES\n[1] JUEGO DEL ARCADE\nINGRESE LO QUE DESEA MODIFICAR:", "\nERROR. REINGRESE: ", 0, 1, 3))
				{
					if(option == 1)
					{
						controller_ListJuego(pArrayListJuego);
						utn_getNumeroRange(&idJuego, "\nINGRESE ID DEL JUEGO A AGREGAR: ", "ERROR. REINGRESE: ", 0, MAX_ID, 3);
						while(controller_getIndexbyIdJuego(pArrayListJuego, idJuego) == -1)
							{
								utn_getNumeroRange(&idJuego, "\nINGRESE ID EXISTENTE DEL JUEGO A AGREGAR: ", "ERROR. REINGRESE: ", 0, MAX_ID, 3);
							}
						if(Arcade_setIdJuego(aux, idJuego) == 1)
						{
							rtn = 1;
						}
					} else
					{
						utn_getNumeroRange(&newCapacityMax, "\nINGRESE LA NUEVA CAPACIDAD DE JUGADORES: ", "\nERROR. REINGRESE: ", 1, MAX_PLAYERS, 3);
						if(Arcade_setMaxPlayers(aux, idJuego) == 1)
						{
							rtn = 1;
						}
					}
				}
			}

		}
	}
	return rtn;
}

int controller_getIndexbyIdArcade(LinkedList* pArrayList, int id)
{
	int rtn = -1;
	int indexFounded;
	Arcade* aux;

	for(int i = 0; i < ll_len(pArrayList); i++)
	{
		aux = (Arcade*) ll_get(pArrayList, i);

		if(Arcade_getId(aux, &indexFounded))
		{
			if(indexFounded == id)
			{
				rtn = ll_indexOf(pArrayList, aux);
				break;
			}
		}
	}
	return rtn;
}

int controller_removeArcade(LinkedList* pArrayListArcade)
{
		int rtn = -1;
		int id;
		int index;
		int response;
		if (pArrayListArcade != NULL) {
			if (utn_getNumeroRange(&id, "INGRESE ID A BORRAR: ",
					"ERROR. REINGRESE: ", 1, MAX_ID, 3)) {
				index = controller_getIndexbyIdArcade(pArrayListArcade, id);
				Arcade *aux = ll_get(pArrayListArcade, index);
				if (aux != NULL && index != -1) {
					puts("\nARCADE A BORRAR: ");
					Arcade_printOne(aux);
					utn_getNumeroRange(&response,
							"\n¿ESTA SEGURO DE QUE DESEA ELIMINARLO? \n[0] N0\n[1]SI\nINGRESE UNA OPCION: ",
							"ERROR. REINGRESE: ", 0, 1, 3);
					if (response == 1) {
						if (ll_remove(pArrayListArcade, index)) {
							rtn = 1;
						}
					}

				}
			}
		}
		return rtn;
}
