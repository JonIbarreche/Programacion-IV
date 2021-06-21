/*
 * ConEdicion.h
 *
 *  Created on: 21 jun. 2021
 *      Author: leire
 */

#ifndef LIBROPAPEL_H_
#define LIBROPAPEL_H_

#include "Libro.h"

class LibroPapel: public Libro
{
	int precioEnvio;
	int diasAlquilados;

public:
	LibroPapel( const int nSerie,const char *titulo, const char *autor, const int precio, int precioEnvio, int diasAlquilados);
	LibroPapel( LibroPapel &);
	virtual ~LibroPapel();

	void setprecioEnvio(int);
	int getprecioEnvio() const;
	void setdiasAlquilados(int);
	int getdiasAlquilados() const;


	virtual void imprimir();

};


#endif /* LIBROPAPEL_H_ */
