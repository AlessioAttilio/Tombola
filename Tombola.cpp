#include "Tombola.h"

namespace Variabili {
    char SceltaProgramma;
    unsigned int NumeriTabella = 1;
    const unsigned int PrezzoCartella = 10, CartelleRichieste = 1;
    int Soldi = 0, CostoCartelle = 0, Controllo = 0, NumeriEstratti = 0;
    bool ControlloAmbo = false, ControlloTerno = false, ControlloQuaterna = false, ControlloQuintina = false, ControlloTombola = false, Pagato = false;

    string Simbologia[90] = {
            "L'ITALIA", "LA GATTA", "LA BAMBINA", "IL MAIALE", "LA MANO", "IL PULPITO FEMMINILE", "IL VASO",
            "LA MADONNA", "LA FIGLIATA", "I FAGIOLI", "I RATTI", "I SOLDATI ", "SANT'ANTONIO", "L'UBRIACO",
            "IL RAGAZZO", "LA FORTUNA",
            "LA DISGRAZIA", "IL SANGUE", "LA RISATA", "LA FESTA", "LA DONNA NUDA",
            "IL PAZZO", "LO SCEMO", "LE GUARDIE", "NATALE", "ANNA - MADRE DELLA VERGINE", "IL VASO DA NOTTE", "IL SENO",
            "IL PADRE DEI BAMBINI", "LE PALLE DEL TENENTE", "IL PADRONE DI CASA",
            "IL CAPITONE", "GLI ANNI DI CRISTO", "LA TESTA", "L'UCCELLINO", "LE CASTAGNETTE", "IL MONACO", "LE MAZZATE",
            "LA CORDA AL COLLO",
            "L'ERNIA", "IL COLTELLO", "IL CAFFE' ",
            "LA DONNA PETTEGOLA AFFACCIATA AL BALCONE", "LE CARCERI", "IL VINO BUONO", "IL DENARO", "IL MORTO",
            "IL MORTO CHE PARLA", "IL PEZZO DI CARNE",
            "IL PANE", "IL GIARDINO",
            "LA MAMMA", "IL VECCHIO", "IL CAPPELLO", "LA MUSICA", "LA CADUTA", "IL GOBBO", "IL PACCO", "I PELI",
            "IL LAMENTO", "IL CACCIATORE",
            "IL MORTO ASSASSINATO", "LA SPOSA", "LA GIACCA", "IL PIANTO", "LE DUE ZITELLE", "IL TOTANO NELLA CHITERRA",
            "LA ZUPPA COTTA", "IL SOTTOSOPRA", "IL PALAZZO", "L'UOMO DI MERDA", "LA MERAVIGLIA", "L'OSPEDALE",
            "LA GROTTA",
            "PULCINELLA", "LA FONTANA", "I DIAVOLETTI", "LA PROSTITUTA", "IL LADRO", "LA BOCCA", "I FIORI",
            "LA TAVOLA IMBANDITA",
            "IL MALTEMPO", "LA CHIESA", "LE ANIME DEL PURGATORIO", "LA BOTTEGA", "I PIDOCCHI", "I CACIOCAVALLI",
            "LA VECCHIA", "LA PAURA"
    };


    struct Cartella {
        unsigned int Numeri{};
        bool Marcato = false;
    };

    const unsigned int Righe = 9, Colonne = 10;

    const unsigned int RigheSingolaCartella = 3, ColonneSingolaCartella = 5;
    Cartella CartellaSingola[ColonneSingolaCartella][RigheSingolaCartella];

    const unsigned int RigheDoppiaCartella = 6, ColonneDoppiaCartella = 10;
    Cartella CartellaDoppia[ColonneDoppiaCartella][RigheDoppiaCartella];

    const unsigned int RigheTriplaCartella = 9, ColonneTriplaCartella = 15;
    Cartella CartellaTripla[ColonneTriplaCartella][RigheTriplaCartella];

    int Numeri[ColonneSingolaCartella * RigheSingolaCartella];
    bool NumeriCartellone[90];
    bool NumeriGenerati[90];
}

using namespace Variabili;

void LineeGuida() {
    do {
        cout << "╔═════════════════════════════════╗" << endl;
        cout << "  ---  LA SMORFIA NAPOLETANA  ---    " << endl;
        cout << "╠═════════════════════════════════╣" << endl;
        cout << " C) Crediti            " << endl;
        cout << " I) Istruzioni Gioco       " << endl;
        cout << " U) Esci                      " << endl;
        cout << "╚═════════════════════════════════╝" << endl;

        cout << "╔═══════════════════════════════╗" << endl;
        cout << "Inserire la Propria Scelta: ";
        cin >> SceltaProgramma;
        cout << "╚═══════════════════════════════╝" << endl;

        switch (toupper(SceltaProgramma)) {
            case 'C':
                Crediti();
                break;
            case 'I':
                IstruzioniGioco();
                break;
            case 'E':
                Uscire();
                break;
        }
    } while ((SceltaProgramma == toupper('c')) || (SceltaProgramma == toupper('l')) || (SceltaProgramma == toupper('u')));
}

void Crediti() {
    cout << "╔═════════════════════════════════╗" << endl;
    cout << "  ---  LA SMORFIA NAPOLETANA  ---    " << endl;
    cout << "╠═════════════════════════════════╣" << endl;
    cout << "       Progetto Eseguito da: " << endl;
    cout << " ALESSIO ATTILIO (GESTORE PROGETTO)" << endl;
    cout << " SAMUELE CAPUANO" << endl;
    cout << " FRANCESCO PICARDI" << endl;
    cout << "╚═════════════════════════════════╝" << endl ;
}

void IstruzioniGioco() {
    cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "                                                        ---  LA SMORFIA NAPOLETANA  ---    " << endl;
    cout << "╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣" << endl;
    cout << "    Come si Gioca alla Smorfia? " << endl;
    cout << "Il Gioco Della Tombola Necessita Di Un Tabellone Grande Su Cui Sono Riportati I Numeri Da 1 A 90. " << endl;
    cout << "Ci Sono Poi Le Cartelle Sono Mini Riproduzioni Del Tabellone Principale (Hanno Stampati 15 Numeri Per Ogni Scheda). " << endl;
    cout << "I Numeri Verranno Estratti Dal Bussolotto E Nessuno Dei Partecipanti, Nemmeno Chi Toccherà Estrarre Numeri, Saprà Il Numero Prima Che Uscisse Dal Bussolotto. " << endl;
    cout << "I Giocatori, Dopo Aver Acquistato Le Cartelle, Le Dispongono Davanti A Sé E Oscurano Il Numero Che Verrà Estratto Dal Bussolotto Con L'apposita Casellina. " << endl;
    cout << "Quando Tutte Le Caselline Con I Numeri Vengono Oscurate Il Giocatore Ha Fatto \"Tombola\" E Acquista Il Premio Finale." << endl;
    cout << " Oltre Alla Tombola È Possibile Anche Decidere Dei Premi Minori Che Si Acquisiscono Facendo ControlloAmbo (Due Numeri Sulla Stessa Riga) "
            "Terno (Tre Numeri Sulla Stessa Riga) Quaterna (Quattro Numeri Sulla Stessa Riga) E Cinquina (Cinque Numeri Sulla Stessa Riga)." << endl;
    cout << "╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl ;
}

void Uscire() {
    cout << "╔═══════════════════════════════════╗" << endl;
    cout << "Arrivederci e Grazie per Aver Giocato" << endl;
    cout << "╚═══════════════════════════════════╝" << endl;

    sleep(2);
    exit(0);
}

void CreaCartella() {
    CostoCartelle = PrezzoCartella * CartelleRichieste;

    cout << "╔═════════════════════════════════╗" << endl;
    cout << "  ---  LA SMORFIA NAPOLETANA  ---    " << endl;
    cout << "    ---  Scontrino Fiscale  ---    " << endl;
    cout << "╠═════════════════════════════════╣" << endl;
    cout << " Il Totale delle Cartelle e' €: " << CostoCartelle << endl;
    cout << "╚══════════════════════════════════╝" << endl;

    do {
        cout << "╔════════════════════════════════════════════╗" << endl;
        cout << "Versare €: " << CostoCartelle << ": ";
        cin >> Soldi;
        cout << "╚════════════════════════════════════════════╝" << endl;

        if (CostoCartelle == Soldi) {
            Pagato = true;
            cout << "Buon Divertimento." << endl;
            cout << "Attendere Prego.." << endl << endl;
        } else if (CostoCartelle > Soldi) {
            CostoCartelle = CostoCartelle - Soldi;
            abs(CostoCartelle);
        } else {
            Pagato = true;
            Soldi = Soldi - CostoCartelle;

            cout << "╔════════════════════════════════════════════╗" << endl;
            cout << "Il suo Resto: " << CostoCartelle << endl;
            cout << "╚════════════════════════════════════════════╝" << endl;
        }
    } while (!Pagato);
    IniziaGioco();
}

void IniziaGioco() {
    Reset();
    GeneraCartellaSingola();
    GiocaSingolaCartella();
}

void GiocaSingolaCartella() {
    bool Ambo = false;
    bool Terna = false;
    bool Quaterna = false;
    bool Cinquina = false;
    bool Tombola = false;
    bool ControlloUscito;

    VisualizzazioneSingola();

    while (!Tombola) {
        ControlloUscito = false;
        int NumeroEstratto;
        while (!ControlloUscito) {
            NumeroEstratto = GeneraNumero();
            ControlloUscito = ControlloNumeroUscito(NumeroEstratto);
        }
        cout << "\n Il Numero Estratto e': " << NumeroEstratto << ": " << Simbologia[NumeroEstratto-1]  << endl << endl;
        MarcaCartellaSingola(NumeroEstratto);
        VisualizzazioneSingola();
        sleep(1);

        if (!Ambo) {
            bool AmboEseguito = ControlloAmboCartellaSingola();
            if (AmboEseguito) {
                Ambo = true;
                cout << "╔════════════════════════════════════════════╗" << endl;
                cout << " Complimenti, hai Fatto Ambo! " << endl;
                cout << "Hai Vinto " << PrezzoCartella/8;
                sleep(1);
                cout << "╚════════════════════════════════════════════╝" << endl;

                sleep(1);
            }
        }

        if (!Terna) {
            bool TernaEseguito = ControlloTernaCartellaSingola();
            if (TernaEseguito) {
                Terna = true;
                cout << "╔════════════════════════════════════════════╗" << endl;
                cout << " Complimenti, hai Fatto Terna! " << endl;
                cout << "Hai Vinto " << PrezzoCartella/6;
                sleep(1);
                cout << "╚════════════════════════════════════════════╝" << endl;

                sleep(1);
            }
        }

        if (!Quaterna) {
            bool QuaternaEseguito = ControlloQuaternaCartellaSingola();
            if (QuaternaEseguito) {
                Quaterna = true;
                cout << "╔════════════════════════════════════════════╗" << endl;
                cout << " Complimenti, hai Fatto Quaterna! " << endl;
                cout << "Hai Vinto " << PrezzoCartella / 4;
                sleep(1);
                cout << "╚════════════════════════════════════════════╝" << endl;

                sleep(1);
            }
        }

        if (!Cinquina) {
            bool CinquinaEseguito = ControlloCinquinaCartellaSingola();
            if (CinquinaEseguito) {
                Cinquina = true;
                cout << "╔════════════════════════════════════════════╗" << endl;
                cout << " Complimenti, hai Fatto Cinquina! " << endl;
                cout << "Hai Vinto " << PrezzoCartella / 3;
                sleep(1);
                cout << "╚════════════════════════════════════════════╝" << endl;
            }
        }

        if (!Tombola) {
            bool TombolaEseguito = ControlloTombolaCartellaSingola();
            if (TombolaEseguito) {
                Tombola = true;
                cout << "╔════════════════════════════════════════════╗" << endl;
                cout << " Complimenti, hai Vinto! " << endl ;
                cout << "Hai Vinto " << PrezzoCartella / 2;
                sleep(1);
                cout << "╚════════════════════════════════════════════╝" << endl;

            }
        }
    }
}

void VisualizzazioneSingola() {
    cout << "╔═══════════════════════════════════════════════════════════════════════════════╗" << endl;
    for (int i = 0; i < RigheSingolaCartella; ++i) {
        cout << "║\t\t";
        for (int j = 0; j < ColonneSingolaCartella; ++j) {
            cout << CartellaSingola[j][i].Numeri;

            if (CartellaSingola[j][i].Marcato) {
                cout << "*";
            }
            cout << "\t\t║\t\t";
        }
        cout << endl << endl;
    }
    cout << "╚═══════════════════════════════════════════════════════════════════════════════╝" << endl;
}

int GeneraNumero() {
    srand(time(NULL));
    return 1 + rand() % 90;
}

void InizializzaNumeriGenerati() {
    for (int i = 0; i < 90; i++) {
        NumeriGenerati[i] = false;
    }
}

bool ControlloNumeriDoppi(int Numero) {
    if (!NumeriGenerati[Numero]) {
        NumeriGenerati[Numero] = true;
        return true;
    } else {
        return false;
    }
}

bool ControlloNumeroUscito(int Numero) {
    if (NumeriCartellone[Numero] == false) {
        NumeriCartellone[Numero] = true;
        return true;
    } else {
        return false;
    }
}

void MarcaCartellaSingola(int Numero) {
    for (int i = 0; i < ColonneSingolaCartella; i++) {
        for (int j = 0; j < RigheSingolaCartella; j++) {
            if (CartellaSingola[i][j].Numeri == Numero) {
                CartellaSingola[i][j].Marcato = true;
                return;
            }
        }
    }
}

bool ControlloAmboCartellaSingola() {
    int NumeriAmbo = 2;
    int contaNumeriAmbo = 0;

    for (int i = 0; i < RigheSingolaCartella; i++) {
        for (int j = 0; j < ColonneSingolaCartella; j++) {
            if (CartellaSingola[j][i].Marcato) {
                contaNumeriAmbo++;
            }
        }
        if (contaNumeriAmbo == NumeriAmbo) {
            return true;
        } else {
            contaNumeriAmbo = 0;
        }
    }
    return false;
}

bool ControlloTernaCartellaSingola() {
    int NumeriTerno = 3;
    int contaNumeriTerno = 0;

    for (int i = 0; i < RigheSingolaCartella; i++) {
        for (int j = 0; j < ColonneSingolaCartella; j++) {
            if (CartellaSingola[j][i].Marcato) {
                contaNumeriTerno++;
            }
        }
        if (contaNumeriTerno == NumeriTerno) {
            return true;
        } else {
            contaNumeriTerno = 0;
        }
    }
    return false;
}

bool ControlloQuaternaCartellaSingola() {
    int NumeriQuaterna = 4;
    int contaNumeriQuaterna = 0;

    for (int i = 0; i < RigheSingolaCartella; i++) {
        for (int j = 0; j < ColonneSingolaCartella; j++) {
            if (CartellaSingola[j][i].Marcato) {
                contaNumeriQuaterna++;
            }
        }
        if (contaNumeriQuaterna == NumeriQuaterna) {
            return true;
        } else {
            contaNumeriQuaterna = 0;
        }
    }
    return false;
}

bool ControlloCinquinaCartellaSingola() {
    int NumeriCinquina = 5;
    int contaNumeriCinquina = 0;

    for (int i = 0; i < RigheSingolaCartella; i++) {
        for (int j = 0; j < ColonneSingolaCartella; j++) {
            if (CartellaSingola[j][i].Marcato) {
                contaNumeriCinquina++;
            }
        }
        if (contaNumeriCinquina == NumeriCinquina) {
            return true;
        } else {
            contaNumeriCinquina = 0;
        }
    }
    return false;
}

bool ControlloTombolaCartellaSingola() {
    for (int i = 0; i < RigheSingolaCartella; i++) {
        for (int j = 0; j < ColonneSingolaCartella; j++) {
            if (!CartellaSingola[j][i].Marcato) {
                return false;
            }
        }
    }
    return true;
}


void Reset() {
    InizializzaCartellaSingola();
}

void InizializzaCartellaSingola() {
    for (int i = 0; i < RigheSingolaCartella; i++) {
        for (int j = 0; j < ColonneSingolaCartella; j++) {
            CartellaSingola[j][i].Numeri = 0;
            CartellaSingola[j][i].Marcato = false;
        }
    }
}

void GeneraCartellaSingola() {
    srand(time(NULL));
    bool Uscito = false;

    for (int i = 0; i < RigheSingolaCartella; i++) {
        for (int j = 0; j < ColonneSingolaCartella; j++) {
            while (!Uscito) {
                int NumeroGenerato = 1 + rand() % 90;
                Uscito = ControlloNumeriDoppi(NumeroGenerato);
                if (Uscito) {
                    CartellaSingola[j][i].Numeri = NumeroGenerato;
                }
                sleep(1);
            }
            Uscito = false;
        }
    }
}
