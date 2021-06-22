/*
 * Revista.c
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */


#include <stdio.h>
#include "revista.h"


void imprimirRevista(revista r){
	printf("id.%i  titulo%s autor%s precio=%i" ,r.idrevista,r.titulo, r.autor, r.precio);
}
