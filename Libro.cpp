/*
 * Libro.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */


#include "Libro.h"
#include <stdio.h>

Libro::Libro(const int nSerie, const char autor, const int fechaLanzamiento){

	this->nSerie= nSerie;
	this->autor= autor;
	this->fechaLanzamiento= fechaLanzamiento;

}
Libro::Libro(){

	this->nSerie= 0;
	this->autor= "";
	this->fechaLanzamiento= 0;
}
Libro::Libro(Libro &l){

	this->nSerie= l.nSerie;
	this->autor= l.autor;
	this->fechaLanzamiento= l.fechaLanzamiento;

}
virtual Libro::~Libro(){


}
