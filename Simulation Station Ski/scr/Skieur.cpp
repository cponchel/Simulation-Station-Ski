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
}


Skieur::~Skieur() {
	// TODO Auto-generated destructor stub
}

}
