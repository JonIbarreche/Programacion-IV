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
#include "LibroPapel.h"
#include "LibroDigital.h"
#include "SedeBiblioteca.h"
#include "Revista.h"
#include "SedeBiblioteca.c"
#include "Revista.c"


int main(void) {

	//datos prueba c++

	Libro l1(1,"libro1","autor1",12);
	Libro l2(2,"libro2","autor2",10);
	l1.imprimir();
	l2.imprimir();

	LibroDigital ld1(l1.getNSerie(),l1.getTitulo(),l1.getAutor(),l1.getPrecio(),7);
	ld1.imprimir();
	LibroPapel lp2(l2.getNSerie(),l2.getTitulo(),l2.getAutor(),l2.getPrecio(),4,7);
	lp2.imprimir();

	Biblioteca b1;
	b1.setid(1);
	b1.setnombre("biblioteca1");
	b1.setubicacion("Bilbao");
	b1.aniadirLibros(&l1);
	b1.imprimirBiblioteca();

	//datos prueba c
		//revistas
	cout<<"datos prueba c"<<endl;
	revista r1;
	r1.idrevista=1;  strcpy(r1.titulo,"Hola"); strcpy(r1.autor,"Agustin"); r1.precio=14;
	revista r2;
	r2.idrevista=2;  strcpy(r2.titulo,"Lecturas"); strcpy(r2.autor,"Roberto"); r2.precio=14;
	revista r3;
	r3.idrevista=3;  strcpy(r3.titulo,"Corazon"); strcpy(r3.autor,"Carmina"); r3.precio=22;
	cout<<"imprimir revista"<<endl;
	imprimirRevista(r1);

	Revistas rr1;
	rr1.numRevistas=2;
	rr1.revistas=&r1;
	rr1.revistas=&r2;
	cout<<"imprimir revistas"<<endl;
	imprimirRevistas1(rr1);

	cout<<"numero de revistas con precio menor que 15="<<endl;
	revista revistas[5];
	revistas[0].idrevista=1;strcpy(revistas[0].titulo,"Hola");strcpy(revistas[0].autor,"Hodei");revistas[0].precio=20;
	revistas[1].idrevista=2;strcpy(revistas[1].titulo,"Lecturas");strcpy(revistas[1].autor,"Carmen"); revistas[1].precio=14;
	revistas[2].idrevista=3;strcpy(revistas[2].titulo,"Corazon");strcpy(revistas[2].autor,"Carmina"); revistas[2].precio=20;
	revistas[3].idrevista=4;strcpy(revistas[3].titulo,"Una");strcpy(revistas[3].autor,"Juan"); revistas[3].precio=20;
	revistas[4].idrevista=5;strcpy(revistas[0].titulo,"Otra");strcpy(revistas[4].autor,"Pablo"); revistas[4].precio=14;

	printf("%i \n",cuantasRevistas(revistas, 5, 15));
	cout<<"revistas baratas (menos de 15 euros)"<< endl;
	int baratas;

	revista * revistass;
	revistass = (revista *)malloc(sizeof(revista) * 3);
	revistass[0] = r1;
	revistass[1] = r2;
	revistass[2] = r3;

	 	char **lista = listadoPrecioBarato(revistass, 5, &baratas);
		printf("\ revistas baratas:\n");
		int i;
		for (i = 0; i < baratas;i++) {
			printf("%s\n", lista[i]);
		}


		//biblios
	biblioteca bb1;
	bb1.id=1; strcpy(bb1.nombre,"biblio1");strcpy(bb1.ubicacion,"Bilbao");
	biblioteca bb2;
	bb2.id=2; strcpy(bb2.nombre,"biblio2");strcpy(bb2.ubicacion,"Donosti");
	cout<<"imprimir biblio"<<endl;
	imprimirbiblioteca(bb1);

	grupoBiblioteca gb1;
	gb1.numBibliotecas=2;
	gb1.bibliotecas=&bb1;
	gb1.bibliotecas=&bb2;
	cout<<"imprimir biblios"<<endl;
	imprimirbibliotecas1(gb1);


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
