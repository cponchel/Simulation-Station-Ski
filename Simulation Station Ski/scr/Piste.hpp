/*
 * Piste.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#ifndef SCR_PISTE_HPP_
#define SCR_PISTE_HPP_

#include "Arc.hpp"
#include "cstdlib"
/**
 * \class LieuRestauration
 * \brief
 * \author Clementine Chevalier
 * \version 1.0
 * \date avril 2017
 */

class Piste : public Arc {
	int niveau;
public:
	/**
	 * \Piste()
	 * constructeur par defaut de Piste
	 */
	Piste();
	/**
	 * Piste(int)
	 * Constructeur de Piste
	 * initialise le niveau de la Piste
	 */
	Piste(string,bool,int,vector<Arc*>,int);
	/**
	 * \fn int getNiveau()
	 * return int
	 * retourne le niveau de la piste
	 */
	int getNiveau();
	/**
	 * \fn void setNiveau(int)
	 * modifie la valeur du niveau de la piste
	 */
	void setNiveau(int);
	virtual ~Piste();
	/**
	 * \fn int calculerTempsTrajet
	 * return int
	 * calcule le temps de trajet du skieur pour finir la piste en fonction du temps moyen de la piste et du niveau du skieur
	 */

	int calculerTempsTrajet(int);
	/**
	 * \fn int calculerTempsAttente()
	 * return int
	 * renvoie 0 car temps attente pour une piste est nul
	 */
	int calculerTempsAttente();

	int getNbPersonneEnAttente();

	void setNbPersonneEnAttente(int);

};

#endif /* SCR_PISTE_HPP_ */
