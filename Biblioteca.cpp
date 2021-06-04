/*
 * Biblioteca.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */


#include "Biblioteca.h"
#include "Libro.h"
#include <iostream>
#include <string.h>

using namespace std;

Biblioteca::Biblioteca(const int id,const int Usuario, const int contrasena, char* nombre, char* ubicacion, Libro* libros, int num_libro){
	this->id=id;
	this->Usuario=Usuario;
	this->contrasena= contrasena;
	this->nombre = new char[strlen(nombre) + 1];
		strcpy(this->nombre, nombre);
	this->ubicacion = new char[strlen(ubicacion) + 1];
		strcpy(this->ubicacion, ubicacion);
	this->libros = libros;
	this->num_libro=num_libro;

}
Biblioteca::Biblioteca(){

	this->id=0;
	this->Usuario=0;
	this->contrasena= 0;
	this->nombre = new char[1];
	this->nombre[0] = '\0';
	this->ubicacion = new char[1];
	this->ubicacion[0] = '\0';
	this->libros= NULL;
	this->num_libro=0;
}
Biblioteca::Biblioteca(Biblioteca &b){

	this->id=b.id;
	this->Usuario=b.Usuario;
	this->contrasena= b.contrasena;
	this->nombre = new char[strlen(b.nombre) + 1];
		strcpy(this->nombre, b.nombre);
	this->ubicacion = new char[strlen(b.ubicacion) + 1];
		strcpy(this->ubicacion, b.ubicacion);
	this->libros= b.libros;
	this->num_libro=b.num_libro;

}
Biblioteca::~Biblioteca(){


}
void Biblioteca::aniadirLibros(Libro * libro){
	Libro **libros = new Libro *[this->num_libro + 1];
		for (int i = 0;i < this->num_libro;i++) {
			libros[i] = this->libros[i];
		}
		libros[this->num_libro] = libro;
		this->num_libro++;
		delete [] this->libros;
		this->libros = libros;
}
void Biblioteca::imprimirLibros(){

	for (int i = 0;i < this->num_libro;i++)  {
			cout << "Libro " << i+1 << ": " << this->libros[i].getNSerie() << ",s " << this->libros[i].getTitulo() << ", " <<" " << this->libros[i].getAutor() <<", "  << this->libros[i].getPrecio() << endl;
}
}
