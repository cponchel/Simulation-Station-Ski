/*
 * LieuRestauration.h
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#ifndef SCR_LIEURESTAURATION_HPP_
#define SCR_LIEURESTAURATION_HPP_

#include <cstdlib>
#include "Arc.hpp"
/**
 * \class LieuRestauration
 * \brief
 * \author Clementine Chevalier
 * \version 1.0
 * \date avril 2017
 */

class LieuRestauration : public Arc{
	int capaciteResto;
public:
	/**
	* \fn LieuRestauration()
	* Constructeur par defaut de LieuRestauration
	*/
	LieuRestauration();
	/**
	 * \fn LieuRestauration(int)
	 * Constructeur LieuRestauration
	 * initialise la capacite maximale du LieuRestauration
	 */
	LieuRestauration(string,bool,int,vector<Arc*>,int);
	virtual ~LieuRestauration();
	/**
	 * \fn getCapaciteResto()
	 * return int
	 * Retourne la capacite maximale du LieuRestauration
	 */
	int getCapaciteResto();
	/**
	 * \fn setCapaciteResto
	 * modifie la valeur capaciteResto
	 */
	//void setCapaciteResto(int);
	/**
	 * \fn int calculerTempsTrajet()
	 * return int
	 * calcule temps de trajt en renvoyant un nombre aleatoire entre 10 et 40 min
	 */
	int calculerTempsTrajet();
	/**
	 * \fn int calculerTempsAttente
	 * return int
	 * renvoie 0 car si LieuRestauration complet le skieur fait une piste
	 */
	int calculerTempsAttente();

	int getNbPersonneEnAttente();
};

#endif /* SCR_LIEURESTAURATION_HPP_ */
