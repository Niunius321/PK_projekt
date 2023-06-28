#include "main.h"

class Dane {
private:
    std::list<std::list<std::string>> listaList;
public:
    void Dodaj(std::list<std::string> lista){
        listaList.push_back(lista);
    }
    const std::list<std::list<std::string>>& Pobierz_dane() const{
        return listaList;
    }
	void Dodaj_dane(std::tuple<int, int, std::string> lista);
	void Wczytaj_dane(const std::string& plik_wej);

};
/////////////////////////////////
class Wczytaj {
public:
	void Wczytaj_dane(Dane& dane, const std::string plik_wej);
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
	void Szukanie_tel(Dane& dane, std::string tel,int wybor);
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
    bool znalezione=false;
    
public:
	void Start(Dane& dane);
};
/////////////////////
