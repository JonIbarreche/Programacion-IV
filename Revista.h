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
	char *titulo;
	char *autor;
	int precio;

} revista;

void imprimirRevistas(revista r);


#endif /* REVISTA_H_ */
