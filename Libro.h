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

class Libro
{
private:
	int nSerie;
	char autor;
	int fechaLanzamiento;

public:
	Libro(const int nSerie, const char autor, const int fechaLanzamiento);
	Libro();
	Libro(Libro &l);
	virtual ~Libro();

};


#endif /* LIBRO_H_ */
