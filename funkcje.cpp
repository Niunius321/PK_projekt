#include "main.h"

void Dane::Wczytaj_dane(const std::string& plik_wej) {
	std::ifstream plik(plik_wej);
	if (!plik) {
		std::cout << "Nie mo¿na otworzyæ pliku!" << std::endl;
	}
	else {
		std::string line;
		while (std::getline(plik, line)) {
			std::istringstream ss(line);
			std::string field;

			std::getline(ss, field, ' '); // telefon
			std::string tel = field;

			std::getline(ss, field, ' '); // ilosc wyszukan
			std::cout << field << std::endl;

			std::getline(ss, field, ' ');
			std::cout << field << std::endl;
		}
	}
}