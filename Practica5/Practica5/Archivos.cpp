#include"Archivos.h"
using namespace std;

// Implementaciones
bool cargarEdificios(tListaEdificios &listaEdificios){
	bool ok = true;
	int estado;
	char c;
	ifstream archivo;
	archivo.open(EDIFICIOS);
	if(archivo.is_open()){
		tEdificio edif;
		listaEdificios.capacidad = CAPACIDAD_INICIAL;
		listaEdificios.edificios = new tEdificio[listaEdificios.capacidad];
		archivo >> edif.codigo;
		while(edif.codigo != -1){
			if(listaEdificios.contador == listaEdificios.capacidad)
				ampliarEdificios(listaEdificios);
			archivo.get(c); /* Leemos para mover el puntero, 
			y asi poder leer el nombre del edificio.*/
			archivo.getline(edif.nombre, MAX_CADENA);
			archivo >> edif.precio;
			archivo >> edif.dinero;
			archivo >> edif.prestigio;
			archivo >> estado;
			edif.estado = tEstadoEdificio(estado); // Usamos el molde para leer el estado del edificio
			listaEdificios.edificios[listaEdificios.contador] = edif;
			listaEdificios.contador++;
			archivo >> edif.codigo;
		}
		archivo.close();
	}
	else{
		ok = false;
	}
	return ok;
}

bool cargarJugadores(tListaJugadores &listaJugadores){
	bool ok = true;
	char c;
	ifstream archivo;
	archivo.open(JUGADORES);
	if(archivo.is_open()){
		tJugador jugador;
		listaJugadores.capacidad = CAPACIDAD_INICIAL;
		listaJugadores.jugadores = new tJugador[listaJugadores.capacidad];
		archivo.getline(jugador.usuario, MAX_CADENA);	
		while(strcmp(jugador.usuario, "X") != 0){ 
			if(listaJugadores.contador == listaJugadores.capacidad)
				ampliarJugadores(listaJugadores);
		//strcmp(cadena1, cadena2)Para comparar cadenas al estilo C, devuelve 0 cuando son iguales
			archivo.getline(jugador.password, MAX_CADENA);
			archivo.getline(jugador.universidad, MAX_CADENA);
			archivo >> jugador.dinero;
			archivo >> jugador.prestigio;
			cargarEdificiosComprados(archivo, jugador); // Leer la lista de edificios comprados
			listaJugadores.jugadores[listaJugadores.contador] =  jugador;
			listaJugadores.contador++;
			archivo.get(c); 
			/* Leemos para mover el puntero, 
			y asi poder leer el nombre del edificio.*/
			archivo.getline(jugador.usuario, MAX_CADENA);
		}
		archivo.close();	
	}
	else{
		ok = false;
	}
	return ok;
}

void cargarEdificiosComprados(ifstream &archivo, tJugador &jugador){
	jugador.comprados.contador = 0;
	int codigo;
	archivo >> codigo;
	while((codigo != -1) && (jugador.comprados.contador < MAX_EDIFICIOS)){
		jugador.comprados.codigo[jugador.comprados.contador] = codigo;
		jugador.comprados.contador++;
		archivo >> codigo;
	}
}

void guardarJugadores(tListaJugadores listaJugadores){
	ofstream archivo;
	archivo.open(JUGADORES);
	for(int i = 0; i < listaJugadores.contador; i++){
		archivo << listaJugadores.jugadores[i].usuario << endl;
		archivo << listaJugadores.jugadores[i].password << endl;
		archivo << listaJugadores.jugadores[i].universidad << endl;
		archivo << listaJugadores.jugadores[i].dinero << endl;
		archivo << listaJugadores.jugadores[i].prestigio << endl;
		for(int j = 0; j < listaJugadores.jugadores[i].comprados.contador; j++){
			archivo << listaJugadores.jugadores[i].comprados.codigo[j] << endl;
		}
		archivo << "-1" << endl;
	}
	archivo << "X";
	archivo.close();
}

void guardarEdificios(tListaEdificios listaEdificios){
	ofstream archivo;
	archivo.open(EDIFICIOS);
	for(int i = 0; i < listaEdificios.contador; i++){
		archivo << listaEdificios.edificios[i].codigo << endl;
		archivo << listaEdificios.edificios[i].nombre << endl;
		archivo << listaEdificios.edificios[i].precio << endl;
		archivo << listaEdificios.edificios[i].dinero << endl;
		archivo << listaEdificios.edificios[i].prestigio << endl;
		archivo << listaEdificios.edificios[i].estado << endl;
	}
	archivo << "-1";
	archivo.close();
}
