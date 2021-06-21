/*
 * LibroDigital.cpp
 *
 *  Created on: 21 jun. 2021
 *      Author: leire
 */


#include <iostream>
#include <string.h>

#include "LibroDigital.h"
#include "sqlite3.h"

using namespace std;

LibroDigital::LibroDigital( const int nSerie,const char *titulo, const char *autor, const int precio, int num_ediciones, char **nombreEdicion):Libro(nSerie,titulo,autor,precio){

	this->num_ediciones= num_ediciones;
	for (int i = 0; i < num_ediciones; i++) {


	//this->nombreEdicion[i] = new char[i][nombreEdicion];
	}

}

/*LibroDigital::LibroDigital(const LibroDigital &ce):Libro(ce) {
	this->num_ediciones= ce.num_ediciones;
		for (int i = 0; i < ce.num_ediciones; i++) {


		this->nombreEdicion[i] = new char[i][ce.nombreEdicion];
		}
}*/
LibroDigital::~LibroDigital(){
delete[] this->nombreEdicion;
}

void LibroDigital::imprimir(){
	Libro::imprimir();
		cout << endl;
		cout << "LLibro:" << endl;
		cout << "-----" << endl;
		for (int j=0;j<this->num_ediciones;j++)
		{
			cout << "ediciones" << j+1 << ": " << this->nombreEdicion[j];
		}
}
