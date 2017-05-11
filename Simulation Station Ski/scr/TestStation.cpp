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
	cout << "**station->run()** " << endl;
	station.run();

	//TEST initArcs()
	//cout << "**initArcs()**" << endl;
	//station.initArcs();

	//TEST afficheTableauAdmin()



	cout << "**afficheTableauAdmin()**" << endl;
	vector<Arc*> parcs;
	vector<Arc> arcs;
	Arc arc1("Premier Arc",true,0,parcs);
	parcs.push_back(&arc1);
	Arc arc2("Second Arc",true,0,parcs);
	parcs.push_back(&arc2);
	arcs.push_back(arc1);
	arcs.push_back(arc2);
	station.afficheTableauAdmin(arcs,50,12);

	cout << "**initialisation des arcs, verif que les pointeurs fonctinnent bien**" << endl;
	cout << station.getArcs()[5]->getSuivants()[0]->getNom() << " = " << station.getArcs()[8]->getNom() << endl;
	cout << station.getArcs()[5]->getSuivants()[0]->getSuivants()[0]->getNom() << " = " << station.getArcs()[44]->getNom() << endl;


	return 0;
}
