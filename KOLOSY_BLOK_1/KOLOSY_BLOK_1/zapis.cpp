#include "Wybor.h"
#include "zapis.h"

void zapiszTablice(const char* sciezkaPliku, short* tablica)
{
	FILE* plik = fopen(sciezkaPliku, "w+b");

	short rozmiar = tablica[-1] >> 8;

	if (plik)
	{
		fwrite(&tablica[-1], sizeof(short), 1, plik);
		fwrite(tablica, sizeof(tablica - 1), rozmiar - 1, plik);
		fclose(plik);
		std::cout << "Tablica zapisana do pliku: " << sciezkaPliku << " o rozmiarze: " << rozmiar << std::endl;
	}
	else
		std::cerr << "Nie udalo sie otworzyc pliku do zapisu." << std::endl;
}