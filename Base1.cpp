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
	baseiniciar();
	char *error = 0;
	int res, res1, res2;
	const char *sql;
	const char *sql1;
	const char *sql2;

	sql = "CREATE TABLE LIBROS ("
			"NSERIE NUMBER PRIMARY KEY, "
			"TITULO TEXT, "
			"AUTOR TEXT, "
			"PRECIO NUMBER );";

	sql1 = "CREATE TABLE BIBLIOTECA ("
			"ID NUMBER PRIMARY KEY, "
			"NOMBRE TEXT, "
			"UBICACION TEXT, "
			"CODLIB NUMBER references Libro(NSERIE);";

	sql2 = "CREATE TABLE RESERVA ("
			"CODRESERVA NUMBER PRIMARY KEY, "
			"CLIENTE TEXT, "
			"CODLIB NUMBER references Libro(NSERIE), "
			"DIA NUMBER ,"
			"HORA NUMBER);";

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
	res2 = sqlite3_exec(db, sql2, NULL, 0, &error);
	if (res2 != SQLITE_OK) {
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
			"INSERT INTO LIBROS (NSERIE, TITULO, AUTOR, PRECIO) VALUES(11, 'Profundis', 'OscarWilde', 20);";
	char const *sql1 =
			"INSERT INTO Libros(NSERIE, TITULO, AUTOR, PRECIO) VALUES(12, 'LaIsla', 'JulioVerne', 35);";
	char const *sql2 =
			"INSERT INTO Libros(NSERIE, TITULO, AUTOR, PRECIO) VALUES(13, 'Profundis', 'OscarWilde', 19);";
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

	sqlite3_prepare_v2(db, "SELECT * from LIBROS", -1, &stmt, NULL);
	sqlite3_exec(db, "SELECT * from LIBROS", callback, 0, NULL);

}

void Base1::registrarReserva() {
	baseiniciar();
	int res, res1, res2;
	char *error = 0;

	char const *sql =
			"INSERT INTO RESERVA(CODRESERVA, CLIENTE, CODLIB, DIA, HORA) VALUES(1, 'Xabier', 11, 1, 4);";
	char const *sql1 =
			"INSERT INTO RESERVA(CODRESERVA, CLIENTE, CODLIB, DIA, HORA) VALUES(2, 'Unai', 12, 2, 3);";
	char const *sql2 =
			"INSERT INTO RESERVA(CODRESERVA, CLIENTE, CODLIB, DIA, HORA) VALUES(3, 'Asier', 13, 8, 6);";
	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Reserva añadida!\n");
	}
	res1 = sqlite3_exec(db, sql1, NULL, 0, &error);
	if (res1 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Reserva añadida!\n");
	}
	res2 = sqlite3_exec(db, sql2, NULL, 0, &error);
	if (res2 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Reserva añadida!\n");
	}
}

void Base1::leerReserva() {
	baseiniciar();
	sqlite3_stmt *stmt;
	char *t;
	char *ec;

	sqlite3_prepare_v2(db, "SELECT * from RESERVA", -1, &stmt, NULL);
	sqlite3_exec(db, "SELECT * from RESERVA", callback, 0, NULL);

}

void Base1::registrarBiblioteca() {
	baseiniciar();
	int res, res1;
	char *error = 0;
	char const *sql =
			"INSERT INTO BIBLIOTECA(ID, NOMBRE, UBICACION, CODLIB) VALUES(1, 'Biblio1','Gazteiz', 11);";
	char const *sql1 =
			"INSERT INTO BIBLIOTECA(ID, NOMBRE, UBICACION, CODLIB) VALUES(2, 'Biblio2', 'Bilbao', 12);";

	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Biblioteca añadida!\n");
	}
	res1 = sqlite3_exec(db, sql1, NULL, 0, &error);
	if (res1 != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Biblioteca añadida!\n");
	}

}

void Base1::leerBiblioteca() {
	baseiniciar();
	sqlite3_stmt *stmt;
	char *t;
	char *ec;

	sqlite3_prepare_v2(db, "SELECT * from BIBLIOTECA", -1, &stmt, NULL);
	sqlite3_exec(db, "SELECT * from BIBLIOTECA", callback, 0, NULL);

}

void Base1::cerrar() {
	sqlite3_close(db);
}

