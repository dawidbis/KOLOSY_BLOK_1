#include "0A_sekcja_1.h"

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

void kolos()
{
	short* tab1 = alokujTablice(16);
	zapiszTablice("Tablica0.txt", tab1);

	std::cout << std::endl;

	odczytajTablice("Tablica0.txt", 16);

	delete[](tab1 - 1);
	tab1 = nullptr;
}