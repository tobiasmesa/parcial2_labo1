/*
 * parser.h
 *
 *  Created on: 25 jun. 2022
 *      Author: tobic
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Controller.h"

int parser_SalonFromText(FILE* pFile , LinkedList* pArrayListSalon);
int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuego);
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade);
#endif /* PARSER_H_ */
