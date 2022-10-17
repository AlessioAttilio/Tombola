

# La Tombola Napoletana: Realtà e Codice*
## Gli Strumenti
Il gioco della tombola necessita di un **tabellone** grande su cui sono riportati i numeri da 1 a 90 il quale solitamente viene posto disteso sul tavolo o appeso. Ci sono poi le **cartelline** che non sono altro che mini riproduzioni del tabellone principale (hanno stampati 15 numeri per ogni scheda). Sono presenti anche il **sacchetto** con all'interno tutti i **gettoni** con i **numeri da 1 a 90**, il **bussolotto** (opzionale) per mischiare tali numeri e delle pedine da posizionare sul **numero estratto**.

---

## Le Regole del Gioco
Durante il gioco si decide un croupier ovvero colui che avrà il compito di mischiare ed estrarre i numeri dal bussolotto (o dal sacchetto) e barrare la casella del corrispettivo numero sul tabellone grande. I giocatori invece, dopo aver acquistato le cartelle (l'acquisto può essere simbolico o pagato in denaro) le dispongono davanti a sè e oscurano il numero che il croupier estrae con l'apposita casellina. Quando tutte le caselline con i numeri (sempre diversi per ogni cartella) vengono oscurate il giocatore ha fatto "tombola" e acquista il premio finale. Oltre alla tombola è possibile anche decidere dei premi minori che si acquisiscono facendo **ambo** (due numeri sulla stessa riga) **terno** (tre numeri sulla stessa riga) **quaterna** (quattro numeri sulla stessa riga) e **cinquina** (cinque numeri sulla stessa riga).

  ---
  ![Le Cartelle](https://www.compratombolaonline.it/wp-content/uploads/2018/10/T1_15_A_WHITE-1.png)
---  
  # L'Informatica
Diviso in Tre Files: 
> `main.cpp`
> `Tombola.cpp`
> `Tombola.h`

---
 In `main.cpp`, Troviamo il Menù a Scelta del Gioco.
In   `Tombola.cpp`, Troviamo le Funzioni e le Procedure Riferite per Permettere al Programma di Funzionare.
In `Tombola.h`, Troviamo le Definizioni di Tutte le Procedure e Funzioni Utilizzate nel Programma

 ---
# LineeGuida()
 ci consente di visualizzare crediti, istruzioni di gioco e uscita dal programma.
 
 ---
# crediti() 
Ci Permette di visualizzare chi sono i creatori del progetto

---

# istruzioni() 
Ci Permette di Visualizzare le Istruzioni del Gioco

---
# Codice - Introduzione 
Se l’Utente Richiederà di Iniziare il Gioco Verrà Direzionato nella **Procedura** `CreaCartella` Dove Andremo ad Assegnare il Costo della Cartella, per Reindirizzarlo Successivamente al Gioco Vero e Proprio.

---
# IniziaGioca()
Ci Consente di Inizializzare il Gioco, Eseguendo Tre Procedure:

> `Reset()`  
> `GeneraCartellaSingola()`
> `GiocaSingolaCartella()`

---

# Reset()
Chiama la **Procedura** `InizializzaCartellaSingola`.

---

# InizializzaCartellaSingola()
Inizializza il **Campo** Chiamato **Numeri** Presente nella **Matrice di Record** a **0** ed il Campo Chiamato **Marcato** a **`true`** 

---

# GeneraCartellaSingola()
Consente di Generare un **Numero Random** da 1 a 90 ed Esegue un **Controllo**, Chiedendo al Programma se il Numero è già Stato Estratto, facendo Riferimento ad una **Variabile Booleana**, che fa Riferimento ad una **Funzione Booleana**  Chiamata `ControlloNumeriDoppi`

---

# ControlloNumeriDoppi()

Dato un **Vettore** di 90 Elementi, in Questa **Funzione Booleana** Possiamo  Andare ad Effettuare un Controllo, Richiedendo al Programma, se il Valore **Presente nel Vettore** con Indice del **Numero Generato** è Falso (Quindi non Ancora Uscito), di **Assegnarlo a Vero** e di **Ritornare un Valore Vero**, Altrimenti Assegna e **Ritorna un Valore Falso**

---

# ControlloAmboCartellaSingola() 
Dato una Costante, Andiamo ad Identificare **l'Ambo Come 2 Elementi** sulla Colonna, Ed Effettuiamo un Controllo, Richiedendo al Programma, se il **Campo** Chiamato **Marcato**, Presente nella **Matrice di Record** è Uguale a **true**, di Assegnare ad una Variabile Contatore Chiamata `contaNumeriAmbo`, Quando la **Variabile Contatore** Arriva a 2, Allora è Avvenuto **l'Ambo**

---

# ControlloTernaCartellaSingola()
 Dato una Costante, Andiamo ad Identificare **il Terno Come 3 Elementi** sulla Colonna, Ed Effettuiamo un Controllo, Richiedendo al Programma, se il **Campo** Chiamato **Marcato**, Presente nella **Matrice di Record** è Uguale a **true**, di Assegnare ad una Variabile Contatore Chiamata `contaNumeriTerno`, Quando la **Variabile Contatore** Arriva a 3, Allora è Avvenuto **il Terno**

---
# ControlloQuaternaCartellaSingola() 
Dato una Costante, Andiamo ad Identificare **la Quaterna Come 4 Elementi** sulla Colonna, Ed Effettuiamo un Controllo, Richiedendo al Programma, se il **Campo** Chiamato **Marcato**, Presente nella **Matrice di Record** è Uguale a **true**, di Assegnare ad una Variabile Contatore Chiamata `contaNumeriQuaterna`, Quando la **Variabile Contatore** Arriva a 4, Allora è Avvenuta **la Quaterna**

---
# ControlloCinquinaCartellaSingola() 
Dato una Costante, Andiamo ad Identificare **la Quintina Come 5 Elementi** sulla Colonna, Ed Effettuiamo un Controllo, Richiedendo al Programma, se il **Campo** Chiamato **Marcato**, Presente nella **Matrice di Record** è Uguale a **true**, di Assegnare ad una Variabile Contatore Chiamata `contaNumeriQuintina`, Quando la **Variabile Contatore** Arriva a 5, Ritorna un Valore Booleano di Tipo **`true`**, Allora è Avvenuta **la Quintina**

---
# ControlloTombolaCartellaSingola()
In Questa Funzione, Andiamo ad **Esaminare** Tutti gli Elementi della **Matrice di Record**, Quindi Mentre Tutte le Caselle della Matrice non Sono State **Marcate**, Allora Ritorna un **Valore Booleano** di Tipo **`false`**, Quando Ritorna un Valore di Tipo **`true`**, **Allora è Avvenuta la Tombola**

---
![Le Cartelle](https://wips.plug.it/cips/paginegialle.it/magazine/cms/2018/12/93519067_s-Cropped.jpg?w=744&h=418&a=c)

---

# Crediti
**MarkDown ReadMe Prodotto da:**
> [ATTILIO ALESSIO](mailto:alessio.attilio@itimedi.it) (Creatore)
> [SAMUELE CAPUANO](mailto:samuele.capuano@itimedi.it) (Ricercatore)
	
[Licenza](https://github.com/AlessioAttilio/Tombola/blob/main/LICENSE)

