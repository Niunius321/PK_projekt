#include "main.h"

class Dane {
private: 
	std::list<std::list<std::string>> dane;
public:
	void Dodaj_dane( std::list<std::string> lista) {
		dane.push_back(lista);
	}
	void Wypisz() {
		for (const auto lista : dane) {
			for (const auto element : lista) {
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
	}
};
class Pobieranie{
private:
	Dane dane;
public:
	void Wczytaj_dane(const std::string& plik_wej);

};
class Zapis {
public:
	void Zapisz_dane(const std::string& plik_wej);
};
