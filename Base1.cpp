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

	const char *sql2;

	sql = "CREATE TABLE LIBROS ("
			"NSERIE NUMBER PRIMARY KEY, "
			"TITULO TEXT, "
			"AUTOR TEXT, "
			"PRECIO NUMBER );";

	const char *sql1 = "CREATE TABLE BIBLIOTECA ("
			"ID NUMBER PRIMARY KEY, "
			"NOMBRE TEXT, "
			"UBICACION TEXT, "
			"NSERIE NUMBER, "
			"FOREIGN KEY(NSERIE) REFERENCES LIBROS(NSERIE) );";
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
void Base1::leer1Libro(int nserie) {
	baseiniciar();
	sqlite3_stmt *stmt;

	//Convertimos el entero con el numero de serie a buscar a un array de char y asi poder concatenarlo a la select
	char cadena[100] = "SELECT * from LIBROS where NSERIE = ";
	char cad[100];
	sprintf(cad, "%d", nserie);

	strcat(cadena, cad);
	int result = sqlite3_prepare_v2(db, cadena, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return;
	}

	char titulo[100];
	char autor[100];

	result = sqlite3_step(stmt) ;
	if (result == SQLITE_ROW) {
		int serie = sqlite3_column_int(stmt, 0);
		strcpy(titulo, (char *) sqlite3_column_text(stmt, 1));
		strcpy(autor, (char *) sqlite3_column_text(stmt, 2));
		int precio = sqlite3_column_int(stmt, 0);
		printf("N.Serie: %d Titulo: %s Autor: %s Precio: %d\n", serie, titulo, autor, precio);
	} else {
		printf("No encontrado libro con n.serie: %d\n", nserie);
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return;
	}
	}

void Base1::insertar1Libro(int nserie, char* titulo, char* autor, int precio) {
	baseiniciar();
	sqlite3_stmt *stmt;

	int res;
	char *error = 0;
	char * sql = new char[200];
	strcpy(sql, "INSERT INTO LIBROS (NSERIE, TITULO, AUTOR, PRECIO) VALUES(");
	char cad1[100];
	sprintf(cad1, "%d", nserie);
	strcat(sql, cad1);
	char * cad2 = (char *) ", '";
	strcat(sql, cad2);
	strcat(sql, titulo);
	char * cad3 = (char *) "', '";
	strcat(sql, cad3);
	strcat(sql, autor);
	char * cad4 = (char *) "', ";
	strcat(sql, cad4);
	char cad5[100];
	sprintf(cad5, "%d", precio);
	strcat(sql, cad5);
	char * cad6 = (char *) ");";
	strcat(sql, cad6);

	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", error);
		sqlite3_free(error);
	} else {
		fprintf(stdout, "Libro añadido!\n");
	}

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
			"INSERT INTO BIBLIOTECA(ID, NOMBRE, UBICACION, NSERIE) VALUES(1, 'Biblio1','Gazteiz', 11);";
	char const *sql1 =
			"INSERT INTO BIBLIOTECA(ID, NOMBRE, UBICACION, NSERIE) VALUES(2, 'Biblio2', 'Bilbao', 12);";

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
void Base1::leer1Biblioteca(int nserie) {
	baseiniciar();
	sqlite3_stmt *stmt;

	//Convertimos el entero con el numero de serie a buscar a un array de char y asi poder concatenarlo a la select
	char cadena[100] = "SELECT * from BIBLIOTECA where NSERIE = ";
	char cad[100];
	sprintf(cad, "%d", nserie);

	strcat(cadena, cad);
	int result = sqlite3_prepare_v2(db, cadena, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return;
	}

	char nombre[100];
	char ubicacion[100];

	result = sqlite3_step(stmt) ;
	if (result == SQLITE_ROW) {
		int serie = sqlite3_column_int(stmt, 0);
		strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
		strcpy(ubicacion, (char *) sqlite3_column_text(stmt, 2));
		int id = sqlite3_column_int(stmt, 0);

		printf("id: %d nombre: %s ubicacion: %s N.Serie: %d\n", id, nombre, ubicacion, serie);
	} else {
		printf("No encontrado biblio con n.serie: %d\n", nserie);
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return;
	}
	}
void Base1::cerrar() {
	sqlite3_close(db);
}

