/*
 * LibroDigital.h
 *
 *  Created on: 21 jun. 2021
 *      Author: leire
 */

#ifndef LIBRODIGITAL_H_
#define LIBRODIGITAL_H_

#include "Libro.h"

class LibroDigital: public Libro
{
	char** nombreEdicion;
	int num_ediciones;

public:
	LibroDigital( const int nSerie,const char *titulo, const char *autor, const int precio, int num_ediciones, char **nombreEdicion);
	LibroDigital(const LibroDigital &);
	virtual ~LibroDigital();

	virtual void imprimir();

};

#endif /* LIBRODIGITAL_H_ */
