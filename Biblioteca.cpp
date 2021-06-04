/*
 * Biblioteca.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */


#include "Biblioteca.h"
#include "Libro.h"
#include <iostream>
#include <string.h>

#include "sqlite3.h"

using namespace std;

Biblioteca::Biblioteca(const int id, char* nombre, char* ubicacion, Libro* libros, int num_libro){
	this->id=id;

	this->nombre = new char[strlen(nombre) + 1];
		strcpy(this->nombre, nombre);
	this->ubicacion = new char[strlen(ubicacion) + 1];
		strcpy(this->ubicacion, ubicacion);

		this->libros[this->num_libro] = libros;
		this->num_libro++;

}
Biblioteca::Biblioteca(){

	this->id=0;
	this->nombre = new char[1];
	this->nombre[0] = '\0';
	this->ubicacion = new char[1];
	this->ubicacion[0] = '\0';
	this->libros= NULL;
	this->num_libro=0;
}
Biblioteca::Biblioteca(Biblioteca &b){

	this->id=b.id;
	this->nombre = new char[strlen(b.nombre) + 1];
		strcpy(this->nombre, b.nombre);
	this->ubicacion = new char[strlen(b.ubicacion) + 1];
		strcpy(this->ubicacion, b.ubicacion);
	this->libros= b.libros;
	this->num_libro=b.num_libro;

}
Biblioteca::~Biblioteca(){


}
void Biblioteca::aniadirLibros(Libro * libro){
	Libro **libros = new Libro *[this->num_libro + 1];
		for (int i = 0;i < this->num_libro;i++) {
			libros[i] = this->libros[i];
		}
		libros[this->num_libro] = libro;
		this->num_libro++;
		delete [] this->libros;
		this->libros = libros;
}
/*void Biblioteca::imprimirLibros(){

	for (int i = 0;i < this->num_libro;i++)  {
			cout << "Libro " << i+1 << ": " << this->libros[i].getNSerie() << ",s " << this->libros[i].getTitulo() << ", " <<" " << this->libros[i].getAutor() <<", "  << this->libros[i].getPrecio() << endl;
}
}*/

int showAllBibliotecas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre from Biblioteca";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int id;
	char nombre[100];

	printf("\n");
	printf("\n");
	printf("Showing Libros:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			printf("ID: %d Name: %s\n", id, nombre);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int insertNewBiblio(sqlite3 *db, char nombre[],char ubicacion[],Libro* libros, int num_libro) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into Biblioteca (id, nombre, ubicacion, libros, num_libro) values (NULL, ?,?,?,?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 2, ubicacion, strlen(ubicacion), SQLITE_STATIC);
	int i;
	for (i = 0; i < num_libro; i++) {
		//result = sqlite3_bind_text(stmt, 2, libros->getTitulo(), libros->getTitulo(), SQLITE_STATIC);
	}

	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Libros table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

