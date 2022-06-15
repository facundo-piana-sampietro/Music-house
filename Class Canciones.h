#ifndef CLASS_CANCIONES_H_INCLUDED
#define CLASS_CANCIONES_H_INCLUDED

class Fecha {
  private:
    int dia, mes, anio;
  public:
    Fecha (int d=00, int m=00, int a=0000){
        dia=d;
        mes=m;
        anio=a;
    }
    void Cargar() {
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
    }
    void Mostrar() {
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

    ///GETS

    int getAnio() {return anio;}
    int getMes() {return mes;}
    int getDia() {return dia;}
    ///SETS

    void setAnio (int a){anio=a;}
    void setMes (int m){mes=m;}
    void setDia (int d){dia=d;}

};

class Canciones{
protected:
    ///PROPIEDADES
    int IDC;
    char Ncancion[30];
    char Nautor[30];
    int IDI;
    Fecha fecha;
    bool Estado;

public:
    ///CONSTRUCTOR
    Canciones (int idc=0, const char *nc="----",const char *na="----",int idi=0,bool e=true){
        IDC=idc;
        strcpy (Ncancion, nc);
        strcpy (Nautor, na);
        IDI=idi;
        Estado=e;
    }
    ///METODOS
    void Cargar (){
    cout << "CARGA DE CANCION";
    cout << endl << "----------------" << endl;
    cout << "ID de la cancion: " << IDC << endl;
    cout << "Ingrese el nombre de la cancion: ";
    cargarCadena(Ncancion, 30);
    cout << "Ingrese el nombre del autor: ";
    cargarCadena(Nautor, 30);
    cout << "Ingrese el ID del interprete: ";
    cin >> IDI;
    cout << "Fecha de estreno" << endl;
    fecha.Cargar();
    Estado=true;
    }

    void Mostrar (){
    cout << "------------------" << endl;
    cout << "ID de la cancion: " << IDC << endl;
    cout << "Nombre de la cancion: " << Ncancion << endl;
    cout << "Nombre del autor: " << Nautor << endl;
    cout << "ID del interprete: " << IDI << endl;
    cout << "Fecha de estreno" << endl;

    fecha.Mostrar();
    }

    ///METODOS DE ARCHIVOS
    bool grabarEnDisco(){
    FILE *p;
    bool grabo;
    p=fopen ("canciones.dat", "ab");
    if (p==NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
        return false;
    }
    grabo=fwrite (this, sizeof (Canciones), 1, p);
    fclose (p);
    return grabo;
    }

    bool leerEnDisco(int pos){
    FILE *p;
    bool leyo;
    p=fopen ("canciones.dat", "rb");
    if (p==NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO :(" << endl;
        return false;
    }
    fseek(p, sizeof (Canciones)*pos, 0);
    leyo=fread (this, sizeof (Canciones), 1, p);
    fclose (p);
    return leyo;
    }

    bool modificarEnDisco(int pos){
        FILE *p;
        p=fopen ("canciones.dat", "rb+");
        if (p==NULL) {
            return false;
        }
        fseek(p, sizeof(Canciones)*pos,0);
        fwrite (this, sizeof (Canciones), 1, p);
        fclose(p);
        return true;
    }

    ///GETS
    int getIDC(){return IDC;}
    int getIDI(){return IDI;}
    const char* getNcancion(){return Ncancion;}
    const char* getNautor(){return Nautor;}
    Fecha getFecha(){return fecha;}
    bool getEstado(){return Estado;}
    ///SETS
    void setIDC (int i){IDC=i;}
    void setIDI (int ii){IDI=ii;}
    void setNcancion(const char* nc){strcpy (Ncancion, nc);}
    void setNautor(const char* na){strcpy (Nautor, na);}
    void setFecha (Fecha f){fecha=f;}
    void setEstado (bool e){Estado=e;}
};



#endif // CLASS_CANCIONES_H_INCLUDED
