#ifndef CLASS_INTERPRETES_H_INCLUDED
#define CLASS_INTERPRETES_H_INCLUDED

class Interpretes{
protected:
    ///PROPIEDADES
    int IDI;
    char Nombre[40];
    char Nacionalidad[20];
    int TipoI;
    int TipoM;
    bool Estado;

public:
    ///CONSTRUCTOR
   Interpretes (int idi=0, const char *no="----",const char *na="----",int ti=0, int tm=0, bool e=true){
        IDI=idi;
        strcpy (Nombre, no);
        strcpy (Nacionalidad, na);
        TipoI=ti;
        TipoM=tm;
        Estado=e;
    }
    ///METODOS

    void Cargar (){
    cout << "CARGA DE INTERPRETE";
    cout << endl << "-----------------------" << endl;
    cout << "ID del interprete: " << IDI << endl;
    cout << "Ingrese el nombre del interprete: ";
    cargarCadena(Nombre, 40);
    cout << "Ingrese su nacionalidad: ";
    cargarCadena(Nacionalidad, 20);
    cout << "Ingrese el tipo de interprete: ";
    cin >> TipoI;
    cout << "Ingrese el tipo de musica: ";
    cin >> TipoM;
    Estado=true;
    }

    void Mostrar (){
    cout << "----------------" << endl;
    cout << "ID del interprete: " << IDI << endl;
    cout << "Nombre del interprete: " << Nombre << endl;
    cout << "Nacionalidad: " << Nacionalidad << endl;
    cout << "Tipo de interprete: " << TipoI << endl;
    cout << "Tipo de musica: " << TipoM << endl;
    }

    ///METODOS DE ARCHIVOS
    bool grabarEnDisco(){
    FILE *q;
    bool grabo;
    q=fopen ("interpretes.dat", "ab");
    if (q==NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
        return false;
    }
    grabo=fwrite (this, sizeof (Interpretes), 1, q);
    fclose (q);
    return grabo;
    }

    bool leerEnDisco(int pos){
    FILE *q;
    bool leyo;
    q=fopen ("interpretes.dat", "rb");
    if (q==NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
        return false;
    }
    fseek(q, sizeof (Interpretes)*pos, 0);
    leyo=fread (this, sizeof (Interpretes), 1, q);
    fclose (q);
    return leyo;
    }

    bool modificarEnDisco(int pos){
        FILE *q;
        q=fopen ("interpretes.dat", "rb+");
        if (q==NULL) {
            return false;
        }
        fseek(q, sizeof(Interpretes)*pos,0);
        fwrite (this, sizeof (Interpretes), 1, q);
        fclose(q);
        return true;
    }

    ///GETS
    int getIDI(){return IDI;}
    const char* getNombre(){return Nombre;}
    const char* getNacionalidad(){return Nacionalidad;}
    int getTipoI(){return TipoI;}
    int getTipoM(){return TipoM;}
    bool getEstado(){return Estado;}
    ///SETS
    void setIDI (int ii){IDI=ii;}
    void setNombre(const char* no){strcpy (Nombre, no);}
    void setNacionalidad(const char* na){strcpy (Nacionalidad, na);}
    void setTipoI(int ti){TipoI=ti;}
    void setTipoM(int tm){TipoM=tm;}
    void setEstado (bool e){Estado=e;}
};

#endif // CLASS_INTERPRETES_H_INCLUDED
