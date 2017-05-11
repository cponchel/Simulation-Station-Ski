/*
 * RemonteMecanique.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#include "RemonteMecanique.hpp"

RemonteMecanique::RemonteMecanique():Arc() {


	niveauMinPistes=1;
	frequence=1;
	nbPersonneEnAttente=0;
	// TODO Auto-generated constructor stub

}


RemonteMecanique::RemonteMecanique(string leNom, bool ouverture, int tm, vector <Arc*> lesArcsSuivant,int niv,int f):Arc(leNom,ouverture,tm,lesArcsSuivant)
{
	niveauMinPistes=niv;
	frequence=f;
	nbPersonneEnAttente=0;
}

RemonteMecanique::~RemonteMecanique() {
	// TODO Auto-generated destructor stub
}

int RemonteMecanique::getNiveau()
{
	return niveauMinPistes;
}

void RemonteMecanique::setNiveau(int niv)
{
	niveauMinPistes=niv;
}

int RemonteMecanique::getFrequence()
{
	return frequence;
}

void RemonteMecanique::setFrequence(int f)
{
	frequence=f;
}

int RemonteMecanique::getNbPersonneEnAttente()
{
	return nbPersonneEnAttente;
}

void RemonteMecanique::setNbPersonneEnAttente(int nbPers)
{
	nbPersonneEnAttente=nbPers;
}

int RemonteMecanique::getCapaciteResto()
{
	return 0;
}

int RemonteMecanique::calculerTempsAttente()
{
	return 0;
}

int RemonteMecanique::calculerTempsTrajet()
{
	return getTempsMoyen();
}
