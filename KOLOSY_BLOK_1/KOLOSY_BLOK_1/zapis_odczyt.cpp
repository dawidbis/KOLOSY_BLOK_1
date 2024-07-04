#include "zapis_odczyt.h"

void zapisz(int** tab, const char* nazwaPliku)
{
	//FILE* wskNaPlik = nullptr;
	//wskNaPlik = fopen(nazwaPliku, "wb");

	uint32_t liczbaKolumn = tab[-1][0];
	uint32_t liczbaWierszy = tab[-1][0];
	liczbaWierszy >> 16;

	std::cout << std::bitset<32>(liczbaKolumn) << "x" << std::bitset<32>(liczbaWierszy);

	//if (wskNaPlik != nullptr)
	//{

	//}

}

int** odczyt(const char* nazwaPliku)
{

	return nullptr;
}
