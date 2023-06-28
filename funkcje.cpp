#include "main.h"

//////////////////////////////////
void Wczytaj::Wczytaj_dane(Dane& dane,const std::string plik_wej) {
	std::ifstream plik(plik_wej);
	if (!plik) {
		std::cout << "Nie mozna otworzyc pliku" << std::endl;
	}
	else {
		std::string line;
        std::list<std::string> wewnetrzna;
		while (std::getline(plik, line)) {
			std::istringstream ss(line);
			std::string field;
			std::getline(ss, field, ' '); // telefon
            wewnetrzna.push_back(field);
			std::getline(ss, field, ' '); // ilosc wyszukan
            wewnetrzna.push_back(field);
			std::getline(ss, field, ' '); // informacja
            wewnetrzna.push_back(field);
			std::string kto = field;
            dane.Dodaj(wewnetrzna);
			wewnetrzna.clear();
		}
	}
	plik.close();
}
///////////////////////////////////
void Zapis::Save(const Dane& dane, const std::string& plik_wej) {
	std::ofstream outputFile("/Users/oskarukleja/Downloads/PK_projekt-main/pk/pk/baza.csv");
    std::list<std::list<std::string>> danee = dane.Pobierz_dane();
	if (outputFile.is_open()) {
        for (const auto& lista : danee) {
            for (const auto& wartosc : lista) {
                outputFile<<wartosc<<" ";
            }
            outputFile<<"\n";
        }
		outputFile.close(); // Zamkniêcie strumienia plikowego
		std::cout << "Zapisano do pliku.\n";
	}
	else {
		std::cout << "Nie mozna otworzyc pliku."<<std::endl;
	}
}
//////////////////////////////////
void Baza::Wypisz_dane(const Dane& dane) {
    std::list<std::list<std::string>> listaList = dane.Pobierz_dane();
    for (const auto& lista : listaList) {
           for (const auto& wartosc : lista) {
               std::cout << wartosc << " ";
           }
           std::cout << std::endl;
       }
}
//////////////////////////////
void Szukaj::Szukanie_tel( Dane& dane,std::string tel, int wybor) {
    std::list<std::list<std::string>> listaList = dane.Pobierz_dane();
	bool znalezione = false;
    for (const auto& lista : listaList) {
        if (lista.front()==tel) {
            znalezione=true;
            auto element = lista.begin();
            std::cout<<"Znaleziony numer: "<<lista.front()<<" Ilosc wyszukan: ";
            std::advance(element, 1);
            std::cout<<stoi(*element)+1<<" Rodzaj dzwoniacego: ";
            std::advance(element, 1);
            std::cout<<*element;
        }
        
    }
	if (znalezione == false) {
		std::cout << "Nie znaleziono w bazie takiego numeru telefonu, czy chcesz dodaæ go do bazy? 1 -> Tak  2 -> Nie";
		std::cin >> wybor;
		if (wybor == 1) {
            std::list<std::string> wewnetrzna;
			std::cout << "Podaj nr telefonu:";
			std::cin >> tel;
            wewnetrzna.push_back(tel);
            wewnetrzna.push_back("1");
			std::cout << "Podaj rodzaj telefonu:";
			std::cin >> kto;
            wewnetrzna.push_back(kto);
			dane.Dodaj(wewnetrzna);
            wewnetrzna.clear();
			zapis.Save(dane, "/Users/oskarukleja/Downloads/PK_projekt-main/pk/pk/baza.csv");
		}
		else {
			std::cout << "tak";
		}
	}
}

////////////////
void Wybor::Start(Dane& dane) {
	std::cout << "Witaj przedstawiam bazê danych nêkaj¹cych telefonów. Wybierz co chcesz zrobiæ." << std::endl << "Wpisz 1 aby wyszukaæ numer telefonu" << std::endl << "Wpisz 2 aby dodaæ numer telefonu do bazy danych" << std::endl;
	std::cin >> wybor;
    std::list<std::list<std::string>> listaList = dane.Pobierz_dane();
	if (wybor == 1) {
		std::cout << "Czy chcesz wyszukaæ po numerze telefonu? 1 -> Tak  2 -> Nie" << std::endl;
		std::cin >> wybor;
		if (wybor == 1) {
			std::cout << "Podaj numer telefonu który chcesz wyszukaæ (format bez spacji)" << std::endl;
			std::cin >> tel;
			szukaj.Szukanie_tel(dane, std::to_string(tel), wybor);
		}
		else if (wybor == 2) {
			std::cout << "Podaj jakiego typu telefonu szukasz"<<std::endl;
			std::cin >> kto;
            for(auto el : listaList){
                if(el.back()==kto){
                    auto element = el.begin();
                    std::cout<<"Numer telefonu: "<<*element<<" Ilosc wyszukan: ";
                    std::advance(element, 1);
                    std::cout<<stoi(*element)+1<<" Kto: ";
                    std::advance(element, 1);
                    std::cout<<*element<<std::endl;
                }
            }
		}
	}
	else if (wybor == 2) {
        std::list<std::string> wewnetrzna;
		std::cout << "Podaj nr telefonu:";
		std::cin >> tel;
        for(auto el : listaList){
            if(stoi(el.front())==tel){
                
                std::cout<<"Taki telefon znajduje sie w bazie!";
                znalezione=true;
            }
        }
        if(znalezione==false){
            wewnetrzna.push_back(std::to_string(tel));
            wewnetrzna.push_back("1");
            std::cout << "Podaj rodzaj telefonu:";
            std::cin >> kto;
            wewnetrzna.push_back(kto);
            dane.Dodaj(wewnetrzna);
            wewnetrzna.clear();
            zapis.Save(dane, "/Users/oskarukleja/Downloads/PK_projekt-main/pk/pk/baza.csv");
        }
	}
}


