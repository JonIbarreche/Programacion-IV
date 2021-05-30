/*
 * Cliente.h
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Libro.h"
class Cliente
{
private:
	char* nombre;
	int contrasenya;
	int edad;
	char *email;
	int puntos;
	Libro *libros;

public:
	Cliente(const char *nombre, const int contrasenya, const int edad, const char *email, const int puntos,const Libro *libros);
	Cliente();
	Cliente(Cliente &c);
	virtual ~Cliente();
};



#endif /* CLIENTE_H_ */
