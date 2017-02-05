#include <iostream>
#include <vector>
#include <string>
#include "Pacient.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

int generareNumar(int deLa, int panaLa) {
	return rand() % panaLa + deLa;
}

int main() {
	srand(time(NULL) * rand() % 100 + 1); // generare seed pentru random;
	vector<Pacient> pacienti;
	vector<string> BoliCunoscute = { "fetopatie", "diabet", "gripa", "paradontoza"};
	vector<string> Tratamente = { "Aquarion", "Rhodiolin", "Oregano", "Omega" };
	vector<string> numeDePacienti = { "Popescu", "Grigore", "Jifcu", "Toma", "Sandulescu", "Elerian", "Stan" };
	vector<string> prenumeDePacienti = { "Stefan", "Alin", "Bogdan", "Radu", "Iulian", "Ionut", "Albert", "Nicolae", "Stefan", "Gicu" };

	int choice;
	bool appOn = true;
	while (appOn) {
		system("CLS");
		try {
			cout << "\n\n\t\t\t Pacienti \n\n";
			cout << "1. Generare pacienti\n";
			cout << "2. Editare pacient\n";
			cout << "3. Determinarea numarului de pacienti care sufera de o anumita boala : \n";
			cout << "4. Afisarea pacientilor care au acelasi tratament : \n";
			cout << "5. Afisarea pacientilor cu un numar de retete peste un numar dat : \n";
			cout << "6. Determinarea numarului de medicamente prescrise de tipul : \n";
			cout << "7. Determinarea numarului de pacienti dintr-un anumit domeniu : \n";
			cout << "8. Show pacients \n";
			cout << "9. Exit\n";
			cout << "\n Your choice :";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "Introduceti numarul de pacienti : ";
				int nrPacienti;
				std::cin >> nrPacienti;
				while (nrPacienti) {
					Pacient *pacient = new Pacient(numeDePacienti[generareNumar(0, numeDePacienti.size())], prenumeDePacienti[generareNumar(0, prenumeDePacienti.size())], generareNumar(1, 80));
					pacienti.push_back(*pacient);
					nrPacienti--;
				}
				break;
			}
			case 2: {
				if (pacienti.size() == 0)
					throw "Lista cu pacienti este goala";
				system("CLS");
				cout << "Introduceti numarul pacientului :";
				int index;
				std::cin >> index;
				pacienti[index - 1].PacientInfo();
				cout << "Ce doriti sa modificati : ";
				int modif;
				std::cin >> modif;
				switch (modif)
				{
				case 1: {
					pacienti[index - 1].SchimbareVarsta();
					Sleep(3000);
					break;
				case 2:
					pacienti[index - 1].SchimbareDomeniuLucru();
					break;
				case 3:
					pacienti[index - 1].SchimbareNumarRetete();
					break;
				case 4:
					pacienti[index - 1].AddBoala(BoliCunoscute);
					break;
				case 5:
					pacienti[index - 1].AddTratament(Tratamente);
					break;
				default:
					break;
				}
						break;
				}
			}
			case 3: {
				cout << "Bolile cunoscute sunt : ";
				for (auto it : BoliCunoscute)
					cout << it << " ";
				cout << endl;
				cout << "\nIntroduceti boala :";
				string boala;
				cin >> boala;
				for (auto it : pacienti)
					for (auto itBoala : it.boliPacient)
						if (itBoala == boala)
							cout << it.Nume << "-" << it.Prenume << endl;
				system("pause");
			}
					break;
			case 4:
				for (auto tratamente : Tratamente) {
					cout << "Tratament : " << tratamente << endl;
					for (auto itPacient : pacienti) {
						for (auto tratamentPacient : itPacient.tratamentPacient) {
							if (tratamente == tratamentPacient) {
								cout << itPacient.Nume << "-" << itPacient.Prenume << ", ";
							}
						}
					}
					cout << endl;
					system("pause");
					cout << endl << endl;
				}
				break;
			case 5: {
				cout << "Introduceti numarul de retete : ";
				int nrRetete;
				cin >> nrRetete;
				cout << "Pacienti cu numar de retete peste numarul dat : ";
				for (auto it : pacienti)
					if (it.numarDeRetete > nrRetete)
						cout << it.Nume << "-" << it.Prenume << ", ";
				cout << endl;
				system("pause");
			}
					break;
			case 6: {
				int counterMedicamente = 0;
				for (auto tratamente : Tratamente) {
					cout << "Medicamente : " << tratamente << endl;
					for (auto itPacient : pacienti) {
						for (auto tratamentPacient : itPacient.tratamentPacient) {
							if (tratamente == tratamentPacient) {
								counterMedicamente++;
							}
						}
					}
					cout << counterMedicamente;
					counterMedicamente = 0;
					cout << endl << endl;
				}
				system("pause");
			}
					break;
			case 7: {
				cout << "Introduceti domeniul :";
				string domeniu;
				cin >> domeniu;
				cout << "Pacienti in domeniul introdus : ";
				for (auto it : pacienti) {
					if (it.domeniuDeLucru == domeniu)
						cout << it.Nume << "-" << it.Prenume;
				}
				cout << endl;
				system("pause");
			}
					break;
			case 8: {
				cout << "Pacienti inscrisi : \n";
				for (int i = 0; i < pacienti.size(); i++) {
					cout << i + 1 << ". " << pacienti[i].Nume << "-" << pacienti[i].Prenume << " " << pacienti[i].varsta << endl;
				}
				system("pause");
			}
					break;
			case 9:
				appOn = false;
				break;
			default:
				break;
			}
		}
		catch (const char * msg) {
			cout << msg << endl;
		}
	}

	
	system("PAUSE");
}