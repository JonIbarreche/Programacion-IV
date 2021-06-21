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
	int diasAlquilados;

public:

	LibroDigital( const int nSerie,const char *titulo, const char *autor, const int precio, int diasAlquilados);
	LibroDigital( LibroDigital &);
		virtual ~LibroDigital();

	void setdiasAlquilados(int);
	int getdiasAlquilados() const;

		virtual void imprimir();
};

#endif /* LIBRODIGITAL_H_ */
