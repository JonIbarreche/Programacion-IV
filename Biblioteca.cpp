/*
 * Biblioteca.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */


#include "Biblioteca.h"
#include <iostream>
#include <string.h>

using namespace std;

Biblioteca::Biblioteca(const int Usuario, const int contrasena, char* nombre, char* ubicacion, Libro* libros){

	this->Usuario=Usuario;
	this->contrasena= contrasena;
	this->nombre = new char[strlen(nombre) + 1];
		strcpy(this->nombre, nombre);
	this->ubicacion = new char[strlen(ubicacion) + 1];
		strcpy(this->ubicacion, ubicacion);
	this->libros = libros;


}
Biblioteca::Biblioteca(){

	this->Usuario=0;
	this->contrasena= 0;
	this->nombre = new char[1];
	this->nombre[0] = '\0';
	this->ubicacion = new char[1];
	this->ubicacion[0] = '\0';
	this->libros= NULL;
}
Biblioteca::Biblioteca(Biblioteca &b){

	this->Usuario=b.Usuario;
	this->contrasena= b.contrasena;
	this->nombre = new char[strlen(b.nombre) + 1];
		strcpy(this->nombre, b.nombre);
	this->ubicacion = new char[strlen(b.ubicacion) + 1];
		strcpy(this->ubicacion, b.ubicacion);
	this->libros= b.libros;

}
Biblioteca::~Biblioteca(){


}
