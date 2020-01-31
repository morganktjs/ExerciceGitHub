#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;

#include "activite.h" 
#include "eleve.h" 

const int maxActivites = 10;
const int maxEleves = 25;

Activite lesActivites[maxActivites];
Eleve lesEleves[maxEleves];

int nombreActivitesReelles = 0;
int nombreElevesReels = 0;

char AfficherMenu();
//partie 1
void AjouterActivite();
void AfficherLesActivites();
void Afficher(Activite inActivite);

//partie 2
void AjouterLesEleves();
void AfficherLesEleves();
void InscrireUnEleve(string, string, string);
void Afficher(Eleve inEleve);

//partie 3
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();


int main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': AfficherLesActivites();
			break;
		case '3': AjouterLesEleves();
			break;
		case '4': AfficherLesEleves();
			break;
		case '5': InscrireEleveActivite();
			break;
		case '6': AfficherLesInscriptions();
			break;
		}
	}
}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une activite";
	Gotoxy(15, 6);
	cout << "2- Afficher toutes les activites";
	Gotoxy(15, 8);
	cout << "3- Ajouter des eleves";
	Gotoxy(15, 10);
	cout << "4- Afficher les eleves";
	Gotoxy(15, 12);
	cout << "5- Inscrire un eleve a une activite";
	Gotoxy(15, 14);
	cout << "6- Afficher les inscriptions d'une activite";
	Gotoxy(15, 16);
	cout << "0- Arreter";
	Gotoxy(15, 18);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code;
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivitesReelles comme indice pour le tableau

	lesActivites[nombreActivitesReelles].InitialiserActivite(titre, code);
	lesActivites[nombreActivitesReelles].AssignerResponsable(responsable);
	nombreActivitesReelles++;
}

//----------------------------------------------------------------------------------------
void AfficherLesActivites()
{
	ClrScr();

	for (int i = 0; i < nombreActivitesReelles; i++)
	{
		Afficher(lesActivites[i]);
	}

	_getch();
}
//----------------------------------------------------------------------------------------
void Afficher(Activite inActivite)
{
	cout << "Le code de l'activite est " << inActivite.getCodeActivite() << ", le titre est " << inActivite.getTitre() << " et le responsable est " << inActivite.getResponsable() << "\n";
}
//----------------------------------------------------------------------------------------
void Afficher(Eleve inEleve)
{
	cout << "Le code de l'eleve est " << inEleve.getCodeEleve() << ", son nom est " << inEleve.getNom() << " et son prenom est " << inEleve.getPrenom() << "\n";
}
//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");
}

//----------------------------------------------------------------------------------------
void AfficherLesEleves()
{
	ClrScr();

	for (int i = 0; i < nombreElevesReels; i++)
	{
		Afficher(lesEleves[i]);
	}

	_getch();
}
//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{
	lesEleves[nombreElevesReels].InscrireEleve(inCode, inNom, inPrenom);
	nombreElevesReels++;
}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	cout << "Activite desiree: ";
	cin >> activite;
	cptActivite = RechercherActivite(activite);

	if (cptEleve != maxEleves && cptActivite != maxActivites)
	{
		Afficher(lesEleves[cptEleve]);
		Afficher(lesActivites[cptActivite]);
		lesEleves[cptEleve].InscrireAUneActivite(&lesActivites[cptActivite]);
	}
	else
	{
		cout << "L'eleve ou l'activite n'existe pas";
	}

	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int cptEleve = 0;
	bool trouve = false;
	while (trouve == false && cptEleve < maxEleves)
	{
		if (lesEleves[cptEleve].getCodeEleve() == inCodeVoulu)
		{
			trouve = true;
		}
		else
		{
			cptEleve++;
		}
	}
	return cptEleve;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	bool trouve = false;
	int cptActivite = 0;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{

		if (lesActivites[cptActivite].getCodeActivite() == inCodeActiviteVoulue)
		{
			trouve = true;
		}
		else
		{
			cptActivite++;
		}
	}
	return cptActivite;
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	string activite;
	int cptEleve = 0;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;

	while (cptEleve < maxEleves/*nombreActivites*/)
	{
		if (lesEleves[cptEleve].getActivite() != NULL)
		{
			if (lesEleves[cptEleve].getActivite()->getCodeActivite() == activite)
			{
				Afficher(lesEleves[cptEleve]);
			}
		}

		cptEleve++;
	}

	_getch();
}







