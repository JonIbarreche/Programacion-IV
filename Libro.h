/*
 * Libro.h
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include <iostream>
#include <string.h>

#include "sqlite3.h"

class Libro
{
private:
	int nSerie;
	char *titulo;
	char *autor;
	int precio;
public:
	Libro(const int nSerie, const char *titulo,const char *autor, const int precio);
	Libro();
	Libro(Libro &l);
	virtual ~Libro();

	int getNSerie() const;
	char* getTitulo() const;
	char* getAutor() const;
	int getPrecio() const;
	void setNSerie(int nSerie);
	void setTitulo(char * titulo);
	void setAutor(char * autor);
	void setprecio(int precio);


	int showAllLibros(sqlite3 *db);
	int insertNewCountry(sqlite3 *db, char titulo[],char autor[], int precio);

};


#endif /* LIBRO_H_ */
