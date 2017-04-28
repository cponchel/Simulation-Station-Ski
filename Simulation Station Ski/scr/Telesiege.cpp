/*
 * Telesiege.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#include "Telesiege.hpp"

Telesiege::Telesiege() {
	// TODO Auto-generated constructor stub

}

Telesiege::~Telesiege() {
	// TODO Auto-generated destructor stub
}

int Telesiege::calculerTempsAttente()
{
	return (nbPersonneEnAttente%capaciteSiege)*frequence;
}

int Telesiege::calculerTempsTrajet()
{
	return tempsMoyen;
}

