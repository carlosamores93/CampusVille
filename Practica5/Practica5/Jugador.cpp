#include"Jugador.h"
using namespace std;

// Implementaciones
void mostrarJugador(tJugador jugador, tListaEdificios listaEdificios){
	int posicion, codigo;
	cout << "==================================================" << endl;
	cout << right << setw(13) << "Usuario: " << jugador.usuario << " (" << jugador.universidad <<  ")" << endl;
	cout << right << setw(13) << "Dinero: " << jugador.dinero << endl;
	cout << right << setw(13) << "Prestigio: " << jugador.prestigio << endl;
	cout << right << setw(13) << "Edificios: " << jugador.comprados.contador << endl;
	for(int i = 0; i < jugador.comprados.contador; i++){
		codigo = jugador.comprados.codigo[i];
		buscarEdificio(listaEdificios, codigo, posicion);//{
		cout << right << setw(16) << "Edificio #" << i + 1 << " - " << listaEdificios.edificios[posicion].nombre << " - D: " 
			<< listaEdificios.edificios[posicion].dinero << " - P: "  << listaEdificios.edificios[posicion].prestigio << endl;
			//}	
	}
}

tJugador nuevoJugador(){
	tJugador jug;
	cout << endl << "Introduce el usuario: ";
	cin.sync();
	cin >> jug.usuario;
	cin.sync();
	cout << "Introduce el password: ";
	cin >> jug.password;
	cin.sync();
	cout << "Introduce el nombre de la empresa: ";
	cin.getline(jug.universidad, MAX_CADENA);
	jug.dinero = DINERO;
	jug.prestigio = 0;
	jug.comprados.contador = 0;
	return jug;
}

bool listaCompradosLlena(tJugador jugador){
	bool llena = false;
	if(jugador.comprados.contador == MAX_EDIFICIOS){
		llena = true;
	}
	return llena;
}

tError comprarEdificio(tJugador &jugador, int codigo, tListaEdificios &listaEdificios){
	tError error;
	int posicion;
	if(!buscarEdificio(listaEdificios, codigo, posicion)) error = NoEncontrado;
	else if(listaEdificios.edificios[posicion].estado != disponible) error = NoDisponible;
	else if(listaCompradosLlena(jugador)) error = ListaLlena;
	else if(jugador.dinero < listaEdificios.edificios[posicion].precio) error = NoDinero;
	else{
		// Si el jugador tiene lo mismo o mas dinero que lo que cuesta el edificio, compramos.
		listaEdificios.edificios[posicion].estado = comprado; // Ponemos el edificio como comprado
		jugador.dinero = jugador.dinero - listaEdificios.edificios[posicion].precio;
		jugador.comprados.codigo[jugador.comprados.contador] = codigo;
		jugador.comprados.contador++;
		error = Exito;
	}
	return error;
}
