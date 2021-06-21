/*
 * LibroDigital.cpp
 *
 *  Created on: 21 jun. 2021
 *      Author: leire
 */


#include <iostream>
#include <string.h>

#include "LibroDigital.h"
#include "sqlite3.h"

using namespace std;

LibroDigital::LibroDigital( const int nSerie,const char *titulo, const char *autor, const int precio, int diasAlquilados):Libro(nSerie,titulo,autor,precio){

	this->diasAlquilados= diasAlquilados;
}

LibroDigital::LibroDigital( LibroDigital &l):Libro(l) {

		this->diasAlquilados= l.diasAlquilados;

}
LibroDigital::~LibroDigital(){

}


void LibroDigital::setdiasAlquilados(int da){
this->diasAlquilados=da;
	}
int LibroDigital::getdiasAlquilados() const{
return this->diasAlquilados;

}


void LibroDigital::imprimir(){
	Libro::imprimir();
		cout << "dias alquilados:" <<this->getdiasAlquilados() << endl;

}
