/*
 * Teleski.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#ifndef TELESKI_HPP_
#define TELESKI_HPP_
#include "RemonteMecanique.hpp"

class Teleski : public RemonteMecanique {
public:
	Teleski();
	virtual ~Teleski();
	int calculerTempsAttente();
	int calculerTempsTrajet();
};

#endif /* TELESKI_HPP_ */
