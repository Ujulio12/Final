#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"
#include "Usuario.h"

using namespace std;
class Usuario
{
	private:
		string name, password;
	public:
		void menu();
		void iniciarSesion();
		void menuSecundario();
		void crearCuenta();
		void modificarCuenta();
		void borrarCuenta();
};


#endif // USUARIO_H
