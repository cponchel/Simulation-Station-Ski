/*
 * LieuRestauration.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#include "LieuRestauration.hpp"

LieuRestauration::LieuRestauration(int cap) {
	// TODO Auto-generated constructor stub
	capaciteResto=cap;
}

LieuRestauration::~LieuRestauration() {
	// TODO Auto-generated destructor stub
}

int LieuRestauration::getCapaciteResto()
{
	return capaciteResto;
}

void LieuRestauration::setCapaciteResto(int cap)
{
	capaciteResto=cap;
}

int LieuRestauration::calculerTempsTrajet()
{
	return 600 +rand()%1800; //temps entre 10 et 40 min
}
