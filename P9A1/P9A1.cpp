/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 01.12.2016									  */
/* Projekt: P9A1										  */
/* Beschreibung: Primzahlen								  */
/**********************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>		// f�r strlen- Funktion
#include <ctype.h>		// f�r isDigit- Funktion
#include <stdlib.h>		// f�r atoi- Funktion

#define Groesse 10
#define laenge_array 10000
int pruefen(char[Groesse]);		// Funktionsdeklaration
int is_primzahl(int);

int main(void) {	// Hauptprogramm
	int aussuchen = 0, wert = 0, beenden = 1, index = 0, index2 = 0, index3 = 0, zwischenspeicher = 0;		// Variabeln Initialisierungen
	char eingabe[Groesse] = { 0 };
	int primzahlen[laenge_array] = { 0 };

	while (beenden != 0) {		// Endlosschleife
		printf("Was moechten sie tun?\n 1. Pruefen ob die eingegebene Zahl eine Primzahl ist\n 2. Alle Primzahlen bis dahin ausgeben\n 3. Programm beenden\n\nBitte waehlen:\t");
		fgets(eingabe, Groesse, stdin);		// String eingabe
		aussuchen = pruefen(eingabe);		// den R�ckgabewert(Integer) in die Variable aussuchen speichern
		if (aussuchen > 0 && aussuchen < 3) {		// wenn aussuchen gr��er 0 und kleiner 3 ist verlangt er nach einem wert
			printf("Geben sie eine zahl ein die sie pruefen moechten: \t");
			fgets(eingabe, Groesse, stdin);
			wert = pruefen(eingabe);
		}

		switch (aussuchen) {		// Daf�r da um etwas auszuw�hlen
		case 1:		// wenn die Variable aussuchen den wert 1 hat dann f�hrt er das bis zum break aus
			system("cls");		// l�scht die CMD
			index = is_primzahl(wert);		// funktionsaufruf + r�ckgabewert in index rein speichern
			if (index == 1) {		// wenn eine 1 zur�ckgegeben wurde dann gibt er den unteren text aus
				printf("Zahl %i = Primzahl.\n\n", wert);
			}
			else {		// wenn eine 0 zur�ckgegeben wurde dann gibt er den unteren text aus
				printf("Zahl %i = KEINE Primzahl.\n\n", wert);
			}
			fgets(eingabe, Groesse, stdin);		// Damit das Programm zum stehen kommt. hab getchr() damit ersetzt. bei getchar() wenn ich da zahlen eingebe
			system("cls");						// kommt irgendetwas komisches raus
			break;		// ein abbruchpunkt f�r diesen case

		case 2:		// wenn aussuchen = 0 ist dann f�hrt er diese Befehle bis zum break aus
			system("cls");
			for (index = 0; index <= wert; index++) {	// soll alle werte bis wert �berpr�fen ob es eine primzahl ist.
				index2 = is_primzahl(index);		// funktionsaufruf zum �berpr�fen ob es eine primzahl ist
				if (index2 == 1) {		// wenn es eine ist (1 = true) dann speicher er in das Array Primzahlen[index3] den zwischenspeicher(index also)
					primzahlen[index3] = index;
					index3++;		// f�r den Array
				}
			}
			printf("Ihre Primzahlen lauten:\n");
			for (index = 0, index2 = 0; index < index3; index++) {		// soll alle Werte von dem Array ausgeben. index3 kennt die Anzahl wegen der oberen Zeile wo 
				printf("%i\t", primzahlen[index]);			// index3 hochgez�hlt wurde und jedesmal dabei die zahlen gespeichert wurden
				index2++;		// index2 wird hochgez�hlt
				if (index2 == 7) {		// hab cih gemacht damit das Programm �bersichtlicher wird. wenn index2 den wert 7 erreicht macht es einen 
					printf("\n");		// Zeilensprung
					index2 = 0;			// anschlie�end wird index2 wieder zur�ckgesetzt
				}
			}
			printf("\n\n");
			fgets(eingabe, Groesse, stdin);		// damit das programm zum stehen kommt.
			system("cls");
			for (index = 0; index < index3; index++) {		// l�scht die werte die in dem Array primzahlen[index] gespeichert wurden
				primzahlen[index] = 0;
			}
			index3 = 0;		// setzt index3 auf 0 f�r einen weiteren durchlauf
			break;		// ende von case 2

		case 3:			// wenn aussuchen den wert 3 hat dann 
			printf("Das Programm wird nun beendet.");		// gibt er den text aus
			beenden = 0;		// und beenden anschlie�end das programm in dem er die Bedingung f�r die Endlosschleife ganz am Anfang erf�llt
			break;		// ende von case 3

		default:		// wenn aussuchen einen nicht vorhandenen wert hat dann f�hrt er dies aus
			printf("Ungueltige Wahl.\n\n");		// text ausgabe
			fgets(eingabe, Groesse, stdin);		// damit das programm zum stehen kommt
			system("cls");		// l�scht wieder die commandozeile
		}
	}
	getchar();		// damit das programm zum stehen kommt
	return 0;		// r�ckgabewert
}

// funktionsaufruf f�r pruefen
int pruefen(char eingabe[Groesse]) {		// ein string wurde �bergeben. ein integer wert wird �bergeben
	int laenge = 0, fehler = 0, index = 0;	// initialisierungen
	laenge = strlen(eingabe);		// um herauszufinden wie gro� der string ist
	if (eingabe[0] == '+') {		// �berpr�ft ob ein + am anfang steht um es abzufangen
		laenge -= 2;		// wenn ja dann dekrementiert er die l�nge um 2
		for (index = 0; index < laenge; index++) {		// dient dazu um den + weg zu machen und um die zahlen zu vertauschen
			eingabe[index] = eingabe[index + 1];		// tauscht den ersten wert des arrays mit dem n�chsten
			eingabe[index + 1] = 0;		// setzt den n�chsten wert des arrays auf 0
		}
	}
	else {		// wenn die obige bedingung nicht erf�llt wurde dann f�hrt er das aus
		laenge -= 1;	// l�nge wird um 1 dekrementiert. (l�nge--)
	}
	for (index = 0; index < laenge; index++) {		// dient dazu um alle string- zeichen zu �berpr�fen ob auch alle zahlen sind
		if (isdigit(eingabe[index]) == 0) {	// wenn eine 0 zur�ckgegeben wurde(also false) dann ist die stelle des arrays KEINE zahl und
			fehler++;		// die variable fehler wird incrementiert
		}
	}
	index = 0;		// index wird auf 0 gesetzt
	if (fehler == 0) {		// wenn fehler = 0 ist dann f�hrt er die schleife aus
		index = atoi(eingabe);		// wandelt den string in einen integer wert um und setzt es mit index gleich
	}
	fehler = 0;	// setzt fehler = 0
	return index;	// gibt index wieder zur�ck
}			// ende........


int is_primzahl(int wert) {		// Funktion
	int counter = 0, index = 0, fehler = 0;		// Intialisierungen (lokal)
	fehler = 0;		// auf 0 setzen
	counter = 0;	// auf 0 setzen

	// wenn der mitgegebene wert ungleich 0 ist f�hrt er die folgenden befehle aus
	if (wert != 0)
	{		
		// wenn die bedingung erf�llt ist f�hrt er die folgenden befehle aus
		if (wert > 0 || wert % 2 != 0 && wert != 2)
		{	
			// index wird gleich 2 gesetzt. solange index kleiner wert-1 ist f�hrt er das aus.
			for (index = 2; index < wert - 1; index++)
			{
				// wenn wert durch index keinen restwert hat, f�hrt er die unteren befehle aus
				if (wert % index == 0)
				{
					fehler++;
					// damit die forschleife zu ende geht.
					// weil index ja gr��er gleich mit wert sein muss damit die schleife auffh�rt durchzulaufen
					index = wert;
					// wert auf 0 setzen
					wert = 0;		
				}
			}
		}
		if (fehler == 0) {	// wenn fehler = 0 ist dann wird index auf 1 gesetzt und zur�ckgegeben als true
			index = 1;
		}
		else {		// andernfalls wird eine 0 also false zur�ckgegeben
			index = 0;
		}
	}
	else {		// wenn wert = 0 ist dann wird eine 0 bzw false zur�ckgegeben
		index = 0;
	}
	return index;		// index wird zur�ckgegeben.
}