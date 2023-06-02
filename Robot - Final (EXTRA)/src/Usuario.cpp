#include "Usuario.h"
#include "player.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

string nameUser, code;

void Usuario::menu()
    {
    Usuario ingresoUsuario;
    int opcion;
	do
    {
	system("cls");
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |      INGRESO DE SESION     |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Iniciar Sesion"<<endl;
	cout<<"\t\t\t 2. Crear cuenta"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
	case 1:
		ingresoUsuario.iniciarSesion();
		break;
	case 2:
		ingresoUsuario.crearCuenta();
		break;
	case 3:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida... Por favor prueba otra vez..";
	}
	getch();
    }while(opcion!=3);
    system("cls");
}
void Usuario::crearCuenta()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Agregar Nuevo Usuario -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: ";
	cin>>name;
	cout<<"\t\t\tIngresa la contrasena: ";
	cin>>password;
	file.open("nombresUsuarios.txt", ios::app | ios::out);
	file << std::left << std::setw(15) << name <<std::left<<std::setw(15)<< password << "\n";
	file.close();
}
void Usuario::iniciarSesion()
{
    system("cls");
	fstream file;
	int found = 0, opcion;
	file.open("nombresUsuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		cout<<"\n----------------------------------------------------------------------------------------------------------------";
        cout<<"\n--------------------------------------------------- Iniciar Sesion ---------------------------------------------"<<endl;
		cout<<"\n\t\tUsuario: ";
		cin>>nameUser;
		cout << "\t\tContrasena: ";
		cin >> code;
		file >> name >> password;
		while(!file.eof())
		{
			if(nameUser == name && code == password)
			{
                do{
                system("cls");
                cout<<"\n------------------------------------------------------------------------------------------------------------------------";
                cout<<"\n------------------------------------------- BIENVENIDO AL JUEGO ROBOT --------------------------------------------------"<<endl;
                cout << "\n\tUsuario: " << name << endl << endl;
                cout << "\n\t\t1. Iniciar Juego" << endl;
                cout << "\t\t2. Modificar Usuario" << endl;
                cout << "\t\t3. Creditos" << endl;
                cout << "\t\t4. salir" << endl;
                cin >> opcion;
                    switch(opcion)
                    {
                        case 1:
                            file.close();
                            system("cls");
                            {
    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022

                            gamemap map;
                            player hero;
                            map.drawPortada();
                            //map.draw();
                            while(map.isGameOver==false)
                            {
                              cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
                              hero.callInput();

                              //Actualizar información del jugador en el mapa
                              if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
                              {
                             //   system("cls");
                                map.draw();
                              } else
                              {
                               // system("cls");
                                hero.resetToSafePosition();
                                //Dibujamos el mapa
                                map.draw();
                              }
                              //map.draw();

                            }

                        }
                            system("pause");
                            break;
                        case 2:
                            file.close();
                            menuSecundario();
                            break;
                        case 3:
                            system("cls");
                            std::cout << "=============================================" << std::endl;
                            std::cout << "||    Bienvenido al Programa EASTER EGG    ||" << std::endl;
                            std::cout << "=============================================" << std::endl;
                            std::cout << std::endl;
                            std::cout << "    UUUU   UUUU   MMMM     MMM   GGGGGG   " << std::endl;
                            std::cout << "    UUUU   UUUU   MMMMM   MMMM  GGGGGGGG  " << std::endl;
                            std::cout << "    UUUU   UUUU   MMMMMM MMMMM GGG        " << std::endl;
                            std::cout << "    UUUU   UUUU   MMM MMMM MMM GGG   GGGGG " << std::endl;
                            std::cout << "    UUUU   UUUU   MMM  MM  MMM GGG    GGGG  " << std::endl;
                            std::cout << "    UUUU   UUUU   MMM      MMM  GGGGGGGGG   " << std::endl;
                            std::cout << "    UUUUUUUUUUU   MMM      MMM   GGGGGGG  " << std::endl;
                            std::cout << "     UUUUUUUUU    MMM      MMM    GGGGG   " << std::endl;
                            std::cout << std::endl;
                            std::cout << "            Bienvenido al programa" << std::endl;
                            std::cout << "Esperamos que disfrutes explorando nuevas posibilidades." << std::endl;
                            std::cout << std::endl;
                            std::cout << "=============================================" << std::endl;
                            std::cout << "||          NOMBRE DE LOS CREADORES        ||" << std::endl;
                            std::cout << "=============================================" << std::endl;
                            std::cout << "||     9959-22-9790        Javier Lima     ||" << std::endl;
                            std::cout << "||     9959-22-9304        Kesdy Melgar    ||" << std::endl;
                            std::cout << "||     9959-22-8           Julio Molina    ||" << std::endl;
                            std::cout << "||     9959-22-5755        Erick Solares   ||" << std::endl;
                            std::cout << "=============================================" << std::endl;
                            std::cout << std::endl;
                            system("pause");
                        case 4:
                            return;
                        default:
                            cout << "\n\t\tOpcion inválida" << endl;
                            system("pause");
                            break;
                    }
                }while(opcion!=4);
				found++;
			}
			file >> name >> password;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t El usuario o contrasena sin incorrectos...";
		}
		file.close();
	}
}
void Usuario::menuSecundario()
{
    int opcion;
	do
    {
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Modificacion de Usuario ----------------------------------------------"<<endl;
    cout << "\n\tUsuario: " << name << endl << endl;
	cout<<"\t\t\t 1. Cambiar usuario o contrasena"<<endl;
	cout<<"\t\t\t 2. Borrar Usuario"<<endl;
	cout<<"\t\t\t 3. Regresar"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
            modificarCuenta();
            break;
        case 2:
            borrarCuenta();
            break;
        case 3:
            return;
        default:
            cout<<"\n\t\t\t Opcion invalida... Por favor, prueba otra vez..";
            system ("pause");
            break;
        }
    }while(opcion!=3);
}
void Usuario::modificarCuenta()
{
	system("cls");
	fstream file,file1;
	string name2, password2;
	int found=0, opcion;
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	cout<<"\n Ingrese su nombre de usuario: ";
    cin>>name2;
    cout<<" Ingrese la contrasena: ";
    cin>>password2;
    file1.open("Record.txt",ios::app | ios::out);
    file >> name >> password;
    while(!file.eof())
    {
        if(name2!=name && password2!=password){
         file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< password << "\n";
        }
        else{
            cout << "\n\tQue desea modificar?" << endl;
            cout << "\t1. Usuario" << endl;
            cout << "\t2. Contrasena" << endl;
            cout << "\tIngrese una opcion" << endl;
            cin >> opcion;
            if (opcion == 1){
                cout <<"\n Ingrese su nombre de usuario: ";
                cin >> name;
                file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< password<< "\n";
                found++;
            }
            else{
                if (opcion == 2){
                    cout <<" Ingrese la contrasena: ";
                    cin >> password;
                }
            file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< password << "\n";
            found++;
            }
        }
        file >> name >> password;
    }
    if(found == 0)
    {
        cout<<"\n\t\t\t Usuario no encontrado...";
    }
    file1.close();
    file.close();
    remove("nombresUsuarios.txt");
    rename("Record.txt","nombresUsuarios.txt");
}
void Usuario::borrarCuenta()
{
	system("cls");
	fstream file,file1;
	string name2, password2;
	int found=0;
	cout<<"\n------------------------- Borrar Cuenta -------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el usuario para borrar: ";
		cin>>name2;
		cout<<" Ingrese la contrasena: ";
		cin>>password2;
		file1.open("Record.txt",ios::app | ios::out);
		file >> name >> password;
		while(!file.eof())
		{
			if(name2!= name && password2 != password)
			{
				file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< password<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t Borrado de Usuario exitoso";
			}
			file >> name >> password;
		}
		if(found==0)
		{
			cout<<"\n\t Usuario no encontrado...";
		}
		file1.close();
		file.close();
		remove("nombresUsuarios.txt");
		rename("Record.txt","nombresUsuarios.txt");
		exit(0);
	}
}
