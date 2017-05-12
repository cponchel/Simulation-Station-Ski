/*
 * LieuRestauration.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#include "LieuRestauration.hpp"

LieuRestauration::LieuRestauration():Arc()
{

	capaciteResto=30;
}

LieuRestauration::LieuRestauration(string leNom, bool ouverture, int tm, vector <Arc*> lesArcsSuivant,int cap):Arc(leNom,ouverture,tm,lesArcsSuivant) {

	capaciteResto=cap;
}

LieuRestauration::~LieuRestauration() {

}

int LieuRestauration::getCapaciteResto()
{
	return capaciteResto;
}

/*void LieuRestauration::setCapaciteResto(int cap)
{
	capaciteResto=cap;
}
*/

int LieuRestauration::calculerTempsTrajet()
{
	return getTempsMoyen() +rand()%1800; //temps entre 10 et 40 min
}

int LieuRestauration::calculerTempsAttente()
{
	return 0;
}
int LieuRestauration::getNbPersonneEnAttente()
{
	return 0;
}

bool LieuRestauration::estSature()
{
	if(getNbPersonneA()==getCapaciteResto())
	{
		return true;
	}
	else
	{
		return false;
	}
}
