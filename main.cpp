#include "main.h"

int main() {
    Pobieranie pobieraj;
    Dane dane;
    pobieraj.Wczytaj_dane("C:/Users/Oskar/Downloads/baza.csv");
    dane.Wypisz();
    return 0;
}