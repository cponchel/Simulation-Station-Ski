/*
 * Station.cpp
 *
 *  Created on: 17 avr. 2017
 *      Author: CynthiaMiaina
 */

#include "Station.hpp"

namespace std {

Station::Station(string unMode, int nbSkieurs, int d, int t) {
	mode=unMode;
	nombreDeSkieurs=nbSkieurs;
	dureeOuverture=d;
	tempsActuel=t;

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

}

void Station::demarrer(){


}

void Station::afficheTitre(string titre){
	std::system("clear");
	cout << "**** \t" << titre << "\t ****"<< endl;
}




Station::~Station() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */


