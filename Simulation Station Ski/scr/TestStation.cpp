/*
 * TestStation.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Colette Ponchel
 */

#include "Station.hpp"

using namespace std;

int main(){

	Station * station = new Station("Utilisateur", 50, 1000, 1800);



	/*
	 * A titre d'exemple :
	 */
	//TEST getDureeOuverture()
	cout << "**station->getDureeOuverture()**";
	if(station->getDureeOuverture()==1000){
		cout << "OK" << endl;
	}
	else{
		cout << "KO" << endl;
	}


	/*
	 * Vrais tests :
	 */
	//TEST afficheTitre(string)
	cout << "**station->afficheTitre(\"Bienvenue\")*";
	station->afficheTitre("Bienvenue");

	//TEST accueil()
	cout<< "**station->accueil()**";
	station->accueil();
	cout << station->getMode() << endl;

	//TEST run()
	cout << "**station->run()**";
	station->run();
	delete station;
	return 0;
}
