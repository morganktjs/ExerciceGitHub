#ifndef ACTIVITE_H 
#define ACTIVITE_H

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;

class Activite
{

	private:
		string codeActivite;
		string titre;
		string responsable;

	public: 
		Activite();
		Activite(string aTitre, string aCodeActivite, string aResponsable);
		void InitialiserActivite(string aTitre, string aCodeActivite);
		void AssignerResponsable(string aResponsable);

		string getCodeActivite() const;
		string getTitre() const;
		string getResponsable() const;
};

#endif