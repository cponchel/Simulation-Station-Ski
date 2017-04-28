/*
 * Piste.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#ifndef SCR_PISTE_HPP_
#define SCR_PISTE_HPP_

#include "Arc.hpp"

class Piste : public Arc {
	int niveau;
public:
	int getNiveau();
	void setNiveau(int);
	Piste(int);
	virtual ~Piste();
	int calculerTemps(int);
};

#endif /* SCR_PISTE_HPP_ */
