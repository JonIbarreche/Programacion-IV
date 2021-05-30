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

Biblioteca::Biblioteca(const int Usuario, const int contrasena, Libro* libros){

	this->Usuario=Usuario;
	this->contrasena= contrasena;
	this->libros = libros;


}
Biblioteca::Biblioteca(){

	this->Usuario=0;
	this->contrasena= 0;
	this->libros= NULL;
}
Biblioteca::Biblioteca(Biblioteca &b){

	this->Usuario=b.Usuario;
	this->contrasena= b.contrasena;
	this->libros= b.libros;

}
Biblioteca::~Biblioteca(){


}
