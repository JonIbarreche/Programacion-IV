/*
 * Revista.c
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */


#include "revista.h"
int idrevista;
	char *titulo;
	char *autor;
	int precio;

void imprimirRevistas(revista r){
	printf("id.%i  titulo %s autor %s precio=%i" ,r.idrevista,r.titulo, r.autor, r.precio);
}
