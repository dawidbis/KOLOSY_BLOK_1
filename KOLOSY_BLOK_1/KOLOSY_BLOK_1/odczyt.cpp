#include "odczyt.h"

void odczytajTablice(const char* sciezkaPliku, uint8_t rozmiar)
{
	FILE* plik = fopen(sciezkaPliku, "r+b");

	short liczba = 0;

	short* tab = new short[rozmiar];

	if (plik)
	{
		fread(&liczba, sizeof(short), 1, plik);
		fread(tab, sizeof(tab - 1), rozmiar - 1, plik);
		fclose(plik);
	}
	else
		std::cerr << "Nie udalo sie otworzyc pliku do odczytu." << std::endl;

	uint8_t tRozmiar = liczba >> 8;
	uint8_t tIleRazy = liczba;

	std::cout << "Rozmiar:  " << std::bitset<8>(tRozmiar) << " = " << (short)tRozmiar << std::endl << std::endl;
	std::cout << "Ile razy: " << std::bitset<8>(tIleRazy) << " = " << (short)tIleRazy << std::endl << std::endl;

	std::cout << "Elementy w tablicy: ";
	for (int i = 0; i < rozmiar; i++) {
		std::cout << tab[i] << " ";
	}

	std::cout << std::endl;
}