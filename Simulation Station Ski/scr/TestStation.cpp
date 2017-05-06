/*
 * TestStation.cpp
 *
 *  Created on: 28 avr. 2017
 *      Author: Colette Ponchel
 */

#include "Station.hpp"
#include "RemonteMecanique.hpp"
#include "LieuRestauration.hpp"
#include <typeinfo>

using namespace std;

int main(){


	Station station;

	/*
	 * A titre d'exemple :
	 */
	//TEST getDureeOuverture()
	cout << "**station->getDureeOuverture()**";
	if(station.getDureeOuverture()==1000){
		cout << "OK" << endl;
	}
	else{
		cout << "KO" << endl;
	}


	/*new Skieur(nom,prenom,niveau,tempsEnSecondes(h,m,s))
	 * Vrais tests :
	 */
	//TEST afficheTitre(string)
	cout << "**station->afficheTitre(\"Bienvenue\")*";
	station.afficheTitre("Bienvenue");

	//TEST accueil()
	/*
	cout<< "**station->accueil()**";
	station->accueil();
	cout << station->getMode() << endl;
	*/

	//TEST run()
	cout << "**station->run()**";
	station.run();

	//TEST initArcs()
	cout << "**initArcs()**";
	//station.initArcs();

	return 0;
}
