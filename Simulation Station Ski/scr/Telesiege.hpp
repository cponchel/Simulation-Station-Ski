/*
 * Telesiege.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#ifndef TELESIEGE_HPP_
#define TELESIEGE_HPP_
#include "RemonteMecanique.hpp"


class Telesiege : public RemonteMecanique{
public:
	int capaciteSiege;
public:
	Telesiege();
	virtual ~Telesiege();
	int calculerTempsAttente();
	int calculerTempsTrajet();
};

#endif /* TELESIEGE_HPP_ */
