#ifndef ARCHIVOSBINARIOS_H
#define ARCHIVOSBINARIOS_H

#include<iostream>
#include<fstream>
#include<cstring>
#include"ListaEdificios.h"
#include"ListaJugadores.h"
using namespace std;

// Declaracion de tipos y constantes
const int SIZE_EDIFICIO = sizeof(tEdificio);
const int SIZE_JUGADOR = sizeof(tJugador);
const tCadena EDIFICIOS_B = "edificios.dat"; // Constante al estilo C para el archivo edificios
const tCadena JUGADORES_B = "jugadores.dat"; // Constante al estilo C para el archivo jugadores

// Declaracion de prototipos

//Función para cargar la lista variable de edificios.
//Entrada: la lista variable de edificios
//Salida: la lista variable de edificios
//Devuelve: devuelve un booleano(cierto o false) dependiendo de si la carga ha sido correcta o no 
bool cargarEdificiosBinario(tListaEdificios &listaEdificios);

//Función para cargar la lista variable de jugadores
//Entrada: la lista de jugadores
//Salida: la lista de jugadores
//Devuelve: cierto si ha cargado correctamente los jugadores y falso si ha habiado algun fallo.
bool cargarJugadoresBinario(tListaJugadores &listaJugadores);

//Función para guardar los jugadores de la lista de tamaño variable
//Entrada: lista de jugadores
//Salida: nada
//Devuelve: no devuelve nada
void guardarJugadoresBinario(tListaJugadores listaJugadores);

//Función para gurdar la lista de los edificios actuales.
//Entrada:  la lista de tamaño variable de edificios
//Salida: nada
//Devuelve: no devuelve nada
void guardarEdificiosBinario(tListaEdificios listaEdificios);

#endif