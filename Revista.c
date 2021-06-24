/*
 * Revista.c
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
char** listadoPrecioBarato(revista * r, int tamanyo, int * baratos) {
	int i, cont = 0;
	for (i = 0;i < tamanyo;i++) {
		if (r[i].precio < 15) {
			cont++;
		}
	}

	//Creamos un vector de cont nombres
	char **lista;
	lista = (char **) malloc(cont * sizeof(char *));
	for(i = 0 ; i < cont ; i++){
		lista[i] = (char *) malloc(30 * sizeof(char));
	}

	*baratos = cont;

	cont = 0;
	for (i = 0;i < tamanyo;i++) {
		if (r[i].precio < 15) {
			strcpy(lista[cont], r[i].titulo);
			cont++;
		}
	}

	return lista;
}

revista * crearRevista(char * titulo) {
	revista * a = (revista *)malloc(sizeof(revista));
	strcpy(a->titulo, titulo);
	strcpy(a->autor, NULL);
	a->precio = 0;


	return a;
}

