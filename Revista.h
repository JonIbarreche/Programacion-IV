/*
 * Revista.h
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */

#ifndef REVISTA_H_
#define REVISTA_H_

typedef struct {
	int idrevista;
	char titulo[20];
	char autor[20];
	int precio;

} revista;
typedef struct {
	int numRevistas;
	revista * revistas;
} Revistas;
void imprimirRevista(revista r);
void imprimirRevistas1(Revistas rs);

#endif /* REVISTA_H_ */
