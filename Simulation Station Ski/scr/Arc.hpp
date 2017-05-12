/*
 * Arc.hpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */


#ifndef SCR_ARC_HPP_
#define SCR_ARC_HPP_

#include <string>
#include <vector>
#include <functional>
using namespace std;
/**
 * \class Station
 * \brief Gestion du type Arc
 * \brief Arc est la classe mere de Piste, RemonteeMecanique
 * Telesiege et Teleski
 * \author Cynthia Rasamimanananivo
 * \author Cl�mentine Chevalier
 * \version 1.0
 * \date avril 2017
 */

class Arc {
	string nom;
	bool ouvert;
	int tempsMoyen;
	vector<Arc*> suivants;
	int nbPersonneA;


public:
	/**
	* \fn Arc()
	* Constructeur par defaut d'Arc
	*/
	Arc();

	/**
	* \fn Arc(string,bool,int,vector<Arc>,int)
	* \param string,bool,int,vector<Arc>
	* \brief Constructeur surcharge qui
	* permet de creer l'Arc et l'initialiser
	* avec le nom de l'Arc, l'etat de l'ouverture (ouvert ou ferme)
	* le temps moyen pendant lequel on reste sur l'Arc (exprime en secondes)
	* les arcs suivants (la prochaine piste, ou le prochain lieu de restauration
	* ou le prochain teleski par exemple)
	*/
	Arc(string,bool,int,vector<Arc*>);



	/**
	* \fn string getNom()
	* \return string
	* Retourne le nom de l'Arc
	*/
	string getNom();



	/**
	* \fn bool getPrenomS()
	* \return bool
	* Retourne si l'arc est ouvert ou non
	*/
	bool getOuvert();

	/**
	* \fn int getTempsMoyen()
	* \return int
	* \brief Retourne le temps moyen passe sur l'arc
	* \brief le temps est exprime en secondes
	*/
	int getTempsMoyen();

	/**
	* \fn vector <Arc>& getSuivants()
	* \return vector <Arc>
	* \brief Retourne l'arc suivant
	*/
	vector <Arc*>& getSuivants();



	/**
	* \fn int getNiveau()
	* \return int
	* Retourne le niveau associ� � l'arc
	*/
	virtual int getNiveau();

	/**
	* \fn int getNbPersonneA()
	* \return int
	* Retourne le nombre de personne sur l'arc
	*/
	virtual int getNbPersonneA();

	/**
	* \fn int getNbPersonneEnAttente()
	* \return int
	* Retourne le nombre de personne en attente sur l'arc
	*/
	virtual int getNbPersonneEnAttente();
	/**
	* \fn int getFrequence()
	* \return int
	* Retourne la frequence de la remontee mecanique
	*/
	virtual int getFrequence();


	/**
	* \fn void setNom(string)
	* \param string
	* \brief Permet de modifier le nom de l'arc
	*/
	void setNom(string);

	/**
	* \fn void setOuvert(bool)
	* \param bool
	* \brief Permet de modifier l'etat d'ouverture de l'arc
	*/
	void setOuvert(bool);

	/**
	* \fn void setTempsMoyen(int)
	* \param int
	* \brief Permet de modifier le temps moyen pass� sur l'arc
	*/
	void setTempsMoyen(int);

	/**
	* \fn void setSuivants(vector<Arc>)
	* \param vector<Arc>
	* \brief Permet de modifier l'arc suivant sur lequel on va pointer
	*/
	void setSuivants(vector<Arc*>&);

	/**
	* \fn void setNbPersonneA(int)
	* \param int
	* \brief Permet de modifier le nombre de personne sur l'arc
	*/
	void setNbPersonneA(int);

	/**
	* \fn void setNbPersonneEnAttente(int)
	* \param int
	* \brief Permet de modifier le nombre de personne en attente
	*/
	void setNbPersonneEnAttente(int);


	/**
	* \fn void calculerTempsTrajet()
	* \return int
	* \brief Retourne le temps de trajet
	* le temps est exprim� en secondes
	*/
	int calculerTempsTrajet();

	/**
	* \fn void calculerTempsAttente()
	* \return int
	* \brief Retourne le temps d'attente
	* le temps est exprim� en secondes
	*/
	virtual int calculerTempsAttente();

	/**
	* \fn virtual ~Arc()
	* Destructeur d'Arc
	*/
		//virtual void setCapaciteResto(int)=0;



	int getCapaciteResto();
	/**
	 * \fn bool estSature()
	 * return bool
	 * Retourne si l'arc est sature
	 */

	virtual bool estSature();
	virtual ~Arc();
};


#endif /* SCR_ARC_HPP_ */
