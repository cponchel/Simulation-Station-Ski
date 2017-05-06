/*
 * RemonteMecanique.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: xliu04
 */

#ifndef REMONTEMECANIQUE_HPP_
#define REMONTEMECANIQUE_HPP_
#include "Arc.hpp"

class RemonteMecanique : public Arc{
public:
	int niveauMinPistes;
	int frequence;
	int nbPersonneEnAttente;
public:
	/**
	 * \fn RemonteMecanique()
	 * constructeur par defaut de RemonteMecanique
	 */
	RemonteMecanique();
	/**
	 * \fn RemonteMecanique(int,int)
	 * constructeur de RemonteMecanique initialisant niveauMinPistes et frequence
	 */
	RemonteMecanique(string, bool,int,vector <Arc>,int,int);
	/**
	 * \fn int getNiveau()
	 * return int
	 * retourne le niveau min necessaire pour emprunter la remonte
	 */
	int getNiveau();
	/**
	 * \fn void setNiveau(int)
	 * modifie niveauMinPistes
	 */
	void setNiveau(int);
	/**
	 * \fn int getFrequence()
	 * return int
	 * renvoie la frequence en secondes
	 */
	int getFrequence();
	/**
	 * \fn void setFrequence(int)
	 * modifie la frequence
	 */
	void setFrequence(int);
	/**
	 * \fn int getNbPersonneEnAttente()
	 * return int
	 * retourne le nombre de personnes en attente
	 */
	int getNbPersonneEnAttente();
	/**
	 * \fn void setNbPersonneEnAttente(int)
	 * modifie le nombre de personne en attente
	 */
	void setNbPersonneEnAttente(int);
	virtual ~RemonteMecanique();
};

#endif /* REMONTEMECANIQUE_HPP_ */
