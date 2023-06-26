#include "main.h"

int main() {
    int wybor;
    std::string kto;
    Dane dane;
    Wczytaj czyt;
    Wybor wybor1;
    czyt.Wczytaj_dane(dane,"C:/Users/Oskar/Downloads/baza.csv");
    wybor1.Start(dane);
    
    return 0;
}