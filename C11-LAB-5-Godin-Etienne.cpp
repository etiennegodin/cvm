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
			}
			else if (formatPapier == '3')
			{
				nbImpR = nbOri * nbExe / 2;
				nbImpRV = 0;
			}
			else
			{
				cout << "Mauvais formatR";
			}

		case 'V':
			if (formatPapier == '1' || formatPapier == '2')
			{
				if (nbOri % 2 != 0)
				{
					nbImpR = nbExe;
					nbImpRV = (nbOri - 1) * nbExe / 2;
				}
				else
				{
					nbImpR = 0;
					nbImpRV = nbOri * nbExe / 2;
				}
			}
			else if (formatPapier == '3')
			{
				reste = nbOri % 4;
				if (reste == 0)
				{
					nbImpR = 0;
					nbImpRV = nbOri * nbExe / 4;
				}
				else if (reste == 1 || reste == 2)
				{
					nbImpR = nbExe;
					nbImpRV = (nbOri - reste) * nbExe / 4;
				}
				else if (reste == 3)
				{
					nbImpR = 0;
					nbImpRV = (nbOri + 1) * nbExe / 4;
				}
				else cout << "Mauvaise Recto verso";

			
			}
			else
			{
				cout << "Mauvais formatV";
			}
	}	


	return make_tuple(nbImpR, nbImpRV);
}

/*
double etape2()
{
	// Calcul du coût de l'impression
	const double PRIX_8x11R = 31;
	const double PRIX_8x11RV = 60;
	const double PRIX_11x17R = 61;
	const double PRIX_11x17RV = 100;

	double coutR, coutRV;




}

double etape3()
{
	// Calcul du coût du papier
	char typePapier;
	const double PRIX_PAPIER_1 = 20.50;
	const double PRIX_PAPIER_2 = 67.34;
	const double PRIX_PAPIER_3 = 122.94;

	double coutPapier;



}

double etape4()
{
	// Calcul du coût du façonnage du document

	char aPerforer, typeFaconnage;
	const double PRIX_BROCHE = 0.03;
	const double PRIX_ENCOLLER = 0.6;
	const double PRIX_TABLETTE = 0.35;
	const double PRIX_DOSCHEVAL = 0.1;
	const double PRIX_PERFORER = 3.0;
	double coutFaconnage; 


}

double etape5()
{
	// Calcul des taxes et du coût total



}
*/

int main()

{
	int nbOri, nbExe;
	char formatPapier, typeImpression, typePapier, aPerforer, typeFaconnage;

	//etape1 


	getUserInput(nbOri, nbExe, formatPapier, typeImpression, typePapier, aPerforer, typeFaconnage);

	int nbImpR, nbImpRV;

	tie(nbImpR, nbImpRV) = etape1(nbOri, nbExe, formatPapier, typeImpression);

	/*
	cout << nbOri << "\n"
		<< nbExe << "\n"
		<< formatPapier << "\n"
		<< typeImpression << "\n"
		<< typePapier << "\n"
		<< aPerforer << "\n"
		<< typeFaconnage << "\n";
	*/


	
	cout << nbImpR << "\n"
		<< nbImpRV << "\n";
	


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