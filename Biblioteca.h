/*
 * Biblioteca.h
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include "Libro.h"
#include <iostream>
#include <string.h>

using namespace std;

class Biblioteca
{
private:
	int id;
	int Usuario;
	int contrasena;
	char *nombre;
	char *ubicacion;
	Libro *libros;
	int num_libro;

public:
	Biblioteca(const int id,const int Usuario, const int contrasena, char* nombre, char* ubicacion, Libro *libros, int num_libro);
	Biblioteca();
	Biblioteca(Biblioteca &b);
	void aniadirLibros(Libro *libro);
	virtual ~Biblioteca();
	void imprimirLibros();
};



#endif /* BIBLIOTECA_H_ */
