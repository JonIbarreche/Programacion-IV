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

#include "sqlite3.h"
using namespace std;

class Biblioteca
{
private:
	int id;
	char *nombre;
	char *ubicacion;
	Libro **libros;
	int num_libro;

public:
	Biblioteca(const int id, char* nombre, char* ubicacion, Libro *libros, int num_libro);
	Biblioteca();
	Biblioteca(Biblioteca &b);
	void aniadirLibros(Libro *libro);
	virtual ~Biblioteca();
	void imprimirLibros();
	int showAllBibliotecas(sqlite3 *db);
	int insertNewBiblio(sqlite3 *db, char nombre[],char ubicacion[],Libro* libros, int num_libro);

};



#endif /* BIBLIOTECA_H_ */
