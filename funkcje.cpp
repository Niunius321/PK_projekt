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
void Zapis::Save(const Dane& dane, const std::string& plik_wej) {
	std::ofstream outputFile("C:/Users/Oskar/Downloads/baza.csv"); // Tworzenie obiektu strumienia plikowego
	std::vector<std::tuple<int, int, std::string>> dane1 = dane.Pobierz_dane1();
	if (outputFile.is_open()) { // Sprawdzenie, czy plik zosta³ otwarty poprawnie
		for (const auto& tuple : dane1) {
			int value1 = std::get<0>(tuple);
			int value2 = std::get<1>(tuple);
			std::string value3 = std::get<2>(tuple);

			outputFile << value1 << " " << value2 << " " << value3 << "\n";
		}

		outputFile.close(); // Zamkniêcie strumienia plikowego
		std::cout << "Zapisano do pliku.\n";
	}
	else {
		std::cerr << "Nie mo¿na otworzyæ pliku.\n";
	}
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
//////////////////////////////
void Szukaj::Szukanie_tel( Dane& dane,int tel, int wybor) {
	std::vector<std::tuple<int, int, std::string>> dane1 = dane.Pobierz_dane1();
	bool znalezione = false;
	for (const auto& tuple : dane1) {
		int szukane = std::get<0>(tuple);
		if (tel == szukane) {
			znalezione = true;
			int ile = std::get<1>(tuple);
			std::string kto = std::get<2>(tuple);
			std::cout << "Znaleziono podany numer: " << tel << " " << ile+1 << " " << kto << std::endl;
		}
	}
	if (znalezione == false) {
		std::cout << "Nie znaleziono w bazie takiego numeru telefonu, czy chcesz dodaæ go do bazy? 1 -> Tak  2 -> Nie";
		std::cin >> wybor;
		if (wybor == 1) {
			std::cout << "Podaj nr telefonu:";
			std::cin >> tel;
			std::cout << "Podaj rodzaj telefonu:";
			std::cin >> kto;
			dane.Dodaj_dane({ tel,1,kto });
			zapis.Save(dane, "C:/Users/Oskar/Downloads/baza.csv");
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
	if (wybor == 1) {
		std::cout << "Czy chcesz wyszukaæ po numerze telefonu? 1 -> Tak  2 -> Nie" << std::endl;
		std::cin >> wybor;
		if (wybor == 1) {
			std::cout << "Podaj numer telefonu który chcesz wyszukaæ (format bez spacji)" << std::endl;
			std::cin >> tel;
			szukaj.Szukanie_tel(dane, tel, wybor);
		}
		else if (wybor == 2) {
			std::cout << "Podaj jakiego typu telefonu szukasz"<<std::endl;
			std::cin >> kto;
			std::vector<std::tuple<int, int, std::string>> dane1 = dane.Pobierz_dane1();
			for (const auto& tuple : dane1) {
				std::string szukane = std::get<2>(tuple);
				if (kto == szukane) {
					tel = std::get<0>(tuple);
					int ile = std::get<1>(tuple);
					std::cout << "Znaleziono podany/e typy numerow: " << tel << " " << ile + 1 << " " << kto << std::endl;
				}
			}
		}
	}
	else if (wybor == 2) {
		std::cout << "Podaj nr telefonu:";
		std::cin >> tel;
		std::cout << "Podaj rodzaj telefonu:";
		std::cin >> kto;
		dane.Dodaj_dane({ tel,1,kto });
		zapis.Save(dane, "C:/Users/Oskar/Downloads/baza.csv");
	}
}


