#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
using namespace std;

class Pacient
{
public:
	Pacient(std::string Nume, std::string Prenume, int Varsta);
	~Pacient();

	std::string Nume; // Numele pacientului
	std::string Prenume;
	int varsta; // Varsta pacientului
	int numarDeRetete; //Numar de retete date pacientului
	std::string Statut; // Status pacient tanar, varstnic;
	std::string domeniuDeLucru; // Domeniul in care lucreaza pacientu;
	std::vector<std::string> boliPacient; // un vector cu bolile pe care pacientul le detine;
	std::vector<std::string> tratamentPacient; // un vector cu tratamentele pacientului

	void PacientInfo();
	void SchimbareVarsta();
	void SchimbareDomeniuLucru();
	void SchimbareNumarRetete();
	void AddBoala(vector<string> & BoliCunoscute);
	void AddTratament(vector<string> & Tratamente);

};

