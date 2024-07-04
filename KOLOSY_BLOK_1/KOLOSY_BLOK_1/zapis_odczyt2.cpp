#include "zapis_odczyt2.h"

void zapiszTablice(short* tablica, const char* nazwaPliku)
{
    FILE* plik = fopen(nazwaPliku, "w+b");

    if (plik == nullptr) {
        std::cerr << "B³¹d otwarcia pliku do zapisu\n";
        return;
    }

    // Najpierw zapisujemy rozmiar tablicy i licznik
    short zlaczenie = tablica[-1];
    uint16_t rozmiar = zlaczenie;
    rozmiar >>= 8;
    fwrite(&zlaczenie, sizeof(short), 1, plik);

    //Zapisujemy zawartoœæ tablicy
    size_t napisano = fwrite(tablica, sizeof(short), rozmiar, plik);
    if (napisano != rozmiar) {
        std::cerr << "B³¹d zapisu zawartoœci tablicy do pliku\n";
        fclose(plik);
        return;
    }

    fclose(plik);
}

void odczytajPlik(const char* nazwaPliku)
{
    FILE* plik = fopen(nazwaPliku, "r+b");
    if (plik == nullptr) {
        std::cerr << "B³¹d otwarcia pliku do odczytu\n";
        return;
    }
    short zlaczenie;
    fread(&zlaczenie, sizeof(short), 1, plik);
    std::cout << "odczyt zlaczenia z pliku: " << std::bitset<16>(zlaczenie) << "\n";
    short czesc1 = (zlaczenie >> 8);
    uint16_t maska = 0x00C8;
    short rozmiar = (czesc1 & maska);
    std::cout << "rozmiar z pliku: " << std::bitset<16>(rozmiar) << "\nBez bitsetu z pliku: " << rozmiar << "\n";
    uint16_t licznik = zlaczenie & 0xFF;

    std::cout << "Rozmiar: " << rozmiar << ", Licznik: " << licznik << std::endl;
    short* tablica = new short[rozmiar];
    fread(tablica, sizeof(short), rozmiar, plik);

    // Wyœwietlamy zawartoœæ tablicy
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << tablica[i] << ", ";
    }
    std::cout << std::endl;

    delete[] tablica;

    fclose(plik);
}
