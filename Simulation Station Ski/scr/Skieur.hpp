/*!
 * \file Skieur.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Cynthia Rasamimanananivo
 */

#ifndef SKIEUR_HPP_
#define SKIEUR_HPP_
#include "Arc.hpp"
//#include "time.h"
#include <cstdlib>
#include <string>



namespace std{

/*!
 * \class Skieur
 * \brief Gestion du type skieur
 *
 * \author Cynthia Rasamimanananivo
 * \author Clémentine Chevalier
 * \author Xuan Liu
 * \version 1.0
 * \date avril 2017
 */

class Skieur {
	string nomS;
	string prenomS;
	int niveauS;
	int heureArrivee;
	int heureDepart;
	Arc arcActuel;
	int tempsTrajet;
	int tempsAttente;
	int tempsTotalPistes;
	int tempsTotalRemontee;
	int tempsTotalRepos;

public:

	/**
	* \fn Skieur()
	* Constructeur par defaut de Skieur()
	*/
	Skieur();

	/**
	* \fn Station(string,string,int,int)
	* \param string, string, int,int
	* \brief Deuxieme constructeur surcharge et permet de creer le skieur
	* avec son nom, son prenom et son niveau et son heure d'arrivee exprimee en seconde
	*
	*/
	Skieur(string,string,int,int);

	Skieur(int dureeOuverture);

	/**
	* \fn string getNomS()
	* \return string
	* Retourne le nom du Skieur
	*/
	string getNomS();


	/**
	* \fn string getPrenomS()
	* \return string
	* Retourne le prenom du Skieur
	*/
	string getPrenomS();

	/**
	* \fn int getNiveau()
	* \return int
	* Retourne le niveau du Skieur
	*/
	int getNiveauS();

	/**
	* \fn int getHeureArrivee()
	* \return int
	* Retourne l'heure a laquelle e Skieur arrive, l'heure est exprime en seconde
	*/
	int getHeureArrivee();

	/**
	* \fn int getHeureDepart()
	* \return int
	* Retourne l'heure a laquelle le Skieur part, l'heure est exprime en seconde
	*/
	int getHeureDepart();
	/**
	 * \fn Arc getArcActuel()
	 * \return Arc
	 * Retourne l'arc sur lequel se trouve le Skieur
	 */
	Arc getArcActuel();
	/**
	* \fn int getTempsTrajet()
	* \return int
	* Retourne le temps que le skieur met a effectuer son trajet
	* Le temps est exprime en seconde
	*/
	int getTempsTrajet();

	/**
	* \fn int getTempsAttente()
	* \return int
	* Retourne le temps d'attente du skieur avant une activite
	* Le temps est exprime en seconde
	*/
	int getTempsAttente();

	/**
	* \fn int getTempsTotalPistes()
	* \return int
	* Retourne le temps que le skieur met a faire toutes les pistes
	* Le temps est exprime en seconde
	*/
	int getTempsTotalPistes() ;

	/**
	* \fn int getTempsTotalRemontee()
	* \return int
	* Retourne le temps total pendant lequel le skieur a pris une remontee
	* Le temps est exprime en seconde
	*/
	int getTempsTotalRemontee();

	/**
	* \fn int getTempsTotalRemontee()
	* \return int
	* Retourne le temps total pendant lequel le skieur s'est restaure
	* Le temps est exprime en seconde
	*/
	int getTempsTotalRepos() ;


	void setNomS(string);
	void setPrenomS(string);
	void setNiveauS(int);

	/**
	* \fn void setHeureArrivee(int)
	* \param int
	* Modifie l'heure a laquelle le Skieur arrive a la station
	*/
	void setHeureArrivee(int) ;

	/**
	* \fn void setHeureDepart(int)
	* \param int
	* Modifie l'heure a laquelle le Skieur part
	*/
	void setHeureDepart(int) ;
	/**
	 * \fn void setArcActuel(Arc)
	 * \param Arc
	 * Modifie l'arc surquel se trouve le Skieur
	 */
	void setArcActuel(Arc);

	/**
	* \fn void setTempsTrajet(int)
	* \param int
	* Modifie le temps pendant que le skieur met a effectuer son trajet
	* Le temps est exprime en seconde
	*/
	void setTempsTrajet(int) ;

	/**
	* \fn void setTempsAttente(int)
	* \param int
	* Modifie le temps pendant le skieur attend
	* Le temps est exprime en seconde
	*/
	void setTempsAttente(int) ;

	/**
	* \fn void setTempsTotalPistes(int)
	* \param int
	* Modifie le temps que le skieur met a faire toutes ses pistes
	* Le temps est exprime en seconde
	*/
	void setTempsTotalPistes(int) ;

	/**
	* \fn void setTempsTotalRemontee(int)
	* \param int
	* Modifie le temps total pendant lequel le skieur a pris une remontee
	* Le temps est exprime en seconde
	*/
	void setTempsTotalRemontee(int);

	/**
	* \fn void setTempsTotalRepos(int)
	* \param int
	* Modifie le temps total pendant lequel le skieur s'est restaure
	* Le temps est exprime en seconde
	*/
	void setTempsTotalRepos(int);


	void determinerArcSuivant();
	void emprunterArcSuivant();
	void seDeplacer();
	void partir();
	/**
	* \fn Station()
	* Destructeur de Station
	*/
	virtual ~Skieur();
};

} /* namespace std */

#endif /* SKIEUR_HPP_ */

