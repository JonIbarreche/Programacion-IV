/*
 * SedeBiblioteca.c
 *
 *  Created on: 22 jun. 2021
 *      Author: leire
 */

#include <stdio.h>

#include "SedeBiblioteca.h"



void imprimirbiblioteca(biblioteca b){

printf("%i %s %s \n", b.id,b.nombre,b.ubicacion);

}
void imprimirbibliotecas1(grupoBiblioteca b){
	for (int i = 0; i < b.numBibliotecas; ++i) {
		imprimirbiblioteca(b.bibliotecas[i]);
	}


}

int cuantosNombres(biblioteca * b, int tamanyo, char letra) {
	int i;
	int cont = 0;
	for (i = 0; i < tamanyo; i++) {
		if (b[i].nombre[0] == letra) {
			cont++;
		}
	}

	return cont;
}
char** listadoNombres(biblioteca * b, int tamanyo, char letra) {
	int i;
	int dim = cuantosNombres(b, tamanyo, letra);


	char **lista;
	typedef char nombre [30];
	lista = (char **) malloc(dim * sizeof(char *));
	for(i = 0 ; i < dim ; i++){
		lista[i] = (char *) malloc(sizeof(nombre));
	}

	int cont = 0;
	for (i = 0; i < tamanyo; i++) {
		if (b[i].nombre[0] == letra) {
			strcpy(lista[cont], b[i].nombre);
			cont++;
		}
	}

	return lista;
}
