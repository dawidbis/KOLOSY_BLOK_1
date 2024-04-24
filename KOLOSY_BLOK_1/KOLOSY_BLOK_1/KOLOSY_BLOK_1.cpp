#include "Wybor.h"
#include "0A_sekcja_1.h"

#ifdef kolos_0A_sekcja_0

struct Size
{
    size_t columns;
    size_t rows;
};

int** allocate(uint16_t columns, uint16_t rows)
{

    int size = 0;

    size |= columns << 16;
    size |= rows;

    int** tab = new int* [rows];
    tab[0] = new int{ size };

    tab++;

    for (size_t i = 0; i < rows; i++)
    {
        tab[i] = new int[columns];
    }


    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            tab[i][j] = i * j;
        }
    }

    return tab;
}

Size getSize(int** tab)
{
    int size = tab[-1][0];

    int rows = size & 0x0000ffff;
    int columns = (size & 0xffff0000) >> 16;

    std::cout << rows << " " << columns;

    return { 0, 0 };
}

void saveTab(const char* path, int** tab, int16_t columns, int16_t rows)
{
    FILE* file = nullptr;
    file = fopen(path, "wb");


    for (size_t i = 0; i < columns; i++)
    {
        fwrite(tab[i], sizeof(int), rows, file);
    }

    fclose(file);
}

int** readTab(const char* path, int16_t columns, int16_t rows)
{
    FILE* file = nullptr;
    file = fopen(path, "wb");

    auto tab = allocate(columns, rows);

    for (size_t i = 0; i < columns; i++)
    {
        fread(tab[i], sizeof(int), rows, file);
    }

    fclose(file);

    return tab;
}

int main()
{
    constexpr int sexik = 2;
    const constexpr static int64_t UwU = 3;

    auto tab = allocate(sexik, UwU);
    saveTab("a.txt", tab, sexik, UwU);
    auto sex = readTab("a.txt", 2, UwU);

    for (size_t i = 0; i < UwU; i++)
    {
        for (size_t j = 0; j < sexik; j++)
        {
            std::cout << sex[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
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

int main()
{
	kolos();
}

#endif
