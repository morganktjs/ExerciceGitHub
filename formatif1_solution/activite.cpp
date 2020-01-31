#include "activite.h"

Activite::Activite()
{
	codeActivite = "";
	titre = "";
	responsable = "";
}

Activite::Activite(string aTitre, string aCodeActivite, string aResponsable)
{
	codeActivite = aCodeActivite;
	titre = aTitre;
	responsable = aResponsable;
}

void Activite::AssignerResponsable(string aResponsable)
{
	responsable = aResponsable;
}

void Activite::InitialiserActivite(string aTitre, string aCodeActivite)
{
	titre = aTitre;
	codeActivite = aCodeActivite;
}

string Activite::getTitre() const
{
	return titre;
}

string Activite::getCodeActivite() const
{
	return codeActivite;
}
string Activite::getResponsable() const
{
	return responsable;
}