/*
 * ConEdicion.h
 *
 *  Created on: 21 jun. 2021
 *      Author: leire
 */

#ifndef CONEDICION_H_
#define CONEDICION_H_

#include "Libro.h"

class ConEdicion: public Libro
{
	char** nombreEdicion;
	int num_ediciones;

public:
	ConEdicion( const int nSerie,const char *titulo, const char *autor, const int precio, int num_ediciones, char **nombreEdicion);
	ConEdicion(const ConEdicion &);
	virtual ~ConEdicion();

	virtual void imprimir();

};


#endif /* CONEDICION_H_ */
