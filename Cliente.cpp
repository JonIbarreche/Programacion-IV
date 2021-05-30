/*
 * Cliente.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */


#include "Cliente.h"
#include <stdio.h>
#include <iostream>
#include "Cliente.h"

using namespace std;
Cliente::Cliente(const char *nombre,int contrasenya,int edad, const char *email, int puntos, const Libro *libros){
	this->nombre = new char[strlen(nombre) + 1];
		strcpy(this->nombre, nombre);
	this->contrasenya=contrasenya;
	this->edad=edad;
	this->email = new char[strlen(email) + 1];
			strcpy(this->email, email);
	this->puntos=puntos;
	this->libros=new Libro [strlen(libros->titulo)+1];
		strcpy(this->libros->titulo,libros->titulo);
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
