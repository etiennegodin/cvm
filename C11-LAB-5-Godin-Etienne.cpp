#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <tuple>
#include "../cvm 25.h"

using namespace std;

struct Inputs {
	int nbOri;
	int nbExe;
	char formatPapier;
	char typeImpression;
	char typePapier;
	char aPerforer;
	char typeFaconnage;
	int nbImpR = 0;
	int nbImpRV = 0;
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


	Inputs user{};

	int tab = 10;
	int col = 35;
	int choix = 40;

	char temp;

	cout <<left << setw(col) << "Nombre d'originaux" << ":";
	cin >> user.nbOri;

	cout << left << setw(col) << "Nombre d'exemplaires \x85 reproduire" << ":";
	cin >> user.nbExe;

	//Format papier
	cout << "Format du papier :" << endl
		<< setw(tab) << "" << "1. 8\xabx11" << endl
		<< setw(tab) << "" << "2. 8\xabx14" << endl
		<< setw(tab) << "" << setw(choix) << "3. 11x17" << "Votre choix : ";
	user.formatPapier = _getch();
	cout << user.formatPapier << endl << endl;

	//Type d'impression
	if (user.nbOri % 2 == 0)
	{
		cout << "Type d'impression :" << endl
			<< setw(tab) << "" << "R. recto" << endl
			<< setw(tab) << "" << setw(choix) << "V. recto - verso" << "Votre choix : ";
		user.typeImpression = toupper(_getch());
		cout << user.typeImpression << endl << endl;
	}
	else user.formatPapier = 'R';

	//Format papier
	cout << "Type de papier :" << endl
		<< setw(tab) << "" << "1. Repro + gris" << endl
		<< setw(tab) << "" << "2. Rolland \x82volution glacier" << endl
		<< setw(tab) << "" << setw(choix) << "3. Wausau royal, fibre texte \x82tain" << "Votre choix : ";
	user.typePapier = _getch();
	cout << user.typePapier << endl << endl;

	// Perforer
	cout << setw(tab+choix) << "Voulez-vous des documents perfor\x82s ? (O/N)" << "Votre choix : ";
	user.aPerforer = toupper(_getch());
	cout << user.aPerforer << endl << endl;

	// Faconnage 
	cout << "Type de fa\x87onnage:" << endl
		<< setw(tab) << "" << "1. Broche en coin" << endl
		<< setw(tab) << "" << "2. Encoller avec ruban" << endl
		<< setw(tab) << "" << "3. Tablettes" << endl
		<< setw(tab) << "" << "4. Broche \x85 dos de cheval" << endl
		<< setw(tab) << "" << "5. Encoller avec ruban" << endl
		<< setw(tab) << "" << setw(choix) << "5. Aucun" << "Votre choix : ";
	user.typeFaconnage = _getch();
	cout << user.typeFaconnage << endl << endl;

	cout << "Appuyez sur un touche pour continuer ...";
	_getch();


	return user;

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
			}
			else 
			{
				cout << "Mauvaise Recto verso";
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
	if (i.formatPapier == '1')
	{
		coutPapier = (coutPapier / 2);
	}

	c.coutPapier = coutPapier;
}

void etape4(const Inputs& i, Couts& c)
{
	// Calcul du coût du façonnage du document

	const double PRIX_BROCHE = 0.03;
	const double PRIX_ENCOLLER = 0.6;
	const double PRIX_TABLETTE = 0.35;
	const double PRIX_DOSCHEVAL = 0.1;
	const double PRIX_PERFORER = 3.0;

	double coutFaconnage ; 

	switch (i.typeFaconnage)
	{

		case '1':
			coutFaconnage = (i.nbExe * PRIX_BROCHE);
			break;

		case '2':
			if (i.formatPapier == '1' || i.formatPapier == '2')
			{
				coutFaconnage = (i.nbExe * PRIX_ENCOLLER);
			}
			break;

		case '3':
			coutFaconnage = (i.nbExe * PRIX_TABLETTE);
			break;

		case '4':
			if (i.formatPapier == '3')
			{
				coutFaconnage = (i.nbExe * PRIX_DOSCHEVAL);
			}
			break;

		case '5':
			coutFaconnage = 0;
			break;
	}

	cout << coutFaconnage;

	if (i.aPerforer == 'O')
	{
		coutFaconnage += ((i.nbImpR + i.nbImpRV) / 1000.0) * PRIX_PERFORER;
	}

	c.coutFaconnage = coutFaconnage;

}

void etape5(Couts& c)

{
	// CONSTANTES 
	const double TPS = 0.05;
	const double TVQ = 0.09975;

	// Calcul cout de production et total
	c.coutProduction = c.coutR + c.coutRV + c.coutPapier + c.coutFaconnage;
	c.coutTotal = c.coutProduction * (TVQ + TPS + 1);
}

int main()

{
	// User inputs
	Inputs test1{ 1,10,'1','R','1', 'O', '5'};
	Inputs test2{ 10,10,'2','R','3','N', '1' };
	Inputs test3{ 10,10,'3','R','2','O', '4' };
	Inputs test4{ 9,15,'1','V','1','N', '2' };
	Inputs test5{9,12,'3','V','3','O','3'};

	//Inputs userInputs;
	Inputs userInputs{getUserInput() };

	//Initilaiser resultats 
	Couts couts;

	// Calcul du nb de feuilles a imprimer
	etape1(userInputs);

	// Calcul du coût de l'impression
	etape2(userInputs, couts);

	// Calcul du coût du papier
	etape3(userInputs, couts);

	// Calcul du coût du façonnage du document
	etape4(userInputs, couts);

	// Calcul cout de production et total
	etape5(couts);

	cout << couts.coutProduction;
	
	_getch();
	
}
