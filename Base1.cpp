/*
 * Base.cpp
 *
 *  Created on: 18 may. 2020
 *      Author: Xabier
 */

#include "Base1.h"
#include "sqlite3.h"

using namespace std;

Base1::~Base1() {
	// TODO Auto-generated destructor stub
}

sqlite3* Base1::getc() {
	return this->db;
}

static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*) data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

void Base1::baseiniciar() {

	int res;
	/* Open database */
	res = sqlite3_open("data.db", &db);
	if (res) {
		fprintf(stderr, "No puedo abrir la base de datos: %s\n",
				sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stderr, "Base de datos OK\n");
	}
	/* Create SQL statement */

}

void Base1::creartablas() {
	char *error = 0;
	int res, res1, res2;
	const char *sql;
	const char *sql1;
	const char *sql2;

	sql = "CREATE TABLE Libros ("
			"NSerie NUMBER PRIMARY KEY, "
			"Titulo TEXT, "
			"Autor TEXT, "
			"Precio NUMBER );";

	sql1 = "CREATE TABLE Biblioteca ("
			"Id NUMBER PRIMARY KEY, "
			"Nombre TEXT, "
			"Ubicacion TEXT, "
			"CodLib NUMBER references Libro(NSerie);";

	sql2 = "CREATE TABLE Reserva ("
			"CodReserva NUMBER PRIMARY KEY, "
			"Cliente TEXT, "
			"CodLib NUMBER references Libro(NSerie), "
			"Dia NUMBER ,"
			"Hora NUMBER);";

	/* Execute SQL statement */
	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {

	}
	res1 = sqlite3_exec(db, sql1, NULL, 0, &error);
	if (res1 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {

	}
	res2 = sqlite3_exec(db, sql1, NULL, 0, &error);
	if (res1 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {

	}

}


void Base1::registrarLibro() {
	baseiniciar();
	int res, res1, res2;
	char *error = 0;
	char const *sql =
			"INSERT INTO Libros(nSerie, titulo, autor,  precio) VALUES(11, 'Profundis', 'OscarWilde', 20);";
	char const *sql1 =
			"INSERT INTO Libros(nSerie, titulo, autor, precio) VALUES(12, 'LaIsla', 'JulioVerne', 35);";
	char const *sql2 =
			"INSERT INTO Libros(nSerie, titulo, autor, precio) VALUES(13, 'Profundis', 'OscarWilde', 19);";
	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Libro añadido!\n");
	}
	res1 = sqlite3_exec(db, sql1, NULL, 0, &error);
	if (res1 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Libro Añadido!\n");
	}
	res2 = sqlite3_exec(db, sql2, NULL, 0, &error);
	if (res2 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Libro Añadido!\n");
	}
}
void Base1::leerLibro() {
	baseiniciar();
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, "select * from Libros", -1, &stmt, NULL);
	sqlite3_exec(db, "SELECT * FROM Libros", callback, 0, NULL);

}

void Base1::registrarReserva() {
	baseiniciar();
	int res, res1, res2;
	char *error = 0;
	char *error1 = 0;
	char *error2 = 0;
	char const *sql =
			"INSERT INTO Reserva(CodReserva, Cliente, CodLib, Dia, Hora) VALUES(1, 'Xabier', 11, 1, 4);";
	char const *sql1 =
			"INSERT INTO Reserva(CodReserva, Cliente, CodLib, Dia, Hora) VALUES(1, 'Unai', 11, 1, 4);";
	char const *sql2 =
			"INSERT INTO Reserva(CodReserva, Cliente, CodLib, Dia, Hora) VALUES(1, 'Asier', 11, 1, 4);";
	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Reserva añadida!\n");
	}
	res1 = sqlite3_exec(db, sql1, NULL, 0, &error1);
	if (res1 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Reserva añadida!\n");
	}
	res2 = sqlite3_exec(db, sql2, NULL, 0, &error2);
	if (res2 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Reserva añadida!\n");
	}
}
void Base1::registrarBiblioteca() {
	baseiniciar();
	int bib, bib1;
	char *error = 0;
	char *error1 = 0;
	char const *sql =
			"INSERT INTO Biblioteca(id, nombre, ubicacion, libros) VALUES(1, 'Biblio1','Gazteiz', 4);";
	char const *sql1 =
			"INSERT INTO Biblioteca(id, nombre, ubicacion, libros) VALUES(2, 'Biblio2', 'Bilbao', 4);";

	bib = sqlite3_exec(db, sql, NULL, 0, &error);
	if (error != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Biblioteca añadida!\n");
	}
	bib1 = sqlite3_exec(db, sql1, NULL, 0, &error1);
	if (error1 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error1);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Biblioteca añadida!\n");
	}

}
void Base1::leerReserva() {
	baseiniciar();
	sqlite3_stmt *stmt;
	char *t;
	char *ec;

	sqlite3_prepare_v2(db, "select * from Reserva", -1, &stmt, NULL);
	sqlite3_exec(db, "SELECT * FROM Reserva", callback, 0, NULL);

}

void Base1::cerrar() {
	sqlite3_close(db);
}

