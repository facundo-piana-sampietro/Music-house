#ifndef PARCIAL_PIANA_SAMPIETRO_H_INCLUDED
#define PARCIAL_PIANA_SAMPIETRO_H_INCLUDED
///PROTOTIPOS
void CancionesxInterprete();
void Menureportes();
void MasEstrenos();
bool ListarxNombre();
void ArchivoClasica();
void GuardarEnArchivo(int);
void mostrarClasica ();
bool crearArchivo();
bool noEsta(const char*);
void Canciones2010();
int cantidadcanciones(int);
void SinEstrenos2020();
void Canciones2021();
void mostrarCanciones2021();
bool EncontrarCanciones2021(int);
bool CancionesDeseadas();
bool crearArchivoInterpretes2021();

///DESARROLLOS
void Menureportes () {
    int opc;
    while (true) {

        cuadro(32,80,8,27);
        rlutil::locate(50,9);
        cout << "MENU REPORTES" << endl;
        rlutil::locate(33,10);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(35,11);
        cout << "1. Cantidad de canciones por interprete " << endl;
        rlutil::locate(36,12);
        cout << "2. Anio con mas estrenos de este siglo " << endl;
        rlutil::locate(34,13);
        cout << "3. Listar canciones por nombre de interprete" << endl;
        rlutil::locate(35,14);
        cout << "4. Canciones de los interpretes clasicos" << endl;
        rlutil::locate(33,15);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(52,16);
        cout << "PARCIAL" << endl;
        rlutil::locate(33,17);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(33,18);
        cout << "5. Cantidad de canciones del autor del año 2010"<<endl;
        rlutil::locate(34,19);
        cout << "6. Mes/es sin estrenos de discos del año 2020" << endl;
        rlutil::locate(35,20);
        cout << "7. Generar archivo con canciones de este año" << endl;
        rlutil::locate(40,21);
        cout << "8. Mostrar canciones del año 2021" << endl;
        rlutil::locate(37,22);
        cout << "9. Mostrar cantidad de canciones deseada" << endl;
        rlutil::locate(33,23);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(43,24);
        cout << "0. Volver al menu principal" << endl ;
        rlutil::locate(33,25);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,26);
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system ("cls");

        switch (opc) {
        case 1:

            CancionesxInterprete();

            break;

        case 2:
            MasEstrenos();

            break;
        case 3:
            bool listo;
            listo=ListarxNombre();
            if (listo==false) {

                cout << endl << "NO SE PUDO ENCONTRAR EL ARTISTA." << endl;
            }
            break;
        case 4:

            ArchivoClasica();

            break;
        case 5:

            Canciones2010();

            break;
        case 6:

            SinEstrenos2020();
            break;
        case 7:
            Canciones2021();
            break;
        case 8:
            mostrarCanciones2021();
            break;
        case 9:
            CancionesDeseadas();
            break;
        case 0:

            return;

            break;
        default:
            rlutil::setColor(rlutil::RED);
            cout << "INGRESE UNA OPCION VALIDA!" << endl;
            break;
        }
        cout << endl;
        rlutil::setColor(rlutil::BLACK);
        system("pause");
        system ("cls");
    }

}

void CancionesxInterprete() {
    Interpretes obj;
    Canciones obj2;
    int idi;
    int pos=0,pos2=0,cc=0;
    while (obj.leerEnDisco(pos++)==1) {
        idi=obj.getIDI();
        while (obj2.leerEnDisco(pos2++)==1) {

            if (idi==obj2.getIDI()) {
                cc++;
            }
        }
        cout << "Artista: " << obj.getNombre() << endl;
        cout << "ID de interprete: " << obj.getIDI() << endl;
        cout << "Cantidad de canciones: " << cc << endl;
        cc=0;
        pos2=0;
        cout << "------------------------------------------------------------------" << endl;

    }
}

void MasEstrenos() {

    Canciones obj;
    Fecha f;
    int pos=0,vAnio[22]= {},maxi,maxianio;
    while (obj.leerEnDisco(pos++)==1) {
        f=obj.getFecha();
        if (f.getAnio() >= 2000 && f.getAnio() <= 2021) {
            if (obj.getEstado()!=false) {
                vAnio[f.getAnio()-2000]++;

            }


        }


    }
    maxi=vAnio[0];
    maxianio=2000;
    for (int i=1; i < 22; i++) {

        if (maxi < vAnio[i]) {
            maxi=vAnio[i];
            maxianio=i+2000;
        }

    }
    cout << "El anio con mas registros de canciones es el anio " << maxianio;
}

bool ListarxNombre() {
    Canciones obj;
    Interpretes obj1;
    bool comp;
    char art[30];
    int pos=0,pos1=0,idi;
    cout << "Ingrese el artista del cual desea listar sus canciones: ";
    cargarCadena(art,30);
    while (obj1.leerEnDisco(pos++)==1) {
        comp=strcmp(art,obj1.getNombre());
        if (comp==0) {
            idi=obj1.getIDI();
            while (obj.leerEnDisco(pos1++)==1) {

                if (idi==obj.getIDI()) {
                    if (obj.getEstado()!=false) {
                        obj.Mostrar();
                    }
                }

            }
            return true;
        }
    }
    return false;
}

class Clasica {
  protected:
    ///PROPIEDADES
    int IDC;
    char Ncancion[30];
    char Nautor[30];

  public:

    ///METODOS DE ARCHIVOS
    void Mostrar () {
        cout << "------------------" << endl;
        cout << "ID de la cancion: " << IDC << endl;
        cout << "Nombre de la cancion: " << Ncancion << endl;
        cout << "Nombre del autor: " << Nautor << endl;
    }
    bool grabarEnDisco() {
        FILE *p;
        bool grabo;
        p=fopen ("clasica.dat", "ab");
        if (p==NULL) {
            cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
            return false;
        }
        grabo=fwrite (this, sizeof (Canciones), 1, p);
        fclose (p);
        return grabo;
    }

    bool leerEnDisco(int pos) {
        FILE *p;
        bool leyo;
        p=fopen ("clasica.dat", "rb");
        if (p==NULL) {
            cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
            return false;
        }
        fseek(p, sizeof (Canciones)*pos, 0);
        leyo=fread (this, sizeof (Canciones), 1, p);
        fclose (p);
        return leyo;
    }
    bool crearArchivoClasica() {
        FILE *p;
        p=fopen("clasica.dat", "wb");
        if (p==NULL) {
            return false;
        }
        fclose(p);
        return true;
    }
    ///GETS
    int getIDC() {
        return IDC;
    }
    const char* getNcancion() {
        return Ncancion;
    }
    const char* getNautor() {
        return Nautor;
    }
    ///SETS
    void setIDC (int i) {
        IDC=i;
    }
    void setNcancion(const char* nc) {
        strcpy (Ncancion, nc);
    }
    void setNautor(const char* na) {
        strcpy (Nautor, na);
    }
};


void ArchivoClasica() {
    Interpretes obj;
    Clasica obj1;
    bool noesta,creo;
    int pos=0,c=0;
    creo=obj1.crearArchivoClasica();
    if (creo==false) {
        cout << "No se pudo crear el archivo!" << endl;
    } else {
        while (obj.leerEnDisco(pos++)==1) {
            if (obj.getTipoM()==2) {

                GuardarEnArchivo(obj.getIDI());


            }
        }
        cout << "CANCION/ES CLASICAS" << endl;
        int pos1=0;

        while (obj1.leerEnDisco(pos1++)==1) {

            obj1.Mostrar();


        }
    }
}

void GuardarEnArchivo(int idi) {
    Clasica aux;
    Canciones obj;
    int idc;
    bool noesta;
    int pos=0;
    while (obj.leerEnDisco(pos++)==1) {

        if (idi==obj.getIDI()) {
            if (obj.getEstado()!=false) {

                aux.setIDC(obj.getIDC());
                aux.setNautor(obj.getNautor());
                aux.setNcancion(obj.getNcancion());
                aux.grabarEnDisco();
            }
        }
    }
}

///

/// --------------------------------   PARCIAL   ----------------------------------------

///

void Canciones2010() {
    char nombre[40];
    int iguales;
    Canciones obj;
    int c=0;
    bool encontro=false;
    cout << "Ingresar nombre de autor: ";
    cargarCadena(nombre,40);
    int pos=0;
    while (obj.leerEnDisco(pos++)==1) {
        iguales=strcmp(obj.getNautor(),nombre);

        if (iguales==0) {
            encontro=true;
            c++;
        }

    }

    if (encontro != true) {
        cout << endl << "AUTOR INEXISTENTE EN EL ARCHIVO DE INTERPRETES!" << endl;
    }
    else {
        cout << endl << "CANCIONES DEL AUTOR '" << nombre << "' REGISTRADAS EN 2010: " << c << endl;
    }
}


void SinEstrenos2020() {
    Canciones obj;
    Fecha f;
    int pos=0,c2020=0,csin2020[12]= {};
    while (obj.leerEnDisco(pos++)==1) {
        f=obj.getFecha();
        if (f.getAnio()==2020 ) {
            if (obj.getEstado()==true) {
                c2020++;
                csin2020[f.getMes()-1]++;
            }
        }

    }

    cout << "Meses sin estrenos de discos durante el 2020" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i=0; i<12; i++) {
        if (csin2020[i]==0) {
            cout << "Mes numero " << i+1 << endl;
        }
    }

}


class Interpretes2021 {
  protected:
    ///PROPIEDADES
    int IDI;
    char Nombre[40];
    char Nacionalidad [20];

  public:

    ///METODOS DE ARCHIVOS
    void Mostrar () {
        cout << "------------------" << endl;
        cout << "ID del inteprete: " << IDI << endl;
        cout << "Nombre del autor: " << Nombre << endl;
        cout << "Nacionalidad: " << Nacionalidad << endl;
    }
    bool grabarEnDisco() {
        FILE *p;
        bool grabo;
        p=fopen ("interpretes2021.dat", "ab");
        if (p==NULL) {
            cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
            return false;
        }
        grabo=fwrite (this, sizeof (Interpretes2021), 1, p);
        fclose (p);
        return grabo;
    }

    bool leerEnDisco(int pos) {
        FILE *p;
        bool leyo;
        p=fopen ("interpretes2021.dat", "rb");
        if (p==NULL) {
            cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
            return false;
        }
        fseek(p, sizeof (Interpretes2021)*pos, 0);
        leyo=fread (this, sizeof (Interpretes2021), 1, p);
        fclose (p);
        return leyo;
    }

    ///GETS
    int getIDI() {
        return IDI;
    }
    const char* getNombre() {
        return Nombre;
    }
    const char* getNacionalidad() {
        return Nacionalidad;
    }
    ///SETS
    void setIDI (int ii) {
        IDI=ii;
    }
    void setNombre(const char* no) {
        strcpy (Nombre, no);
    }
    void setNacionalidad(const char* na) {
        strcpy (Nacionalidad, na);
    }
};

void Canciones2021() {

    Interpretes obj;
    Interpretes2021 reg;

    bool creo,esteAnio,grabo;
    int pos=0,c=0,c2=0;

    creo=crearArchivoInterpretes2021();

    if (creo==false) {
        cout << "No se pudo crear el archivo!" << endl;
    } else {
        while (obj.leerEnDisco(pos++)==1) {
            c2++;
            esteAnio=EncontrarCanciones2021(obj.getIDI());
            if (esteAnio==true) {
                if (obj.getEstado()==true) {

                    reg.setIDI(obj.getIDI());
                    reg.setNombre(obj.getNombre());
                    reg.setNacionalidad(obj.getNacionalidad());
                    grabo=reg.grabarEnDisco();

                    if (grabo==false) {
                        c++;
                    }
                }

            }

        }
    }

    if (c2==c) {
        cout << "El archivo no pudo grabar ninguna cancion!" << endl;
    } else if (c!=0) {
        cout << "El archivo se creo correctamente, pero hubo " << c << " canciones que no se pudieron grabar :/" <<  endl;
    } else {
        cout << "El archivo se creo correctamente!" << endl;
    }
}

bool EncontrarCanciones2021(int idi) {
    Fecha f;
    Canciones obj;
    int pos=0;
    while (obj.leerEnDisco(pos++)==1) {
        if (idi==obj.getIDI()) {
            f=obj.getFecha();
            if (f.getAnio()==2021) {
                return true;
            }
        }

    }
    return false;
}

void mostrarCanciones2021() {
    Interpretes2021 obj;
    int pos=0;

    cout << "Canciones creadas en el 2021" << endl;
    while (obj.leerEnDisco(pos++)==1) {
        obj.Mostrar();
    }
}


///Hacer un vector dinámico de enteros que tenga el tamaño que se ingrese por teclado.
///Luego cargar y mostrar ese vector

bool CancionesDeseadas() {
    int cantc;
    Canciones *deseoC;
    cout << "Cantidad de canciones a mostrar: ";
    cin >> cantc;
    deseoC= new Canciones[cantc];
    if (deseoC==NULL) {
        cout << "No se pudo asignar memoria!";
        return false;
    }

    for (int i=0;i<cantc;i++){
        deseoC[i].leerEnDisco(i);
    }

    for (int i=0;i<cantc;i++){
        deseoC[i].Mostrar();
    }

    delete deseoC;

}

 bool crearArchivoInterpretes2021() {
        FILE *p;
        p=fopen("interpretes2021.dat", "wb");
        if (p==NULL) {
            return false;
        }
        fclose(p);
        return true;
    }


#endif // PARCIAL_PIANA_SAMPIETRO_H_INCLUDED
