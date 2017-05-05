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
#include <vector>
#include <fstream>
#include "Arc.hpp"
#include "Skieur.hpp"

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
	int frequenceAffichage;
	vector<Skieur> skieurs;
	vector<Arc> arcs;
	int static const NB_MIN_SKIEURS = 10;
	int static const NB_MAX_SKIEURS = 1000;
	int static const DUREE_MIN = 1000; //16'40''
	int static const DUREE_MAX = 43200; //12h0'0''
	int static const FREQUENCE_MIN = 1; //1sec


public:
	/**
	 * \fn Station()
	 * Constructeur par défaut de Station
	 */
	Station();
	/**
	 * \fn Station(string, int,int,int)
	 * Constructeur de Station avec choix des paramètres
	 */
	Station(string unMode, int nbSkieurs, int d, int f);
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
	 * \fn int getFrequenceAffichage() const
	 * \return int
	 * Retourne la frequence d'affichage
	 */
	int getFrequenceAffichage() const;
	/**
	 * \fn vector<Skieur> getSkieurs() const
	 * \return vector<Skieur>
	 * Retourne la liste des skieurs
	 */
	vector<Skieur>& getSkieurs() const;
	/**
	 * \fn Skieur getSkieur(int) const
	 * \return Skieur
	 * Retourne le ième Skieur de la liste skieurs
	 */
	Skieur getSkieur(int) const;
	/**
	 * \fn vector<Arc> getArcs() const
	 * \return vector<Skieur>
	 * Retourne la liste des Arcs
	 */
	vector<Arc>& getArcs() const;
	/**
	 * \fn int demanderInt()
	 * \return int
	 * Demande de saisir un entier et gère les erreurs
	 * En cas d'erreur retourne min-1
	 */
	int static demanderInt();
	/**
	 * \fn int demanderInt(int min, int max)
	 * \return int
	 * \param int min (borne int de l'entier)
	 * \parem int max (borne sup de l'entier)
	 * Demande de saisir un entier positif et gère les erreurs
	 * En cas d'erreur retourne -1
	 */
	int static demanderInt(int, int);
	/**
	 * \fn void modeUtilisateur()
	 * Lance le mode Utilisateur
	 */
	void modeUtilisateur();
	/**
	 * \fn void menuModifUtilisateur()
	 * Affiche le menu relatif aux modifications autorisées à l'utilisateur
	 */
	void menuModifUtilisateur();
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
	 * \fn void initArcs()
	 * Initialise les arcs selon un plan de station précis
	 */
	void initArcs();
	/**
	 * \fn depalcerSkieurs()
	 * Appelle la fonction déplacer le skieur sur chaque Skieur de la station, s’il est arrive et s’il n’est pas reparti
	 */
	void deplacerSkieurs();
	/**
	 * \fn demarrer()
	 * \return bool
	 * Affiche le menu d'accueil, retourne false si on quitte le programme, true sinon
	 */
	bool accueil();
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
	/**
	 * \fn void modifierNombreDeSkieurs()
	 * Demande à l'utilisateur/admin de choisir un nouveau nombre de skieurs
	 */
	void modifierNombreDeSkieurs();
	/**
	 * \fn void modifierDureeOuverture()
	 * Demande à l'utilisateur/admin de choisir une nouvelle durée d'ouverture
	 */
	void modifierDureeOuverture();
	/**
	 * \fn void modifierFrequenceAffichage()
	 * Demande à l'utilisateur/admin de choisir une nouvelle fréquence d'affichage
	 */
	void modifierFrequenceAffichage();
	/**
	 * \fn void gererArcs()
	 * Demande à l'admin de gérer l'ouverture et la fermeture des arcs
	 */
	void gererArcs();
	/**
	 * \fn void static tempsEnSecondes(int,int,int)
	 * \return int
	 * Convertit un temps h m s en secondes
	 */
	int static tempsEnSecondes(int,int,int);
	/**
	 * \fn vector<int> static secondesEnTemps(int)
	 * \return vector<int>
	 * Convertit des secondes en temps h m s stocké dans un vecteur : [0] = h, [1] = m, [2] = s
	 */
	vector<int> static secondesEnTemps(int);
	/**
	 * \fn void sauvegarderParamFichier()
	 * Sauvegarde les parametres actuels dans le fichier des parametres
	 */
	void sauvegarderParamFichier();

};

} /* namespace std */

#endif /* SCR_STATION_HPP_ */
