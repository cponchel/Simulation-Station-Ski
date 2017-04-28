/*
 * Teleski.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#include "Teleski.hpp"

Teleski::Teleski() {
	// TODO Auto-generated constructor stub

}

Teleski::~Teleski() {
	// TODO Auto-generated destructor stub
}

int Teleski::calculerTempsAttente()
{
	return nbPersonneEnAttente*frequence;
}

int Teleski::calculerTempsTrajet()
{
	return getTempsMoyen();
}

