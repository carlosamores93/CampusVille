#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include<iostream>
#include<fstream>
#include<cstring>
#include"ListaEdificios.h"
#include"ListaJugadores.h"
using namespace std;

// Declaracion de tipos y constantes
const tCadena EDIFICIOS = "edificios.txt"; // Constante al estilo C para el archivo edificios
const tCadena JUGADORES = "jugadores.txt"; // Constante al estilo C para el archivo jugadores
const int CAPACIDAD_INICIAL = 10;
// Declaracion de prototipos

//Funci�n para cargar la lista variable de edificios.
//Entrada: la lista variable de edificios
//Salida: la lista variable de edificios
//Devuelve: devuelve un booleano(cierto o false) dependiendo de si la carga ha sido correcta o no 
bool cargarEdificios(tListaEdificios &listaEdificios);

//Funci�n para cargar la lista variable de jugadores
//Entrada: la lista de jugadores
//Salida: la lista de jugadores
//Devuelve: cierto si ha cargado correctamente los jugadores y falso si ha habiado algun fallo.
bool cargarJugadores(tListaJugadores &listaJugadores);

//Funci�n para cargar los edificios que tiene comprados un jugadores
//Entrada: le pasamos el archivo donde leemos los edifiicos y el jugador
//Salida: archivo y jugador
//Devuelve: no devuelve nada.
void cargarEdificiosComprados(ifstream &archivo, tJugador &jugador);

//Funci�n para guardar los jugadores de la lista de tama�i variable
//Entrada: lista de jugadores
//Salida: nada
//Devuelve: no devuelve nada
void guardarJugadores(tListaJugadores listaJugadores);

//Funci�n para gurdar la lista de los edificios actuales.
//Entrada:  la lista de tama�o variable de edificios
//Salida: nada
//Devuelve: no devuelve nada
void guardarEdificios(tListaEdificios listaEdificios);

#endif