/*
 * Skieur.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: mrasamimanananivo
 */

#include "Skieur.hpp"


namespace std{

Skieur::Skieur() {
	nomS="sonNom";
	prenomS="sonPrenom";
	niveauS=0;
	heureArrivee=0;
	heureDepart=0;
	tempsTrajet=0;
	tempsAttente=0;
	tempsTotalPistes=0;
	tempsTotalRemontee=0;
	tempsTotalRepos=0;


}

Skieur::Skieur(string leNom,string lePrenom,int leNiveau,int lHeureArrivee){
	nomS=leNom;
	prenomS=lePrenom;
	niveauS=leNiveau;
	heureArrivee=lHeureArrivee;
	heureDepart=0;
	tempsTrajet=0;
	tempsAttente=0;
	tempsTotalPistes=0;
	tempsTotalRemontee=0;
	tempsTotalRepos=0;
}



//constructeur au hasard
Skieur::Skieur(int dureeOuverture){

	tempsTrajet=0;
	tempsAttente=0;
	tempsTotalPistes=0;
	tempsTotalRemontee=0;
	tempsTotalRepos=0;


	//nomS au hasard
	ifstream fichierNoms("fichiers/noms.txt", ios::in);
	if(!fichierNoms){
		throw string("Impossible d'ouvrir le fichier des noms. ");
		nomS = "Inconnu";
	}
	else{
		string nbNomsFichierStr;
		getline(fichierNoms, nbNomsFichierStr);

		int nbNomsFichier=atoi(nbNomsFichierStr.c_str());
		int nbHasard = rand()%nbNomsFichier + 1;
		int i;
		string nomHasard;
		for (i=1; i<=nbHasard; i++){
			getline(fichierNoms, nomHasard);
		}
		fichierNoms.close();
		nomS=nomHasard;
	}

	//prenomS au hasard
	ifstream fichierPrenoms("fichiers/prenoms.txt", ios::in);
	if(!fichierPrenoms){
		throw string("Impossible d'ouvrir le fichier des prenoms. ");
		prenomS = "Inconnu";
	}
	else{
		string nbPrenomsFichierStr;
		getline(fichierPrenoms, nbPrenomsFichierStr);
		int nbPrenomsFichier=atoi(nbPrenomsFichierStr.c_str());
		int nbHasard = rand()%nbPrenomsFichier + 1;

		int j;
		string prenomHasard;
		for (j=1; j<=nbHasard+1; j++){
			getline(fichierPrenoms, prenomHasard);
		}
		fichierPrenoms.close();
		prenomS=prenomHasard;
	}
	//niveau au hasard
	niveauS=rand()%4 + 1;

	//heureDepart
	heureDepart = dureeOuverture/2 + rand()%(dureeOuverture/2-1800);
	heureArrivee = rand()%(heureDepart/2);

}
void Skieur::setNomS(string leNom) {
	nomS=leNom;
}

void Skieur::setPrenomS(string lePrenom) {
	prenomS=lePrenom;
}

void Skieur::setNiveauS(int leNiveau) {
	niveauS=leNiveau;
}

void Skieur::setHeureArrivee(int lHeureArrivee){
	heureArrivee=lHeureArrivee;
}
void Skieur::setHeureDepart(int lHeureDepart){
	heureDepart=lHeureDepart;
}
void Skieur::setArcActuel(Arc arcA){
	arcActuel=arcA;
}

void Skieur::setTempsTrajet(int tTrajet){
	tempsTrajet=tTrajet;
}
void Skieur::setTempsAttente(int tAttente) {
	tempsAttente=tAttente;
}
void Skieur::setTempsTotalPistes(int tTotalPistes) {
	tempsTotalPistes=tTotalPistes;
}
void Skieur::setTempsTotalRemontee(int tTotalRemontee){
	tempsTotalRemontee=tTotalRemontee;
}
void Skieur::setTempsTotalRepos(int tTotalRepos){
	tempsTotalRepos=tTotalRepos;
}
string Skieur::getNomS(){
	return nomS;
}

string Skieur::getPrenomS(){
	return prenomS;
}

int Skieur::getNiveauS(){
	return niveauS;
}

int Skieur:: getHeureArrivee(){
	return heureArrivee;
}

int Skieur:: getHeureDepart(){
	return heureDepart;
}

Arc Skieur::getArcActuel(){
	return arcActuel;
}
int Skieur::getTempsTrajet(){
	return tempsTrajet;
}

int Skieur::getTempsAttente(){
	return tempsAttente;
}
int Skieur::getTempsTotalPistes(){
	return tempsTotalPistes;
}

int Skieur:: getTempsTotalRemontee(){
	return tempsTotalRemontee;
}
int Skieur:: getTempsTotalRepos(){
	return tempsTotalRepos;
}
/*
void Skieur::determinerArcSuivant(){
	vector<int> proba;

	for(int i=0;getArcActuel().getSuivants().size();i++)
	{
		if(getNiveauS()>=getArcActuel().getSuivants()[i].getNiveau()) // on place l'indice de l'arc dans un tab si le Skieur est apte a emprunter l'arc
		{
			proba.push_back(i);
		}
	}
	int temp=rand()%proba.size(); // on choisit au hasard un indice ind du tableau compris entre 0 et tab.size() exclus

	// mise à jour de l'arc actuel
	setArcActuel(getArcActuel().getSuivants()[proba[temp]]); // l'arc actuel correspond à la case d'indice tab[ind] du vecteur arcSuivants

}

void Skieur::emprunterArcSuivant()
{
	determinerArcSuivant();
	setTempsTrajet(getArcActuel().calculerTempsTrajet());
	setTempsAttente(getArcActuel().calculerTempsAttente());

	//mise a jour du nb de personnes sur l'arc
	if(getTempsAttente()>0)
	{
		getArcActuel().setNbPersonneEnAttente(getArcActuel().getNbPersonneEnAttente()+1);
	}
	else
	{
		getArcActuel().setNbPersonneA(getArcActuel().getNbPersonneA()+1);
	}
}



void Skieur::seDeplacer(){
	if (getTempsAttente()>0)
	{
		tempsAttente--;
	}
	else if (getTempsAttente()==0){
		getArcActuel().setNbPersonneEnAttente(getArcActuel().getNbPersonneEnAttente()-1);
	}
	if (getTempsTrajet()>0)
	{
		tempsTrajet--;
	}
	else if (getTempsTrajet()==0){
			getArcActuel().setSuivant(getArcActuel().getSuivant())=null;
			emprunterArcSuivant();
		}


}
*/


Skieur::~Skieur() {
	// TODO Auto-generated destructor stub
}

}
