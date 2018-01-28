#include"ListaEdificios.h"
using namespace std;

// Implementaciones
bool buscarEdificio(tListaEdificios listaEdificios, int codigo, int &posicion){	
	bool encontrado = false;
	int ini = 0, fin = listaEdificios.contador - 1;
	posicion = busquedaBinariaRecursiva(listaEdificios, codigo, ini, fin);
	if(posicion == -1){
		encontrado = false;
	}
	else{
		encontrado = true;
	}
	return encontrado;
}

bool listaEdificiosLlena(tListaEdificios listaEdificios){
	bool llena = false;	
	if(listaEdificios.contador == listaEdificios.capacidad){
		llena = true;
	}
	return llena;
}

void insertarEdificio(tEdificio edif, tListaEdificios &listaEdificios){
	// Lo insertamos en ordeno por codigo,
	int i = 0;
	while ((i < listaEdificios.contador) && (listaEdificios.edificios[i].codigo < edif.codigo)){
		i++;					
	}
	// Insertamos en la posición i
	for (int j = listaEdificios.contador; j > i; j--){ // Desplazamos una posición a la derecha
		listaEdificios.edificios[j] = listaEdificios.edificios[j - 1];
	}
	listaEdificios.edificios[i] = edif;
	listaEdificios.contador++;
}

bool bajaEdificio(tListaEdificios &listaEdificios, int codigoBorrar){
	int pos;
	bool edifBorrado = false;
	if(buscarEdificio(listaEdificios, codigoBorrar, pos)){
		if(listaEdificios.edificios[pos].estado == disponible){
			listaEdificios.edificios[pos].estado = borrado;
			edifBorrado = true;
		}
	}
	return edifBorrado;
}

void destruirEdificios(tListaEdificios &listaEdificios){
	delete [] listaEdificios.edificios;
	listaEdificios.contador = 0;
}

void ampliarEdificios(tListaEdificios &listaEdificios){
	listaEdificios.capacidad = (listaEdificios.capacidad * 3) / 2 + 1;
	tEdifPtr aux;
	aux = new tEdificio[listaEdificios.capacidad];
	for(int i = 0; i < listaEdificios.contador; i++){
		aux[i] = listaEdificios.edificios[i];
	}
	delete [] listaEdificios.edificios;
	listaEdificios.edificios = aux;
}

int busquedaBinariaRecursiva(tListaEdificios listaEdificios, int codigo, int ini, int fin){
	int pos = -1;
	if(ini <= fin){
		int mitad = (ini + fin) / 2;
		if(codigo == listaEdificios.edificios[mitad].codigo){
			pos = mitad;
		}
		else{
			if(codigo < listaEdificios.edificios[mitad].codigo){
				pos = busquedaBinariaRecursiva(listaEdificios, codigo, ini, mitad - 1);
			}
			else{
				pos = busquedaBinariaRecursiva(listaEdificios, codigo, mitad + 1, fin);
			}
		}
	}
	return pos;
}
