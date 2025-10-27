#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

// CONSTANTES D'AFFICHAGES
const int TAB = 10;
const int COL= 35;
const int CHOIX = 40;

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

void updateUi(vector<int> results)

{
	cout << results.size() << endl;
	/*
	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << "\n";
	}
	*/


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
		cout << nbLancers << endl;
		// nb decimale = nbExperience 
		results = rollDice(results, nbLancers);

		updateUi(results);

		cout << "cumu" << nbLancerCumulatif;


		_getch();





	}

}
