/*
 * SedeBiblioteca.c
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */

#include <stdio.h>

#include "SedeBiblioteca.h"



void imprimirbiblioteca(biblioteca b){

printf("%i %s %s", b.id,b.nombre,b.ubicacion);

}
void imprimirbibliotecas1(grupoBiblioteca b){
	for (int i = 0; i < b.numBibliotecas; ++i) {
		imprimirbiblioteca(b.bibliotecas[i]);
	}


}


