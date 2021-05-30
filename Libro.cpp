/*
 * Libro.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */


#include "Libro.h"
#include <stdio.h>

Libro::Libro(const int nSerie,const char *titulo, const char *autor, const int fechaLanzamiento){

	this->nSerie= nSerie;
	this->titulo = new char[strlen(titulo) + 1];
			strcpy(this->titulo, titulo);
	this->fechaLanzamiento= fechaLanzamiento;
	this->autor = new char[strlen(autor) + 1];
			strcpy(this->autor, autor);
}
Libro::Libro(){

	this->nSerie= 0;
	this->autor = new char[1];
		this->autor[0] = '\0';
	this->fechaLanzamiento= 0;
	this->titulo = new char[1];
		this->titulo[0] = '\0';
}
Libro::Libro(Libro &l){

	this->nSerie= l.nSerie;
	this->titulo = new char[strlen(l.titulo) + 1];
		strcpy(this->titulo, l.titulo);
	this->fechaLanzamiento= l.fechaLanzamiento;
	this->autor = new char[strlen(l.autor) + 1];
		strcpy(this->autor, l.autor);
}
Libro::~Libro(){

	delete []titulo;
	delete[] autor;

}
