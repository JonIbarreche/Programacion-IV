/*
 * Main.cpp
 *
 *  Created on: 27 may. 2021
 *      Author: leire
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Biblioteca.h"
#include "Cliente.h"
#include "Libro.h"

#include "sqlite3.h"
#include "Base1.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcion1;
	bool bucle = true;

	int idl, prec;
		char tit[100];
		char autor[100];

	char nombre[20];
	char clave[20];
	char cadena[100];
	FILE *fichero;
	char nombre_buscar[20];
	char clave_buscar[20];
	bool encontrado;

	Base1 a;
	a.baseiniciar();
	a.creartablas();
	a.registrarBiblioteca();
	a.registrarLibro();
	a.registrarReserva();

	while (bucle) {
		printf("Menu Principal\n\n");
		printf("\n   Escoge una opción:");
		printf("\n   1. Iniciar sesión como usuario.");
		printf("\n   2. Iniciar sesión como trabajador.");
		printf("\n   3. Registrarse.");
		printf("\n   4. Salir.");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			printf("\n   Introduzca su usuario: ");
			fflush(stdin);
			scanf("%s", nombre_buscar);
			printf("\n   Introduzca su contraseña: ");
			fflush(stdin);
			scanf("%s", clave_buscar);

			if ((fichero = fopen("usuarios.txt", "rt")) == NULL) {
				printf("No se puede abrir el fichero.\n");
				exit(1);
			}

			encontrado = false;
			while (fscanf(fichero, "%s %s", nombre, clave) != EOF) {
				if (strcmp(nombre, nombre_buscar) == 0
						&& strcmp(clave, clave_buscar) == 0) {
					encontrado = true;
				}
			}

			fclose(fichero);

			if (encontrado) {
				printf("\n   Inicio de sesión con exito! ");
				printf("\n");
				printf("\n   Seleccione acción: ");
				printf("\n   1. Escoger libro. ");
				printf("\n   2. Informacion de los libros. ");
				fflush(stdin);
				scanf("%d", &opcion);

				switch (opcion) {

				case 1:
					printf("\n  Escribe el nserie del libro  ");
					fflush(stdin);
					scanf("%d", &opcion);
					a.leer1Libro(opcion);
					printf("\n   Desea ver en que biblioteca esta? ");
									printf("\n");
									printf("\n   Seleccione acción: ");
									printf("\n   1. si ");
									printf("\n   2. no ");
									fflush(stdin);
									scanf("%d", &opcion1);
									switch (opcion1) {
									case 1:
										a.leer1Biblioteca(opcion);
										break;
									case 2:
										break;

									}
									break;

				case 2:
					printf("\n Informacion de los libros.");
					a.leerLibro();
					break;
				}
				printf("\n\n\n");
			} else {
				printf("\n   Usuario - Contraseña no registrado! ");
				printf("\n\n\n");

				printf("\n   ¿Desea recordar la contraseña?:");
				printf("\n   1. Si.");
				printf("\n   2. No.");

				fflush(stdin);
				scanf("%d", &opcion1);

				switch (opcion1) {
				case 1:

					printf("\n\n");
					printf("Nombre usuario a buscar: ");
					fflush(stdin);
					fgets(cadena, 20, stdin);
					sscanf(cadena, "%s", nombre_buscar);
					if ((fichero = fopen("usuarios.txt", "rt")) == NULL) {
						printf("No se puede abrir el fichero.\n");
						exit(1);
					}

					while (fscanf(fichero, "%s %s", nombre, clave) != EOF) {
						if (strcmp(nombre_buscar, nombre) == 0) {
							printf("Nombre usuario: %s\n", nombre);
							printf("Clave: %s\n", clave);
						}
					}

					fclose(fichero);

					break;
				case 2:
					fclose(fichero);
					break;
				}
			}
			break;

		case 2:
			printf("\n   Introduzca su usuario: ");
			fflush(stdin);
			scanf("%s", nombre_buscar);
			printf("\n   Introduzca su contraseña: ");
			fflush(stdin);
			scanf("%s", clave_buscar);

			if ((fichero = fopen("usuarios.txt", "rt")) == NULL) {
				printf("No se puede abrir el fichero.\n");
				exit(1);
			}

			encontrado = false;
			while (fscanf(fichero, "%s %s", nombre, clave) != EOF) {
				if (strcmp(nombre, nombre_buscar) == 0
						&& strcmp(clave, clave_buscar) == 0) {
					encontrado = true;
				}
			}

			fclose(fichero);

			if (encontrado) {
				printf("\n   Inicio de sesión con exito! ");
				printf("\n");
				printf("\n   Seleccione acción: ");
				printf("\n   1. Ver reservas. ");
				printf("\n   2. Devolver libro. ");
				printf("\n   3. Añadir libro. ");
				printf("\n   4. Eliminar libro. ");
				fflush(stdin);
				scanf("%d", &opcion);

				switch (opcion) {

				case 1:
					a.leerReserva();
					break;
				case 2:
					printf("\n Libro devuelto.");
					break;
				case 3:
				{


						printf("\n  Escribe el nserie del libro  ");
						fflush(stdin);
						scanf("%d", &idl);
						printf("\n  Escribe el titulo del libro  ");
						fflush(stdin);
						gets(tit);
						printf("\n  Escribe el autor del libro  ");
						fflush(stdin);
						gets(autor);
						printf("\n  Escribe el precio del libro  ");
						fflush(stdin);
						scanf("%d", &prec);

						a.insertar1Libro(idl,tit,autor,prec);
						a.leer1Libro(idl);
					break;
				}
					break;

				case 4:
					printf("\n  Escribe el nserie del libro  ");
						fflush(stdin);
						scanf("%d", &opcion);
						a.borrarLibro(opcion);
					break;
				}
				printf("\n\n\n");
			} else {
				printf("\n   Usuario - Contraseña no registrado! ");
				printf("\n\n\n");

				printf("\n   ¿Desea recordar la contraseña?:");
				printf("\n   1. Si.");
				printf("\n   2. No.");

				fflush(stdin);
				scanf("%d", &opcion1);

				switch (opcion1) {
				case 1:

					printf("\n\n");
					printf("Nombre usuario a buscar: ");
					fflush(stdin);
					fgets(cadena, 20, stdin);
					sscanf(cadena, "%s", nombre_buscar);
					if ((fichero = fopen("usuarios.txt", "rt")) == NULL) {
						printf("No se puede abrir el fichero.\n");
						exit(1);
					}

					while (fscanf(fichero, "%s %s", nombre, clave) != EOF) {
						if (strcmp(nombre_buscar, nombre) == 0) {
							printf("Nombre usuario: %s\n", nombre);
							printf("Clave: %s\n", clave);
						}
					}

					fclose(fichero);

					break;
				case 2:
					fclose(fichero);
					break;
				}
			}

			break;

		case 3:

			if ((fichero = fopen("usuarios.txt", "at")) == NULL) {
				printf("No se puede abrir el fichero.\n");
				exit(1);
			}

			do {
				printf("\n\n");
				printf("Introduzca su usuario ");
				printf(" O escriba fin para salir del registro: ");
				fflush(stdin);
				fgets(cadena, 20, stdin);
				sscanf(cadena, "%s", nombre);

				if (strcmp(nombre, "fin") != 0) {
					printf("Introduzca su contraseña:  ");
					fflush( stdin);
					fgets(cadena, 20, stdin);
					sscanf(cadena, "%s", clave);
					printf("\n   Registro con exito! ");

					/* Guarda el registro en el fichero */
					fprintf(fichero, "%s %s\n", nombre, clave);

				}
			} while (strcmp(nombre, "fin") != 0);

			fclose(fichero);

			break;

		case 4:
			printf("\n   Adiós. ");
			bucle = false;
			break;

		default:
			printf("Opcion no valida vuelva a intentar");

		}
	}

	return 0;

	return EXIT_SUCCESS;
}
