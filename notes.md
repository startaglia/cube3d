
- MI DEVO SEGNARE LA DIREZIONE VERSO CUI VADO E QUELLA DA CUI VENGO

- MI DEVO SEGNARE LE COORDINATE DEI 4 PUNTI ESTREMI DELLA MAPPA ED INIZIO DA SINISTRA VERSO DESTRA IN SENSO ORARIO.

- PARTENDO DAL PUNTO PIU ALTO A SINISTRA ED INIZIO AD ANDARE VERSO DESTRA

- ANALISI 4 DIREZIONI:

	- DIREZIONE VERSO DESTRA (⇨), SPAZIO SOLO SOPRA . 3 SITUAZIONI DI BLOCCO:

		- L'UNO DOVE MI TROVO FORMA UN ANGOLO ESTERNO, OVVERO HA LO SPAZIO SOPRA E A DESTRA, QUINDI DEVO SCENDERE (↴)
		- L'UNO DOVE MI TROVO FORMA UN ANGOLO INTERNO, QUINDI NON HA SPAZI DA NESSUN LATO E, VISTO CHE LA DIREZIONE ERA VERSO DESTRA DEVO SALIRE. (⤴)
		- L' UNO DOVE MI TROVO È AD UN PUNTO MORTO, QUINDI HA 3 SPAZI (SOPRA, A DESTRA E IN BASSO). A QUESTO PUNTO MI BASTA INVERTIRE LA DIREZIONE. (↻)

	- DIREZIONE VERSO SINISTRA (⇦), SPAZIO SOLO SOTTO . 3 SITUAZIONI DI BLOCCO:

		- L'UNO DOVE MI TROVO FORMA UN ANGOLO ESTERNO, OVVERO HA LO SPAZIO SOTTO E A SINISTRA, QUINDI DEVO SALIRE (⬑)
		- L'UNO DOVE MI TROVO FORMA UN ANGOLO INTERNO, QUINDI NON HA SPAZI DA NESSUN LATO E, VISTO CHE LA DIREZIONE ERA VERSO SINISTRA DEVO SCENDERE. (⬐)
		- L' UNO DOVE MI TROVO È AD UN PUNTO MORTO, QUINDI HA 3 SPAZI (SOTTO, A SINISTRA E IN ALTO). A QUESTO PUNTO MI BASTA INVERTIRE LA DIREZIONE. (↻)

	- DIREZIONE VERSO IL BASSO (↓), SPAZIO SOLO A DESTRA. 3 SITUAZIONI DI BLOCCO:

		- L'UNO DOVE MI TROVO FORMA UN ANGOLO ESTERNO, QUINDI HA SPAZIO A DESTRA E IN BASSO. DEVO GIRARE A SINISTRA (↲)
		- L'UNO DOVE MI TROVO FORMA UN ANGOLO INTERNO, QUINDI NON HA NESSUNO SPAZIO DA NESSUN LATO. DEVO GIRARE A DESTRA (↳)
		- L' UNO DOVE MI TROVO È AD UN PUNTO MORTO, QUINDI HA 3 SPAZI (A DESTRA, A SOTTO E A SINISTRA). A QUESTO PUNTO MI BASTA INVERTIRE LA DIREZIONE. (↻)

	- DIREZIONE VERSO L'ALTO (↾), SPAZIO SOLO A SINISTRA. 3 SITUAZIONI DI BLOCCO:

		- L'UNO DOVE MI TROVO FORMA UN ANGOLO ESTERNO, QUINDI HA SPAZIO A SINISTRA E IN ALTO. DEVO GIRARE A DESTRA (↱)
		- L'UNO DOVE MI TROVO FORMA UN ANGOLO INTERNO, QUINDI NON HA NESSUNO SPAZIO DA NESSUN LATO. DEVO GIRARE A SINISTRA (↰)
		- L' UNO DOVE MI TROVO È AD UN PUNTO MORTO, QUINDI HA 3 SPAZI (A DESTRA, A SOPRA E A SINISTRA). A QUESTO PUNTO MI BASTA INVERTIRE LA DIREZIONE. (↻)



KNOWN BUGS
- NEL FILE, DOPO LA MAPPA SE, SENZA SEPARARLI DA UNA RIGA VUOTA, SI INSERISCONO CARATTERI AMMESSI, QUINDI 1 0 N S E W LI ACCETTA ANCHE SE NON SONO DIRETTAMENTE SOTTO LA MAPPA, COME NE FOSSERO UN PROLUNGAMENTO.
- SE CI SONO TANTE RIGHE VUOTE TRA L'ULTIMO ID E LA MAPPA E SI METTE UN CARATTERE NON AMMESSO SENZA DARE PRIMA UNO SPAZIO MI DA UN ERRORE DI SINTASSI IDENTIFICATORI SBAGLIATA, SE SI DA UNO SPAZIO INVECE MI DA ERRORE CHE LA MAPPA DEVE ESSERE L'ULTIMA COSA NEL FILE