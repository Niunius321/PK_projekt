#include "main.h"

int main() {
    std::string kto;
    Dane dane;
    Wczytaj czyt;
    Wybor wybor1;
    czyt.Wczytaj_dane(dane,"/Users/oskarukleja/Downloads/PK_projekt-main/pk/pk/baza.csv");
    wybor1.Start(dane);
    
    return 0;
}
