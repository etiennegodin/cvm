#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include "../../cvm 25.h"
using namespace std;

// CONSTANTES D'AFFICHAGES
const int col1 = 10;
const int col2= 15;
const int col3 = 15;

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

	clrscr();

	//Titre
	cout << "Exp\x82rience al\202atoire avec " << setprecision(0) << size << " lancer" << (size == 1 ? "" : "s")<< endl << endl;
	//Titre tableau
	cout << setw(col1) << right << "Face" << setw(col2) << "Fr\x82quence" << setw(col3) << "Distribution"<< endl << endl;
	// Donnees
	for (int i = 0; i < freq.size(); i++)
	{
		cout << setw(col1-1) << right << "Face " << (i+1) << setw(col2) << freq.at(i) << setw(col3 - 2.0) << setprecision(2) << fixed << ((freq.at(i) / size) * 100) << " %" << endl;
	}
	cout << setw(col1) << "" << setw(col2) << "--------" << setw(col3) << "--------"<< endl;
	cout << setfill(' ') << setw(col1) << right << "" << setw(col2) << setprecision(0) << size << setw(col3 - 2.0) << setprecision(2) << fixed << 100.00 << " %" <<endl << endl;

	// Cumul
	cout << "Statistiques cumulatives apres " << nbExperience << " exp\x82rience" << (nbExperience == 1 ? "" : "s")
		<< endl << endl;
	cout << " ===> " << nbLancerCumulatif << " lancer" << (nbLancerCumulatif == 1 ? "" : "s")
		<< endl << endl;
	cout << "\n\n\n\n\n";
	if (nbExperience < 7) _getch();
	else cout << " A U  R E V O I R  !";
	cout << endl;
}

int main()
{
	int nbExperience = 7;
	int nbLancers = 0;
	int nbLancerCumulatif = 0;

	for (int i = 0; i < nbExperience; i++)
	{
		vector <int> results;
		if (nbLancers < 1) nbLancers = 1;
		else nbLancers = (pow(10, i));

		nbLancerCumulatif = nbLancerCumulatif + nbLancers;
		results = rollDice(results, nbLancers);
		updateUi(results, nbLancerCumulatif, i+1);
	}
}