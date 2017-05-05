/*
 * Arc.h
 *
 *  Created on: 14 avr. 2017
 *      Author: cchevalier
 */

#ifndef SCR_ARC_HPP_
#define SCR_ARC_HPP_

#include <string>
#include <vector>
#include <string.h>
using namespace std;


class Arc {
	string nom;
	bool ouvert;
	int tempsMoyen;
	vector <Arc> suivants;

public:
	Arc();
	Arc(string,bool, int,vector<Arc>);

	virtual ~Arc();
	string getNom();
	bool getOuvert();
	int getTempsMoyen();
	vector <Arc>& getSuivants();
	void setNom(string);
	void setOuvert(bool);
	void setTempsMoyen(int);
	void setSuivants(vector<Arc>);
	int getNiveau();
	int calculerTempsTrajet();
	int calculerTempsAttente();
};


#endif /* SCR_ARC_HPP_ */
