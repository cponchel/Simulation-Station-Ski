/*
 * Teleski.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#include "Teleski.hpp"

Teleski::Teleski() {

}

Teleski::~Teleski() {
}

int Teleski::calculerTempsAttente()
{
	return nbPersonneEnAttente*frequence;
}

int Teleski::calculerTempsTrajet()
{
	return getTempsMoyen();
}

