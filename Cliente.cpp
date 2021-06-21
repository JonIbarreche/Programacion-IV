/*
 * Cliente.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */



#include "Cliente.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Cliente::Cliente(const char *nombre, const int contrasenya, const int edad, const char *email, const int puntos, Libro *libros){
	this->nombre = new char[strlen(nombre) + 1];
		strcpy(this->nombre, nombre);
	this->contrasenya=contrasenya;
	this->edad=edad;
	this->email = new char[strlen(email) + 1];
			strcpy(this->email, email);
	this->puntos=puntos;
	this->libros=libros;
}
Cliente::Cliente(){
	this->nombre = new char[1];
	this->nombre[0] = '\0';
	this->contrasenya=0;
	this->edad=0;
	this->email=new char [1];
	this->email[0] = '\0';
	this->puntos=0;
	this->libros=NULL;

}
Cliente::Cliente(Cliente &c){
	this->nombre = new char[strlen(c.nombre) + 1];
		strcpy(this->nombre, c.nombre);
	this->contrasenya=c.contrasenya;
	this->edad = c.edad;
	this->email=new char [strlen(c.email)+1];
		this->email=c.email;
	this->puntos=c.puntos;
	this->libros=libros;

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
	delete [] this->email;
	delete [] this->nombre;
}

