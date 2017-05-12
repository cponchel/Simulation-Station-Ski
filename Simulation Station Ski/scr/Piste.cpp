/*
 * Piste.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#include "Piste.hpp"


Piste::Piste(string leNom, bool ouverture, int tm, vector<Arc*> lesArcsSuivant, int niv):Arc(leNom,ouverture,tm,lesArcsSuivant) {
	niveau=niv;
}

Piste::Piste():Arc() {
	niveau = 1;
}

Piste::~Piste() {

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

int Piste::calculerTempsAttente()
{
	return 0;
}

int Piste::getNbPersonneEnAttente()
{
	return 0;
}

void Piste::setNbPersonneEnAttente(int nbPers)
{

}

bool Piste::estSature()
{
	if (getNbPersonneA()>CAPACITE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
