#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H

#include<iostream>
#include<cstring>
#include"Jugador.h"
using namespace std;

// Declaracion de tipos y constantes
const int MAX_JUGADORES = 20; //Maximo numero de jugadores.

typedef struct{
	tJugPtr jugadores;
	int contador;
	int capacidad;
}tListaJugadores;

// Prototipos

//Función para buscar un  jugador en la lista de jugadores, dado su nombre.
//Entrada: la lista de jugadores, el usuaruio y la posicion
//Salida: sale la posicion donde se ha encontrado el jugador
//Devuelve: un booleano, indicandi si se ha enciontrado el jugador(true) o si el jugador no se ha encontrado(false)
bool buscarJugador(tListaJugadores listaJugadores, const tCadena usuario, int &pos);

//Función para comprobar si la lista de los jugadores está llena o no
//Entrada: la lista de jugadores
//Salida: nada
//Devuelve: cierto si la lista está llena y falso en caso contrario.
bool listaJugadoresLlena(tListaJugadores listaJugadores);

//Función para insertar un jugador en la lista de jugadores, se inserta al final de la lista
//Entrada: un jugador y la lista de jugadores
//Salida: la lista de jugadores con el  jugador insertado
//Devuelve: nada
void insertarJugador(tJugador jugador, tListaJugadores &listaJugadores);

//Función para dar de baja un jugador, es decir eliminarlo de la lista de jugadores
//Entrada: el nombre el jugador a eliminar, la lista de jugadores y la lista de edificios.
//Salida: la lista de jugadores despues de eliminar el jugador y la lista de edificio, si el jugador tenia edificios estos edificios pasan a estar disponible y listos para que sean conprados por otro jugador
//Devuelve: true si se ha eliminado el jugador y false si no se ha eliminado.
bool bajaJugador(const tCadena nombre, tListaJugadores &listaJugadores, tListaEdificios &listaEdificios);

//Funcion que destruye la lista de jugadores
//Entrada: la lista de jugadores
//Salida: la lista de jugadores modificada
//Devuelve: nada
void destruirJugadores(tListaJugadores &listaJugadores);

//Funcion aumenta el tamaño de la lista de jugadores
//Entrada: la lista de jugadores
//Salida: la lista de jugadores ampliada
//Devuelve: nada
void ampliarJugadores(tListaJugadores &listaJugadores);

#endif