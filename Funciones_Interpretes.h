#ifndef FUNCIONES_INTERPRETES_H_INCLUDED
#define FUNCIONES_INTERPRETES_H_INCLUDED

///PROTOTIPOS
void Menuinterpretes ();
bool cargarInterprete ();
bool mostrarInterprete ();
int ultimoIDI();
bool validarTipoI (int);
bool validarTipoM (int);
bool listarxIDI();
int buscarInterprete(int);
bool modificarTipoM();
bool bajaLogicaI();

///DESARROLLOS

void Menuinterpretes (){
    int opc;
while (true) {
    cuadro(32,80,8,20);
        rlutil::locate(47,9);
        cout << "MENU INTERPRETES" << endl;
        rlutil::locate(33,10);
        cout << "----------------------------------------------" << endl;
        rlutil::locate(45,11);
        cout << "1. Agregar interprete " << endl;
        rlutil::locate(45,12);
        cout << "2. Listar interprete por ID" << endl;
        rlutil::locate(45,13);
        cout << "3. Listar todas los interpretes" << endl;
        rlutil::locate(45,14);
        cout << "4. Modificar tipo de musica" << endl;
        rlutil::locate(45,15);
        cout << "5. Eliminar interprete" << endl;
        rlutil::locate(33,16);
        cout << "----------------------------------------------" << endl;
         rlutil::locate(45,17);
        cout << "0. Volver al menu principal" << endl ;
         rlutil::locate(33,18);
        cout << "----------------------------------------------" << endl;
         rlutil::locate(45,19);
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system ("cls");
         switch (opc){

        case 1:
            bool cargo;
            cargo=cargarInterprete();

            if (cargo==true) {
                cout <<  "INTERPRETE CARGADO CORRECTAMENTE!"<< endl;
            }
            else {
                    rlutil::setColor(rlutil::RED);
                cout << endl << "NO SE PUDO CARGAR EL/LA INTERPRETE :(" << endl;
            }
            break;
        case 2:

            listarxIDI();


            break;
        case 3:
            mostrarInterprete();
            break;
        case 4:
            bool modifico;
            modifico=modificarTipoM();
            if (modifico==true){
                cout << endl << "TIPO DE MUSICA MODIFICADO CORRECTAMENTE!" << endl;
            }
            else{
                    rlutil::setColor(rlutil::RED);
                cout << endl << "NO SE PUDO MODIFICAR EL TIPO DE MUSICA :(" << endl;
            }
            break;
        case 5:
            bool borro;
            borro=bajaLogicaI();
            if (borro==true){
                cout << endl << "INTERPRETE BORRADO/A " << endl;
            }
            else{
                    rlutil::setColor(rlutil::RED);
                cout << endl << "NO SE PUDO BORRAR EL/LA INTERPRETE" << endl;
            }
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
        rlutil::setColor(rlutil::WHITE);
        system ("pause");
        system ("cls");
    }
}

bool cargarInterprete(){
    Interpretes obj;
    int ti,tm,c,validoI, validoM;

    c=ultimoIDI();
    c++;
    obj.setIDI(c);
    obj.Cargar();
    ti=obj.getTipoI();
    tm=obj.getTipoM();
    validoI = validarTipoI (ti);
    validoM = validarTipoM (tm);
    bool grabo;
    cout << endl;
    if (validoI==false && validoM==false){
        rlutil::setColor(rlutil::RED);
        cout << "Tipo de interprete y tipo de musica incorrecto!" << endl;
        return false;
    }
    else if (validoM == false ){
        rlutil::setColor(rlutil::RED);
        cout << "Tipo de musica incorrecto!" << endl;
        return false;
    }
    else if (validoI == false){
        rlutil::setColor(rlutil::RED);
        cout << "Tipo de interprete incorrecto!" << endl;
        return false;
    }

    grabo = obj.grabarEnDisco();
    if (grabo == false) {
        return false;
    }
       return true;

}

bool validarTipoI(int ti){

    if (ti < 1 || ti > 5){
        return false;
    }
    else{
        return true;
    }

}
bool validarTipoM(int tm){

    if (tm < 1 || tm > 10){
        return false;
    }
    else{
        return true;
    }

}

bool mostrarInterprete () {
    cout << "INTERPRETE/ES" << endl;
    int pos=0;
    Interpretes obj;
    bool mostro;

    while (obj.leerEnDisco(pos)==1) {

        if (obj.getEstado()!=false){
        obj.Mostrar();
        }
        pos++;
    }

    if (mostro == false) {
        return false;
    }
    return true;
}


int ultimoIDI(){
 FILE *q;
 Interpretes obj;
 int cantreg;
 int cantbyte=0;
 q=fopen("interpretes.dat" , "rb") ;
 if (q==NULL){
    return 0 ;
 }
 while (fread(&obj, sizeof obj, 1, q)==1);
 cantbyte=ftell(q);
 cantreg = cantbyte/sizeof (Interpretes);
 fclose(q);
 return cantreg;

}

bool listarxIDI() {
    int id;
    int pos;
    Interpretes obj;
    cout << "Ingrese el ID del interprete a listar: ";
    cin >> id;
    pos = buscarInterprete(id);
    if (pos == -1){
            rlutil::setColor(rlutil::RED);
            cout << endl << "INTERPRETE NO ENCONTRADO/A :(" << endl;
        return false;
    }
    obj.leerEnDisco(pos);
    cout << endl <<  "INTERPRETE ENCONTRADO/A"<< endl;
    obj.Mostrar();

}

int buscarInterprete(int id) {
    Interpretes obj;
    int pos=0;
    while (obj.leerEnDisco(pos)==1) {

        if (obj.getIDI()==id) {
                if (obj.getEstado()==true){
            return pos;

            }
        }
        pos++;
    }

    return -1;
}

bool modificarTipoM() {
    int id,pos, tm;
    Interpretes obj;
    bool modifico, validoM;
    cout << "Ingrese el ID del/la interprete a modificar: ";
    cin >> id;
    pos = buscarInterprete(id);
    if (pos == -1){
            rlutil::setColor(rlutil::RED);
            cout << endl << "INTERPRETE NO ENCONTRADO/A :(" << endl;
            cout << "------------------------" << endl;
        return false;
    }
    obj.leerEnDisco(pos);
    cout << endl << "INTERPRETE ENCONTRADO/A"<< endl;
    obj.Mostrar();
    cout << endl<<  "-------------------------" << endl;
    cout << "Ingrese el nuevo tipo de musica: ";
    cin >> tm;
    validoM=validarTipoM(tm);
    if (validoM == false ){
        rlutil::setColor(rlutil::RED);
        cout << endl << "Tipo de musica incorrecto!" << endl;
        return false;
    }
    obj.setTipoM(tm);
    modifico=obj.modificarEnDisco(pos);
    return modifico;

}

bool bajaLogicaI(){
    int id;
    int pos;
    char v;
    bool borro;
    Interpretes obj;
    cout << "Ingrese el ID del/la interprete a borrar: ";
    cin >> id;
    pos = buscarInterprete(id);
    if (pos == -1){
            rlutil::setColor(rlutil::RED);
            cout << endl <<  "INTERPRETE NO ENCONTRADO/A :(" << endl;
            cout << "------------------------" << endl;
        return false;
    }
    obj.leerEnDisco(pos);
    cout << endl << "INTERPRETE ENCONTRADO/A"<< endl;
    obj.Mostrar();
    cout << "-------------------" << endl;
    cout << "BORRAR INTERPRETE? ('S' para si, 'N' para no): ";
    cin >> v;
    if (v == 'n' || v == 'N'){
        return false;
    }
    else if (v != 's' && v != 'S'){
        rlutil::setColor(rlutil::RED);
        cout << "OPCION NO VALIDA";
        return false;
    }
    else{
       obj.setEstado(false);
       borro=obj.modificarEnDisco(pos);
       return borro;
    }
}



#endif // FUNCIONES_INTERPRETES_H_INCLUDED
