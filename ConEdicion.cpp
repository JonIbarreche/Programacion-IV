/*
 * ConEdicion.cpp
 *
 *  Created on: 21 jun. 2021
 *      Author: leire
 */

#include "ConEdicion.h"
#include <iostream>
#include <string.h>

#include "sqlite3.h"

using namespace std;

ConEdicion::ConEdicion( const int nSerie,const char *titulo, const char *autor, const int precio, int num_ediciones, char **nombreEdicion):Libro(nSerie,titulo,autor,precio){

	this->num_ediciones= num_ediciones;
	for (int i = 0; i < num_ediciones; i++) {


	//this->nombreEdicion[i] = new char[i][nombreEdicion];
	}

}

/*ConEdicion::ConEdicion(const ConEdicion &ce):Libro(ce) {
	this->num_ediciones= ce.num_ediciones;
		for (int i = 0; i < ce.num_ediciones; i++) {


		this->nombreEdicion[i] = new char[i][ce.nombreEdicion];
		}
}*/
ConEdicion::~ConEdicion(){
delete[] this->nombreEdicion;
}

void ConEdicion::imprimir(){
	Libro::imprimir();
		cout << endl;
		cout << "LLibro:" << endl;
		cout << "-----" << endl;
		for (int j=0;j<this->num_ediciones;j++)
		{
			cout << "ediciones" << j+1 << ": " << this->nombreEdicion[j];
		}
}
