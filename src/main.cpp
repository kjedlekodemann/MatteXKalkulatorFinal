#include <vector>
#include <iostream>
#include <string>
#include "primtall.hpp"
#include "euklid.hpp"
#include "diofantiskLigningUrgh.hpp"
#include "kongruens.hpp"
#include "misc.hpp"
#include "geometriskSted.hpp"
using namespace std;

int main() {
    Pungt a = {2,4};
    Pungt b = {4,8};
    cout << "distansen mellom " << a << " og " << b << " er " << a.distanse(b);
    return 0;
}




int hoved() {
    char valg;
    cout << "Velg din modus!" << endl << endl << "Primtallssjekk: (P)" << endl << "Primtallsfaktorisering: (F)" << endl << "Euklid Algoritmen: (E)" << endl << "Omvendt Euklid Algoritmen: (O)" << endl << "Diofantisk Ligning: (D)" << endl << "Kongruenssjekk: (K)" << endl << "Kongruens: (S)" << endl << endl;
    cin >> valg;
    valg = toupper(valg); 
    if (std::cin.fail() || (valg!=toupper('k')&&valg!=toupper('s')&&valg!=toupper('p')&&valg!=toupper('f')&&valg!=toupper('e')&&valg!=toupper('o')&&valg!=toupper('d'))) {
        throw std::runtime_error("Input Fail");
    } else if (valg==toupper('p')) {
        clearTerminal();
        int a;
        cout << endl << "Skriv inn ett tall: " << endl;
        cin >> a;
        if (sjekkPrim(a)) {
            cout << "Ja, " << a << " er et primtall." << endl;
            return 0;
        } else {
            cout << "Nei, " << a << " er ikke ett primtall." << endl;
            return 0;
        }
    } else if (valg==toupper('f')) {
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
        int a,mod;
        cout << endl << "Skriv inn tallet: " << endl;
        cin >> a;
        cout << endl << "Skriv inn modulo: " << endl;
        cin >> mod;
        int r = kongruens(a,mod);
        cout << a << " ≡ " << r << " (mod " << mod << ')' << endl;
    }
}