#ifndef NEW_TOMBOLA_H
#define NEW_TOMBOLA_H
#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
#include <ctime>
#include <unistd.h>
using namespace std;

//Procedure:
    void LineeGuida();
    void Uscire();
    void Crediti();
    void IstruzioniGioco();
    void CreaCartella();
    void Reset();
    void IniziaGioco();
    void InizializzaCartellaSingola();
    void GiocaSingolaCartella();
    void GeneraCartellaSingola();
    bool ControlloNumeriDoppi(int Numeri);
    void MarcaCartellaSingola(int Numero);
    void VisualizzazioneSingola();

//Funzioni:
    int GeneraNumero();
    bool ControlloAmboCartellaSingola();
    bool ControlloTernaCartellaSingola();
    bool ControlloQuaternaCartellaSingola();
    bool ControlloCinquinaCartellaSingola();
    bool ControlloTombolaCartellaSingola();
    bool ControlloNumeroUscito(int Numero);
#endif
