#include <vector>
#include <iostream>
#include <windows.h>
#include <string>
#include "primtall.hpp"
#include "euklid.hpp"
#include "diofantiskLigningUrgh.hpp"
#include "kongruens.hpp"
#include "misc.hpp"
#include "geometriskSted.hpp" //includes :DDDD
using namespace std; //gjør at me ikke må skrive "std::" før funksjoner i std lib  

int hoved() {
    char valg; //bruker en bokstav som valget ditt
    cout << "Velg din modus!" 
    << endl << endl << 
    "Primtallssjekk: (P)" << endl << 
    "Primtallsfaktorisering: (F)" << endl << 
    "Euklid Algoritmen: (E)" << endl << 
    "Omvendt Euklid Algoritmen: (O)" << endl << 
    "Diofantisk Ligning: (D)" << endl << 
    "Kongruenssjekk: (K)" << endl << 
    "Kongruens: (S)" << endl <<
    "Geometrisk Stedssjekk: (G)" << endl << endl; //LAAAAAAAAAANG print
    cin >> valg; //input
    valg = toupper(valg); //valg uppercase 
    if (std::cin.fail() || (valg!=toupper('k')
    &&valg!=toupper('s')&&valg!=toupper('p')
    &&valg!=toupper('f')&&valg!=toupper('e')
    &&valg!=toupper('o')&&valg!=toupper('d')&&
    valg!=toupper('g'))) { //stor if statement, sjekker om ingenting er ødelagt (feil med input statement)
        BlueScreen(); //error hvis det er tilfellet
    } else if (valg==toupper('p')) { //hvis valgt P (etc)
        clearTerminal(); //gjør bare terminalen tom tom sahur
        int a; //definerer variabel som brukes
        cout << endl << "Skriv inn ett tall: " << endl;
        cin >> a; //input
        if (sjekkPrim(a)) {
            cout << "Ja, " << a << " er et primtall." << endl;
            return 0;
        } else {
            cout << "Nei, " << a << " er ikke ett primtall." << endl;
            return 0;
        } //basic logikk
    } else if (valg==toupper('f')) { //det meste fra if toupper(p) gjenbrukes
        clearTerminal();
        int a;
        cout << endl << "Skriv inn ett tall: " << endl;
        cin >> a;
        cout << endl << a << " = ";
        printVector(primtallsFaktorisering(a));
        return 0;
    } else if (valg==toupper('e')) {
        clearTerminal();
        int a, b;
        cout << endl << "Skriv inn ett tall: " << endl;
        cin >> a;
        cout << endl << "Skriv inn ett annet tall: " << endl;
        cin >> b;
        if (a>b) {
            cout << "SFD av " << a << " og " << b << " = " << euklid(a,b) << endl;
        } else {
            cout << "SFD av " << b << " og " << a << " = " << euklid(b,a) << endl;
        }
        return 0;
    } else if (valg==toupper('o')) {
        clearTerminal();
        int a, b;
        cout << endl << "Skriv inn det første tallet: " << endl;
        cin >> a;
        cout << endl << "Skriv inn det andre tallet: " << endl;
        cin >> b;
        omvEuklid res = omvendtEuklid(a,b);
        cout << endl << res.x << "*" << a;
        if (res.y<0) {
            cout << " - " << -res.y << " * " << b << " = " << res.gcd << endl;
        } else {
            cout << " + " << res.y << " * " << b << " = " << res.gcd << endl;
        }
    } else if (valg==toupper('d')) {
        clearTerminal();
        int a, b, c;
        cout << endl << "Skriv inn x: " << endl;
        cin >> a;
        cout << endl << "Skriv inn y: " << endl;
        cin >> b;
        cout << endl << "Skriv inn resultater: " << endl;
        cin >> c;
        Linje l = diofantiskLinje(a,b,c);
        if (l.dx<0) {
        cout << endl << "x = " << l.x0 << " - " << -l.dx << "k" << endl;
        } else {
        cout << endl << "x = " << l.x0 << " + " << l.dx << "k" << endl;
        }
        if (l.dy<0) {
        cout << endl << "y = " << l.y0 << " - " << -l.dy << "k" << endl;
        } else {
        cout << endl << "y = " << l.y0 << " + " << l.dy << "k" << endl;
        }
        return 0;
    } else if (valg==toupper('k')) {
        clearTerminal();
        long long a,b,c;
        cout << endl << "Skriv inn det første tallet: " << endl;
        cin >> a;
        cout << endl << "Skriv inn det andre tallet: " << endl;
        cin >> b;
        cout << endl << "Skriv inn modulo: " << endl;
        cin >> c;
        if (sjekkKongruens(a,b,c)) {
            cout << "Ja, " << a << " er kongruent med " << b << "(mod " << c << ')' << endl;
        } else {
            cout << "Nei, " << a << " er  ikke kongruent med " << b << "(mod " << c << ')' << endl;
        }
        return 0;
    } else if (valg==toupper('s')) {
        clearTerminal();
        int a,mod;
        cout << endl << "Skriv inn tallet: " << endl;
        cin >> a;
        cout << endl << "Skriv inn modulo: " << endl;
        cin >> mod;
        int r = kongruens(a,mod);
        cout << a << " ≡ " << r << " (mod " << mod << ')' << endl;
    } else if (valg==toupper('g')) {
        clearTerminal();
        short type;
        cout << "Vil du sjekke en sirkel (1), midtnormal (2) eller Linje (3)?" << endl;
        cin >> type;
        clearTerminal();
        Pungt a,b,p,m;
        double ax,ay,bx,by,px,py,mx,my,r;
        
        switch (type) {
            case 1:
                cout << "M(x)? (midten)" << endl; 
                cin >> mx;
                cout << "M(y)? (midten)" << endl; 
                cin >> my;
                cout << "P(x)?" << endl; 
                cin >> px;
                cout << "P(y)?" << endl; 
                cin >> py;
                cout << "Radius?" << endl;
                cin >> r; 
                clearTerminal();
                m = {mx,my};
                p = {px,py};
                if (erPaaSirkel(p,m,r)) {
                    cout << "Ja, Punktet P(" << px << ", " << py << ") er i det geometriske stedet for Punktet M(" << mx << ", " << my << ") med radiusen " << r << endl;
                    return 0;
                } else {
                    cout << "Nei, Punktet P(" << px << ", " << py << ") er ikke i det geometriske stedet for Punktet M(" << mx << ", " << my << ") med radiusen " << r << endl;
                    return 0;
                }
            case 2:
                cout << "A(x)?" << endl; 
                cin >> ax;
                cout << "A(y)?" << endl; 
                cin >> ay;
                cout << "B(x)?" << endl; 
                cin >> bx;
                cout << "B(y)?" << endl; 
                cin >> by;
                cout << "P(x)?" << endl; 
                cin >> px;
                cout << "P(y)?" << endl; 
                cin >> py;
                clearTerminal();
                a = {ax,ay};
                b = {bx,by};
                p = {px,py};
                if (erPaaMidtnormal(p,a,b)) {
                    cout << "Ja, Punktet P(" << px << ", " << py << ") er i det geometriske stedet mellom A(" << ax << ", " << ay << ") og B(" << bx << ", " << by << ")." << endl;
                    return 0;
                } else {
                    cout << "Nei, Punktet P(" << px << ", " << py << ") er ikke det geometriske stedet mellom A(" << ax << ", " << ay << ") og B(" << bx << ", " << by << ")." << endl;
                    return 0;
                }
            case 3:
                cout << "A(x)?" << endl; 
                cin >> ax;
                cout << "A(y)?" << endl; 
                cin >> ay;
                cout << "B(x)?" << endl; 
                cin >> bx;
                cout << "B(y)?" << endl; 
                cin >> by;
                cout << "P(x)?" << endl; 
                cin >> px;
                cout << "P(y)?" << endl; 
                cin >> py;
                clearTerminal();
                a = {ax,ay};
                b = {bx,by};
                p = {px,py};
                if (erPaaLinje(a,b,p)) {
                    cout << "Ja, Punktet P(" << px << ", " << py << ") er i det geometriske stedet mellom A(" << ax << ", " << ay << ") og B(" << bx << ", " << by << ")." << endl;
                    return 0;
                } else {
                    cout << "Nei, Punktet P(" << px << ", " << py << ") er ikke det geometriske stedet mellom A(" << ax << ", " << ay << ") og B(" << bx << ", " << by << ")." << endl;
                    return 0;
                }
            default:
                BlueScreen();
        }
    }
    return 1;
}

int main() { //brukt main for testing
    char fortsett;
    hoved();
    cout << "Vil du fortsette? (y/n)" << endl;
    cin >> fortsett;
    while (fortsett='y') {
        if (hoved()) {
            BlueScreen();
        }
    } //return 1 hvis error 0 ellers. (kjører også hovedfunksjonen)
    return 0;
}




