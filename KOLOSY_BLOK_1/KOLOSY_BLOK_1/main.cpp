#include "Wybor.h"

using namespace std;

#ifdef kol_przykladowy

#include "zapis_odczyt.h"

int** alokujTablice(uint16_t liczbaWierszy, uint16_t liczbaKolumn)
{
    // Zakodowanie rozmiaru
    uint32_t zakodowanyRozmiar = liczbaWierszy << 16 | liczbaKolumn;

    // Alokacja pamięci na wskaźniki do wierszy
    int** tablica = new int* [liczbaWierszy + 1] {};

    // Alokacja pamięci na każdy wiersz
    for (uint16_t i = 0; i <= liczbaWierszy; ++i)
    {
        tablica[i] = new int[liczbaKolumn] {};
    }

    // Zapisanie zakodowanego rozmiaru w elemencie [-1][0]
    tablica[0][0] = zakodowanyRozmiar;

    return tablica + 1; // Przesunięcie wskaźnika, aby [-1] było dostępne
}

int main()
{
    uint16_t liczbaWierszy = 21;
    uint16_t liczbaKolumn = 18;

    int** tablica = alokujTablice(liczbaWierszy, liczbaKolumn);

    // Sprawdzenie zapisanego rozmiaru
    uint32_t zakodowanyRozmiar = tablica[-1][0];
    uint16_t zapisaneWiersze = zakodowanyRozmiar >> 16;
    uint16_t zapisaneKolumny = zakodowanyRozmiar & 0xFFFF;

    std::cout << "Zapisane wiersze: " << zapisaneWiersze << std::endl;
    std::cout << "Zapisane kolumny: " << zapisaneKolumny << std::endl;

    // Wypisanie
    for (uint16_t i = 0; i <= liczbaKolumn - 1; ++i)
    {
        for(uint16_t j = 0; j <= liczbaWierszy - 1; ++j)
        {
            cout << tablica[j][i] << " ";
        }
        cout << endl;
    }

    // Zwolnienie pamięci
    for (uint16_t i = 0; i <= liczbaWierszy; ++i)
    {
        delete[](tablica - 1)[i];
    }
    delete[](tablica - 1);

    zapisz(tablica, "cipka");

    return 0;
}

#endif

#ifdef kol_sek_2

#include "zapis_odczyt2.h"

short* alokujTablice(short size)
{
    static short s_counter = 0;
    short* tab = new short[size + 1] {};
    tab[0] = size << 8 | s_counter;
    s_counter++;
    return (tab + 1);
}

void odczytajRozmiarILicznik(short* tablica) {
    uint16_t zlaczenie = *(tablica - 1);
    short size = zlaczenie >> 8;
    uint16_t licznik = zlaczenie & 0xFF;
    cout << "Rozmiar: " << size << ", Licznik: " << licznik << endl;
}


int main()
{
    short size = 200;
    short* wskaznikNaTablice = alokujTablice(size);
    short* wskaznikNaTablice1 = alokujTablice(size);
    //cout << "16/8: " << bitset<16>(wskaznikNaTablice1[-1]) << "\n";
    zapiszTablice(wskaznikNaTablice, "faddtek.txt");
    zapiszTablice(wskaznikNaTablice1, "maciek.txt");
    odczytajPlik("faddtek.txt");
    odczytajPlik("maciek.txt");
    delete[](wskaznikNaTablice - 1);
    delete[](wskaznikNaTablice1 - 1);
}

#endif

#ifdef  kol_sek_2_t1

short* alokujTab(short size)
{
    static short s_counter = 0;

    if (size > 0)
    {
        short* tab = new short[size + 1] {};
        tab[0] = s_counter << 8 | size;
        s_counter++;
        return (tab + 1);
    }
    else return nullptr;
}

void dealokujTab(short* tab)
{
    delete[](tab - 1);
    tab = nullptr;
}

short odczytajRozmiarTab(short* tablica);

void zapiszTab(short* tab, const char* nazwaPliku)
{
    FILE* wskPlik = fopen(nazwaPliku, "wb");

    if (wskPlik == nullptr || tab == nullptr) {
        cerr << "Błąd\n";
        return;
    }

    fwrite(&tab[-1], sizeof(short), 1, wskPlik);

    short rozmiar = odczytajRozmiarTab(tab);

    size_t zapisaneElementy = fwrite(tab, sizeof(short), rozmiar, wskPlik);

    if (zapisaneElementy != rozmiar) {
        cerr << "Błąd zapisu zawartości tablicy do pliku\n";
        fclose(wskPlik);
        return;
    }

    fclose(wskPlik);
}


short* odczytajTab(const char* nazwaPliku)
{
    FILE* plik = fopen(nazwaPliku, "rb");

    if (plik == nullptr) {
        cerr << "Błąd\n";
        return nullptr;
    }

    short rozmiar;

    fread(&rozmiar, sizeof(short), 1, plik);

    short* tab = alokujTab(rozmiar);

    fread(tab, sizeof(short), rozmiar, plik);

    fclose(plik);

    return tab;
}

short odczytajRozmiarTab(short* tab) {
    uint16_t zakodowaneDane = *(tab - 1);
    short size = zakodowaneDane;
    size = zakodowaneDane & 0xFF;

    return size;
}

bool porownajTab(short* tabA, short* tabB)
{
    short sizeA = odczytajRozmiarTab(tabA);
    short sizeB = odczytajRozmiarTab(tabB);

    return (sizeA == sizeB) ? (memcmp(tabA, tabB, sizeA * sizeof(short)) == 0) : false;
}

void wygenerujTab(short* tab)
{
    for (int i = 0; i < odczytajRozmiarTab(tab); i++) tab[i] = rand() % 90 + 10;
}


void odczytajZawartoscTab(short* tab)
{
    for (int i = 0; i < odczytajRozmiarTab(tab); i++) std::cout << " " << tab[i];
}

int main()
{
    srand(time(NULL));

    short size = 20;
    short* wskaznikNaTablice = alokujTab(size);
    short* wskaznikNaTablice1 = alokujTab(size + 10);
    short* wskaznikNaTablice2 = alokujTab(size + 20);

    wygenerujTab(wskaznikNaTablice);
    wygenerujTab(wskaznikNaTablice1);
    wygenerujTab(wskaznikNaTablice2);

    std::cout << " Odczytywanie danych z tablicy:\n";

    odczytajZawartoscTab(wskaznikNaTablice); std::cout << "\n";
    odczytajZawartoscTab(wskaznikNaTablice1); std::cout << "\n";
    odczytajZawartoscTab(wskaznikNaTablice2); std::cout << "\n";

    zapiszTab(wskaznikNaTablice2, "Plik2.txt");

    short* wskaznikNaTablice3 = odczytajTab("Plik2.txt");

    if (porownajTab(wskaznikNaTablice2, wskaznikNaTablice3))
    {
        std::cout << "\nTablice sa rowne" << "\n";
    }
    else
    {
        std::cout << "Tablice nie sa rowne" << "\n";
    }

    dealokujTab(wskaznikNaTablice);
    dealokujTab(wskaznikNaTablice1);
    dealokujTab(wskaznikNaTablice2);
    dealokujTab(wskaznikNaTablice3);
}

#endif //  kol_sek_2_t1
