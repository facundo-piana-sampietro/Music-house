#ifndef ESTETICA_H_INCLUDED
#define ESTETICA_H_INCLUDED

///PROTOTIPOS
void pin(int,int);
void sin(int);
void caudro (int,int,int,int);
void cambiarcolor(int);
void charmander();

///DESARROLLO
void cuadro (int x1,int x2,int y1,int y2) {

    int x=y1, j=y1;
    rlutil::locate(x1, y1);

    cout << (char)201;

    for (int i=0; i<x2-x1-1; i++) {

        cout << (char)205;

    }



    rlutil::locate(x2, y1);
    cout << (char)187;


    for (int i=0; i<y2-y1-1; i++) {
        x++;
        rlutil::locate(x2, x);
        cout << (char)186 << endl;
    }


    cout << endl;

    for (int i=0; i<y2-y1-1; i++) {
        j++;
        rlutil::locate(x1, j);

        cout << (char)186 << endl;
    }


    rlutil::locate(x1, y2);
    cout << (char)200;



    for (int i=0; i<x2-x1-1; i++) {

        cout << (char)205;


    }

    rlutil::locate (x2, y2);
    cout << (char)188;
}
void cambiarcolor(int X) {
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}


void pin(int x,int c) {
    cambiarcolor (c);
    int i;
    for(i=1; i<=x; i++) {
        cout<<char(219)<<char(219);
    }
}
void sin(int o) {

    int j;
    for(j=1; j<=o; j++) {
        cout<<char(255)<<char(255);
    }
}

void charmander(){
 int n=240,r=244,a=252,am=254, v=2;
            rlutil::setBackgroundColor(rlutil::BROWN);
            cout<<"\n";

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(4);
            pin(4,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(9);
            pin(1,n);


            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(3);
            pin(1,n);
            pin(1,r);
            pin(2,a);
            pin(1,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(7);
            pin(1,n);
            pin(1,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(2);
            pin(1,n);
            pin(1,r);
            pin(4,a);
            pin(1,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(6);
            pin(1,n);
            pin(2,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(2);
            pin(1,n);
            pin(6,a);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(6);
            pin(1,n);
            pin(2,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(1);
            pin(1,n);
            pin(7,a);
            pin(1,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(4);
            pin(1,n);
            pin(1,r);
            pin(1,am);
            pin(2,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            pin(1,n);
            pin(4,a);
            sin(1);
            pin(1,n);
            pin(2,a);
            pin(1,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(4);
            pin(1,n);
            pin(1,r);
            pin(2,am);
            pin(1,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            pin(1,n);
            pin(4,a);
            pin(2,n);
            pin(1,a);
            pin(3,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(3);
            pin(1,n);
            pin(1,r);
            pin(1,am);
            pin(2,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            pin(1,n);
            pin(4,a);
            pin(2,n);
            pin(1,a);
            pin(3,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(4);
            pin(1,n);
            pin(1,a);
            pin(2,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(1);
            pin(1,n);
            pin(1,r);
            pin(5,a);
            pin(4,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(3);
            pin(1,n);
            pin(1,a);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(2);
            pin(2,n);
            pin(9,r);
            pin(1,n);
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(1);
            pin(1,n);
            pin(2,a);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(4);
            pin(3,n);
            pin(2,r);
            pin(1,n);
            pin(3,r);
            pin(2,n);
            pin(1,r);
            pin(1,a);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(5);
            pin(1,n);
            pin(2,am);
            pin(1,n);
            pin(5,r);
            pin(1,n);
            pin(2,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(5);
            pin(1,n);
            pin(3,am);
            pin(2,n);
            pin(3,r);
            pin(1,n);
            pin(1,r);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(4);
            pin(1,n);

            sin(1);
            pin(1,n);
            pin(3,am);
            pin(4,r);
            pin(2,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(5);
            pin(3,n);

            sin(2);
            pin(3,r);
            pin(2,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(8);
            pin(3,n);
            pin(1,r);
            pin(2,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(9);
            pin(1,n);

            sin(1);
            pin(1,r);

            sin(1);
            pin(1,n);

            cout<<"\n\t";
            rlutil::setBackgroundColor(rlutil::BROWN);
            sin(10);
            pin(3,n);
}


#endif // ESTETICA_H_INCLUDED
