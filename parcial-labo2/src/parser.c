/*
 * parser.c
 *
 *  Created on: 25 jun. 2022
 *      Author: tobic
 */

#include "parser.h"


int parser_SalonFromText(FILE* pFile , LinkedList* pArrayListSalon)
{
		int rtn = 1;
		int countData;

		Salon* aux;

		char id[100];
		char name[LEN_NAME];
		char address[LEN_ADDRESS];
		char type[100];

		if(pFile != NULL){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,name,address,type); // LEE LA PRIMERA LINEA
			do{
				countData = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,name,address,type);;
				if(countData == 4)
				{
					aux = Salon_newParametros(id, name, address, type);
					if(aux != NULL)
					{
						ll_add(pArrayListSalon, aux);
					} else
					{
						free(aux);
						rtn = -1;
					}
				}else
				{
					free(aux);
					rtn = -1;
				}
				//Cuando valido el countdata cargar el pasajero y pasarlo a linked list
			}while(feof(pFile) == 0);
		}
	    return rtn;
}


int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuego)
{
		int rtn = 1;
		int countData;

		Juego* aux;

		char id[1000];
		char name[LEN_NAME];
		char companyName[LEN_COMPANY];
		char type[LEN_TYPE];

		if(pFile != NULL){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,name,companyName,type); // LEE LA PRIMERA LINEA
			do{
				countData = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,name,companyName,type);;
				if(countData == 4)
				{
					aux = Juego_newParametros(id, name, companyName, type);
					if(aux != NULL)
					{
						ll_add(pArrayListJuego, aux);
					} else
					{
						free(aux);
						rtn = -1;
					}
				}else
				{
					free(aux);
					rtn = -1;
				}
				//Cuando valido el countdata cargar el pasajero y pasarlo a linked list
			}while(feof(pFile) == 0);
		}
	    return rtn;
}

int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
			int rtn = 1;
			int countData;
			Arcade* aux;
			char id[100];
			char nationality[LEN_NATIONALITY];
			char typeSound[100];
			char maxPlayers[100];
			char maxCoins[100];
			char idSalon[100];
			char idJuego[100];

			if(pFile != NULL){
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nationality,typeSound,maxPlayers,maxCoins,idSalon,idJuego); // LEE LA PRIMERA LINEA
				do{
					countData = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nationality,typeSound,maxPlayers,maxCoins,idSalon,idJuego);
					if(countData == 7)
					{
						aux = Arcade_newParametros(id, nationality, typeSound, maxPlayers, maxCoins, idSalon, idJuego);
						if(aux != NULL)
						{
							ll_add(pArrayListArcade, aux);
						} else
						{
							free(aux);
							rtn = -1;
						}
					}else
					{
						free(aux);
						rtn = -1;
					}
					//Cuando valido el countdata cargar el pasajero y pasarlo a linked list
				}while(feof(pFile) == 0);
			}
		    return rtn;
}
