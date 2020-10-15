#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <chrono>

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
		std::ofstream file1("testas31.txt");
		std::ofstream file2("testas32.txt");
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

std::ofstream FR("rez.txt");		//pasirinkto hasuoti teksto rezultatas - globalus

void Spausdinimas( int h) {
	if (h < 4096) {
		while (h < 4096) {
			h = h * 13;			//pavertimas i hexadecimal
		}
	}
	char hexas[20];
	sprintf_s(hexas, "%X", h);

	FR << hexas;
}

void Hashavimas(std::vector<std::string> duomenys) {
	std::string hashas;
	unsigned long long int simb = 1, temp = 1;	//temporary

	std::chrono::steady_clock sc;	//pradedama skaiciuoti trukme
	auto start = sc.now();

	for (int y = 0; y < duomenys.size(); y++) {
		for (int i = 0; i < duomenys.at(y).length(); i++) {
			simb = simb + int(duomenys.at(y)[i]);	//paimamas vienas simbolis, paverciamas i ASCII
			simb = simb * int(duomenys.at(y)[i]) * (i + 1); //padauginamas is savo pozicijos 
			while (simb > 1000000) simb = simb / 10; //kad nepasiektu per daug, kad neiseitu s ribu dalinama
		}
		for (int i = 0; i < 16; i++) {
			while (simb < 10000000) {
				simb = simb + temp; // +int(duomenys[(duomenys.length() % temp) - 1]);
				simb = simb * temp; // *int(duomenys[(duomenys.length() % temp) - 1]);
				temp++;
			}
			if (simb % 100000 > 65535) {	//penki paskutiniai skaitmenys tikrinami (ffff)
				Spausdinimas((int)simb % 10000);
				simb = (simb - (simb / 10000)) / 10000;
			}
			else {
				Spausdinimas((int)simb % 100000);
				simb = (simb - (simb / 100000)) / 100000;
			}
		}
		std::cout << y << " eilute" << std::endl;
	}
	auto end = sc.now();
	auto time_span = static_cast<std::chrono::duration<double>>(end - start);

	std::cout << "Hashavimas truko " << time_span.count()  << " sek" << std::endl;

	std::cout << "Baigta" << std::endl;
	
	FR.close();
	//dabar konvertuojama i hexadecimal
}



std::vector<std::string> SkaitymasFailo(std::string FD) {
	std::ifstream file(FD);
	
	std::string eilute;
	std::vector<std::string> visoseil;

	while (true) {
		std::getline(file, eilute);		//skaito teksta po eilute
		visoseil.push_back(eilute);
		if (file.eof()) break;
	}

	file.close();
	return visoseil;
}

std::vector<std::string> SkaitymasRanka() {
	std::string temp;
	std::vector<std::string> duomenys;
	std::cout << "Veskite norima hashuoti teksta:";
	std::cin >> temp;
	duomenys.push_back(temp);
	return duomenys;

}

std::vector<std::string> Pasirinkimas() {
	std::vector<std::string> duomenys;	//duomenys gauti is failo
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

	else {std::cout << "Klaida - neuzhashino" << std::endl;}
	return duomenys;
}

void Lyginimas() {
	std::string file1, file2;
	std::cout << "Pirmo failo pav" << std::endl;
	std::cin >> file1;
	std::ifstream F1(file1);
	std::cout << "Antro failo pav" << std::endl;
	std::cin >> file2;
	std::ifstream F2(file2);

	int sutampa = 0;
	std::string pirmas, antras;
	F1 >> pirmas;
	F2 >> antras;
	F1.close();
	F2.close();

	for (int i = 0; i < 64; i++) {
		if (pirmas[i] == antras[i]) {
			sutampa++;
		}
	}

	std::cout << "sutampa " << sutampa << " is 64" << std::endl;
	
}

int main() {

	char atsakymas;
	std::vector<std::string> duomenys;
	GeneravimasFailuPvz();
	duomenys = Pasirinkimas();
	Hashavimas(duomenys);
	std::cout << "Ar reikalingas hashu lyginimas? T/N" << std::endl;
	std::cin >> atsakymas;
	if (atsakymas == 'T') { Lyginimas(); }

	return 0;
}

