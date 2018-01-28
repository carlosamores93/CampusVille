/*
		Practica 5

Nombre: Carlos Amores y Frank Julca
Grupo: 1º E   G.I.C.
		Grupo18

*/
#include<iostream>
#include<fstream>
#include<cstring>
#include"Archivos.h"
#include"ArchivosBinarios.h"
using namespace std;

// Declaracion de constantes
const tCadena ADMIN = "admin", PASS = "12345", SALIR = "salir", S = "s";

// Declaracion de prototipos 

//Función para dar la bienvendia al campus.
//Entrada: nada
//Salida: nada
//Devuelve: nada
void bienvenidaCampus();

//Función para comprobar que el usuario introduce la contraseña .
//Entrada: la contraseña
//Salida: nada
//Devuelve: un bool true si introduce la contraseña correcta, solo tiene tres intentos.
bool comprobarContrasenia(const tCadena contra);

//Función para elegir la opcion que quiere ejecutar el administrador.
//Entrada: la lista de edificios y la lista de jugadores. 
//Salida: las dos listas actualizadas, ya que se puede agregar un jugador, borrar, agregar edificio, borrar ect
//Devuelve: nada
void administrador(tListaEdificios &listaEdificios, tListaJugadores &listaJugadores);

//Función para mostrar al usuario las opciones del administrador y que elija que opcion quiere ejecutar
//Entrada: nada
//Salida: nada
//Devuelve: un entero, dependiendo de la opcion que ha elegido
int menuAdmin();

//Función para elegir la opcion que quiere ejecutar el jugador.
//Entrada: la lista de edificios, la lista de jugadores y la posicion del jugador
//Salida: las dos listas actualizadas, ya que el jugador puede comprar edificios
//Devuelve: nada
void jugador(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios, int pos);

//Función para mostrar al usuario las opciones del jugador y que elija que opcion quiere ejecutar
//Entrada: la lista de jugadores  y la posicion, para saber la posicion del jugadro
//Salida: nada
//Devuelve: un entero, dependiendo de la opcion que ha elegido
int menuJuego(tListaJugadores listaJugadores, int  pos);

//Función para mostrar la clasificacion ordenada por dinero
//Entrada: la lista de jugadores
//Salida: nada
//Devuelve: nada
void clasificacionOrdenadaDinero(tListaJugadores listaJugadores);

//Función para mostrar la clasificacion ordenada por prestigio
//Entrada: la lista de jugadores
//Salida: nada
//Devuelve: nada
void clasificacionOrdenadaPrestigio(tListaJugadores listaJugadores);

//Función para ver mis edificios que tengo comprados.
//Entrada: la lista de edificios, jugadores y la posicion del la lista de jugadores, para saber el jugador 
//Salida: nada
//Devuelve: nada
void verMisEdificios(tListaEdificios listaEdificios, tListaJugadores listaJugadores, int pos);

//Función para compar un edificios, se comprueba que el edificio este disponible, qu eel coodigo del edificio a comparar sea correcto,  qu ela lista de edificios comprados no esté llena y que el jugador tenga suficiente dinero para comprar el edificio.
//Entrada: la lista de jugadores, edificios y la posicion del jugador.
//Salida: la lista de jugadores y la de edificios actualizada con todos los cambios realizados
//Devuelve: nada
void comprarUnEdificio(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios, int pos);

//Función para recorre la lista de jugadores y, para cada uno, recorre su lista de edificios comprados. Para cada edificio, añade (o resta) el dinero y puntos de prestigio que el edificio genera en cada turno.
//Entrada: la lista de edificios y la lista de jugadores
//Salida: la lista de jugadores con su dinero y prestigio actualizados
//Devuelve: nada
void ejecutarUnTurno(tListaEdificios listaEdificios, tListaJugadores &listaJugadores);

//Función para llamar al subprograma que muestra todos los edificios de la lista de edificios
//Entrada: la lista de edificios
//Salida: nada
//Devuelve: nada
void ejecutarListadoEdificios(tListaEdificios listaEdificios);

//Función para pedir al usuario un nuevo edificio(nuevoEdificio()) y para insertarlo en la lista de edificios (insertarEdificio(edif, listaEdificios))
//Entrada: la lista de edificios
//Salida: la lista de edificios
//Devuelve: nada
void ejecutarNuevoEdificio(tListaEdificios &listaEdificios);

//Función para borrar un edificios(bajaEdificio(listaEdificios, codigoBorrar)), dado un codigo introducido por el usuario.
//Entrada: lista de edificios
//Salida: lista de edificios
//Devuelve: nada
void ejecutarBorrarEdificio(tListaEdificios &listaEdificios);

//Función para mostrar todos los jugadores de la lista de jugadores, con sus respectivos edificios comprados.
//Entrada: la lista de edificios y la lista de jugadores
//Salida: nada
//Devuelve: nada
void ejecutarListadoJugadores(tListaJugadores listaJugadores, tListaEdificios listaEdificios);

//Función para insertar un nuevo jugador a la lista de jugadores, validando su nombre sobre todo, es decir que el nombre del nuevo jugador no puede ser ni "X" ni "admin" ni "salir"
//Entrada: la ista de jugadores
//Salida: la lista de jugadores
//Devuelve: nada
void ejecutarNuevoJugador(tListaJugadores &listaJugadores);

//Función para llamar al subprograma para que borre un  jugador de la lista de jugadores
//Entrada: la lista de jugadores y la liesta de edificios
//Salida: la lista de jugadores y la liesta de edificios
//Devuelve: nada
void ejecutarBorrarJugador(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios);

//Función para mostrar al jugador los edificios  que se encuentran disponible para comprar
//Entrada:  la lista de edificios
//Salida: nada
//Devuelve: nada
void ejecutarEdificiosDisponibles(tListaEdificios listaEdificios);

//Función que cargar los datos de los archivos de texto en las listas
//Entrada: la lista de edificios y la lista de jugadores
//Salida: las nuevas listas de edificios y de jugadores
//Devuelve: nada
void ejecutarImportarDatos(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios);

// Programa pricipal
int main(){
	bool listaVacia = false;
	tListaJugadores listaJugadores;
	tListaEdificios listaEdificios;
	tCadena usuario = "\0";
	int pos;

	if(!cargarEdificiosBinario(listaEdificios)){
		listaEdificios.edificios = new tEdificio[CAPACIDAD_INICIAL];
		listaEdificios.contador = 0;
		listaVacia = true;
	}
	if(!cargarJugadoresBinario(listaJugadores)){
		listaJugadores.jugadores = new tJugador[CAPACIDAD_INICIAL];
		listaJugadores.contador = 0;
		listaVacia = true;
	}
	if(listaVacia)
		cout << endl << "Se ha producido un error al cargar las listas, empezemos con listas vacias" << endl << endl;
	else
		cout << endl << "Listas cargadas" << endl;
	bienvenidaCampus();
	while(strcmp(usuario, SALIR) && strcmp(usuario, S)){
		cout << "Usuario: ";
		cin >> usuario;
		cin.sync();
		if(strcmp(usuario, ADMIN) == 0){
			if(comprobarContrasenia(PASS)) // Solo un subprograma.
				administrador(listaEdificios, listaJugadores);
		}else 
			if(buscarJugador(listaJugadores, usuario, pos))
				if(comprobarContrasenia(listaJugadores.jugadores[pos].password))
					jugador(listaJugadores, listaEdificios, pos);
	}
	guardarEdificiosBinario(listaEdificios);
	guardarJugadoresBinario(listaJugadores);
	cout << endl << "Listas guardadas" << endl;
	destruirJugadores(listaJugadores);
	destruirEdificios(listaEdificios);
	system("pause");
    return 0;
}

// Implementaciones
void bienvenidaCampus(){
	cout << endl << "Bienvenido a Campus Ville" << endl;
	cout << "==========================" << endl;
	cout << endl << "Escribe 'salir' o 's' para cerrar el programa..." << endl;
}

bool comprobarContrasenia(const tCadena contra){
	bool correcto = false;;	
	int fallos = 3;
	tCadena contraseña;
	while((fallos > 0) && !correcto){
		cout << "Contrasenia (" << fallos << " intentos): ";
		cin >> contraseña;
		cin.sync();
		fallos--;
		if(strcmp(contraseña, contra) == 0){
			correcto = true;
		}
	}
	return correcto;
}

void administrador(tListaEdificios &listaEdificios, tListaJugadores &listaJugadores){
	int op = -1;
	while(op != 0){
		op = menuAdmin();
		switch(op){
			case 0:	
				cout << "Fin de la sesion" << endl << endl;
				bienvenidaCampus();
				break;
			case 1:
				// Ver el listado de edificios
				ejecutarListadoEdificios(listaEdificios);
				break;
			case 2:
				// Nuevo edificio
				ejecutarNuevoEdificio(listaEdificios);
				break;
			case 3:
				// Borrar un edificio
				ejecutarBorrarEdificio(listaEdificios);
				break;
			case 4:
				// Ver el listado de jugadores
				ejecutarListadoJugadores(listaJugadores, listaEdificios);
				break;
			case 5:
				// Nuevo jugador
				ejecutarNuevoJugador(listaJugadores);
				break;
			case 6:
				// Borrar un jugador
				ejecutarBorrarJugador(listaJugadores, listaEdificios);
				break;
			case 7:
				// Ejecutar un turno
				ejecutarUnTurno(listaEdificios, listaJugadores);
				break;
			case 8:
				// Ver la clasificacion (ordenada por dinero)
				clasificacionOrdenadaDinero(listaJugadores);
				break;
			case 9:
				ejecutarImportarDatos(listaJugadores, listaEdificios);
				break;
			default:
				cout << endl << "Opcion no valida, escoge otra por favor" << endl;
		}
	}
}

int menuAdmin(){
	int opcion = -1;
	cout << endl << endl << "Menu de administracion" << endl;
	cout << "======================" << endl;
	cout << "1.- Ver el listado de edificios" << endl;
	cout << "2.- Nuevo edificio" << endl;
	cout << "3.- Borrar un edificio" << endl;
	cout << "4.- Ver el listado de jugadores" << endl;
	cout << "5.- Nuevo jugador" << endl;
	cout << "6.- Borrar un jugador" << endl;
	cout << "7.- Ejecutar un turno" << endl;
	cout << "8.- Ver la clasificacion" << endl;
	cout << "9.- Importar datos de archivo de texto" << endl;
	cout << "0.- Cerrar la sesion" << endl;
	cout << "Entra una opcion: ";
	cin >> opcion;
	cin.sync();
	return opcion;
}

void jugador(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios, int pos){
	int op = -1;
	while(op != 0){
		op = menuJuego( listaJugadores, pos);
		switch(op){
			case 0:	
				cout << "Fin de la sesion" << endl << endl; 
				bienvenidaCampus(); 
				break;
			case 1:
				// Ver mis edificios
				verMisEdificios(listaEdificios, listaJugadores, pos);
				break;
			case 2:
				// Ver los edificios disponibles
				ejecutarEdificiosDisponibles(listaEdificios);
				break;
			case 3:
				// Comprar un edificio
				comprarUnEdificio(listaJugadores, listaEdificios, pos);
				break;
			case 4:
				// Ver la clasificacion (ordenada por dinero)
				clasificacionOrdenadaDinero(listaJugadores);
				break;
			case 5:
				// Ver la clasificacion (ordenada por prestigio)
				clasificacionOrdenadaPrestigio(listaJugadores);
				break;
			default:
				cout << endl << "Opcion no valida, escoge otra por favor" << endl;
		}
	}
}

int menuJuego(tListaJugadores listaJugadores, int pos){
	int opcion = -1;
	cout << endl << "Menu de juego" << endl;
	cout << "=================" << endl;
	cout << "Bienvenido " << listaJugadores.jugadores[pos].usuario << ", elige una opcion:" << endl;
	cout << endl << "1.- Ver mis edificios" << endl;
	cout << "2.- Ver los edificios disponibles" << endl;
	cout << "3.- Comprar un edificio" << endl;
	cout << "4.- Ver la clasificacion (ordenada por dinero)" << endl;
	cout << "5.- Ver la clasificacion (ordenada por prestigio)" << endl;
	cout << "0.- Cerrar sesion" << endl;
	cout  << "Entra una opcion: ";
	cin >> opcion;
	cin.sync();
	return opcion;
}

void clasificacionOrdenadaDinero(tListaJugadores listaJugadores){
	tListaJugadores auxJugadores;
	auxJugadores.jugadores = new tJugador[listaJugadores.contador];
	auxJugadores.contador = listaJugadores.contador;
	for(int i = 0; i < auxJugadores.contador; i++){
		auxJugadores.jugadores[i] = listaJugadores.jugadores[i];
	}
	tJugador tmp;
	for(int i = 0;  i < auxJugadores.contador - 1; i++){
		// Desde el primer elemento hasta el penultimo
		for(int j = auxJugadores.contador - 1; j > i; j--){
			// Desde el ultimo hasta el siguiente a i
			if(auxJugadores.jugadores[j].dinero > auxJugadores.jugadores[j - 1].dinero){
				tmp = auxJugadores.jugadores[j];
				auxJugadores.jugadores[j] = auxJugadores.jugadores[j - 1];
				auxJugadores.jugadores[j - 1] = tmp;
			}
		}
	}
	cout << endl << "Posicion  Dinero    Nombre" << endl;
	cout << "========  ======    ======"  << endl;
	for(int i = 0;  i < auxJugadores.contador; i++){
		cout << right << setw(6) << i + 1 << right << setw(10) << auxJugadores.jugadores[i].dinero 
		<< "    " << auxJugadores.jugadores[i].universidad << endl;
	}
	destruirJugadores(auxJugadores);
}

void clasificacionOrdenadaPrestigio(tListaJugadores listaJugadores){
	tListaJugadores auxJugadores;
	auxJugadores.jugadores = new tJugador[listaJugadores.contador];
	auxJugadores.contador = listaJugadores.contador;
	for(int i = 0; i < auxJugadores.contador; i++){
		auxJugadores.jugadores[i] = listaJugadores.jugadores[i];
	}
	tJugador tmp;
	for(int i = 0;  i < auxJugadores.contador - 1; i++){
		// Desde el primer elemento hasta el penultimo
		for(int j = auxJugadores.contador - 1; j > i; j--){
			// Desde el ultimo hasta el siguiente a i
			if(auxJugadores.jugadores[j].prestigio > auxJugadores.jugadores[j - 1].prestigio){
				tmp = auxJugadores.jugadores[j];
				auxJugadores.jugadores[j] = auxJugadores.jugadores[j - 1];
				auxJugadores.jugadores[j - 1] = tmp;
			}
		}
	}
	cout << endl << "Posicion  Prest.    Nombre" << endl;
	cout << "========  ======    ======"  << endl;
	for(int i = 0;  i < auxJugadores.contador; i++){
		cout << right << setw(6) << i + 1 << right << setw(10) << auxJugadores.jugadores[i].prestigio 
			<< "    " << auxJugadores.jugadores[i].universidad << endl;
	}
	destruirJugadores(auxJugadores);
}

void verMisEdificios(tListaEdificios listaEdificios, tListaJugadores listaJugadores, int pos){
	int codigo, posicion;
	cout << endl << listaJugadores.jugadores[pos].universidad << " (Dinero: " << listaJugadores.jugadores[pos].dinero << ", Prestigio: " 
		 << listaJugadores.jugadores[pos].prestigio << " )"<< endl << endl;
	cout << "Tienes "  << listaJugadores.jugadores[pos].comprados.contador << " edificio(s):" << endl;
	for(int i = 0; i < listaJugadores.jugadores[pos].comprados.contador; i++){
		codigo = listaJugadores.jugadores[pos].comprados.codigo[i];
		if(buscarEdificio(listaEdificios, codigo, posicion)){
			mostrarEdificio(listaEdificios.edificios[posicion]);
		}					
	}
}

void comprarUnEdificio(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios, int pos){
	int codigo, posicion;
	tError error;
	cout << endl << "Introduce el codigo del edificio: ";
	cin.sync();
	cin >> codigo;
	cin.sync();
	if(buscarEdificio(listaEdificios, codigo, posicion)){
		error = comprarEdificio(listaJugadores.jugadores[pos], codigo, listaEdificios);
	}
	else{
		error = NoEncontrado;
	}
	switch(error){
		case NoDisponible: cout << "ERROR: El edificio no está disponible" << endl  << endl; break;
		case NoEncontrado: cout << "ERROR: No es un edificio valido" << endl  << endl; break;
		case NoDinero: cout << "ERROR: No tienes dinero suficiente, el edificio cuesta " << listaEdificios.edificios[posicion].precio << endl << endl; break;
		case ListaLlena: cout << "ERROR: La lista de edificios comprados está llena." << endl  << endl; break;
		case Exito: cout << "Has comprado el edificio y has pagado "  << listaEdificios.edificios[posicion].precio << endl << endl; break;
	}
}

void ejecutarUnTurno(tListaEdificios listaEdificios, tListaJugadores &listaJugadores){
	int codigo, posicion;
	cout << endl;
	for(int i = 0; i < listaJugadores.contador; i++){
		cout << "Procesando jugador: " << listaJugadores.jugadores[i].universidad << endl;
		 for(int j = 0; j < listaJugadores.jugadores[i].comprados.contador; j++){
			codigo = listaJugadores.jugadores[i].comprados.codigo[j];
			if(buscarEdificio(listaEdificios, codigo, posicion)){
				cout << "Edificio: " << listaEdificios.edificios[posicion].nombre 
				<< " ( D: " << listaEdificios.edificios[posicion].dinero 
				<< ", P: " << listaEdificios.edificios[posicion].prestigio << " )" << endl;
				listaJugadores.jugadores[i].dinero = listaJugadores.jugadores[i].dinero + listaEdificios.edificios[posicion].dinero;
				listaJugadores.jugadores[i].prestigio = listaJugadores.jugadores[i].prestigio + listaEdificios.edificios[posicion].prestigio;
			}
		}
	cout << "=======================================" << endl;
	}
}

void ejecutarListadoEdificios(tListaEdificios listaEdificios){
	for(int i = 0; i < listaEdificios.contador; i++){
		mostrarEdificio(listaEdificios.edificios[i]);
	}
}

void ejecutarNuevoEdificio(tListaEdificios &listaEdificios){
	tEdificio edif;
	int pos;
	if(listaEdificiosLlena(listaEdificios))
		ampliarEdificios(listaEdificios);
	edif = nuevoEdificio();
	if(!buscarEdificio(listaEdificios, edif.codigo, pos)){
		insertarEdificio(edif, listaEdificios);
		cout << "Edificio insertado con exito..." << endl;
	}
	else{
		cout << "Error al insertar: El codigo esta duplicado" << endl;
	}
}

void ejecutarBorrarEdificio(tListaEdificios &listaEdificios){
	int codigoBorrar;
	cout << endl << "Codigo del edificio a borrar: ";
	cin.sync();
	cin >> codigoBorrar;
	cin.sync();
	if(bajaEdificio(listaEdificios, codigoBorrar)){
		cout << "Edificio borrado con exito" << endl << endl;
	}
	else{
		cout << "ERROR: El edificio no existe o no está disponible" << endl << endl;
	}
}

void ejecutarListadoJugadores(tListaJugadores listaJugadores, tListaEdificios listaEdificios){
	for(int i = 0; i < listaJugadores.contador; i++){
		mostrarJugador(listaJugadores.jugadores[i], listaEdificios);
	}
}

void ejecutarNuevoJugador(tListaJugadores &listaJugadores){
	int pos;
	tJugador jugador;
	jugador = nuevoJugador();
	if((strcmp(jugador.usuario, ADMIN) != 0) && (strcmp(jugador.usuario, SALIR) != 0) && (strcmp(jugador.usuario, S) != 0) && (strcmp(jugador.usuario, "X") != 0)){ 
	// No se puede introducir como jugadores ni 'admin' ni 'salir', tambien hemos añadido que 'X' no se puede añadir como jugador, ya que es el centinela.
		if(listaJugadoresLlena(listaJugadores))
			ampliarJugadores(listaJugadores);
		if(!buscarJugador(listaJugadores, jugador.usuario, pos)){
			insertarJugador(jugador, listaJugadores);
			cout << "Jugador insertado con exito..." << endl;
		}
		else{
			cout << "ERROR al insertar: El usuario esta duplicado" << endl;
		}
	}
	else{
		cout << "ERROR: El nombre de usuario no es valido" << endl;
	}
}

void ejecutarBorrarJugador(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios){
	tCadena nombre;
	cout << endl << "Nombre del jugador: ";
	cin.sync();
	cin.getline(nombre, MAX_CADENA);
	cin.sync();
	if(bajaJugador(nombre, listaJugadores, listaEdificios)){
		cout << "Eliminando edificios del  jugador..." << endl;
		cout << "Jugador eliminado" << endl << endl;
	}
	else{
		cout << "El jugador no existe" << endl << endl;
	}
}

void ejecutarEdificiosDisponibles(tListaEdificios listaEdificios){
	for(int i = 0; i < listaEdificios.contador; i++){
		if(listaEdificios.edificios[i].estado == disponible){
			mostrarEdificio(listaEdificios.edificios[i]);
		}		
	}
}

void ejecutarImportarDatos(tListaJugadores &listaJugadores, tListaEdificios &listaEdificios){ 
	destruirJugadores(listaJugadores);
	destruirEdificios(listaEdificios);
	if(cargarEdificios(listaEdificios) && cargarJugadores(listaJugadores)){
		cout << endl << "Listas cargadas" << endl;
	}
	else{
		cout << endl << "Se ha producido un error al cargar las listas, empezemos con listas vacias" << endl << endl;
	}
}