/*
 * Station.cpp
 *
 *  Created on: 17 avr. 2017
 *      Author: CynthiaMiaina
 */

#include "Station.hpp"

namespace std {

Station::Station(string unMode, int nbSkieurs, int d) {
	mode=unMode;
	nombreDeSkieurs=nbSkieurs;
	dureeOuverture=d;
	tempsActuel=0;

}

string Station::getMode() const {
	return mode;
}

int Station::getNombreDeSkieurs() const{
	return nombreDeSkieurs;
}

int Station::getDureeOuverture() const {
	return dureeOuverture;
}

int Station::getTempsActuel() const{
	return tempsActuel;
}

void Station::modeUtilisateur() {

}

void Station::modeAdministrateur(){

}

void Station::lancerSimulation(){

}

void Station::deplacerSkieurs(){
//
}

void Station::accueil(){
	afficheTitre("Bienvenue");

	cout << "\nVous êtes :\n1) Administrateur \n2) Utilisateur" << endl;

	int choix = 0;
	while(choix!=1 && choix!=2){
		cin >> choix;
	}

	if(choix==1){
		mode = "Administrateur";
	}
	else{
		mode = "Utilisateur";
	}
}

void Station::afficheTitre(string titre){
	cout << string(50, '\n');
	cout << "****" << titre << "****"<< endl;
}





Station::~Station() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */


