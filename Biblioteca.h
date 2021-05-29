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
	int Usuario;
	int contrasena;
	Libro libros [];

public:
	Biblioteca(const int Usuario, const int contrasena, const Libro libros[]);
	Biblioteca();
	Biblioteca(Biblioteca &b);
	virtual ~Biblioteca();

};



#endif /* BIBLIOTECA_H_ */
