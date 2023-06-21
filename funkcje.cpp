#include "main.h"




void Pobieranie::Wczytaj_dane(const std::string& plik_wej) {
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
			listaDanych.push_back(field);
			std::getline(ss, field, ' '); // ilosc wyszukan
			listaDanych.push_back(field);
			std::getline(ss, field, ' '); // informacja
			listaDanych.push_back(field);
			dane.Dodaj_dane(listaDanych);
			listaDanych.clear();
		}
	}
	plik.close();
}


void Zapis::Zapisz_dane(const std::string& plik_wej) {
	std::ofstream plik(plik_wej);
	plik.close();
}