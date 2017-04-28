/*!
 * \file Skieur.hpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Cynthia Rasamimanananivo
 */

#ifndef SKIEUR_HPP_
#define SKIEUR_HPP_
#include <string>
namespace std{

/*!
 * \class Skieur
 * \brief Gestion du type skieur
 *

 */

class Skieur {
	string nomS;
	string prenomS;
	int niveauS;
	int heureArrivee;
	int heureDepart;
	int tempsTrajet;
	int tempsAttente;
	int tempsTotalPistes;
	int tempsTotalRemontee;
	int tempsTotalRepos;


public:
	Skieur();
	Skieur(string,string,int,int);

	string getNomS();
	string getPrenomS();
	int getNiveauS();
	int getheureArrivee();
	int getheureDepart();
	int getTempsTrajet();
	int getTempsAttente();
	int getTempsTotalPistes() ;
	int getTempsTotalRemontee();
	int getTempsTotalRepos() ;

	void setNomS(string) ;
	void setPrenomS(string) ;
	void setNiveauS(int) ;
	void setheureArrivee(int) ;
	void setheureDepart(int) ;
	void setTempsTrajet(int) ;
	void setTempsAttente(int) ;
	void setTempsTotalPistes(int) ;
	void setTempsTotalRemontee(int);
	void setTempsTotalRepos(int);

	void determinerArcSuivant();
	void emprunterArcSuivant();
	void seDeplacer();
	void partir();

	virtual ~Skieur();
};

} /* namespace std */

#endif /* SKIEUR_HPP_ */

