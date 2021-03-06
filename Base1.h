
/*
 * Base.h
 *
 *  Created on: 18 may. 2020
 *      Author: Xabier
 */

#ifndef BASE1_H_
#define BASE1_H_
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Base1 {
	sqlite3 *db;
public:

	//Base1();
	virtual ~Base1();

	void baseiniciar();
	void creartablas();

	void registrarLibro();
	void registrarReserva();
	void registrarBiblioteca();

	void leerBiblioteca();
	void leerReserva();
	void leerLibro();
	void leer1Libro(int);
	void insertar1Libro(int, char *, char *, int);
	void leer1Biblioteca(int );
	void cerrar();

	void borrarLibro(int);
	void borrarReserva();

	sqlite3* getc();

};

#endif /* BASE1_H_ */
