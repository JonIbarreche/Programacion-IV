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
	int fechaLanzamiento;
	int precio;
public:
	Libro(const int nSerie, const char *titulo,const char *autor, const int fechaLanzamiento, const int precio);
	Libro();
	Libro(Libro &l);
	virtual ~Libro();



};


#endif /* LIBRO_H_ */
