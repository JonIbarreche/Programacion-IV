/*
 * Revista.c
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */


#include <stdio.h>
#include "revista.h"


void imprimirRevista(revista r){
	printf("id.%i  titulo:%s autor:%s precio=%i  \n" ,r.idrevista,r.titulo, r.autor, r.precio);
}
void imprimirRevistas1(Revistas rs){
	for (int i = 0; i < rs.numRevistas; ++i) {
		imprimirRevista(rs.revistas[i]);
		}
}

int cuantasRevistas(revista * r, int tamanyo, int precio){
	int i;
		int cont = 0;
		for (i = 0; i < tamanyo; i++) {
			if (r[i].precio < precio) {
				cont++;
			}
		}

		return cont;
}
