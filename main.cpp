#include "Tombola.h"

char SceltaMain;
int main() {

    do {
        cout << "╔═════════════════════════════════╗" << endl;
        cout << "  ---  LA SMORFIA NAPOLETANA  ---    " << endl;
        cout << "╠═════════════════════════════════╣" << endl;
        cout << " G) Gioca alla Smorfia            " << endl;
        cout << " L) Linee Guida               " << endl;
        cout << " U) Esci                      " << endl;
        cout << "╚═════════════════════════════════╝" << endl;

        cout << "╔═══════════════════════════════╗" << endl;
        cout << "Inserire la Propria Scelta: ";
        cin >> SceltaMain;
        cout << "╚═══════════════════════════════╝" << endl;

        switch (toupper(SceltaMain)) {
            case 'G':
                CreaCartella();
                break;
            case 'L':
                LineeGuida();
                break;
            case 'U':
                Uscire();
                break;

            default:
                cerr << "Errore, Valore Sconosciuto (Error 0x36F): ";
                cout << "Vuoi Uscire dal Programma? [y/n]: ";
                do {
                    cin >> SceltaMain;
                    toupper(SceltaMain);
                    if (SceltaMain == toupper('y')) {
                        Uscire();
                    } else if (SceltaMain == toupper('n')) {
                        main();
                    }
                } while ((SceltaMain != toupper('y')) || (SceltaMain != toupper('n')));
        }
    } while (SceltaMain != toupper('u'));
}
