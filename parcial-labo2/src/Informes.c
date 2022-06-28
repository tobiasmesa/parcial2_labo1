/*
 * Informes.c
 *
 *  Created on: 27 jun. 2022
 *      Author: tobic
 */

#include "Informes.h"

static int coincidencesinArray(int index, int* array, int len);

static int coincidencesinArray(int index, int* array, int len)
{

	for(int i = 0; i < len; i++)
	{
		if(index == array[i]) return 1;
	}

	return 0;
}


/**

	Listar los salones con más de 4 arcade. Indicando ID de salón, nombre, dirección y tipo de salón

 */
int Informe_gerarInformeA(LinkedList* listSalon, LinkedList* listArcade)
{
		int rtn = 1;
		Arcade* arcadeAux = NULL;
		Arcade* arcadeAux2 = NULL;
		Salon* salonAux = NULL;
		int idSalones;
		int contador;
		int salonesPasados[CANT_SALONES];
		int indexSalon;

		if(listArcade != NULL)
		{
			printf("%4s %12s %12s %10s\n","id","name","address","type");
			for(int i = 0; i < ll_len(listArcade); i++) // ITERO EN TODOS LOS ARCADES
			{

				arcadeAux = (Arcade*)ll_get(listArcade, i); // OBTENGO UN ARCADE
				if(arcadeAux != NULL)
				{
					contador = 0;
				if(Arcade_getIdSalon(arcadeAux, &idSalones) == 1 && coincidencesinArray(idSalones, salonesPasados, CANT_SALONES) == 0) // OBTENGO EL ID DEL SALON DE UN ARCADE
					{
					for(int i = 0; i < ll_len(listArcade); i++) // ITERO EN TODOS LOS ARCADES OTRA VEZ
					{
						arcadeAux2=(Arcade*)ll_get(listArcade, i); // USO U NARCADE AUX PARA ACCEDER A SUS ID

						if(arcadeAux2->idSalon == idSalones) // SI EL ID DEL SALON ES IGUAL AL QUE OBTUVE ARRIBA SUMO 1
						{
							contador++; // SUMO
							if(contador == 4) // SI HAY 4 COINCIDENCIAS MUESTRO EL SALON
							{
								indexSalon = controller_getIndexbyIdSalon(listSalon, idSalones);
								salonAux = ll_get(listSalon, indexSalon);
								if(indexSalon != -1 && salonAux != NULL)
								{
									Salon_printOne(salonAux);
									salonesPasados[i] = idSalones;
								}
								break;
							}
						}
						}
					}
				}

			}

		}
	return rtn;
}


/***

 Listar los arcade para más de 2 jugadores, indicando ID de arcade,
 cantidad de jugadores, nombre del juego, su
 género y nombre del salón al que pertenece
 */
int Informe_generarInformeB(LinkedList *listArcade, LinkedList *listSalon) {
	int rtn = -1;
	LinkedList *aux = ll_newLinkedList();
	Arcade *arcadeAux = NULL;
	Salon* salonAux = NULL;
	int maxPlayers;
	int id;
	char nationality[LEN_NATIONALITY];
	char typeSoundStr[LEN_TYPE];
	int type;
	int maxCoins;
	char salonName[LEN_NAME];
	int idSalon;
	int index;

	if (aux != NULL) {
		aux = ll_clone(listArcade);
		for (int i = 0; i < ll_len(aux); i++) {
			arcadeAux = (Arcade*)ll_get(listArcade, i);
			if (Arcade_getMaxPlayers(arcadeAux, &maxPlayers)) {
				if (maxPlayers >= 2) {
					ll_remove(aux, i);
				}
			}

		}
		printf("%5s %15s %15s %10s %10s %1s \n", "ID", "nationality","typeSound", "maxPlayers", "MaxCoins", "NOMBRE_SALON");
		for (int i = 0; i < ll_len(aux); i++) {
			arcadeAux = (Arcade*) ll_get(listArcade, i);
			if (Arcade_getId(arcadeAux, &id)) {
				if (Arcade_getMaxCoins(arcadeAux, &maxCoins) && Arcade_getMaxPlayers(arcadeAux, &maxPlayers)) {
					if (Arcade_getNationality(arcadeAux, nationality)) {
						if (Arcade_getTypeSound(arcadeAux, &type)) {
							if (Arcade_TypeSoundChar(type, typeSoundStr)) {
								if(Arcade_getIdSalon(arcadeAux, &idSalon))
								{
									index = controller_getIndexbyIdSalon(listSalon, idSalon);
									salonAux = (Salon*)ll_get(listSalon, index);
									if(salonAux != NULL)
									{
										if(Salon_getName(salonAux, salonName))
										{
											printf("%4d |%12s |%10s |%10d |%10d |%10s \n",id, nationality, typeSoundStr,maxPlayers, maxCoins, salonName);
											rtn = 1;
										}
									}

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




/**
 *  Un salón se encuentra completo si posee al menos 4 juegos del género plataforma,
 *	3 del género laberinto y 5 del género Aventura. Listar los salones que cumplan con este mínimo de requisito
 */

int Informe_generarInformeD(LinkedList* listSalon, LinkedList* listArcade, LinkedList* listJuego)
{
	int rtn = 1;

	int counterPlat = 0;
	int counterLab = 0;
	int counterAv = 0;

	int idSalon;
	int idSalonAux;
	int idJuegoAux;
	int type;

	Arcade* auxArcade;
	Salon* auxSalon;
	Juego* auxJuego;

	if(listSalon != NULL && listArcade != NULL && listJuego != NULL)
	{
		rtn = 0;
		for(int i = 0; i < ll_len(listSalon); i++)
		{
			auxSalon = (Salon*)ll_get(listSalon, i);
			if(auxSalon != NULL && Salon_getId(auxSalon, &idSalon))
			{
				for(int j = 0; j < ll_len(listArcade); j++)
				{
					auxArcade = (Arcade*)ll_get(listArcade, j);
					if(auxArcade != NULL && Arcade_getIdSalon(auxArcade, &idSalonAux) &&
							idSalon == idSalonAux && Arcade_getIdJuego(auxArcade, &idJuegoAux))
					{
						auxJuego = (Juego*)ll_get(listJuego, idJuegoAux);

						if(auxJuego != NULL && Juego_getType(auxJuego, &type) == 1)
						{

							if(type == 2)
							{
								counterLab++;
							} else if(type == 1)
							{
								counterPlat++;
							} else if (type == 3)
							{
								counterAv++;
							}
						}
						type = 0;
					}
				}
				/**
				 *  Un salón se encuentra completo si posee al menos 4 juegos del género plataforma,
				 *	3 del género laberinto y 5 del género Aventura. Listar los salones que cumplan con este mínimo de requisito
				 */

				printf("\nCOUNTERLABERINTO :%d \nCOUNTER PLATAF: %d \nCOUNTER AVEN: %d\n", counterLab, counterPlat, counterAv);
			if(counterLab >= 3 && counterPlat >= 4 && counterAv >= 5)
			{
				puts("LEGUE");
				Salon_printOne(auxSalon);
			}
				counterPlat = 0;
				counterLab = 0;
				counterAv = 0;
			}

		}

	}

	return rtn;
}



/**
 * ) Listar todos los arcades de un salón determinado ingresando su ID.
 * 	Informar nombre y tipo de salón, listar todos los
arcade con sus datos junto con el nombre del juego que lo compone.
 */

int Informe_generarInformeE(LinkedList* listSalon, LinkedList* listArcade, LinkedList* listJuego)
{

	int rtn = 0;
	int idSeleccionada;
	Salon* salonAux;
	Juego* juegoAux;
	Arcade* arcadeAux;

	int indexSalon;
	char nameSalon[LEN_NAME];
	char typeSalonStr[LEN_TYPE];
	char nameJuego[LEN_NAME];
	int typeSalon;
	int idSalon;
	int idJuego;
	int indexJuego;

	if(listSalon != NULL && listArcade != NULL && listJuego != NULL)
	{
		if(controller_ListSalon(listSalon))
		{

			if(utn_getNumeroRange(&idSeleccionada, "\nINGRESE EL ID DEL SALON: ", "\nERROR.REINGRESE. ", 0, MAX_ID, 3))
			{
				indexSalon = controller_getIndexbyIdSalon(listSalon, idSeleccionada);
				if(indexSalon != -1)
				{
					printf("%-20s|%-10s|%-10s|%-4s |%-12s |%-10s |%10s |%-10s |%-10s |%-10s\n","SalonName","Type","NombreJuego","ID","nationality","typeSound","maxPlayers", "MaxCoins", "ID SALON", "ID JUEGO");


					salonAux = (Salon*)ll_get(listSalon, indexSalon);
					for(int i = 0; i < ll_len(listArcade); i++)
					{
						arcadeAux = (Arcade*)ll_get(listArcade, i);
						if(Arcade_getIdSalon(arcadeAux, &idSalon) && idSalon == idSeleccionada)
						{
							if(Arcade_getIdJuego(arcadeAux, &idJuego))
							{
								indexJuego = controller_getIndexbyIdJuego(listJuego, idJuego);
								juegoAux = (Juego*)ll_get(listJuego, indexJuego);
								if(juegoAux != NULL && Juego_getName(juegoAux, nameJuego))
								{
									if(Salon_getType(salonAux, &typeSalon) && Salon_SalonTypeChar(typeSalon, typeSalonStr) && Salon_getName(salonAux, nameSalon))
									{

										printf("%-20s|%-10s|%-10s|",nameSalon,typeSalonStr,nameJuego);
										Arcade_printOne(arcadeAux);
									}

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

/**
 * Listar toda la información de un salón en específico ingresado por el usuario.
 *  Imprimir ID de salón, nombre, tipo y dirección.
 *
 */

int Informe_gerarInformeC(LinkedList* listSalon)
{
	int rtn = -1;
	int option;
	if(listSalon != NULL)
	{
		utn_getNumeroRange(&option, "\nINGRESE ID DEL SALON: ", "Error. Reingrese: ", 0, MAX_ID, 3);
		if(controller_getIndexbyIdSalon(listSalon, option) != -1)
		{
			printf("%4s %12s %12s %10s\n","ID|","NOMBRE|","DIRECCION|","TIPO|");
			Salon_printOne((Salon*)ll_get(listSalon, controller_getIndexbyIdSalon(listSalon, option)));
		} else
		{
			printf("\nERROR. REINGRESE UN ID DE UN SALON EXISTENTE!");
		}
	}

	return rtn;

}



/**
 *  Imprimir el salón con más cantidad de arcade, indicando todos los datos del salón y
 *  la cantidad de arcade que posee.
	Ordenado de manera ascendente.
 */


// Conseguir el Salon con mas arcades y mostrar los arcades de este ordenados por id o maxplayers
int Informe_generarInformeF(LinkedList* listSalon, LinkedList* listArcade, int (*pFunc)(void*,void*))
{
	int rtn = -1;
	Salon* aux = NULL;
	Arcade* auxArcade = NULL;
	int idSalon;
	int idArcadeSalon;
	int counterArcade = 0;
	int max = 0;
	int idMaxArcadeSalon;

	if(listSalon != NULL && listArcade) // Buscar el salon con mas arcades ! -> obtener ID para listar todos sus arcades
	{
		for(int i = 0; i < ll_len(listSalon); i++)
		{
			aux = (Salon*)ll_get(listSalon, i);
			if(aux != NULL && Salon_getId(aux, &idSalon) )
			{
				for(int j = 0; j < ll_len(listArcade); j++)
				{
					auxArcade = (Arcade*)ll_get(listArcade, j);
					//controller_getIndexbyIdArcade(listArcade, idArcadeSalon);
					if(auxArcade != NULL && Arcade_getIdSalon(auxArcade, &idArcadeSalon)
					 && idSalon == idArcadeSalon)
					{
						counterArcade++;
					}
				}
				if(counterArcade > max)
				{
					max = counterArcade;
					idMaxArcadeSalon = idSalon;
				}
				counterArcade = 0;

				}
			}

		}
	///printf("SALON CON MAS ARCADES ES: %d", idMaxArcadeSalon); ->> TENGO ID
	/// para listar todos sus arcades

	LinkedList* newListArcades = ll_newLinkedList();

	for(int i = 0; i < ll_len(listArcade); i++)
	{
		auxArcade = (Arcade*)ll_get(listArcade, i);
		if(auxArcade != NULL)
		{
			if(auxArcade != NULL && Arcade_getIdSalon(auxArcade, &idSalon) && idSalon == idMaxArcadeSalon)
			{
				ll_add(newListArcades, auxArcade);
			}
		}
	}

	if(ll_sort(newListArcades, pFunc, 1) == 0)
	{
		printf("\nCANTIDAD DE ARCADES: %d", max);
		printf("\nSALON CON MAS ARCADES:\n");
		Salon_printOne((Salon*)ll_get(listSalon, controller_getIndexbyIdSalon(listSalon, idMaxArcadeSalon)));
		printf("\nINFO DE LOS ARCADES: \n");
		controller_ListArcade(newListArcades);
	}

	return rtn;
}


int getMaxId(void* a, void* b)
{
		int retorno = 0;
		Arcade* auxArcade1;
		Arcade* auxArcade2;
		int fichas1;
		int fichas2;

		if(a != NULL && b != NULL)
		{
			auxArcade1 = (Arcade*) a;
			auxArcade2 = (Arcade*) b;
			if(Arcade_getMaxCoins(auxArcade1, &fichas1) && Arcade_getMaxCoins(auxArcade2, &fichas2))
			{
				if(fichas1 > fichas2)
				{
					retorno = 1;
				}
				else if(fichas1 < fichas2)
				{
					retorno = -1;
				}
			}

		}

		return retorno;
}



/**
 * Listar los arcades que cumplan con sonido MONO y el género de su juego sea PLATAFORMA, informando nombre
de juego, género y cantidad de jugadores que soporta el arcade. El listado deberá estar ordenado por nombre de juego.
 *
 */

int Informe_generarInformeG(LinkedList* listArcade, LinkedList* listJuego,int (*pFunc)(void*,void*))
{
	int rtn = -1;
	LinkedList* cloneArcade = ll_newLinkedList();
	Arcade* aux;
	int typeSound;
	Juego* auxjuego;
	int idJuego;
	int idJuegoArcade;
	int typeJuego;
	if(listArcade != NULL)
	{
		for(int i = 0; i < ll_len(listArcade); i++){
			aux = (Arcade*)ll_get(listArcade, i);
			if(Arcade_getTypeSound(aux, &typeSound) && typeSound == MONO && Arcade_getIdJuego(aux, &idJuegoArcade))
			{
				for(int j = 0; j < ll_len(listJuego); j++)
				{
					auxjuego = ll_get(listJuego, j);
					if(Juego_getId(auxjuego, &idJuego)  && idJuego == idJuegoArcade &&
							Juego_getType(auxjuego, &typeJuego) && typeJuego == LABERINTO)
					{
						ll_add(cloneArcade,aux);
					}
				}
			}
		}
		rtn = 1;

	}
	return rtn;
}


int compareName(void* a, void* b)
{
	int rtn = 0;

		char name[LEN_NAME];
		char name2[LEN_NAME];

		Juego* aux1 = (Juego*) a;
		Juego* aux2 = (Juego*) b;

		if(a != NULL)
		{
			if(b  != NULL)
			{
				if(Juego_getName(aux1, name))
				{
					if(Juego_getName(aux2, name2))
					{
						if(strncmp(name,name2,LEN_NAME) > 0)
						{
							rtn = 1;
						}
						else
						{
							rtn = -1;
						}
					}
				}
			}
		}

		return rtn;
}

