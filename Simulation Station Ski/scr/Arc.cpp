/*
 * Arc.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#include "Arc.hpp"



Arc::Arc() {
	nom="Arc hors station";
	ouvert=false;
	tempsMoyen=0;
	nbPersonneA=0;


}

Arc::Arc(string leNom, bool ouverture, int tm, vector <Arc*> lesArcsSuivant) {
	nom=leNom;
	ouvert=ouverture;
	tempsMoyen=tm;
	suivants=lesArcsSuivant;
	nbPersonneA=0;

}
string Arc:: getNom(){
	return nom;
}

bool Arc::getOuvert(){
	return ouvert;
}
int Arc:: getTempsMoyen(){
	return tempsMoyen;
}
vector <Arc*>& Arc:: getSuivants(){
	return suivants;
}

int Arc::getNbPersonneA(){
	return nbPersonneA;
}


void Arc::setNom(string leNom){
	nom=leNom;
}
void Arc::setOuvert(bool ouverture){
	ouvert=ouverture;
}
void Arc::setTempsMoyen(int tmoyen){
	tempsMoyen=tmoyen;
}
void Arc::setSuivants(vector<Arc*> & lesArcsSuivants){
	suivants=lesArcsSuivants;
}

void Arc::setNbPersonneA(int nbPers){
	nbPersonneA=nbPers;
}

int Arc::calculerTempsAttente()
{
	return 0;
}
int Arc::getNiveau()
{
	return 0;
}
int Arc::getFrequence()
{
	return 1;
}
int Arc::getNbPersonneEnAttente()
{
	return 0;
}

void Arc::setNbPersonneEnAttente(int a)
{

}

int Arc::getCapaciteResto()
{
	return 0;
}

int Arc:: calculerTempsTrajet(){
	//heure actuelle - heure de depart sur le d�but de l'arc
	return tempsMoyen;


}

bool Arc::estSature(){
	return false;
}
Arc::~Arc() {
}
