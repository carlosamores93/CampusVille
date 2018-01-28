#include"ListaJugadores.h"
using namespace std;

// Implementaciones
bool buscarJugador(tListaJugadores listaJugadores, const tCadena usuario, int &pos){
	// No es busqueda binaria poor que no estan ordenados por nombre
	bool encontrado = false;
	int i = 0;
	while(i < listaJugadores.contador && !encontrado){
		if(strcmp(listaJugadores.jugadores[i].usuario, usuario) == 0){
			encontrado = true;
			pos = i;
		}
		else{
			i++;
		}
	}
	return encontrado;
}

bool listaJugadoresLlena(tListaJugadores listaJugadores){
	bool llena = false;
	if(listaJugadores.contador == listaJugadores.capacidad){
		llena = true;
	}
	return llena;
}

void insertarJugador(tJugador jugador, tListaJugadores &listaJugadores){
	listaJugadores.jugadores[listaJugadores.contador] = jugador;
	listaJugadores.contador++;
}

bool bajaJugador(const tCadena nombre, tListaJugadores &listaJugadores, tListaEdificios &listaEdificios){
	bool jugadorBorrado = false;
	int posicionJugador, posicionEdificio, codigo;
	if(buscarJugador(listaJugadores, nombre, posicionJugador)){
		jugadorBorrado = true;
		for(int i = 0; i < listaJugadores.jugadores[posicionJugador].comprados.contador; i++){
			// Buscamos los edificios que el jugador ha comprado
			codigo = listaJugadores.jugadores[posicionJugador].comprados.codigo[i];
			if(buscarEdificio(listaEdificios, codigo, posicionEdificio)){
				// Los ponemos disponibles
				listaEdificios.edificios[posicionEdificio].estado =  disponible;
			}
		}
		for(int i = posicionJugador; i < listaJugadores.contador - 1; i++){
			listaJugadores.jugadores[i] = listaJugadores.jugadores[i + 1];
		}
		// Decrementamos el contador
		listaJugadores.contador--;
	}
	return jugadorBorrado;
}

void destruirJugadores(tListaJugadores &listaJugadores){
	delete [] listaJugadores.jugadores;
	listaJugadores.contador = 0;
}

void ampliarJugadores(tListaJugadores &listaJugadores){
	listaJugadores.capacidad = (listaJugadores.capacidad * 3) / 2 + 1;
	tJugPtr aux;
	aux = new tJugador[listaJugadores.capacidad];
	for(int i = 0; i < listaJugadores.contador; i++){
		aux[i] = listaJugadores.jugadores[i];
	}
	delete [] listaJugadores.jugadores;
	listaJugadores.jugadores = aux;
}