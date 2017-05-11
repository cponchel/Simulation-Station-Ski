/*!
 * \file Skieur.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Cynthia Rasamimanananivo
 */

#ifndef SKIEUR_HPP_
#define SKIEUR_HPP_
#include "Arc.hpp"
#include "time.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <typeinfo>
#include "LieuRestauration.hpp"

namespace std{

/*!
 * \class Skieur
 * \brief Gestion du type skieur
 *
 * \author Cynthia Rasamimanananivo
 * \author Clémentine Chevalier
 * \author Xuan Liu
 * \author Colette Ponchel
 * \version 1.0
 * \date avril 2017
 */

class Skieur {
	string nomS;
	string prenomS;
	int niveauS;
	int heureArrivee;
	int heureDepart;
	int nbPassagesLR;
	Arc* arcActuel;
	int tempsTrajet;
	int tempsAttente;
	int tempsTotalPistes;
	int tempsTotalRemontee;
	int tempsTotalRepos;
	int tempsTotalAttente;
	vector<Arc*> arcsDepart;

public:

	/**
	* \fn Skieur()
	* Constructeur par defaut de Skieur()
	*/
	Skieur();

	/**
	* \fn Station(string,string,int,int)
	* \param string, string, int,int
	* \brief Deuxieme constructeur surcharge qui
	* permet de creer le skieur et l'initialser
	* avec son nom, son prenom et son niveau
	* et son heure d'arrivee exprimee en seconde
	*
	*/
	Skieur(string,string,int,int);

	/**
	* \fn Station(int)
	* \param int
	* \brief Troisieme constructeur surcharge et permet de creer le skieur
	* avec un nom au hasard, un prenom au hasard et un niveau au hasard et une heure d'arrivee et une heure depart exprimees en seconde au hasard
	*
	*/
	Skieur(int dureeOuverture,vector<Arc*> arcsDep);

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
	 * \fn vector<Arc> getArcs()
	 * \return vector<Arc>
	 * Retourne la liste des Arcs par lesquels ls skieurs peuvent arriver
	 */
	vector<Arc*> getArcsDepart();
	/**
	 * \fn void setArcsDepart(vector<Arc*> );
	 * \return vector<Arc>
	 * change la valeur de arcsDepart
	 */
	void setArcsDepart(vector<Arc*> );

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
		 * \fn int getNbPassagesLR()
		 * return int
		 * Retourne le nb de passages par un lieu de restauration du Skieur
		 */
	int getNbPassagesLR();
	/**
	 * \fn Arc getArcActuel()
	 * \return Arc
	 * Retourne l'arc sur lequel se trouve le Skieur
	 */
	Arc* getArcActuel();
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
	* \fn int getTempsTotalAttente()
	* \return int
	* Retourne le temps que le skieur passe à attendre
	* Le temps est exprime en seconde
	*/
	int getTempsTotalAttente() ;
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
		 * \fn void setNbPassagesLR(int)
		 * \param int
		 * Modifie le nb de passages par un lieu de Restauration du Skieur
		 */

	void setNbPassagesLR(int);
	/**
	 * \fn void setArcActuel(Arc)
	 * \param Arc
	 * Modifie l'arc surquel se trouve le Skieur
	 */
	void setArcActuel(Arc*);

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

	/**
	* \fn determinerArcSuivant()
	* \param
	* \brief Permet de determiner l'arc suivant a prendre
	* selon le niveau et la position dans la station
	*/
	void determinerArcSuivant();

	/**
	* \fn void emprunterArcSuivant(int instant)
	* \param
	* \brief Permet d'emprunter l'arc suivant
	* en faisant appel a determinerArcSuivant()
	*/
	void emprunterArcSuivant(int instant, string mode);

	/**
	* \fn void seDeplacer(int instant)
	* \param
	* \brief Permet de mettre a jour les temps totaux
	* decrementer le nombre de personne en attente si le temps d'attente est nul
	* on emprunte l'arc suivant si le temps de trajet est nul
	*
	*/
	void seDeplacer(int instant, string mode);
	/**
	 * \fn void choisirArcSuivant()
	 * Ici c'est l'utilisateur qui choisit l'arc suivant
	 */
	void choisirArcSuivant();


	void partir();
	/**
	* \fn Station()
	* Destructeur de Station
	*/
	virtual ~Skieur();
	/**
	 * surchage de l'operateur << pour l'affichage d'un skieur
	 */
	friend ostream& operator<<(ostream&, Skieur const&);
};

} /* namespace std */

#endif /* SKIEUR_HPP_ */

