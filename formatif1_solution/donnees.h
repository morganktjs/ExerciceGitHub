#pragma once
#include "activite.h" 
#include "eleve.h" 

const int maxActivites = 10;
const int maxEleves = 25;

class Donnees
{
public:
	Activite lesActivites[maxActivites];
	Eleve lesEleves[maxEleves];
	Donnees();
};

