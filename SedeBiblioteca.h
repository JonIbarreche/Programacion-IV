/*
 * SedeBiblioteca.h
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */

#ifndef SEDEBIBLIOTECA_H_
#define SEDEBIBLIOTECA_H_


typedef struct {
	int id;
	char *nombre;
	char *ubicacion;

} biblioteca;

typedef struct {
	int numBibliotecas;
	biblioteca * bibliotecas;

} grupoBiblioteca;
void imprimirbiblioteca(biblioteca b);
void imprimirbibliotecas(grupoBiblioteca b);

#endif /* SEDEBIBLIOTECA_H_ */
