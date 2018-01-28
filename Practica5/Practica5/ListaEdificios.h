#ifndef LISTAEDIFICIOS_H
#define LISTAEDIFICIOS_H

#include<iostream>
#include<fstream>
#include"Edificio.h"
using namespace std;

// Declaracion de tipos y contantes
const int MAX_EDIFICIOS = 50; // Numero maximo de edificios

typedef struct{
	tEdifPtr edificios;
	int contador;
	int capacidad;
}tListaEdificios;

// Prototipos

//Función para buscar un edicio en la lista de edificios, dado su codigo
//Entrada: la lista de edificios variable, el codigo y la posicion donde se encuentre el edificio
//Salida: sale la posicion del edificio modificado, ya que se ha encontrado al edificio.
//Devuelve: un boolaeno cierto(si se ha encontrado el edificio) y falso en caso contrario
bool buscarEdificio(tListaEdificios listaEdificios, int codigo, int &posicion);

//Función para para comprobar si la lista de edificios de tamaño variable esta llena o no
//Entrada: la lista de edificios
//Salida: nada
//Devuelve: el bool cierto(si la lista esta llena) y falso en caso contrario
bool listaEdificiosLlena(tListaEdificios listaEdificios);

//Función para insertar un edificio en la lista de edificios de tamaño variable, esta inserccion sea hace de forma que la lista quede ordenada por codigo
//Entrada: una estrucutura edificio y la lista de edificios
//Salida: sale la lista de edificios modioficada, es decir, con el nuevo edificio insertado
//Devuelve: nada
void insertarEdificio(tEdificio edif, tListaEdificios &listaEdificios);

//Función para dar de baja un edificio de la lista variable de edificios(el estado del edificio es borraado) y para saber que edificio se pasa su codigo 
//Entrada: la lista de edificios y el codigo que edificio que se quiere borrar
//Salida: la lista de edificios modificada(se pone el estado del edificio borrado)
//Devuelve: un boleano, cierto si se ha dado de baja con exito y falso en caso contrario
bool bajaEdificio(tListaEdificios &listaEdificios, int codigoBorrar);

//Funcion que destruye la lista de edificios
//Entrada: la lista de edificios
//Salida: la lista de edificios modificada
//Devuelve: nada
void destruirEdificios(tListaEdificios &listaEdificios);

//Funcion aumenta el tamaño de la lista de edificios
//Entrada: la lista de edificios
//Salida: la lista de edificios ampliada
//Devuelve: nada
void ampliarEdificios(tListaEdificios &listaEdificios);

//Funcion busca un edificio dado de forma recursiva
//Entrada: la lista de edificios, el codigo del edificio a buscar, la posicion de inicio y la posicion del final
//Salida: nada
//Devuelve: un entero que indica si se ha encontrado o no
int busquedaBinariaRecursiva(tListaEdificios listaEdificios, int codigo, int ini, int fin);

#endif