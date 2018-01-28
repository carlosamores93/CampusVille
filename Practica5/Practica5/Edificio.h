#ifndef EDIFICIO_H
#define EDIFICIO_H

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

// Declaracion de tipos y constantes
const int MAX_CADENA = 50;
typedef char tCadena[MAX_CADENA];
typedef enum{
	disponible, comprado, borrado
}tEstadoEdificio;

typedef struct{
	int codigo;
	tCadena nombre; // Puede contener espacios cin.getline(nombre, MAX);
	int precio;
	int dinero;
	int prestigio;
	tEstadoEdificio estado;
}tEdificio;

typedef tEdificio *tEdifPtr;

// Declaracion de prototipos

//Función para mostrar un detalles todos los campos de un edificios(nombre, precio, prestigio ect)
//Entrada: una estructura edificio
//Salida: nada
//Devuelve: no devuielve nada
void mostrarEdificio(tEdificio edificio);

//Función para pedir al usuario un nuevo edificio y añadirlo a la lista de edificios de tamaño variable(con otro subprograma)
//Entrada: nada
//Salida: nada
//Devuelve: una estructura edificio
tEdificio nuevoEdificio();

#endif