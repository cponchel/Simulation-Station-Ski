/*
 * Station.hpp
 *
 *  Created on: 17 avr. 2017
 *      Author: CynthiaMiaina
 */

#ifndef SCR_STATION_HPP_
#define SCR_STATION_HPP_

#include <string>
#include <iostream>
#include <cstdlib>
#include "Arc.hpp"

namespace std {
/**
 * \class Station
 * \brief Gestion d'une Station de ski
 * \author Cynthia Rasamimanananivo
 * \author Colette Ponchel
 * \version 1.0
 * \date avril 2017
 */
class Station {

	string mode;
	int nombreDeSkieurs;
	int dureeOuverture;
	int tempsActuel;

public:
	/**
	 * \fn Station(string, int,int)
	 * Constructeur par défaut de Station
	 */
	Station(string, int,int);
	/**
	 * \fn virtual ~Station()
	 * Destructeur de Station
	 */
	virtual ~Station();
	/**
	 * \fn string getMode() const
	 * \return string
	 * Retourne le mode de la Station (Utilisateur ou Administrateur)
	 */
	string getMode() const;
	/**
	 * \fn int getNombreDeSkieurs() const
	 * \return int
	 * Retourne le nombre de skieurs de la Station
	 */
	int getNombreDeSkieurs() const;
	/**
	 * \fn int getDureeOuverture() const
	 * \return int
	 * Retourne la durée d'ouverture totale de la station exprimee en secondes
	 */
	int getDureeOuverture() const;
	/**
	 * \fn int getTempsActuel() const
	 * \return int
	 * Retourne le temps actuel de la station exprimé en secondes
	 */
	int getTempsActuel() const;
	/**
	 * \fn void modeUtilisateur()
	 * Lance le mode Utilisateur
	 */
	void modeUtilisateur();
	/**
	 * \fn void modeAdministrateur()
	 * Lance le mode Administrateur
	 */
	void modeAdministrateur();
	/**
	 * \fn lancerSimulation()
	 * Lance la simulation de la station en fonction du mode
	 */
	void lancerSimulation();
	/**
	 * \fn depalcerSkieurs()
	 * Appelle la fonction déplacer le skieur sur chaque Skieur de la station, s’il est arrive et s’il n’est pas reparti
	 */
	void deplacerSkieurs();
	/**
	 * \fn demarrer()
	 * Affiche le menu d'acceuil
	 */
	void accueil();
	/**
	 * \fn afficheTitre(string)
	 * \param string
	 * Vide la console et affiche un titre entre en paramètre
	 */
	void afficheTitre(string);
	/**
	 * \fn run()
	 * Se lance en début de programme et permet à l'utilisateur/administrateur de lancer une simulation
	 */
	void run();
	//
};

} /* namespace std */

#endif /* SCR_STATION_HPP_ */
