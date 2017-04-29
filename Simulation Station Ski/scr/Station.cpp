/*
 * Station.cpp
 *
 *  Created on: 17 avr. 2017
 *      Author: CynthiaMiaina
 */

#include "Station.hpp"

namespace std {

Station::Station(string unMode, int nbSkieurs, int d, int f) {
	mode=unMode;
	nombreDeSkieurs=nbSkieurs;
	dureeOuverture=d;
	tempsActuel=0;
	frequenceAffichage=f;

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

int Station::getFrequenceAffichage() const{
	return frequenceAffichage;
}

vector<Skieur> Station::getSkieurs() const{
	return skieurs;
}

Skieur Station::getSkieur(int i) const{
	return skieurs[i];
}

vector<Arc> Station::getArcs() const{
	return arcs;
}

void Station::modeUtilisateur() {
	afficheTitre("Mode Utilisateur");
}

void Station::modeAdministrateur(){
	afficheTitre("Mode Administrateur");

	cout << "Vous voulez :" << endl;
	cout << "1) Modifier le nombre de skieurs (Actuellement : " << getNombreDeSkieurs() << ")" << endl;
	cout << "2) Modifier la duree d'ouverture (Actuellement : " << getDureeOuverture() << ")" << endl;
	cout << "3) Modifier la fréquence d'affichage (Actuellement :" << getFrequenceAffichage() << ")" << endl;
	cout << "4) Gérer l'ouverture des installations" << endl;
	cout << "5) Lancer la simulation" << endl;
	cout << "\n0) Retour" << endl;

	int choix = -1;
	while(choix<0 || choix>5){
		cin >> choix;
	}

	switch(choix){
	case 0 :	run();
				break;
	case 1 :	//modifierNombreSkieurs();
				break;
	case 2 :	//modifierDureeOuverture();
				break;
	case 3 :	//modifierFrequenceAffichage();
				break;
	case 4 :	//gererArcs();
				break;
	case 5 : 	lancerSimulation();
				break;
	}
}

void Station::lancerSimulation(){

}

void Station::deplacerSkieurs(){
	for(int i=0;i<getNombreDeSkieurs();i++){
		//getSkieur(i).seDeplacer();
	}
}

bool Station::accueil(){
	afficheTitre("Bienvenue");

	cout << "\nVous êtes :\n1) Administrateur \n2) Utilisateur \n\n0) Quitter" << endl;

	int choix = -1;
	while(choix!=1 && choix!=2 && choix!=0){
		cin >> choix;
	}


	switch(choix){
	case 1 : 	mode = "Administrateur";
				break;
	case 2 :	mode = "Utilisateur";
				break;
	case 0 :	return false;
				break;
	}
	return true;

}

void Station::afficheTitre(string titre){
	cout << string(50, '\n');
	cout << "****" << titre << "****"<< endl;
}

void Station::run(){
	if(accueil()){
		if(mode=="Utilisateur"){
			modeUtilisateur();
		}
		else{
			modeAdministrateur();
		}
	}
}

void Station::init(){

}





Station::~Station() {
	cout << "Station supprimee" << endl;
}

} /* namespace std */


