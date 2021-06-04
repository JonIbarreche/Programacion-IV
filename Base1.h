
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

	void registrarLibro();
	void registrarReserva();
	void registrarBiblioteca();

	void leerReserva();
	void leerLibro();

	void cerrar();
	void creartablas();

	sqlite3* getc();

};

#endif /* BASE1_H_ */
