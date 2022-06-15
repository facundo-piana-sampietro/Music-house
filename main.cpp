
///Programa desarollado para el primer parcial de la materia Laboratorio II, 1°Año, Cuatrimestre 2.
///Desarrolladores: Facundo Piana Sampietro (Legajo 25035) y Pablo Alderete (Legajo 24902).
///Profesores: Daniel Kloster y Maximiliano Wenner.

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <clocale>
#include <string.h>
#include <ctime>
using namespace std;
#include "rlutil.h"
#include "Estetica.h"
#include "cargarcadena.h"
#include "Class Canciones.h"
#include "Class Interpretes.h"
#include "Funciones_Canciones.h"
#include "Funciones_Interpretes.h"
#include "Funciones_Configuracion.h"
#include "parcial_Piana_Sampietro.h"


int main() {
    int opc;

    while (true) {
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::BLACK);
        system("cls");
        cuadro(32,80,8,19);
        rlutil::locate(33,9);
        cout << "BIENVENIDO AL SISTEMA DE REGISTRO DE CANCIONES" << endl;
        rlutil::locate(33,10);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(47,11);
        cout << "1. Menu canciones" << endl;
        rlutil::locate(47,12);
        cout << "2. Menu interpretes " << endl;
        rlutil::locate(47,13);
        cout << "3. Reportes" << endl;
        rlutil::locate(47,14);
        cout << "4. Configuracion" << endl;
        rlutil::locate(33,15);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(47,16);
        cout << "0. Salir del programa" << endl ;
        rlutil::locate(33,17);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(47,18);
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system ("cls");

        switch (opc) {

        case 1:
            rlutil::setBackgroundColor(rlutil::GREEN);
            system("cls");
            Menucanciones();
            break;
        case 2:
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE);
            system("cls");
            Menuinterpretes();
            break;
        case 3:
            rlutil::setBackgroundColor(rlutil::MAGENTA);
            rlutil::setColor(rlutil::BLACK);
            system("cls");
            Menureportes();
            break;
        case 4:
            rlutil::setBackgroundColor(rlutil::CYAN);
            system("cls");
            Menuconfig();
            break;

        case 0:
            {
            charmander();
            rlutil::setBackgroundColor(rlutil::BROWN);
            cuadro(59,98,12,15);
            rlutil::locate(60,13);
            cout << "Gracias por utilizar nuestro programa!";
            rlutil::locate(66,14);
            cout  << "Que tenga un buen dia!! :)";
            rlutil::locate(20,24);
            return 0;
            }
            break;

        default:
            cout << "INGRESE UNA OPCION VALIDA!" << endl;
            break;
        }


        system ("cls");
    }


    return 0;
}
