#include "Pacient.h"

Pacient::Pacient(std::string Nume, std::string Prenume, int Varsta)
{
	if (Varsta < 50)
		Statut = "tanar";
	else
		Statut = "batran";
	this->Nume = Nume;
	this->varsta = Varsta;
	this->Prenume = Prenume;
}

Pacient::~Pacient()
{
}

void Pacient::PacientInfo()
{
	cout << "Pacientul este : " << Nume << "-" << Prenume << endl;
	cout << "1.Varsta : " << varsta << ", ";
	cout << "Statut : " <<Statut << endl;
	cout << "2.Domeniu de lucru : " << domeniuDeLucru << endl;
	cout << "3.Retete prescrise : " << numarDeRetete << endl;
	cout << "4.Boli pacient : ";
	for (auto it :boliPacient)
		cout << it << " ";
	cout << endl;
	cout << "5.Tratamente, retete : ";
	for (auto it : tratamentPacient)
		cout << it << " ";
	cout << endl;
}

void Pacient::SchimbareVarsta()
{
	cout << "Modificati varsta pacientului " << Nume << " : ";
	int varsta;
	cin >> varsta;
	if (varsta < 0)
		throw "Varsta nu poate fi negativa !";
	if (varsta < 50)
		Statut = "tanar";
	else
		Statut = "batran";
	cout << "Varsta a fost modificata !";
}

void Pacient::SchimbareDomeniuLucru()
{
	cout << "Modificati domeniul de lucru al pacientului " << Nume << " : ";
	cin >> domeniuDeLucru;
	cout << "Domeniul de lucru a fost schimbat !\n";
	Sleep(3000);
}

void Pacient::SchimbareNumarRetete()
{
	cout << "Numarul total de retete prescrise pentru pacient : ";
	cin >> numarDeRetete;
	cout << "Numarul de retete a fost schimbat!\n";
}

void Pacient::AddBoala(vector<string> & BoliCunoscute)
{
	cout << "Introduceti o boala noua pentru pacient";
	cout << "Bolile cunoscute sunt : ";
	for (auto it : BoliCunoscute)
		cout << it << " ";
	cout << "\nIntroduceti boala :";
	string boala;
	cin >> boala;
	boliPacient.push_back(boala);
}

void Pacient::AddTratament(vector<string>& Tratamente)
{
	cout << "Introduceti un tratament nou pentru pacient";
	cout << "Tratamente cunoscute sunt : ";
	for (auto it : Tratamente)
		cout << it << ", ";
	cout << "\nIntroduceti tratamentul :";
	string tratament;
	cin >> tratament;
	tratamentPacient.push_back(tratament);
}
