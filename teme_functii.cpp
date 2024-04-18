#include "functii_etichete.h"

void tempApropiataZero()
{
	unsigned int nr_temperaturi = 0; 
	std::vector<int> temperaturi{}; 

	std::cout << "Cea mai apropiata temperatura de zero" << std::endl;
	std::cout << "Introduce-ti numarul de temperaturi: "; 
	std::cin >> nr_temperaturi; 

	//Citim temperaturile de la utilizator
	std::cout << "Introduce-ti temperaturile" << std::endl;
	for (size_t i{}; i < nr_temperaturi; i++) {
		std::cout << "Temperatura " << i << ": "; 
		int temp{}; 
		std::cin >> temp; 
		temperaturi.push_back(temp); 
	}

	int closeToZero = temperaturi.at(0); //initializam max cu prima temperatura din vector
	for (size_t i{}; i < nr_temperaturi; i++) {
		if (temperaturi.at(i) == 0) {
			closeToZero = 0; //Daca intalnim un zerou, iesim din bucla
			break; 
		}
			 
		if (abs(closeToZero) > abs(temperaturi.at(i))) {
			closeToZero = temperaturi.at(i); //luam valoarea care este cea mai mica in modul
		}
		else if (abs(closeToZero) == abs(temperaturi.at(i))) {
			closeToZero = abs(closeToZero); //daca avem doua valori egale in modul, o luam pe cea pozitiva
		}
	}

	std::cout << "Cea mai apropiata temperatura de zero din cele introduse este : " << closeToZero << std::endl;
}


void DejaVu()
{
	std::string sir{}; 
	char caracter{}; 
	bool caracter_identic{ false }; 

	std::cout << "Tema Deja Vu" << std::endl;
	std::cout << "Introduce sirul de caractere litere: "; 
	std::getline(std::cin, sir); //citim sirul de la utilizator


	for (size_t i{}; i < sir.size(); i++) {
		if (sir.at(i) != ' ') {
			caracter = sir.at(i); //luam o litera care sa fie comparata cu restul
		}
		else {
			continue; 
		}

		for (size_t j{ i + 1 }; j < sir.size(); j++) {
			if (caracter == sir.at(j)) { //comparam litera data cu cele de dupa ea
				caracter_identic = true; 
				break;
			}
		}

		if (caracter_identic)
			break; //daca gasim un caracter identic, iesim din ciclu
	}

	if (caracter_identic) {	//afisam rezultatul
		std::cout << "Deja Vu" << std::endl;
		std::cout << "Caracterul " << caracter << " se intalneste cel putin odata." << std::endl;
	}
	else {
		std::cout << "In sirul introdus sunt doar caractere unice." << std::endl;
	}
}


void traducatorDinRoInOrc()
{
	std::string text{}; 

	std::cout << "Traducator din limba romana in limba orca" << std::endl << std::endl;
	std::cout << "Text in limba romana: ";

	std::getline(std::cin, text); 
	
	size_t index{}, inceput_cuvant{};
	std::string cuvant{}; 
	bool inceput_cuvant_flag{ true }, sfarsit_cuvant_flag{ false };

	while (index < text.size()) {

		if (text.at(index) == ' ') { //ignora spatii sau semne de punctuatie
			if (cuvant.empty()) {	 //ce pot fi inaintea textului intreg
				index++;
				continue;
			}
		} else if (std::ispunct(text.at(index))) {
				index++;
				continue;
		}

		if (std::isalpha(text.at(index))) { //daca caracterul curent este o litera il anexam sirului cuvant
			cuvant += text.at(index);
			if (inceput_cuvant_flag) {
				inceput_cuvant_flag = false;
				inceput_cuvant = index;
			}
		}

		if ((index + 1) == text.size()) { //daca urmatorul index nu face parte din sir, incepem traducerea cuvantului
			sfarsit_cuvant_flag = true;
		} else if (std::ispunct(text.at(index + 1)) || text.at(index + 1) == ' ') { //daca urmatorul caracter este semn de punctuatie
			sfarsit_cuvant_flag = true;												//sau este spatiu gol, incepem traducerea cuvantului
		} 



		if (sfarsit_cuvant_flag) { //cand cuvantul este complet, incepem traducerea lui
			//Traducem cuvantul
			char prima_litera = cuvant.at(0);

			for (size_t i{}; i < cuvant.size() - 1; i++) {
				cuvant.at(i) = cuvant.at(i + 1); //mutam literele cu un index in spate
			}

			if (std::isupper(prima_litera)) { //daca prima_litera este majuscula, atunci litera cu index 0 va fi transformata in majuscula
				prima_litera = std::tolower(prima_litera); 
				cuvant.at(0) = std::toupper(cuvant.at(0));
			}

			cuvant.at(cuvant.size() - 1) = prima_litera;
			cuvant += "ay"; //adaugam terminatia "ay"

			text.replace(inceput_cuvant, index - inceput_cuvant + 1, cuvant); //inlocuim cuvantul tradus in locul cuvantului intial

			index += 4; //incrementam cu o unitate, ingnoram "ay" si posibile spatii sau semne de punctuatie
			cuvant.clear(); 
			inceput_cuvant_flag = true; //resetam variabilele
			sfarsit_cuvant_flag = false;

		}
		else {
			index++;
		}
	}
	std::cout << std::endl;
	std::cout << "Text in limba orca: " << text << std::endl;

}