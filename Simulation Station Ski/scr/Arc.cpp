/*
 * Arc.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#include "Arc.hpp"



Arc::Arc() {
	nom="";
	ouvert=false;
	tempsMoyen=0;
	nbPersonneA=0;

}

Arc::Arc(string leNom, bool ouverture, int tm, vector <Arc> lesArcsSuivant) {
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
vector <Arc>& Arc:: getSuivants(){
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
void Arc::setSuivants(vector<Arc> lesArcsSuivants){
	suivants=lesArcsSuivants;
}

void Arc::setNbPersonneA(int nbPers){
	nbPersonneA=nbPers;
}


Arc::~Arc() {
}
