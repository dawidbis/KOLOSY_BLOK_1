#include "Wybor.h"

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

void zapiszTablice(const char* sciezkaPliku, short* tablica);

int main()
{
	zapiszTablice("Tablica0.txt", alokujTablice(2));
	zapiszTablice("Tablica0.txt", alokujTablice(4));
	zapiszTablice("Tablica0.txt", alokujTablice(8));
	zapiszTablice("Tablica0.txt", alokujTablice(16));
}

#endif

short* alokujTablice(uint8_t rozmiar)
{
	static uint8_t licznikTablic = 0;

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

void zapiszTablice(const char* sciezkaPliku, short* tablica)
{
	std::cout << std::endl << std::bitset<16>(tablica[-1]) << std::endl;
}
