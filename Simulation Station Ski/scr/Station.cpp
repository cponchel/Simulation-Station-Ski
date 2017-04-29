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
	cout << "2) Modifier la duree d'ouverture (Actuellement : " << secondesEnTemps(getDureeOuverture())[0] << "h" << secondesEnTemps(getDureeOuverture())[1] << "'" << secondesEnTemps(getDureeOuverture())[2] << "'', soit " << getDureeOuverture() <<" secondes)" << endl;
	cout << "3) Modifier la fréquence d'affichage (Actuellement : toutes les " << secondesEnTemps(getFrequenceAffichage())[0] << "h" << secondesEnTemps(getFrequenceAffichage())[1] << "'" << secondesEnTemps(getFrequenceAffichage())[2] << "'', soit " << getFrequenceAffichage() <<" secondes)" << endl;
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
	case 1 :	modifierNombreDeSkieurs();
				break;
	case 2 :	modifierDureeOuverture();
				break;
	case 3 :	modifierFrequenceAffichage();
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
	/*
	 * Affichage de l'accueil et lancement du menu suivant selon le mode choisi
	 */
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

int Station::tempsEnSecondes(int h, int m, int s){
	return 60*(60*h+m)+s;
}

vector<int> Station::secondesEnTemps(int s){
	vector<int> res;
	res.push_back(s/3600);
	s %= 3600;
	res.push_back(s/60);
	s %= 60;
	res.push_back(s);
	return res;
}

void Station::modifierNombreDeSkieurs(){
	/*
	 * Affichage
	 */
	string titre = "Mode " + mode + " : Modifier le nombre de skieurs";
	afficheTitre(titre);
	cout << "Veuillez rentrer le nouveau nombre de skieurs (<" << NB_MAX_SKIEURS <<") dans la station (Actuellement : " << getNombreDeSkieurs() << ")" << endl;
	int nb = -1;
	/*
	 * Demande du nouveau nombre et mise à jour dans la station
	 */
	while(nb<0 || nb>NB_MAX_SKIEURS){
		cin>>nb;
	}
	nombreDeSkieurs = nb;
	/*
	 * Retour au menu précédent
	 */
	if(mode=="Utilisateur"){
		modeUtilisateur();
	}
	else{
		modeAdministrateur();
	}
}

void Station::modifierDureeOuverture(){
	/*
	 * Affichage
	 */
	string titre = "Mode " + mode + " : Modifier la durée d'ouverture";
	afficheTitre(titre);
	cout << "Veuillez rentrer la nouvelle durée d'ouverture (entre " << DUREE_MIN/3600 << "h et " << DUREE_MAX/3600 << "h) de la station (Actuellement : " << secondesEnTemps(getDureeOuverture())[0] << "h" << secondesEnTemps(getDureeOuverture())[1] << "'" << secondesEnTemps(getDureeOuverture())[2] << "'', soit " << getDureeOuverture() <<" secondes)" << endl;

	int h = -1;
	int m = -1;
	int s = -1;
	/*
	 * Demande de la nouvelle durée et mise à jour dans la station
	 */
	// Heures
	cout << "Nombre d'heures :" << endl;
	while(h<0 || h>DUREE_MAX/3600){
		cin>>h;
	}
	// Minutes
	cout << "Nombre de minutes :" << endl;
	while(m<0 || m>DUREE_MAX/60 + h*60){
		cin>>m;
	}
	// Secondes
	cout << "Nombre de secondes :" << endl;
		while(s<0 || s<DUREE_MIN - (h*60+m)*60 || s>DUREE_MAX + (h*60+m)*60){
			cin>>s;
		}
	dureeOuverture = tempsEnSecondes(h,m,s);
	/*
	 * Retour au menu précédent
	 */
	if(mode=="Utilisateur"){
		modeUtilisateur();
	}
	else{
		modeAdministrateur();
	}

}

void Station::modifierFrequenceAffichage(){
	/*
	 * Affichage
	 */
	string titre = "Mode " + mode + " : Modifier la fréquence d'affichage";
	afficheTitre(titre);
	cout << "Veuillez rentrer la nouvelle fréquence d'affichage (>" << FREQUENCE_MIN << " secondes) de la station (Actuellement : toutes les " << secondesEnTemps(getFrequenceAffichage())[0] << "h" << secondesEnTemps(getFrequenceAffichage())[1] << "'" << secondesEnTemps(getFrequenceAffichage())[2] << "'', soit " << getFrequenceAffichage() <<" secondes)" << endl;

	int h = -1;
	int m = -1;
	int s = -1;
	/*
	 * Demande de la nouvelle durée et mise à jour dans la station
	 */
	// Heures
	cout << "Nombre d'heures :" << endl;
	while(h<0){
		cin>>h;
	}
	// Minutes
	cout << "Nombre de minutes :" << endl;
	while(m<0){
		cin>>m;
	}
	// Secondes
	cout << "Nombre de secondes :" << endl;
		while(s<0 || s<FREQUENCE_MIN - (h*60+m)*60){
			cin>>s;
		}
	frequenceAffichage = tempsEnSecondes(h,m,s);
	/*
	 * Retour au menu précédent
	 */
	modeAdministrateur();

}





Station::~Station() {
	cout << "Station supprimee" << endl;
}

} /* namespace std */


