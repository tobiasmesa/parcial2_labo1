/*
 * Informes.h
 *
 *  Created on: 27 jun. 2022
 *      Author: tobic
 */

#ifndef INFORMES_H_
#define INFORMES_H_


#include "Controller.h"
#include "LinkedList.h"
#include "Salon.h"
#include "Arcade.h"
#include "Informes.h"

#define CANT_SALONES 60

int Informe_generarInformeB(LinkedList* listArcade, LinkedList* listSalon);
int Informe_gerarInformeA(LinkedList* listSalon, LinkedList* listArcade);
int Informe_gerarInformeC(LinkedList* listSalon);
int Informe_generarInformeD(LinkedList* listSalon, LinkedList* listArcade, LinkedList* listJuego);
int Informe_generarInformeE(LinkedList* listSalon, LinkedList* listArcade, LinkedList* listJuego);

int Informe_generarInformeZ(LinkedList* listJuegos);

int Informe_generarInformeF(LinkedList* listSalon, LinkedList* listArcade, int (*pFunc)(void*,void*));
int Informe_generarInformeG(LinkedList* listArcade, LinkedList* listJuego,int (*pFunc)(void*,void*));
int compareName(void* a, void* b);
int getMaxId(void* a, void* b);
int filterByCompany(void* pElement);
#endif /* INFORMES_H_ */
