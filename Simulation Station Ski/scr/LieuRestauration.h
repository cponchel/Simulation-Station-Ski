/*
 * LieuRestauration.h
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#ifndef SCR_LIEURESTAURATION_H_
#define SCR_LIEURESTAURATION_H_
/**
 * \class LieuRestauration
 * \brief
 * \author Clementine Chevalier
 * \version 1.0
 * \date avril 2017
 */

class LieuRestauration {
	int capaciteResto;
public:
	/**
	* \fn LieuRestauration()
	* Constructeur par defaut de LieuRestauration
	*/
	LieuRestauration();
	/**
	 * \fn LieuRestauration(int)
	 * Constructeur LieuRestauration
	 * initialise la capacite maximale du LieuRestauration
	 */
	LieuRestauration(int);
	virtual ~LieuRestauration();
	/**
	 * \fn getCapaciteResto()
	 * return int
	 * Retourne la capacite maximale du LieuRestauration
	 */
	int getCapaciteResto();
	/**
	 * \fn setCapaciteResto
	 * modifie la valeur capaciteResto
	 */
	void setCapaciteResto(int);
};

#endif /* SCR_LIEURESTAURATION_H_ */
