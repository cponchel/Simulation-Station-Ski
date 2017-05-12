/*
 * Telesiege.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#include "Telesiege.hpp"

Telesiege::Telesiege():RemonteMecanique() {
	capaciteSiege=4;
}

Telesiege::Telesiege(string leNom, bool ouverture, int tm, vector <Arc*> lesArcsSuivant,int niv,int freq, int capSiege):RemonteMecanique(leNom,ouverture,tm,lesArcsSuivant,niv,freq)
{
	capaciteSiege=capSiege;
}

Telesiege::~Telesiege() {
	// TODO Auto-generated destructor stub
}
int Telesiege::getCapaciteSiege(){
	return capaciteSiege;
}
int Telesiege::calculerTempsAttente()
{
	return (getNbPersonneEnAttente()%getCapaciteSiege())*getFrequence()+1;
}

bool Telesiege::estSature()
{
	if(getNbPersonneA()>NB_PERSONNES_SATURATION)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*int Telesiege::calculerTempsTrajet()
{
	return getTempsMoyen();
}
*/

