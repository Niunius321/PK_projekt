#include "main.h"

//////////////////////////////////
void Dane::Dodaj_dane(std::tuple<int, int, std::string> lista) {
	dane1.push_back(lista);
}
//////////////////////////////////
void Wczytaj::Wczytaj_dane(Dane& dane,std::string plik_wej) {
	std::ifstream plik(plik_wej);
	if (!plik) {
		std::cout << "Nie mo¿na otworzyæ pliku!" << std::endl;
	}
	else {
		std::string line;
		std::list<std::string> listaDanych;
		while (std::getline(plik, line)) {
			std::istringstream ss(line);
			std::string field;
			std::getline(ss, field, ' '); // telefon
			int tel = stoi(field);
			std::getline(ss, field, ' '); // ilosc wyszukan
			int ile = stoi(field);
			std::getline(ss, field, ' '); // informacja
			std::string kto = field;
			dane.Dodaj_dane({tel,ile,kto});
			listaDanych.clear();
		}
	}
	plik.close();
}
///////////////////////////////////
void Zapis::Save(Dane& dane, const std::string& plik_wej) {
	std::ofstream plik(plik_wej);
plik.close();
}
//////////////////////////////////
void Baza::Wypisz_dane(const Dane& dane) {
	std::vector<std::tuple<int, int, std::string>> dane1 = dane.Pobierz_dane1();
	for (const auto& tuple : dane1) {
		int tel = std::get<0>(tuple);
		int ile = std::get<1>(tuple);
		std::string kto = std::get<2>(tuple);

		std::cout << "Element: " << tel<< " "<< ile<< " "<<kto << std::endl;
	}
}