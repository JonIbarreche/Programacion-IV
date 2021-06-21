/*
 * ConEdicion.cpp
 *
 *  Created on: 21 jun. 2021
 *      Author: leire
 */

#include <iostream>
#include <string.h>

#include "LibroPapel.h"
#include "sqlite3.h"

using namespace std;

LibroPapel::LibroPapel( const int nSerie,const char *titulo, const char *autor, const int precio, int precioEnvio, int diasAlquilados):Libro(nSerie,titulo,autor,precio){
	this->precioEnvio= precioEnvio;
	this->diasAlquilados= diasAlquilados;
}

LibroPapel::LibroPapel( LibroPapel &l):Libro(l) {

	this->precioEnvio= l.precioEnvio;
		this->diasAlquilados= l.diasAlquilados;

}
LibroPapel::~LibroPapel(){

}


void LibroPapel::setprecioEnvio(int pe){
this->precioEnvio=pe;
}
int LibroPapel::getprecioEnvio() const{
return this->precioEnvio;
}
void LibroPapel::setdiasAlquilados(int da){
this->diasAlquilados=da;
	}
int LibroPapel::getdiasAlquilados() const{
return this->diasAlquilados;

}


void LibroPapel::imprimir(){
	Libro::imprimir();
		cout << "precio total con envio:" << this->getPrecio()+this->getprecioEnvio() << endl;
		cout << "dias alquilados:" <<this->getdiasAlquilados() << endl;

}
