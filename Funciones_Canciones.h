#ifndef FUNCIONES_CANCIONES_H_INCLUDED
#define FUNCIONES_CANCIONES_H_INCLUDED

/*Hacer un submenú de listados para Canciones y para interpretes que tenga los listados existentes y agregarle dos listados ordenados por alguno de los campos
*/


///PROTOTIPOS

void Menucanciones ();
bool cargarCancion ();
bool validarInterprete(int);
bool estadoInterprete();
bool validarfecha (Fecha);
void mostrarCancion ();
int ultimoIDC();
bool listarxID();
int buscarCancion(int);
bool modificarFecha();
bool bajaLogica();
void submenuListados();
void listarCancionesOrdenado();
void copiarArchivoEnVector(Canciones *,int);
void mostrarVectorCanciones(Canciones *pCancion,int);
void listarCancionesOrdenadoxNombre();
void ordenarVectorCancionesPorNombre(Canciones *,int );
void listarCancionesOrdenadoxAnio();
void ordenarVectorCancionesPorAnio(Canciones *,int );
void ordenarVectorCancionesPorCancion(Canciones *,int );
void listarCancionesOrdenadoxCancion();
void listarCancionesOrdenadoxIDI();
void ordenarVectorCancionesPorIDI(Canciones *,int);
int contarCanciones();



///DESAROLLOS

void Menucanciones () {

    Canciones obj;
    int opc,c;
    while (true) {
        cuadro(32,80,8,21);
        rlutil::locate(47,9);
        cout << "MENU CANCIONES" << endl;
        rlutil::locate(33,10);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,11);
        cout << "1. Agregar cancion " << endl;
        rlutil::locate(45,12);
        cout << "2. Listar cancion por ID" << endl;
        rlutil::locate(45,13);
        cout << "3. Listar todas las canciones" << endl;
        rlutil::locate(45,14);
        cout << "4. Modificar fecha de estreno" << endl;
        rlutil::locate(45,15);
        cout << "5. Eliminar cancion" << endl;
        rlutil::locate(45,16);
        cout << "6. Submenu listados" << endl;
        rlutil::locate(33,17);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,18);
        cout << "0. Volver al menu principal" << endl ;
        rlutil::locate(33,19);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,20);
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system ("cls");
        switch (opc) {

        case 1:
            bool cargo;
            ///ABRIR ARCHIVO PARA BUSCAR EL ULTIMO ID
            cargo=cargarCancion();

            if (cargo==true) {
                cout << endl << "CANCION CARGADA CORRECTAMENTE!"<< endl;
            } else {
                rlutil::setColor(rlutil::RED);
                cout << endl << "NO SE PUDO CARGAR LA CANCION :(" << endl;
            }

            break;
        case 2:

            listarxID();

            break;
        case 3:

            mostrarCancion();

            break;
        case 4:
            bool modifico;
            modifico=modificarFecha();
            if (modifico==true) {
                cout << endl  << "FECHA MODIFICADA CORRECTAMENTE :)" << endl;
            } else {
                rlutil::setColor(rlutil::RED);
                cout << endl << "NO SE PUDO MODIFICAR LA FECHA :(" << endl;
            }
            break;
        case 5:
            bool borro;
            borro=bajaLogica();
            if (borro==true) {
                cout << endl << "CANCION BORRADA " << endl;
            } else {
                rlutil::setColor(rlutil::RED);
                cout << endl << "NO SE PUDO BORRAR LA CANCION" << endl;
            }
            break;

        case 6:
            submenuListados();
            break;

        case 0:

            return;

            break;
        default:
            rlutil::setColor(rlutil::RED);
            cout <<  "INGRESE UNA OPCION VALIDA!" << endl;
            break;
        }
        cout << endl;
        rlutil::setColor(rlutil::BLACK);
        system("pause");
        system ("cls");
    }

}


bool cargarCancion () {
    Canciones obj;
    Fecha f;
    bool valido;
    int inter;
    int c;
    c=ultimoIDC();
    c++;
    obj.setIDC(c);
    obj.Cargar();
    inter=obj.getIDI();
    ///VALIDAMOS QUE EL INTERPRETE EXISTA Y NO TENGA EL ESTADO EN FALSE, OSEA, NO ESTE EN BAJA LOGICA.
    valido=validarInterprete(inter);

    if (valido==false) {
        rlutil::setColor(rlutil::RED);
        cout << endl << "El ID de interprete no existe en el archivo :/" << endl;
        return false;
    }
    bool grabo;
    ///VALIDAMOS QUE LA FECHA SEA UNA CORRECTA USANDO GET FECHA Y USANDO LA FUNCION VALIDAR FECHA(FECHA)
    f = obj.getFecha();
    if (validarfecha (f) == false) {
        rlutil::setColor(rlutil::RED);
        cout << endl << "Fecha incorrecta!" << endl;
        return false;
    }
    ///FINALMENTE, GRABAMOS EN DISCO
    grabo = obj.grabarEnDisco();
    if (grabo == false) {
        return false;
    }
    return true;

}

void mostrarCancion () {
    int pos=0;
    Canciones obj;
    bool mostro, encontro;

    while (obj.leerEnDisco(pos)==1) {
        ///SI LA CANCION NO TIENE BAJA LOGICA, SE MUESTRA.
        if (obj.getEstado()!=false) {
            cout << "CANCION/ES" << endl;
            obj.Mostrar();
        }
        pos++;
    }


}

bool validarInterprete(int inter) {
    Interpretes obj;
    int pos=0;
    while (obj.leerEnDisco(pos)==1) {
        if (inter == obj.getIDI()) {
            if (obj.getEstado()!=false) {
                return true;

            }
        }
        pos++;
    }
    return false;
}


bool validarfecha(Fecha f) {
    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
	int d, m, a;
    int  diaxmes[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
   	d = now_tm->tm_mday;
   	m = now_tm->tm_mon + 1;
   	a = now_tm->tm_year;
   	a += 1900;

   	if (f.getDia() > d && f.getMes() > m && f.getAnio() > a){
        return false;
   	}
   	else if (f.getDia() > d && f.getMes() > m && f.getAnio() >= a){
        return false;
   	}
   	else if (f.getDia() > d && f.getMes() == m && f.getAnio() >= a){
        return false;
   	}
   	else if (f.getDia() < d && f.getMes() > m && f.getAnio() >= a){
        return false;
   	}
    else if (f.getMes() > m && f.getAnio() >= a){
        return false;
   	}
    else{
        if (f.getAnio() <= 0 || f.getAnio() > 2021) {
            return false;
        }
        else {
            if (f.getMes() < 0 || f.getMes() > 12) {
                return false;
            }
            else {
                if (f.getDia() < 0 || f.getDia() > diaxmes[f.getMes()]) {
                    return false;
                }
            }

        }
    }
    return true;
}

int ultimoIDC() {
    Canciones obj;
    int c=0;
    FILE *p;
    p=fopen("canciones.dat", "rb");
    if (p==NULL) {
            ///DEVOLVEMOS EL CONTADOR QUE VA A ESTAR EN 0 YA QUE, AL DAR NULL, SIGNIFICA QUE TODAVIA NO EXISTE EL ARCHIVO.
        return c;
    }
    fseek (p, -sizeof (Canciones), 2);
    fread (&obj, sizeof (Canciones), 1, p);
    c=obj.getIDC();
    fclose(p);
    return c;
}

bool listarxID() {
    int id;
    int pos;
    Canciones obj;
    cout << "Ingrese el ID de la cancion a listar: ";
    cin >> id;
    pos = buscarCancion(id);
    if (pos == -1) {
        rlutil::setColor(rlutil::RED);
        cout << endl << "CANCION NO ENCONTRADA :(" << endl;
        return false;
    }
    obj.leerEnDisco(pos);
    cout << endl << "CANCION ENCONTRADA"<< endl;
    obj.Mostrar();

}

int buscarCancion(int id) {
    Canciones obj;
    int pos=0;
    while (obj.leerEnDisco(pos)==1) {

        if (obj.getIDC()==id) {
            if (obj.getEstado()==true) {
                return pos;

            }
        }
        pos++;
    }

    return -1;
}

bool modificarFecha() {
    int id,pos,d,m,a;
    Canciones obj;
    Fecha f;
    bool modifico;
    cout << "Ingrese el ID de la cancion a listar: ";
    cin >> id;
    pos = buscarCancion(id);
    if (pos == -1) {
        rlutil::setColor(rlutil::RED);
        cout << endl <<  "CANCION NO ENCONTRADA :(" << endl;
        cout << "------------------------" << endl;
        return false;
    }
    obj.leerEnDisco(pos);
    cout << endl << "CANCION ENCONTRADA"<< endl;
    obj.Mostrar();
    cout << "------------------" << endl << "Ingrese la nueva fecha de estreno: " << endl;
    f.Cargar();
    if (validarfecha(f)==false) {
        rlutil::setColor(rlutil::RED);
        cout << endl << "FECHA INCORRECTA" << endl;
        return false;
    }
    obj.setFecha(f);
    modifico=obj.modificarEnDisco(pos);
    return modifico;

}

bool bajaLogica() {
    int id;
    int pos;
    char v;
    bool borro;
    Canciones obj;
    cout << "Ingrese el ID de la cancion a borrar: ";
    cin >> id;
    pos = buscarCancion(id);
    if (pos == -1) {
        rlutil::setColor(rlutil::RED);
        cout << endl << "CANCION NO ENCONTRADA :(" << endl;
        cout << "------------------------" << endl;
        return false;
    }
    obj.leerEnDisco(pos);
    cout << endl << "CANCION ENCONTRADA"<< endl;
    obj.Mostrar();
    cout << "-------------------" << endl;
    cout << "BORRAR CANCION? ('S' para si, 'N' para no): ";
    cin >> v;
    if (v == 'n' || v == 'N') {
        return false;
    } else if (v != 's' && v != 'S') {
        rlutil::setColor(rlutil::RED);
        cout << "OPCION NO VALIDA";
        return false;
    } else {
        obj.setEstado(false);
        borro=obj.modificarEnDisco(pos);
        return borro;
    }
}

void submenuListados(){
    while (true) {
        int opc;
        cuadro(32,80,8,19);
        rlutil::locate(48,9);
        cout << "SUBMENU LISTADOS" << endl;
        rlutil::locate(33,10);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,11);
        cout << "1. Listar canciones por año " << endl;
        rlutil::locate(35,12);
        cout << "2. Listar canciones alfabeticamente por autor" << endl;
        rlutil::locate(33,13);
        cout << "3. Listar canciones alfabeticamente por cancion" << endl;
        rlutil::locate(37,14);
        cout << "4. Listar canciones por ID de interprete " << endl;
        rlutil::locate(33,15);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,16);
        cout << "0. Volver al menu principal" << endl ;
        rlutil::locate(33,17);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,18);
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system ("cls");
        switch (opc) {

        case 1:
            listarCancionesOrdenadoxAnio();

            break;
        case 2:
            listarCancionesOrdenadoxNombre();


            break;
        case 3:
            listarCancionesOrdenadoxCancion();


            break;
        case 4:
            listarCancionesOrdenadoxIDI();
            break;

        case 0:

            return;

            break;
        default:
            rlutil::setColor(rlutil::RED);
            cout <<  "INGRESE UNA OPCION VALIDA!" << endl;
            break;
        }
        cout << endl;
        rlutil::setColor(rlutil::BLACK);
        system("pause");
        system ("cls");
    }

}

void copiarArchivoEnVector(Canciones *pCancion,int cantReg){
    int i;
    for(i=0;i<cantReg;i++)
        pCancion[i].leerEnDisco(i);

}

void mostrarVectorCanciones(Canciones *pCancion,int cantReg){
    int i;
    for(i=0;i<cantReg;i++){
        pCancion[i].Mostrar();
        cout<<endl<<endl;
    }


}

int contarCanciones(){
    FILE *p;
    p=fopen("canciones.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Canciones);
}

/// POR AÑO!!!

void listarCancionesOrdenadoxAnio(){
    int cantReg;
    Canciones *pCancion;
    cantReg=contarCanciones();
    if(cantReg==0){
        cout<<"NO HAY REGISTROS"<<endl;
        return;
    }
    pCancion=new Canciones[cantReg];
    if(pCancion==NULL)return;

    copiarArchivoEnVector(pCancion,cantReg);
    ordenarVectorCancionesPorAnio(pCancion,cantReg);
    mostrarVectorCanciones(pCancion,cantReg);
    delete pCancion;
}


void ordenarVectorCancionesPorAnio(Canciones *pCancion,int cantReg){
    int i, j, posMin;
    Canciones aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(pCancion[j].getFecha().getAnio()<pCancion[posMin].getFecha().getAnio()){
                posMin=j;
            }
        }
        aux=pCancion[i];
        pCancion[i]=pCancion[posMin];
        pCancion[posMin]=aux;

    }
}

/// POR NOMBRE!!

void listarCancionesOrdenadoxNombre(){
    int cantReg;
    Canciones *pCancion;
    cantReg=contarCanciones();
    if(cantReg==0){
        cout<<"NO HAY REGISTROS"<<endl;
        return;
    }
    pCancion=new Canciones[cantReg];
    if(pCancion==NULL)return;

    copiarArchivoEnVector(pCancion,cantReg);
    ordenarVectorCancionesPorNombre(pCancion,cantReg);
    mostrarVectorCanciones(pCancion,cantReg);
    delete pCancion;
}

void ordenarVectorCancionesPorNombre(Canciones *pCancion,int cantReg){
    int i, j, posMin;
    Canciones aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(strcmp(pCancion[j].getNautor(),pCancion[posMin].getNautor())<0){
                posMin=j;
            }
        }
        aux=pCancion[i];
        pCancion[i]=pCancion[posMin];
        pCancion[posMin]=aux;

    }
}

/// POR CANCION!!

void listarCancionesOrdenadoxCancion(){
    int cantReg;
    Canciones *pCancion;
    cantReg=contarCanciones();
    if(cantReg==0){
        cout<<"NO HAY REGISTROS"<<endl;
        return;
    }
    pCancion=new Canciones[cantReg];
    if(pCancion==NULL)return;

    copiarArchivoEnVector(pCancion,cantReg);
    ordenarVectorCancionesPorCancion(pCancion,cantReg);
    mostrarVectorCanciones(pCancion,cantReg);
    delete pCancion;
}

void ordenarVectorCancionesPorCancion(Canciones *pCancion,int cantReg){
    int i, j, posMin;
    Canciones aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(strcmp(pCancion[j].getNcancion(),pCancion[posMin].getNcancion())<0){
                posMin=j;
            }
        }
        aux=pCancion[i];
        pCancion[i]=pCancion[posMin];
        pCancion[posMin]=aux;

    }
}

/// POR IDI!!

void listarCancionesOrdenadoxIDI(){
    int cantReg;
    Canciones *pCancion;
    cantReg=contarCanciones();
    if(cantReg==0){
        cout<<"NO HAY REGISTROS"<<endl;
        return;
    }
    pCancion=new Canciones[cantReg];
    if(pCancion==NULL)return;

    copiarArchivoEnVector(pCancion,cantReg);
    ordenarVectorCancionesPorIDI(pCancion,cantReg);
    mostrarVectorCanciones(pCancion,cantReg);
    delete pCancion;
}

void ordenarVectorCancionesPorIDI(Canciones *pCancion,int cantReg){
    int i, j, posMin;
    Canciones aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(pCancion[j].getIDI()<pCancion[posMin].getIDI()){
                posMin=j;
            }
        }
        aux=pCancion[i];
        pCancion[i]=pCancion[posMin];
        pCancion[posMin]=aux;

    }
}







#endif // FUNCIONES_CANCIONES_H_INCLUDED
