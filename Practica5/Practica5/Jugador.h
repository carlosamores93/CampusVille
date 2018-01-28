#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include<cstring>
#include<iomanip>
#include"ListaEdificios.h" // Incluye para saber el maximo de edificios
using namespace std;

// Declaracion de tipos y constantes
int const DINERO = 3000;
typedef int tCodigo[MAX_EDIFICIOS];
typedef struct{
	tCodigo codigo;
	int contador;
}tEdificiosComprados;

typedef struct{
	tCadena usuario; //Cadena sin espacios
	tCadena password; //Cadena sin espacios
	tCadena universidad; //Cadena con espacios
	int dinero;
	int prestigio;
	tEdificiosComprados comprados;  // Lista de edificios (codigo) comprados;
}tJugador;

typedef enum{
	NoEncontrado, NoDinero, NoDisponible, ListaLlena, Exito
}tError;

typedef tJugador *tJugPtr;

// Prototipos

//Función para mostrar un jugador con todos sus campos execpto su contraseña
//Entrada: una estrututa jugador y la lista de tamaña variable de edificios
//Salida: no sale nada modificado
//Devuelve: no devuelve nada
void mostrarJugador(tJugador jugador, tListaEdificios listaEdificios);

//Función para pedir al usuario un nuevo jugador, solicitando los campos del jugador uno a uno.
//Entrada: nada
//Salida: 
//Devuelve: devuelve un jugador que será añadido a la lista de jugadores de tamaño variable(otro subprograma)
tJugador nuevoJugador();

//Función para comprobar si la lista de edifios comprados de un jugador esta llena o no
//Entrada: una estructura jugador
//Salida: nada
//Devuelve: un booleano, inidcando si la lista está llena o no
bool listaCompradosLlena(tJugador jugador);

//Función para comprar un edificio, y dentro de este subprograma comprobamos que lo podemos hacer sin fallos
//Entrada: una estrutura jugador, el codigo del edificio y l alista de edificios
//Salida: la estrucutura jugador mofificada y la lista de edificios
//Devuelve: devuelve un enumerado error, dependiedo de si la compra ha sido correcta o no.
tError comprarEdificio(tJugador &jugador, int codigo, tListaEdificios &listaEdificios);

#endif