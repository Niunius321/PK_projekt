#include "main.h"

int main() {
    int wybor,tel;
    std::string kto;
    Dane dane;
    Wczytaj czyt;
    Baza baza;
    Szukaj szukaj;
    czyt.Wczytaj_dane(dane,"C:/Users/Oskar/Downloads/baza.csv");
    std::cout << "Witaj przedstawiam bazę danych nękających telefonów. Wybierz co chcesz zrobić." << std::endl << "Wpisz 1 aby wyszukać numer telefonu" << std::endl << "Wpisz 2 aby dodać numer telefonu do bazy danych" << std::endl;
    std::cin >> wybor;
    if (wybor == 1) {
        std::cout << "Czy chcesz wyszukać po numerze telefonu? 1 -> Tak  2 -> Nie" << std::endl;
        std::cin >> wybor;
        if (wybor == 1) {
            std::cout << "Podaj numer telefonu który chcesz wyszukać (format bez spacji)" << std::endl;
            std::cin >> tel;
            szukaj.Szukanie_tel(dane, tel);
        }
        else {
            baza.Wypisz_dane(dane);
        }
    }
    else if (wybor == 2) {
        baza.Wypisz_dane(dane);
    }
    return 0;
}