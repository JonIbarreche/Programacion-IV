/*
 * SedeBiblioteca.h
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */

#ifndef SEDEBIBLIOTECA_H_
#define SEDEBIBLIOTECA_H_


#include "Biblioteca.h"

typedef struct {
	int numBibliotecas;
	Biblioteca * biblioteca;

} grupoBiblioteca;

void imprimirbibliotecas(Biblioteca b);

#endif /* SEDEBIBLIOTECA_H_ */
