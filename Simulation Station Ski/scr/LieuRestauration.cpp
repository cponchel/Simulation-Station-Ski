/*
 * LieuRestauration.cpp
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#include "LieuRestauration.h"

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
