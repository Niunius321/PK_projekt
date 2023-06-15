#pragma once
#include "main.h"

class Pobieranie {
private:
	std::vector<int> dane;

public:
	void Wczytaj_dane(const std::string& plik_wej);
	void Zapisz_dane(const std::string& plik_wej);
};
