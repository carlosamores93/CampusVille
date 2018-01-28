#include"Edificio.h"
using namespace std;

// Implementaciones
void mostrarEdificio(tEdificio edificio){
	cout << "==================================================" << endl;
	cout << right << setw(25) << "Identificador: " << edificio.codigo << endl;
	cout << right << setw(25) << "Nombre: " << edificio.nombre << endl;
	cout << right << setw(25) << "Precio de compra: " << edificio.precio << endl;
	cout << right << setw(25) << "Dinero por turno: " << edificio.dinero << endl;
	cout << right << setw(25) << "Prestigio por turno: " << edificio.prestigio << endl;
	cout << right << setw(25) << "Estado: ";
	switch(edificio.estado){
		case disponible: cout << "DISPONIBLE" << endl; break;
		case comprado: cout << "COMPRADO" << endl; break;
		case borrado: cout << "BORRADO" << endl; break;
	}
}

tEdificio nuevoEdificio(){
	tEdificio edif;	
	cout << endl << "Identificador: ";
	cin.sync();
	cin >> edif.codigo;
	cin.sync();
	cout << "Nombre del edificio: ";
	cin.getline(edif.nombre, MAX_CADENA);
	cin.sync();
	cout << "Precio de compra: ";
	cin >> edif.precio;
	cin.sync();
	cout << "Prestigio por turno: ";
	cin >> edif.prestigio;
	cout << "Dinero por turno: ";
	cin >> edif.dinero;
	cin.sync();
	edif.estado = disponible;
	return edif;
}