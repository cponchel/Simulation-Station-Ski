/*
 * Piste.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#include "Piste.hpp"
#include "cstdlib"

Piste::Piste(int niv) {
	niveau=niv;
	// TODO Auto-generated constructor stub
}

Piste::~Piste() {
	// TODO Auto-generated destructor stub
}

int Piste::getNiveau(){
	return niveau;
}

void Piste::setNiveau(int niv){
	niveau=niv;
}

int Piste::calculerTempsTrajet(int niveauSkieur) //calculer temps en fonction du niveau
{
	if(niveauSkieur==2)
	{
		return 2*getTempsMoyen()+rand()%80;
	}
	else if(niveauSkieur==3)
	{
		return (3*getTempsMoyen())/2+rand()%80;
	}
	else if(niveauSkieur==4)
	{
		return (6*getTempsMoyen())/5+rand()%80;
	}
	else
	{
		return getTempsMoyen()+rand()%80;
	}
}
