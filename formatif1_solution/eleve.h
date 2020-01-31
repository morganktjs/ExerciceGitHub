#ifndef EleveH 
#define EleveH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include "activite.h"
using namespace std;

class Eleve
{

private:
	string codeEleve;
	string nom;
	string prenom;
	Activite* activite;

public:
	Eleve();
	Eleve(string aCodeEleve, string aNom, string aPrenom, Activite* aActivite);

	string getCodeEleve() const;
	string getNom() const;
	string getPrenom() const;
	Activite* getActivite() const;

	void InscrireEleve(string aCodeEleve, string aNom, string aPrenom);
	void InscrireAUneActivite(Activite * aActivite);
};

#endif

