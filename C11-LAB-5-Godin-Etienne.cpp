#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <tuple>
#include "../cvm 25.h"

using namespace std;

const bool MODE_TEST = true;
const int TEST = 3;


struct Inputs {
	int nbOri;
	int nbExe;
	char formatPapier;
	char typeImpression;
	char typePapier;
	char aPerforer;
	char typeFaconnage;
	int nbImpR;
	int nbImpRV;
};


struct Couts {

	double coutR;
	double coutRV;
	double coutPapier;
	double coutFaconnage;
	double coutProduction;
	double coutTotal;
};



Inputs getUserInput()

{
	Inputs temp{};
	return temp;

}


void etape1(Inputs& i)
{
	// Calcul du nb de feuilles a imprimer

	int nbImpR, nbImpRV, reste;

	switch (i.typeImpression)
	{

		case 'R':
			if (i.formatPapier == '1' || i.formatPapier == '2')
			{	
				nbImpR = i.nbOri * i.nbExe;
				nbImpRV = 0;
				break;
			}
			else if (i.formatPapier == '3')
			{
				nbImpR = i.nbOri * i.nbExe / 2;
				nbImpRV = 0;
				break;
			}
			else
			{
				cout << "Mauvais formatR";
				break;
			}

		case 'V':
			if (i.formatPapier == '1' || i.formatPapier == '2')
			{
				if (i.nbOri % 2 != 0)
				{
					nbImpR = i.nbExe;
					nbImpRV = (i.nbOri - 1) * i.nbExe / 2;
					break;

				}
				else
				{
					nbImpR = 0;
					nbImpRV = i.nbOri * i.nbExe / 2;
					break;

				}
			}
			else if (i.formatPapier == '3')
			{
				reste = i.nbOri % 4;
				if (reste == 0)
				{
					nbImpR = 0;
					nbImpRV = i.nbOri * i.nbExe / 4;
					break;

				}
				else if (reste == 1 || reste == 2)
				{
					nbImpR = i.nbExe;
					nbImpRV = (i.nbOri - reste) * i.nbExe / 4;
					break;

				}
				else if (reste == 3)
				{
					nbImpR = 0;
					nbImpRV = (i.nbOri + 1) * i.nbExe / 4;
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

	i.nbImpR = nbImpR;
	i.nbImpRV = nbImpRV;

}

void etape2(const Inputs& i, Couts& c)
{
	// Calcul du coût de l'impression
	const double PRIX_8x11R = 31;
	const double PRIX_8x11RV = 60;
	const double PRIX_11x17R = 61;
	const double PRIX_11x17RV = 100;

	double coutR, coutRV;
	if (i.formatPapier == '1' || i.formatPapier == '2')
	{
		coutR = (i.nbImpR / 1000.0) * PRIX_8x11R;
		coutRV = (i.nbImpRV / 1000.0) * PRIX_8x11RV;

	}
	else if (i.formatPapier == '3')
	{
		cout << 2;

		coutR = (i.nbImpR / 1000.0) * PRIX_11x17R;
		coutRV = (i.nbImpRV / 1000.0) * PRIX_11x17RV;
	}
	else cout << "Mauvaise entree pour etape 2";

	c.coutR = coutR;
	c.coutRV = coutRV;
}



void etape3(const Inputs& i, Couts& c)
{
	// Calcul du coût du papier
	const double PRIX_PAPIER_1 = 20.50;
	const double PRIX_PAPIER_2 = 67.34;
	const double PRIX_PAPIER_3 = 122.94;
	double coutPapier;
	double feuillesMille = ((i.nbImpR + i.nbImpRV) / 1000.0);


	switch (i.typePapier)
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
	if (i.formatPapier == 1)
	{
		coutPapier = (coutPapier / 2);
	}

	c.coutPapier = coutPapier;
}

double etape4(const Inputs& i, Couts& c)
{
	// Calcul du coût du façonnage du document

	const double PRIX_BROCHE = 0.03;
	const double PRIX_ENCOLLER = 0.6;
	const double PRIX_TABLETTE = 0.35;
	const double PRIX_DOSCHEVAL = 0.1;
	const double PRIX_PERFORER = 3.0;

	double coutFaconnage = 0 ; 

	switch (i.typeFaconnage)
	{

		case '1':
			coutFaconnage += (i.nbExe * PRIX_BROCHE);
			break;

		case '2':
			if (i.formatPapier == 1 || i.formatPapier == 2)
			{
				coutFaconnage += (i.nbExe * PRIX_ENCOLLER);
			}
			break;

		case '3':
			coutFaconnage += (i.nbExe * PRIX_TABLETTE);
			break;

		case '4':
			if (i.formatPapier == 3)
			{
				coutFaconnage += (i.nbExe * PRIX_DOSCHEVAL);
			}
			break;

		case '5':
			break;
	}

	if (i.aPerforer == 'O')
	{
		coutFaconnage += ((i.nbImpR + i.nbImpRV) / 1000.0) * PRIX_PERFORER;
	}

	c.coutFaconnage = coutFaconnage;

}

int main()

{







	
	// CONSTANTES 
	const double TPS = 0.05;
	const double TVQ = 0.09975;

	// User inputs
	Inputs test1{ 1,10,'1','R','1', 'O', '5', 0,0 };
	/*
	Inputs test2{ 10,10,'2','R','3','N', '1' };
	Inputs test3{ 10,10,'3','R','2','O', '4' };
	Inputs test4{ 9,15,'1','V','1','N', '2' };
	Inputs test5{ 9,12,'4','V','3','O', '3' };

	*/
	//Inputs userInputs;

	// 

	Couts couts;


	// Fonction pour determiner les choix de l'utilisateur
	//getUserInput(nbOri, nbExe, formatPapier, typeImpression, typePapier, aPerforer, typeFaconnage);

	// Variables resultats calculs

	int nbImpR, nbImpRV, nbImpTot;
	double coutR, coutRV, coutPapier, coutFaconnage;
	double coutProduction, coutTotal;
	cout << test1.nbImpR << " | " << test1.nbImpRV;

	etape1(test1);
	// Calcul du nb de feuilles a imprimer


	// Calcul du coût de l'impression

	
	// Calcul intermediaire pour total feuilles 


	// Calcul du coût du papier


	// Calcul du coût du façonnage du document
	
	// Calcul cout de production et total
	coutProduction = coutR + coutRV + coutPapier + coutFaconnage;
	coutTotal = coutProduction * (TVQ + TPS + 1);

	// Facture 

	cout << coutR << "\n"
		<< coutRV << "\n"
		<< coutPapier << "\n"
		<< coutFaconnage << "\n"
		<< coutProduction << "\n"
		<< coutTotal << "\n";

	_getch();
	*/

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