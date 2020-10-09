#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>


void GeneravimasFailuPvz() {			//generuoja tik tuos du failus, kuriems reikia >1000 random simboliu, kitu ne

	std::cout << "Generuoti testus? T/N" << std::endl;
	char ats;
	std::cin >> ats;
	if (ats == 'T') {
		char charset[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',		//dalinai paimta is stack overflow
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
			for (int i = 0; i < 1005; i++) {	//kiek bus simboliu eiluteje
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

void Spausdinimas( int h) {
	if (h < 4096) {
		while (h < 4096) {
			h = h * 13;
		}
	}
	char hexas[20];
	sprintf_s(hexas, "%X", h);
	std::cout << hexas;
}

void Hashavimas(std::string duomenys) {
	std::string hashas;
	long long int simb = 1, temp = 1;

	for (int i = 0; i < duomenys.length(); i++) {
		simb = simb + int(duomenys[i]);	//paimamas vienas simbolis, paverciamas i ASCII
		simb = simb * int(duomenys[i]) * (i + 1); //padauginamas is savo pozicijos 
		while(simb > 1000000) simb = simb / 10; //pridedamas prie sumos   65535 4096
	}
	for (int i = 0; i < 16; i++) {
		while (simb < 100000) {
			simb = simb + temp;
			simb = simb * temp;
			temp++;
		}
		if (simb%100000 > 65535) {
			Spausdinimas((int)simb % 10000);
			simb = (simb - (simb / 10000)) / 10000;
		}
		else {
			Spausdinimas((int)simb % 100000);
			simb = (simb - (simb / 100000)) / 100000;
		}
	}
	

	//dabar konvertuojama i hexadecimal
}

std::string SkaitymasFailo(std::string FD) {
	std::ifstream file(FD);
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::string error;
		error = "Failas tuscias, hashavimas nevyks";
		return error;
	}
	else {
		std::string duomenys;
		std::getline(file, duomenys);
		return duomenys;
	}
	file.close();
}

std::string SkaitymasRanka() {
	std::string duomenys;
	std::cout << "Veskite norima hashuoti teksta:";
	std::cin >> duomenys;
	return duomenys;

}

std::string Pasirinkimas() {
	std::string duomenys;	//duomenys gauti is failo
	char ats;
	std::cout << "Failas ar rasymas Ranka? F/R" << std::endl;
	std::cin >> ats;
	if (ats == 'F') {
		std::string FD;
		std::cout << "Iveskite failo pavadinima:" << std::endl;
		std::cin >> FD;

		duomenys = SkaitymasFailo(FD);
	}

	else if (ats == 'R') { duomenys = SkaitymasRanka(); }

	else {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Klaida - veskite dar karta" << std::endl;
		std::cin >> ats;
	}
	return duomenys;
}



int main() {

	std::string duomenys;
	GeneravimasFailuPvz();
	duomenys = Pasirinkimas();
	Hashavimas(duomenys);


	return 0;
}

