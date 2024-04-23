/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 02.12.2016									  */
/* Projekt: P9A2										  */
/* Beschreibung: String umdrehen						  */
/**********************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>		// für strlen- Funktion
#include <ctype.h>		// für isDigit- Funktion
#include <stdlib.h>		// für atoi- Funktion

#define Groesse 10
#define laenge_array 81

// Funktionsdeklarationen
int String_leerzeichen_entfernen(char[laenge_array], int);
int String_umdrehen_und_leerzeichen_einfuegen(char[laenge_array], int, int, int[laenge_array], char[laenge_array], int);

int main(void) {
	int laenge = 0, beenden = 1, wert = 0;	// Initialisierungen
	char eingabe[laenge_array] = { 0 };
	while (beenden != 0) {		// Endlosschleife
		printf("Geben sie einen String ein:\t");	// Textausgabe
		fgets(eingabe, laenge_array, stdin);		// String eingabe
		laenge = strlen(eingabe);		// Länge des Strings herausfinden
		laenge--;		// Wegen der letzten Stelle des Strings damit dies ignoriert wird
		wert = String_leerzeichen_entfernen(eingabe, laenge);	// Funktionsaufruf

		if (wert ==  0) {		// Wenn von Funktion zurückgegebene Wert 0 ist.
			printf("Hierbei handelt es sich um einen Palyndrom.\n");
		}
		else if (wert ==  1) {	// Wenn von Funktion zurückgegebene Wert 1 ist.
				printf("Hierbei handelt es sich NICHT um einen Palyndrom.\n");
		}
		else {					// Wenn von Funktion zurückgegebene Wert ungleich 0/1 ist.
			printf("Sie haben nichts eingegeben.\n");
		}
		
		fgets(eingabe, laenge_array, stdin);		// Damit das Programm zum stehen kommt.
		system("cls");		// Leer die Kommandozeile
	}
	getchar();
	return 0;		// rückgabewert.
}

// Funktion
int String_leerzeichen_entfernen(char eingabe[laenge_array], int laenge) {
	int index = 0, index2 = 0, index3 = 0, unnoetig = 0;	// Initialisierungen
	char zwischenspeicher[laenge_array] = { 0 };	// Array Initialisierungen
	int leerzeichen[laenge_array] = { 0 };

	for (index = 0; index < laenge; index++) {			// Speichert die Eingabe in Zwischenspeicher Array.
		zwischenspeicher[index] = eingabe[index];		// Weil ich das original noch brauche muss es unverändert bleiben.
	}													// Darum nehme ich das zum Verwendungszweck

	for (index = 0, index2 = 0, unnoetig = 1; index < laenge; index++) {		// speichert die Stellen der Leerzeichen
		if (eingabe[index] == ' ') {			// Überprüft ob die indexte. Stelle des Arrays eine Leertaste ist
			leerzeichen[index2] = index;		// Der Wert von index beschreibt gleichzeitig an welcher Stelle die Leertaste
			index2++;							// In dem String Eingabe sich befindet. diese Zahl speichert er in das Array
		}										// Leertaste[] auf die index2.te Stelle.
	}
	if (index2 == 0) {		// Ist dafür gedacht für den Fall das man nichts eingibt. damit später eine Fehlermeldung kommt
		unnoetig = 0;		// Für die if- Bedingung für gleich gedacht
	}

	for (index = index2 - 1; index >= 0; index--) {		// Die Leerzeichen weg machen. Damit ich den String ohne Leerzeichen
														// umdrehen kann. index2 - 1 weil die array mit der nullten Stelle anfängt.
		for (index3 = leerzeichen[index]; index3 < laenge; index3++) {	// gibt den Wert von der ersten Stelle wo ein Leerzeichen
																		// auftritt in die Variable index 3. Führt die Schleife solange index3 < laenge ist aus.
			zwischenspeicher[index3] = zwischenspeicher[index3 + 1];	// Ersetzt die index3.te Stelle des zwischenspeicher[]'s
			zwischenspeicher[index3 + 1] = 0;		// mit der zwischenspeicher[index3 + 1] und setzt die Stelle dann auch auf 0.
		}
	}
	index = String_umdrehen_und_leerzeichen_einfuegen(zwischenspeicher, laenge, index2, leerzeichen, eingabe, unnoetig);
	return index;	// Gibt den Wert von index zurück.
}

// Funktion
int String_umdrehen_und_leerzeichen_einfuegen(char zwischenspeicher[laenge_array], int laenge, int anzahl, int leerzeichen[laenge_array], char eingabe[laenge_array], int fehler) {
	int index = 0, index3 = 0, index4 = 0;
	char ausgeben[laenge_array] = { 0 };
	// Dreht den Text um
	index3 = strlen(zwischenspeicher) - 1;	// Index3 wird die Anzahl der Zeichen des zwischenspeichers übergeben.
	for (index = 0, index4 = 0; index < laenge; index++) {	// index4 ist für die stelle des leerzeichen[]- Arrays gedacht.
		if (index == leerzeichen[index4] && fehler != 0) {	// Überprüft ob index = leerzeichen[index4] ist und etwas 
																// eingegeben wurde. Wenn ja dann wird ausgben[index] = ' ' gesetzt
			ausgeben[index] = ' ';								// und anschließend index4++ für die nächste stelle des
			index4++;											// leerzeichen[] Arrays.
		}
		else {										// wenn die obige if- Abfrage nciht ausgeführt wurde, wird diese ausgeführt
			ausgeben[index] = zwischenspeicher[index3];		// ausgeben[index] erhält das Zeichen von zwischenspeicher[index3].
			index3--;			// index3 wird - 1 gerechnet weil es von der letzten Stelle des zwischenspeicher[] Arrays beginnt.
		}
	}
	printf("Der Text umgedreht:\t\t%s\n", ausgeben);		// Textausgabe
	for (index = 0, fehler = 0; index < laenge; index++) {		// Überprüfen ob es ein Palyndrom ist
		if (toupper(eingabe[index]) != toupper(ausgeben[index])) {		// überprüft ob die Zeichen miteinander übereinstimmen.
			fehler++;		// Das umgekehrte String und das was der User eingegeben hat. unnoetig soll als Fehlermeldung dienen.
		}
	}
	if (fehler == 0 && laenge != 0) {	// Wenn alle Zeichen miteinander übereinstimmen.
		index = 0;
	}
	else if (fehler != 0) {		// Wenn die Werte nicht übereinstimmen.
		index = 1;
	}
	else {		// Wenn nichts eingegeben wurde.
		index = 2;
	}
	return index;	// Gibt den Wert von index zurück.
}


// toupper(): setzt alle Buchstaben in Großbuchstaben.
// tolower(): setzt alle buchstaben in kleinbuchstaben.