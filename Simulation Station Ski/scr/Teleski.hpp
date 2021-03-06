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
	int static const NB_PERSONNES_SATURATION=10;
public:
	/**
	 * \fn Teleski()
	 * constructeur par defaut de Teleski
	 */
	Teleski();
	/**
	 * \fn Teleski(int,int)
	 * constructeur de Teleski
	 */
	Teleski(string, bool, int, vector <Arc*>,int,int);
	virtual ~Teleski();
	/**
	 * \fn int calculerTempsAttente()
	 * return int
	 * retourne le temps d'attente calcule en fonction de la frequence et du nb de personnes en attentee
	 */
	int calculerTempsAttente();
	/**
	 * \fn int calculerTempsTrajet()
	 * return int
	 * retourne le temps moyen
	 */
	int calculerTempsTrajet();
	/**
	 * \fn bool estSature()
	 * return bool
	 * Retourne si l'arc est sature
	 */
	bool estSature();
};

#endif /* TELESKI_HPP_ */
