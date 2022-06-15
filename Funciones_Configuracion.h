#ifndef FUNCIONES_CONFIGURACION_H_INCLUDED
#define FUNCIONES_CONFIGURACION_H_INCLUDED

///PROTOTIPOS
void Menuconfig();
bool bkpCanciones();
bool bkpInterpretes();
bool resCanciones();
bool resInterpretes();
void resDDI();
bool resDDII();
bool resDDIC();

///DESARROLLOS

void Menuconfig () {
    int opc,c;
    while (true) {
        cuadro(32,80,8,20);
        rlutil::locate(47,9);
        cout << "MENU CONFIGURACION" << endl;
        rlutil::locate(33,10);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(35,11);
        cout << "1. Copia de seguridad del archivo canciones" << endl;
        rlutil::locate(34,12);
        cout << "2. Copia de seguridad del archivo interpretes" << endl;
        rlutil::locate(38,13);
        cout << "3. Restaurar el archivo de canciones" << endl;
        rlutil::locate(37,14);
        cout << "4. Restaurar el archivo de interpretes" << endl;
        rlutil::locate(41,15);
        cout << "5. Establecer datos de inicio" << endl;
        rlutil::locate(33,16);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(43,17);
        cout << "0. Volver al menu principal" << endl ;
        rlutil::locate(33,18);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(46,19);
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system ("cls");
        switch (opc) {

        case 1:
            bool copioC;
            copioC=bkpCanciones();
            if (copioC==true) {
                cout << "Se realizo la copia de archivos correctamente!"<<endl;
            } else {
                cout << "Error en la copia de archivos!" << endl;
            }
            break;
        case 2:
            bool copioI;
            copioI=bkpInterpretes();
            if (copioI==true) {
                cout << "Se realizo la copia de archivos correctamente!"<<endl;
            } else {
                cout << "Error en la copia de archivos!" << endl;
            }
            break;
        case 3:
            bool restauroC;
            restauroC=resCanciones();
            if (restauroC==true) {
                cout << "Se realizo la restauracion de archivos correctamente!"<<endl;
            } else {
                cout << "Error en la restauracion de archivos!" << endl;
            }

            break;
        case 4:
            bool restauroI;
            restauroI=resInterpretes();
            if (restauroI==true) {
                cout << "Se realizo la restauracion de archivos correctamente!"<<endl;
            } else {
                cout << "Error en la restauracion de archivos!" << endl;
            }
            break;
        case 5:

            resDDI();

            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA!" << endl;
            break;
        }
        cout << endl;
        rlutil::setColor(rlutil::BLACK);
        system("pause");
        system ("cls");
    }
}

bool bkpCanciones() {
    FILE *b;
    Canciones obj;
    int pos=0;
    b=fopen("canciones.bkp", "wb");
    if (b==NULL) {
        rlutil::setColor(rlutil::RED);

        cout << "No se pudo abrir el archivo de Back Up!" << endl;
        return false;
    }
    while (obj.leerEnDisco(pos)==1) {

        fwrite(&obj, sizeof (Canciones), 1, b);
        pos++;
    }
    fclose (b);
    return true;

}

bool bkpInterpretes() {
    FILE *b;
    Interpretes obj;
    int pos=0;
    b=fopen("interpretes.bkp", "wb");
    if (b==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo de Back Up!" << endl;
        return false;
    }
    while (obj.leerEnDisco(pos)==1) {

        fwrite(&obj, sizeof (Interpretes), 1, b);
        pos++;
    }
    fclose (b);
    return true;
}

bool resCanciones() {
    FILE *b, *p;
    Canciones obj;
    b=fopen("canciones.bkp", "rb");
    if (b==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo de restauracion!" << endl;
        return false;
    }
    p=fopen("canciones.dat", "wb");

    if (p==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo para restaurar!" << endl;
        return false;
    }

    while (fread(&obj, sizeof (Canciones), 1, b)==1) {
        fwrite(&obj, sizeof (Canciones), 1, p);
    }

    fclose (b);
    fclose (p);
    return true;

}

bool resInterpretes() {
    FILE *b, *p;
    Interpretes obj;
    b=fopen("interpretes.bkp", "rb");
    if (b==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo de restauracion!" << endl;
        return false;
    }
    p=fopen("interpretes.dat", "wb");

    if (p==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo para restaurar!" << endl;
        return false;
    }

    while (fread(&obj, sizeof (Interpretes), 1, b)==1) {
        fwrite(&obj, sizeof (Interpretes), 1, p);
    }

    fclose (b);
    fclose (p);
    return true;

}

void resDDI() {
    bool resI, resC;
    resC=resDDIC();
    resI=resDDII();
    if (resC==true) {
        cout << "Se restauro existosamente las canciones con los datos de inicio!" << endl << endl;
    }
    else {
        cout << "No se pudo realizar la restauracion de las canciones con los datos de inicio " << endl << endl;
    }
    if (resI==true) {
        cout << "Se restauro existosamente los interpretes con los datos de inicio!" << endl << endl;
    }
    else {
        cout << "No se pudo realizar la restauracion de interpretes con los datos de inicio " << endl << endl;
    }

}

bool resDDIC() {
    FILE *b, *p;
    Canciones obj;
    b=fopen("inicioc.dat", "rb");
    if (b==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo de datos de inicio de canciones!" << endl;
        return false;
    }
    p=fopen("canciones.dat", "wb");

    if (p==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo de canciones para restaurar con los datos de inicio!" << endl;
        return false;
    }

    while (fread(&obj, sizeof (Canciones), 1, b)==1) {
        fwrite(&obj, sizeof (Canciones), 1, p);
    }

    fclose (b);
    fclose (p);
    return true;

}
bool resDDII() {
    FILE *b, *p;
    Interpretes obj;
    b=fopen("inicioi.dat", "rb");
    if (b==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo de datos de inicio de interpretes!" << endl;
        return false;
    }
    p=fopen("interpretes.dat", "wb");

    if (p==NULL) {
        rlutil::setColor(rlutil::RED);
        cout << "No se pudo abrir el archivo de interpretes para restaurar con los datos de inicio!" << endl;
        return false;
    }

    while (fread(&obj, sizeof (Interpretes), 1, b)==1) {
        fwrite(&obj, sizeof (Interpretes), 1, p);
    }

    fclose (b);
    fclose (p);
    return true;


}

#endif // FUNCIONES_CONFIGURACION_H_INCLUDED
