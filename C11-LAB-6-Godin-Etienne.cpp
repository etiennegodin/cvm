#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <../cvm 25.h>

using namespace std;

// CONSTANTES D'AFFICHAGES
const int col1 = 10;
const int col2= 15;
const int col3 = 15;
const int colspace = 3;

using namespace std;

/*
void afficherFacture(const Couts& couts)

{
	clrscr();

	cout << endl << endl << "FACTURE" << endl << endl;

	cout << setw(3) << "" << setw(CHOIX) << left << "Co\x96t des impressions recto :" << setw(10) << right << fixed << setprecision(2) << couts.coutR << " $" << endl;
	cout << setw(3) << "" << setw(CHOIX) << left << "Co\x96t des impressions recto-verso :" << setw(10) << right << fixed << setprecision(2) << couts.coutRV << " $" << endl
		<< endl;

	cout << setw(3) << "" << setw(CHOIX) << left << "Co\x96t du papier :" << setw(10) << right << fixed << setprecision(2) << couts.coutPapier << " $" << endl;
	cout << setw(3) << "" << setw(CHOIX) << left << "Co\x96t du fa\x87onnage :" << setw(10) << right << fixed << setprecision(2) << couts.coutFaconnage << " $" << endl;
	cout << setw(3) << "" << setw(CHOIX) << "" << right << "------------" << endl << endl;

	cout << setw(3) << "" << setw(CHOIX) << left << "Co\x96t de production :" << setw(10) << right << fixed << setprecision(2) << couts.coutProduction << " $" << endl;
	cout << setw(3) << "" << setw(CHOIX) << "" << right << "============" << endl << endl;


	cout << setw(CHOIX + 3) << left << "Co\x96t total :" << setw(10) << right << fixed << setprecision(2) << couts.coutTotal << " $" << endl;

}

*/

vector <int> rollDice(vector<int> results,int n)
{

	int imin = 1;
	int imax = 6;

	srand(time(0));

	for (int i = 0; i < n; i++)
		results.push_back(rand() % (imax - imin + 1) + imin);

	return results;
}

void updateUi(vector<int> results, int nbLancerCumulatif, int nbExperience)

{
	vector <int> freq = { 0,0,0,0,0,0 };

	double size = results.size();

	int valeurFace;
	for (int i = 0; i < size; i++) 
	{
		valeurFace = results.at(i);
		switch(valeurFace)
		{

			case 1:
				freq.at(0) += 1;
				break;
			case 2:
				freq.at(1) += 1;
				break;
			case 3:
				freq.at(2) += 1;
				break;
			case 4:
				freq.at(3) += 1;
				break;
			case 5:
				freq.at(4) += 1;
				break;
			case 6:
				freq.at(5) += 1;
				break;

		}

	}

	//Titre
	cout << "Experience aleatoire avec " << setprecision(0) << size << " lancer" << (size == 1 ? "" : "s")
		<< endl << endl;
	//Titre tableau
	cout << setw(col1) << right << "Face" << setw(col2) << "Frequence" << setw(col3) << "Distribution"
		<< endl
		<< endl;
	// Donnes
	for (int i = 0; i < freq.size(); i++)
	{

		cout << setw(col1-1) << right << "Face " << (i+1) << setw(col2) << freq.at(i) << setw(col3 - 2.0) << setprecision(2) << fixed << ((freq.at(i) / size) * 100) << " %" << endl;

	}

	cout << setw(col1) << "" << setw(col2) << "--------" << setw(col3) << "--------"
		<< endl << endl;

	cout << setfill(' ') << setw(col1) << right << "" << setw(col2) << size << setw(col3 - 2.0) << setprecision(2) << fixed << 100.00 << " %" << endl;

	// Cumul

	cout << "Statistiques cumulatives apres " << nbExperience << " experience" << (nbExperience == 1 ? "" : "s")
		<< endl << endl;
	cout << " ===> " << nbLancerCumulatif << " lancer" << (nbLancerCumulatif == 1 ? "" : "s")
		<< endl << endl;

}

int main()

{

	int nbExperience = 7;
	int nbLancers = 0;
	int nbLancerCumulatif = 0;

	for (int i = 0; i < nbExperience; i++)
	{
		vector <int> results;

		if (nbLancers < 1)
		{
			nbLancers = 1;
		}
		else
		{
			nbLancers = (pow(10, i));
		}

		nbLancerCumulatif = nbLancerCumulatif + nbLancers;
		results = rollDice(results, nbLancers);

		updateUi(results, nbLancerCumulatif, i+1);

		_getch();





	}

}
