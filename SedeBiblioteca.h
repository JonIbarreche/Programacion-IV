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
	char nombre[20];
	char ubicacion[20];

} biblioteca;

typedef struct {
	int numBibliotecas;
	biblioteca * bibliotecas;

} grupoBiblioteca;
void imprimirbiblioteca(biblioteca b);
void imprimirbibliotecas1(grupoBiblioteca b);
int cuantosNombres(biblioteca * b, int tamanyo, char letra);
char** listadoNombres(biblioteca * b, int tamanyo, char letra);

#endif /* SEDEBIBLIOTECA_H_ */
