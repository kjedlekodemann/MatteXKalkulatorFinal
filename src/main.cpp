#include <vector>
#include <iostream>
#include <string>
#include "primtall.hpp"
#include "euklid.hpp"
#include "diofantiskLigningUrgh.hpp"
#include "kongruens.hpp"
#include "misc.hpp"
using namespace std;

int main() {
    char valg;
    cout << "Velg din modus!" << endl << endl << "Primtallssjekk: (P)" << endl << "Primtallsfaktorisering: (F)" << endl << "Euklid Algoritmen: (E)" << endl << "Omvendt Euklid Algoritmen: (O)" << endl << "Diofantisk Ligning: (D)" << endl << "Kongruenssjekk: (K)";
    cin >> valg;
    if (std::cin.fail() || (valg!=toupper('p')&&valg!=toupper('F')&&valg!=toupper('E')&&valg!=toupper('O')&&valg!=toupper('D'))) {
        throw std::runtime_error("Input Fail");
    } else if (valg==toupper('p')) {
        clearTerminal();
        int a;
        cout << endl << "Skriv inn ett tall: " << endl;
        cin >> a;
        if (sjekkPrim(a)) {
            cout << "Ja, " << a << " er et primtall.";
            return 0;
        } else {
            cout << "Nei, " << a << " er ikke ett primtall.";
            return 0;
        }
    } else if (valg==toupper('f')) {
        clearTerminal();
        int a;
        cout << endl << "Skriv inn ett tall: " << endl;
        cin >> a;
        cout << endl << a;
        printVector(primtallsFaktorisering(a));
        return 0;
    } else if (valg==toupper('e')) {
        clearTerminal();
        int a, b;
        cout << endl << "Skriv inn to tall, delt med mellomrom: " << endl;
        cin >> a,b;
        cout << "SFD av " << a << " og " << b << " = " << euklid(a,b);
        return 0;
    } else if (valg==toupper('o')) {
        clearTerminal();
        int a, b;
        cout << endl << "Skriv inn to tall, delt med mellomrom: " << endl;
        cin >> a,b;
        //gjør imårå
    } else if (valg==toupper('d')) {
        clearTerminal();
        int a, b,c;
        cout << endl << "Skriv inn x, y og resultatet, delt med mellomrom: " << endl;
        cin >> a,b,c;
        //gjør imårå
        return 0;
    } else if (valg==toupper('k')) {
        clearTerminal();
        int a,b,c;
        cout << endl << "Skriv inn to tall og modulo, delt med mellomrom: " << endl;
        cin >> a,b,c;
        if (sjekkKongruens(a,b,c)) {
            cout << "Ja, " << a << " er kongruent med " << b << "(mod " << c << ')';
        } else {
            cout << "Nei, " << a << " er  ikke kongruent med " << b << "(mod " << c << ')';
        }
        return 0;
    }
}