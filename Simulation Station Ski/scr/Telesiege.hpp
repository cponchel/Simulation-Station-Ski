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
	int static const NB_PERSONNES_SATURATION=20;
public:
	/**
	 * \fn Telesiege()
	 * constructeur par defaut de Telesiege
	 * initialise capaciteSiege a 4
	 */
	Telesiege();
	/**
	 * \fn Telesiege(int,int,int)
	 * constructeur de Telesige
	 */

	Telesiege(string, bool, int, vector <Arc*>,int,int,int);
	virtual ~Telesiege();

	int getCapaciteSiege();
	/**
	 * \fn int calculerTempsAttente()
	 * return int
	 * retourne le temps d'attente calcule en fonction du nb de personnes en attente, de la frequence et de la capcite des sieges
	 *
	 */
	int calculerTempsAttente();
	/**
	 * \fn int calculerTempsTrajet()
	 * return int
	 * retourne le tempsMoyen
	 *
	 */
	int calculerTempsTrajet();
	/**
	 * \fn bool estSature()
	 * return bool
	 * Retourne si l'arc est sature
	 */

	bool estSature();
};

#endif /* TELESIEGE_HPP_ */
