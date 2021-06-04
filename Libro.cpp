/*
 * Libro.cpp
 *
 *  Created on: 29 may. 2021
 *      Author: leire
 */


#include "Libro.h"
#include <stdio.h>

#include "sqlite3.h"


Libro::Libro(const int nSerie,const char *titulo, const char *autor, const int precio){

	this->nSerie= nSerie;
	this->titulo = new char[strlen(titulo) + 1];
			strcpy(this->titulo, titulo);
	this->autor = new char[strlen(autor) + 1];
			strcpy(this->autor, autor);
	this->precio= precio;
}
Libro::Libro(){

	this->nSerie= 0;
	this->autor = new char[1];
		this->autor[0] = '\0';
	this->titulo = new char[1];
		this->titulo[0] = '\0';
	this->precio= 0;

}
Libro::Libro(Libro &l){

	this->nSerie= l.nSerie;
	this->titulo = new char[strlen(l.titulo) + 1];
		strcpy(this->titulo, l.titulo);
	this->autor = new char[strlen(l.autor) + 1];
		strcpy(this->autor, l.autor);
	this->precio= l.precio;

}
Libro::~Libro(){

	delete []titulo;
	delete[] autor;

}
int Libro::getNSerie() const
{
	return nSerie;
}

char* Libro::getTitulo() const{
	return titulo;
}
char* Libro::getAutor() const{
	return autor;
	}
int Libro::getPrecio() const{
	return precio;
}

void Libro::setNSerie(int nSerie){
	this->nSerie = nSerie;
}
void Libro::setTitulo(char * titulo){
	this->titulo = new char[strlen(titulo) + 1];
				strcpy(this->titulo, titulo);
}
void Libro::setAutor(char * autor){
	this->autor = new char[strlen(autor) + 1];
				strcpy(this->autor, autor);
}
void Libro::setprecio(int precio){
	this->precio = precio;
}


int showAllLibros(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select nSerie, titulo from Libros";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int nSerie;
	char titulo[100];

	printf("\n");
	printf("\n");
	printf("Showing Libros:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			nSerie = sqlite3_column_int(stmt, 0);
			strcpy(titulo, (char *) sqlite3_column_text(stmt, 1));
			printf("ID: %d Name: %s\n", nSerie, titulo);
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

int insertNewLibro(sqlite3 *db, char titulo[],char autor[], int precio) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into Libros (nSerie, name) values (NULL, ?,?,?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, titulo, strlen(titulo), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 2, autor, strlen(autor), SQLITE_STATIC);
	//result = sqlite3_bind_text(stmt, 2, precio, precio, SQLITE_STATIC);
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
