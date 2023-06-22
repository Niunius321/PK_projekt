#include "main.h"

class Dane {
private:
	std::vector<std::tuple<int, int, std::string>> dane1;
public:
	void Dodaj_dane(std::tuple<int, int, std::string> lista);
	void Wczytaj_dane(const std::string& plik_wej);
	const std::vector<std::tuple<int, int, std::string>>& Pobierz_dane1() const {
		return dane1;
	}
};
/////////////////////////////////
class Wczytaj {
public:
	void Wczytaj_dane(Dane& dane, std::string plik_wej);
};
//////////////////////////////
class Zapis{
public:
	void Save(Dane& dane,const std::string& plik_wej);
	void Wypisz();
};
//////////////////////////////
class Baza {
public:
	void Wypisz_dane(const Dane& dane);
};
class Szukaj : private Dane{
public:
	void Szukanie_tel(Dane& dane,int tel) {
		std::vector<std::tuple<int, int, std::string>> dane1 = dane.Pobierz_dane1();
		bool znalezione = false;
		for (const auto& tuple : dane1) {
			int szukane = std::get<0>(tuple);
			if (tel == szukane) {
				znalezione = true;
				int ile = std::get<1>(tuple);
				std::string kto = std::get<2>(tuple);
				std::cout << "Znaleziono podany numer: " << tel << " " << ile << " " << kto << std::endl;
			}
		}
		if (znalezione == false) {
			std::cout << "Nie znaleziono w bazie takiego telefonu!";
		}
	}
};