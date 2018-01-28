#include"ArchivosBinarios.h"

// Implemetaciones
bool cargarEdificiosBinario(tListaEdificios &listaEdificios){
	bool ok = true;
	fstream archivo;
	archivo.open(EDIFICIOS_B, ios::in | ios::binary);
	if (!archivo.is_open())
		ok = false;
	else{
		archivo.seekg(0, ios::end);
		int pos = archivo.tellg();
		int numEdificios = pos / SIZE_EDIFICIO;
		listaEdificios.contador = numEdificios;
		listaEdificios.capacidad = ((numEdificios / 10) + 1) * 10;
		listaEdificios.edificios = new tEdificio[listaEdificios.capacidad];
		tEdificio edificio;
		archivo.seekg(0, ios::beg);
		for (int i = 0; i < numEdificios; i++) {
			archivo.read( (char *) &edificio, SIZE_EDIFICIO);
			listaEdificios.edificios[i] = edificio;
		}
		archivo.close();
	}
	return ok;
}

bool cargarJugadoresBinario(tListaJugadores &listaJugadores){
	bool ok = true;
	fstream archivo;
	archivo.open(JUGADORES_B, ios::in | ios::binary);
	if (!archivo.is_open())
		ok = false;
	else{
		archivo.seekg(0, ios::end);
		int pos = archivo.tellg();
		int numJugadores = pos / SIZE_JUGADOR;
		listaJugadores.contador = numJugadores;
		listaJugadores.capacidad = ((numJugadores / 10) + 1) * 10;
		listaJugadores.jugadores = new tJugador[listaJugadores.capacidad];
		tJugador jugador;
		archivo.seekg(0, ios::beg);
		for (int i = 0; i < numJugadores; i++) {
			archivo.read( (char *) &jugador, SIZE_JUGADOR);
			listaJugadores.jugadores[i] = jugador;
		}
		archivo.close();
	}
	return ok;
}

void guardarEdificiosBinario(tListaEdificios listaEdificios){
	fstream archivo;
	archivo.open(EDIFICIOS_B, ios::trunc | ios::out | ios::binary);
	for(int i = 0;  i < listaEdificios.contador; i++){
		archivo.write((char *) &listaEdificios.edificios[i], SIZE_EDIFICIO);
	}
	archivo.close();
}

void guardarJugadoresBinario(tListaJugadores listaJugadores){
	fstream archivo;
	archivo.open(JUGADORES_B, ios::out | ios::binary | ios::trunc);
	for(int i = 0;  i < listaJugadores.contador; i++){
		archivo.write((char *) &listaJugadores.jugadores[i], SIZE_JUGADOR);
	}
	archivo.close();
}
