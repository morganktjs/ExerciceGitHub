#include "eleve.h"
#include <conio.h>

Eleve::Eleve()
{
	codeEleve = "";
	nom = "";
	prenom = "";
	activite = NULL;
}

Eleve::Eleve(string aCodeEleve, string aNom, string aPrenom, Activite* aActivite)
{
	codeEleve = aCodeEleve;
	nom = aNom;
	prenom = aPrenom;
	activite = NULL;
}

string Eleve::getCodeEleve() const
{
	return codeEleve;
}

string Eleve::getNom() const
{
	return nom;
}

string Eleve::getPrenom() const
{
	return prenom;
}

Activite* Eleve::getActivite() const
{
	return activite;
}

void Eleve::InscrireEleve(string aCodeEleve, string aNom, string aPrenom)
{

	codeEleve = aCodeEleve;
	nom = aNom;
	prenom = aPrenom;

}

void Eleve::InscrireAUneActivite(Activite* aActivite)
{

	activite = aActivite;

}