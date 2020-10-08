#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void GeneravimasFailuPvz() {			//generuoja tik tuos du failus, kuriems reikia >1000 random simboliu, kitu ne

	std::cout << "Generuoti testus? T/N" << std::endl;
	char ats;
	if (ats == 'T') {
		char charset[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N','O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		'Z', 'a', 'b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o','p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
		std::ofstream file1("testas21.txt");
		std::ofstream file2("testas22.txt");
		int ran;
		srand(time(NULL));
		for (int y = 0; y < 1; y++)	//kiek bus eiluciu
		{
			for (int i = 0; i < 1005; i++){	//kiek bus simboliu eiluteje
				ran = std::round(0 + (double)rand() / RAND_MAX * (62 - 1)); // 62 simboliai 
				file1 << charset[ran];
				ran = std::round(0 + (double)rand() / RAND_MAX * (62 - 1));
				file2 << charset[ran];
			}
			file1 << std::endl;
			file2 << std::endl;
		}
		file1.close();
		file2.close();
		std::cout << "Sugeneruota" << std::endl;
	}

	else if (ats == 'N') {
		std::cout << "Nesugeneruota" << std::endl;
	}

	else {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Klaida - veskite dar karta" << std::endl;
		std::cin >> ats;
	}

}


void Pasirinkimas() {
	char ats;
	std::cout << "Failas ar rasymas Ranka? F/R" << std::endl;
	std::cin >> ats;
	if (ats == 'F') {
		std::string FD;
		std::cout << "Iveskite failo pavadinima:" << std::endl;
		std::cin >> FD;
		SkaitymasFailo(FD);
	}

	else if (ats == 'R') { SkaitymasRanka(); }

	else {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Klaida - veskite dar karta" << std::endl;
		std::cin >> ats;
	}

}

std::string SkaitymasFailo(std::string FD) {

	std::string duomenys;
	std::ifstream file;
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Failas tuscias, hashavimas nevyks" << std::endl;
	}
	else {
		file.open(FD);
		while (!file.eof()) { std::getline(file, duomenys); }
		file.close();
	}
}

std::string SkaitymasRanka() {
	std::string ats;
	std::cout << "Veskite norima hashuoti teksta:";
	std::cin >> ats;
	Hashavimas(ats);

}

std::string Hashavimas(std::string tekstas) {



}


int main() {

	GeneravimasFailuPvz();
	Pasirinkimas();


	return 0;
}

