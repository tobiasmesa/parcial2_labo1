/*
 ============================================================================
 Name        : parcial-labo2.c
 Author      : Tobias Ian Mesa
 Version     :
 Copyright   : Parcial 2 - Labo 1 - UTNFRA
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Controller.h"
#include "LinkedList.h"
#include "Salon.h"
#include "Arcade.h"
#include "Informes.h"

int main(void) {

	setbuf(stdout, NULL);


	LinkedList* llSalones = ll_newLinkedList();
	LinkedList* llJuegos = ll_newLinkedList();
	LinkedList* llArcades = ll_newLinkedList();


	controller_loadFromTextSalon("dataSALONES.csv", llSalones);
	controller_loadFromTextJuego("dataJUEGOS.csv", llJuegos);
	controller_loadFromTextArcade("dataARCADES.csv", llArcades);

	int option;
	char suboption[2];
	do {
		utn_getNumeroRange(&option, "\n************MENU************\n"
				"\nSALON\n"
				"\n1. ALTA SALON"
				"\n2. ELIMINAR SALON"
				"\n3. LISTAR SALONES"
				"\n\nARCADE\n"
				"\n4. INCORPORAR ARCADE"
				"\n5. MODIFICAR ARCADE"
				"\n6. ELIMINAR ARCADE"
				"\n7. IMPRIMIR ARCADES"
				"\n\nJUEGOS"
				"\n8. AGREGAR JUEGO"
				"\n9. IMPRIMIR JUEGO"
				"\n\n10. INFORMES\n"
				"\n0. SALIR (PARA GUARDAR)"
				"\nINGRESE UNA OPCION: ", "\nERROR. REINGRESE: ", 0, 10, 3);

		switch (option) {
		case 1:
			if(controller_addSalon(llSalones) == 1)
			{
				puts("\nSALON AGREGADO!");
				controller_ListLastSalon(llSalones);
			} else
			{
				puts("\nSALON NO AGREDADO!");
			}
			break;
		case 2:
			controller_ListSalon(llSalones);
			if(controller_removeSalon(llSalones) == 1)
			{
				puts("\nSALON ELIMINADO!");
			}
			break;
		case 3:
			if(controller_ListSalon(llSalones) == -1)
			{
				puts("\nNO HAY SALONES PARA MOSTRAR!");
			}
			break;
		case 4:
			if(controller_addArcade(llArcades, llSalones, llJuegos))
			{
				puts("\nARCADE AGREGADO! ");
			} else
			{
				puts("\nEL ARCADE NO HA SIDO AGREGADO! ");
			}
			 //FIX EL MOSTRAR ARCADES HAY ALGO FALLANDO EN LOS GETTERS
			break;
		case 5:
			if(controller_editArcade(llArcades, llJuegos)==1)
			{
				puts("\nARCADO MODIFICADO CORRECTAMENTE!");
			}
			break;
		case 6:
			controller_ListArcade(llArcades);
			controller_removeArcade(llArcades);
			break;
		case 7:
			if(controller_ListArcade(llArcades) == -1)
			{
				puts("\nNO HAY ARCADES PARA MOSTRAR");
			}
			break;
		case 8:
			if(controller_addJuego(llJuegos) == 1)
			{
				puts("\nJUEGO AGREGADO!");
				controller_ListLastJuego(llJuegos);
			} else
			{
				puts("\nJUEGO NO AGREDADO!");
			}
			break;
		case 9:
			controller_ListJuego(llJuegos);
			break;
		case 10:
			utn_getAlfaNum(suboption, sizeof(suboption), "\n ------- SUBMENU ------\n"
							"[A] Listar los salones con m�s de 4 arcade.\n"
							"[B] Listar los arcade para m�s de 2 jugadores.\n"
							"[C] Listar toda la informaci�n de un sal�n en espec�fico ingresado por el usuario.\n"
							"[D] Listar los salones que cumplan con este m�nimo de requisito para estar completo.\n"
							"[E] Listar todos los arcades de un sal�n determinado ingresando su ID.\n"
							"[F] Imprimir el sal�n con m�s cantidad de arcade. Ordenado de manera ascendete.\n"
							"[G] Listar los arcades que cumplan con sonido MONO y el g�nero de su juego sea PLATAFORMA. Ordenado por nombre de juego. \n"
							"[0] Salir\nINGRESE UNA OPCION: ",
					" \nERROR. REINGRESE: ", 3);
					switch (*suboption) {
						case 'a':
						case 'A':
							Informe_gerarInformeA(llSalones, llArcades);
							break;
						case 'b':
						case 'B':
							Informe_generarInformeB(llArcades, llSalones);
							break;
						case 'c':
						case 'C':
							Informe_gerarInformeC(llSalones);
							break;
						case 'd':
						case 'D':
							Informe_generarInformeD(llSalones, llArcades, llJuegos);
							break;
						case 'e':
						case 'E':
							Informe_generarInformeE(llSalones, llArcades, llJuegos);
							break;
						case 'F':
						case 'f':
							Informe_generarInformeF(llSalones, llArcades, getMaxId);
							break;
						case 'g':
						case 'G':
							Informe_generarInformeG(llArcades, llJuegos, compareName);
							break;
						case 's':
						case 'S':
							break;
						default:
							break;
					}

			break;
		default:
			break;
		}

	} while (option != 0);
	controller_saveAsTextSalon("dataSALONES.csv", llSalones);
	controller_saveAsTextJuego("dataJUEGOS.csv", llJuegos);
	controller_saveAsTextArcade("dataARCADES.csv", llArcades);
	return EXIT_SUCCESS;
}
