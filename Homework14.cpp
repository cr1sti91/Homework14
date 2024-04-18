#include <iostream>
#include "functii_etichete.h"

int main()
{
	std::cout << "Tema pe acasa:" << std::endl;
	const std::string optiuni_intrare{ R"(
			1.Tema temperatura cea mai apropiata de zero
			2.Tema Deja Vu
			3.Tema traducere din limba romana in orca
	)" };

	//Afisam optiunile posibile
	std::cout << "Optiuni:" << std::endl << optiuni_intrare << std::endl;

	//Citim optiunea necesara de la tastatura
	std::cout << "Introduce numarul din dreptul optiunii necesare: ";
	short optiune{};
	std::cin >> optiune;
	std::cin.ignore();
	std::cout << std::endl;

	//Executam functia ce corespunde optiunei introduse
	switch (optiune)
	{
	case 1: tempApropiataZero();
		break;
	case 2: DejaVu();
		break;
	case 3: traducatorDinRoInOrc();
		break;
	default: std::cout << "Optiune incorecta!" << std::endl;
	}
}

