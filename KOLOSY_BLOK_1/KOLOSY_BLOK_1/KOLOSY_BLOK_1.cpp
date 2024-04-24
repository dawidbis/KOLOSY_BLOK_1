#include "Wybor.h"
#include "zapis.h"
#include "odczyt.h"

#ifdef kolos_0A_sekcja_0

int main()
{
			
}

#endif

#ifdef kolos_0A_sekcja_1

/*
	Blok 1 [Programowanie proceduralne – operacje plikowe i bitowe]:

1)	Napisz funkcję do alokacji tablicy typu short, tak aby jej -1 element przechowywał jej rozmiar na starszym bajcie.
	Na bajcie młodszym zapisz, jej numer mówiący o tym, która to jest taka tablica zapisana od początku pracy programu.
	Tablica po utworzeniu powinna być zapisana samymi zerami.

2)	Napisz 2 funkcje:
	- do zapisu tablicy z polecenia 1 do pliku w trybie binarnym,
	- do odczytu tablicy z polecenia 1 z pliku w trybie binarnym.
	W pliku należy też przechować wymiary tablicy (zauważ, że w tablicy wymiar jest już zapisany).

3)	Podziel program na pliki, tak aby napisane wyżej funkcje znalazły się w oddzielnej jednostce translacji.

4)	Napisz krótki program główny, który zapisze kilka takich tablic do plików i odczyta poprawnie tą o wskazanym przez
	użytkownika numerze. Nie zapomnij o poprawnym zwolnieniu pamięci, na koniec pracy programu.

*/

short* alokujTablice(uint8_t rozmiar);

int main()
{
	short* tab1 = alokujTablice(16);
	zapiszTablice("Tablica0.txt", tab1);

	std::cout << std::endl;

	odczytajTablice("Tablica0.txt", 16);

	delete[] (tab1-1);
	tab1 = nullptr;
}

short* alokujTablice(uint8_t rozmiar)
{
	static uint8_t bufor; static uint8_t licznikTablic;
	if (rozmiar != bufor) licznikTablic = 0;
	bufor = rozmiar;

	short infoTablica = 0;

	infoTablica |= rozmiar << 8;
	infoTablica |= licznikTablic;

	short* tablica = new short[rozmiar + 1];

	tablica[0] = infoTablica;

	for (int i = 1; i < rozmiar + 1; i++) {
		tablica[i] = 0;
	}

	licznikTablic++;

	return tablica + 1;
}

#endif
