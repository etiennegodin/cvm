#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <tuple>
#include "../cvm 25.h"

using namespace std;

const bool MODE_TEST = true;
const int TEST = 2;

void getUserInput(int& nbOri, int& nbExe, char& formatPapier, char& typeImpression, char& typePapier, char& aPerforer, char& typeFaconnage)

{
	if (MODE_TEST)
	{
		switch (TEST)
		{

			case 1:
				nbOri = 10;
				nbExe = 10;
				formatPapier = '2';
				typeImpression = 'R';
				typePapier = '3';
				aPerforer = 'N';
				typeFaconnage = '1';
				break;

			case 2:	
				nbOri = 10;
				nbExe = 10;
				formatPapier = '2';
				typeImpression = 'R';
				typePapier = '3';
				aPerforer = 'N';
				typeFaconnage = '1';
				break;

			case 3:
				nbOri = 10;
				nbExe = 10;
				formatPapier = '2';
				typeImpression = 'R';
				typePapier = '3';
				aPerforer = 'N';
				typeFaconnage = '1';
				break;

			case 4:
				nbOri = 10;
				nbExe = 10;
				formatPapier = '2';
				typeImpression = 'R';
				typePapier = '3';
				aPerforer = 'N';
				typeFaconnage = '1';
				break;

			case 5:
				nbOri = 10;
				nbExe = 10;
				formatPapier = '2';
				typeImpression = 'R';
				typePapier = '3';
				aPerforer = 'N';
				typeFaconnage = '1';
				break;
			default:
				cout << "Mauvais test";
				break;
		}

	}
	else
	{

		/// Manual user input 

	}


}

tuple <int,int> etape1(int nbOri, int nbExe, char formatPapier, char typeImpression)
{
	// Calcul du nb de feuilles a imprimer
	int nbImpR, nbImpRV, reste;

	switch (typeImpression)
	{

		case 'R':
			if (formatPapier == '1' || formatPapier == '2')
			{	
				nbImpR = nbOri * nbExe;
				nbImpRV = 0;
				break;
			}
			else if (formatPapier == '3')
			{
				nbImpR = nbOri * nbExe / 2;
				nbImpRV = 0;
				break;
			}
			else
			{
				cout << "Mauvais formatR";
				break;
			}

		case 'V':
			if (formatPapier == '1' || formatPapier == '2')
			{
				if (nbOri % 2 != 0)
				{
					nbImpR = nbExe;
					nbImpRV = (nbOri - 1) * nbExe / 2;
					break;

				}
				else
				{
					nbImpR = 0;
					nbImpRV = nbOri * nbExe / 2;
					break;

				}
			}
			else if (formatPapier == '3')
			{
				reste = nbOri % 4;
				if (reste == 0)
				{
					nbImpR = 0;
					nbImpRV = nbOri * nbExe / 4;
					break;

				}
				else if (reste == 1 || reste == 2)
				{
					nbImpR = nbExe;
					nbImpRV = (nbOri - reste) * nbExe / 4;
					break;

				}
				else if (reste == 3)
				{
					nbImpR = 0;
					nbImpRV = (nbOri + 1) * nbExe / 4;
					break;

				}
				else cout << "Mauvaise Recto verso";
				break;

			}
			else
			{
				cout << "Mauvais formatV";
				break;

			}
	}	


	return make_tuple(nbImpR, nbImpRV);
}

tuple <double, double> etape2(int nbImp, int nbImpRV, char formatPapier)
{
	// Calcul du coût de l'impression
	const double PRIX_8x11R = 31;
	const double PRIX_8x11RV = 60;
	const double PRIX_11x17R = 61;
	const double PRIX_11x17RV = 100;
	double coutR, coutRV;
	if (formatPapier == '1' || formatPapier == '2')
	{
		coutR = (nbImp / 1000.0) * PRIX_8x11R;
		coutRV = (nbImpRV / 1000.0) * PRIX_8x11RV;

	}
	else if (formatPapier == '3')
	{
		cout << 2;

		coutR = (nbImp / 1000.0) * PRIX_11x17R;
		coutRV = (nbImpRV / 1000.0) * PRIX_11x17RV;
	}
	else cout << "Mauvaise entree pour etape 2";

	return make_tuple(coutR, coutRV);

}

double etape3(int nbImpTot, char formatPapier, char typePapier)
{
	// Calcul du coût du papier
	const double PRIX_PAPIER_1 = 20.50;
	const double PRIX_PAPIER_2 = 67.34;
	const double PRIX_PAPIER_3 = 122.94;
	double coutPapier;
	double feuillesMille = (nbImpTot / 1000.0);


	switch (typePapier)
	{

		case '1':
			coutPapier = feuillesMille * PRIX_PAPIER_1;
			break;

		case '2':
			coutPapier = feuillesMille * PRIX_PAPIER_2;
			break;

		case '3':
			coutPapier = feuillesMille * PRIX_PAPIER_3;
			break;
	}

	// Si 8.5*11
	if (formatPapier == 1)
	{
		coutPapier = (coutPapier / 2);
	}
	return coutPapier;
}

double etape4(int nbImpTot, int nbExe, char formatPapier, char aPerforer, char typeFaconnage)
{
	// Calcul du coût du façonnage du document

	const double PRIX_BROCHE = 0.03;
	const double PRIX_ENCOLLER = 0.6;
	const double PRIX_TABLETTE = 0.35;
	const double PRIX_DOSCHEVAL = 0.1;
	const double PRIX_PERFORER = 3.0;

	double coutFaconnage; 



	switch (typeFaconnage)
	{

		case '1':
			coutFaconnage = (nbExe * PRIX_BROCHE);
			break;

		case '2':
			if (formatPapier == 1 || formatPapier == 2)
			{
				coutFaconnage = (nbExe * PRIX_ENCOLLER);
			}
			break;

		case '3':
			coutFaconnage = (nbExe * PRIX_TABLETTE);
			break;

		case '4':
			if (formatPapier == 3)
			{
				coutFaconnage = (nbExe * PRIX_DOSCHEVAL);
			}
			break;

		case '5':
			break;
	}

	if (aPerforer == 'O')
	{
		coutFaconnage += (nbImpTot / 1000.0) * PRIX_PERFORER;
	}

	return coutFaconnage;
}



int main()

{
	// CONSTANTES 
	const double TPS = 0.05;
	const double TVQ = 0.09975;

	// User inputs
	int nbOri, nbExe;
	char formatPapier, typeImpression, typePapier, aPerforer, typeFaconnage;

	// Fonction pour determiner les choix de l'utilisateur
	getUserInput(nbOri, nbExe, formatPapier, typeImpression, typePapier, aPerforer, typeFaconnage);

	// Variables resultats calculs
	int nbImpR, nbImpRV, nbImpTot;
	double coutR, coutRV, coutPapier, coutFaconnage;
	double coutProduction, coutTotal;

	// Calcul du nb de feuilles a imprimer
	tie(nbImpR, nbImpRV) = etape1(nbOri, nbExe, formatPapier, typeImpression);

	// Calcul du coût de l'impression
	tie(coutR, coutRV) = etape2(nbImpR, nbImpRV, formatPapier);
	
	// Calcul intermediaire pour total feuilles 
	nbImpTot = nbImpR + nbImpRV;

	// Calcul du coût du papier
	coutPapier = etape3(nbImpTot, formatPapier, typePapier);

	// Calcul du coût du façonnage du document
	coutFaconnage = etape4(nbImpTot, nbExe, formatPapier, aPerforer, typeFaconnage);
	
	coutProduction = coutR + coutRV + coutPapier + coutFaconnage;
	coutTotal = coutProduction * (TVQ + TPS + 1);

	cout << coutR << "\n"
		<< coutRV << "\n"
		<< coutPapier << "\n"
		<< coutFaconnage << "\n"
		<< coutProduction << "\n"
		<< coutTotal << "\n";

	_getch();

	
}


/*
 void printOutput(string titre, double amount, char deviseCode)
{

	cout << setw(17) << left << titre << right << ":" << setw(15) << right << fixed << setprecision(2) << amount << " " << deviseCode << endl << "\n";
}

char getDevise(string title)

{
	char devise;
	int tab = 5;
	int col = 20;
	int choix = 30;

	cout << title << endl << endl;

	cout << setw(tab) << "" << left << setw(col) << "$ -> Dollar" << setw(tab) << "(Canada)" << endl;
	cout << setw(tab) << "" << left << setw(col) << "D -> Dollar" << setw(tab) << "(\x90tats-Unis)" << endl;
	cout << setw(tab) << "" << left << setw(col) << "E -> Euro" << setw(tab) << "(Union Europ\202enne)" << endl;
	cout << setw(tab) << "" << left << setw(col) << "B -> Baht" << setw(tab) << "(Tha\x8blande)" << endl;
	cout << setw(tab) << "" << left << setw(col) << "R -> Roupie" << setw(tab) << "(Inde)" << endl;
	cout << setw(tab) << "" << left << setw(col) << "C -> Couronne" << setw(choix) << "(Danemark)" << "Votre choix : " ;
	devise = toupper(_getch());
	cout << devise << endl << "\n";
	return devise;
}


*/