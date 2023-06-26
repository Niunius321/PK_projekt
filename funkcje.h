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
class Zapis : public Dane{
public:
	void Save(const Dane& dane,const std::string& plik_wej);
};
//////////////////////////////
class Baza {
public:
	void Wypisz_dane(const Dane& dane);
};
class Szukaj{
private:
	Zapis zapis;
	int tel;
	std::string kto;
public:
	void Szukanie_tel(Dane& dane, int tel,int wybor);
};
/////////////////////
class Wybor {
private: 
	Wczytaj czyt;
	Baza baza;
	Szukaj szukaj;
	Zapis zapis;
	int wybor, tel;
	std::string kto;
public:
	void Start(Dane& dane);
};


class Dodawanie_telefonu : public Dane {
private:
	Dane dane;
	int tel;
	std::string kto;
public:
	void Dodaj();
};