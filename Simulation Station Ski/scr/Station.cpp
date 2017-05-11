/*
 * Station.cpp
 *
 *  Created on: 17 avr. 2017
 *      Author: CynthiaMiaina
 */

#include "Station.hpp"




namespace std {


Station::Station(){

	tempsActuel = 0;
	mode = "Utilisateur";
	try{
		ifstream fichier("fichiers/parametres_par_defaut.txt", ios::in);
		if(!fichier){
			throw string("Impossible d'ouvrir le fichier des parametres par defaut. D'autres parametres ont ete choisis pour les remplacer.");
		}


		vector<int> param;

		string input;
		const char* inputchar;
		//Tant qu'on lit une ligne dans le fichier
        while(getline(fichier, input))
        {
        	//On vérifie que chaque caractère est un chiffre avant de l'affecter
        	for (int i=0; i<input.size(); i++){
				if (!isdigit(input[i])){
					fichier.close(); //sinon il ne sera jamais ferme
					throw string("Erreur dans le fichier des parametres par defaut. D'autres parametres ont ete choisis pour les remplacer.");
				}
			}
        	//On caste le string en char* pour utiliser atoi()
			//En effet stoi(...) ne fonctionne pas bien sous Eclipse
			inputchar = input.c_str();
			//On ajoute l'entier au vecteur des parametres
			param.push_back(atoi(inputchar));
        }
        if (param.size()<3){
			throw string("Fichier des parametres par defaut incomplet. D'autres parametres ont ete choisis pour les remplacer.");
		}
        fichier.close();
        //Maj des parametres selon ce qu'on a recolte dans le fichier
        nombreDeSkieurs = param[0];
        dureeOuverture = param[1];
        frequenceAffichage = param[2];
	}
	catch(string & s){
		cout << "ERREUR : " << s << endl;
		mode="Utilisateur";
		nombreDeSkieurs=50;
		dureeOuverture=10000;
		tempsActuel=0;
		frequenceAffichage=1800;
	}




}

Station::Station(string unMode, int nbSkieurs, int d, int f){
	mode=unMode;
	nombreDeSkieurs=nbSkieurs;
	dureeOuverture=d;
	tempsActuel=0;
	frequenceAffichage=f;

}

string Station::getMode() const {
	return mode;
}

int Station::getNombreDeSkieurs() const{
	return nombreDeSkieurs;
}

int Station::getDureeOuverture() const {
	return dureeOuverture;
}

int Station::getTempsActuel() const{
	return tempsActuel;
}

int Station::getFrequenceAffichage() const{
	return frequenceAffichage;
}

vector<Skieur> Station::getSkieurs() const{
	return skieurs;
}

Skieur Station::getSkieur(int i) const{
	return skieurs[i];
}

vector<Arc*> Station::getArcs() const{
	return arcs;
}

vector<Arc*> Station::getArcsDepart() const{
	return arcsDepart;
}

int Station::demanderInt(int min, int max){
	string input = "";
	const char* inputchar;
	int res = min-1;
	try{
		//On demande une chaine de caractère
		cin >> input;
		//On vérifie que chaque caractère est un chiffre avant de l'affecter à res
		for (int i=0; i<input.size(); i++){
			if (!isdigit(input[i])){
				throw string("Entrée erronée");
			}
		}
		//On caste le string en char* pour utiliser atoi()
		//En effet stoi(...) ne fonctionne pas bien sous Eclipse
		inputchar = input.c_str();
		res = atoi(inputchar);
		//Test pour les limites
		if(res<min || res >max){
			throw string("Valeur hors-limite");
		}
	}
	catch(string & s){
		cout << "ERREUR : " << s << endl;
	}
	return res;
}

int Station::demanderInt(){
	string input = "";
	const char* inputchar;
	int res = -1;
	try{
		//On demande une chaine de caractère
		cin >> input;
		//On vérifie que chaque caractère est un chiffre avant de l'affecter à res
		for (int i=0; i<input.size(); i++){
			if (!isdigit(input[i])){
				throw string("Entrée erronée");
			}
		}
		//On caste le string en char* pour utiliser atoi()
		//En effet stoi(...) ne fonctionne pas bien sous Eclipse
		inputchar = input.c_str();
		res = atoi(inputchar);
		if(res<0){
			res = -1; //pour retourner toujours -1 en cas d'erreur
			throw string("Valeur negative");
		}

	}
	catch(string & s){
		cout << "ERREUR : " << s << endl;
	}
	return res;
}

void Station::modeUtilisateur() {

	afficheTitre("Mode Utilisateur");
	string input = "";
	const char* inputchar;
	string nom = "";
	string prenom = "";
	int niveau = 0;
	int h = -1;
	int m = -1;
	int s = -1;

	cout << "Veuillez rentrer le nom du skieur :" << endl;
	while(nom.empty()){
		cin >> nom;
	}

	cout << "Veuillez rentrer le prénom du skieur :" << endl;
	while(prenom.empty()){
		cin >> prenom;
	}

	cout << "Veuillez rentrer le niveau du skieur (entre 1 et 4) :" << endl;
	while(niveau<1 || niveau >4){
		niveau = demanderInt(1,4);
	}

	cout << "Veuillez rentrer l'heure d'arrivee du skieur (0h0'0'' correspond à l'ouverture de la station) :" << endl;
	vector<int> duree = secondesEnTemps(getDureeOuverture());
	cout << "La station ouvrira pendant " << duree[0] << "h" << duree[1] << "'" << duree[2] << "''" << endl;
	do{
		try{
			cout << "Nombre d'heures :" << endl;
			h = demanderInt();
			cout << "Nombre de minutes :" << endl;
			m = demanderInt();
			cout << "Nombre de secondes :" << endl;
			s = demanderInt();
			if(tempsEnSecondes(h,m,s)>getDureeOuverture()){
				throw string("C'est un peu tard pour arriver !");
			}
			else if(h<0 || m<0 || s<0){
				throw string("Valeur(s) incorrecte(s)");
			}
		}
		catch(string & s){
			cout << "ERREUR : " << s << endl;
		}


	}while(tempsEnSecondes(h,m,s)>getDureeOuverture() || h<0 || m<0 || s<0);

	Skieur monSkieur(nom,prenom,niveau,tempsEnSecondes(h,m,s));
	skieurs.push_back(monSkieur);
	cout << "Bienvenue sur les pistes "<< getSkieur(0).getPrenomS() << " !"<< endl;

	// On cree le fichier pour sauvegarder le bilan du skieur
	ofstream fichier("fichiers/bilan_skieur.txt",ios::out | ios::trunc);
	fichier << monSkieur << endl << endl;
	fichier.close();

	menuModifUtilisateur();
}

void Station::menuModifUtilisateur(){
	afficheTitre("Mode Utilisateur");

	cout << "Vous voulez :" << endl;
	cout << "1) Modifier le nombre de skieurs (Actuellement : " << getNombreDeSkieurs() << ")" << endl;
	cout << "2) Modifier la duree d'ouverture (Actuellement : " << secondesEnTemps(getDureeOuverture())[0] << "h" << secondesEnTemps(getDureeOuverture())[1] << "'" << secondesEnTemps(getDureeOuverture())[2] << "'', soit " << getDureeOuverture() <<" secondes)" << endl;
	cout << "3) Lancer la simulation" << endl;
	cout << "\n0) Retour" << endl;

	int choix = -1;
		while(choix<0 || choix>3){
			choix = demanderInt(0,3);
		}

		switch(choix){
		case 0 :	run();
					break;
		case 1 :	modifierNombreDeSkieurs();
					break;
		case 2 :	modifierDureeOuverture();
					break;
		case 3 : 	lancerSimulation();
					break;
		}
}

void Station::modeAdministrateur(){
	afficheTitre("Mode Administrateur");

	cout << "Vous voulez :" << endl;
	cout << "1) Modifier le nombre de skieurs (Actuellement : " << getNombreDeSkieurs() << ")" << endl;
	cout << "2) Modifier la duree d'ouverture (Actuellement : " << secondesEnTemps(getDureeOuverture())[0] << "h" << secondesEnTemps(getDureeOuverture())[1] << "'" << secondesEnTemps(getDureeOuverture())[2] << "'', soit " << getDureeOuverture() <<" secondes)" << endl;
	cout << "3) Modifier la fréquence d'affichage (Actuellement : toutes les " << secondesEnTemps(getFrequenceAffichage())[0] << "h" << secondesEnTemps(getFrequenceAffichage())[1] << "'" << secondesEnTemps(getFrequenceAffichage())[2] << "'', soit " << getFrequenceAffichage() <<" secondes)" << endl;
	cout << "4) Gérer l'ouverture des installations" << endl;
	cout << "5) Lancer la simulation" << endl;
	cout << "\n0) Retour" << endl;

	int choix = -1;
	while(choix<0 || choix>5){
		choix = demanderInt(0,5);
	}

	switch(choix){
	case 0 :	run();
				break;
	case 1 :	modifierNombreDeSkieurs();
				break;
	case 2 :	modifierDureeOuverture();
				break;
	case 3 :	modifierFrequenceAffichage();
				break;
	case 4 :	//gererArcs();
				break;
	case 5 : 	lancerSimulation();
				break;
	}
}

void Station::lancerSimulation(){

	ofstream fichier("fichiers/skieurs.txt",ios::out);

	int premier; //premier skieur a créer aléatoirement



	/*
	 * Création des arcs
	 */
	initArcs();

	/*
	 * Création des skieurs
	 */
	if(mode=="Utilisateur"){
		premier = 1;
		skieurs[0].setArcsDepart(arcsDepart);

	}
	else{
		premier = 0;
	}
	for(int i=premier;i<nombreDeSkieurs;i++){
		Skieur skieur(getDureeOuverture(),arcsDepart);
		skieurs.push_back(skieur);
		fichier << getSkieur(i) << endl;
	}
	fichier.close();


	simulerStation();

}

void Station::initArcs(){

	ifstream fichier("fichiers/arcs.txt", ios::in);
	string ligne;
	string tmp;
	string nomArc;
	int niveau;
	int frequence;
	int capacite;
	bool ouvert;
	int tempsMoyen;
	Arc arc;
	/*
	 * Pour les types :
	 * 1 Piste
	 * 2 Téléski
	 * 3 Télésiège
	 * 4 Lieu de restauration
	 */
	int type;


	/*
	 * Creation des arcs
	 *
	 * Chaque ligne du fichier se compose ainsi :
	 * 2 char pour son numéro, puis un espace
	 * 25 char pour son nom, puis un espace
	 * 1 char pour son type, puis un espace
	 * 1 char pour son niveau, puis un espace
	 * 2 char pour la fréquence, puis un espace
	 * 2 char pour la capacité, puis un espace
	 * 1 char pour l'ouverture/fermeture, puis un espace
	 * 4 char pour le temps moyen passe sur l'arc, puis un espace
	 * 2 char pour chaque arc suivant (son numéro), puis un espace
	 */

	while(getline(fichier,ligne)){
		// Lecture du nom de l'arc
		nomArc = ligne.substr(3,25);

		// Lecture du type
		tmp = ligne.substr(29,1);
		type = atoi(tmp.c_str());

		// Lecture du niveau
		tmp = ligne.substr(31,1);
		niveau = atoi(tmp.c_str());

		// Lecture de la frequence
		tmp = ligne.substr(33,2);
		frequence = atoi(tmp.c_str());

		// Lecture de la capacite
		tmp = ligne.substr(36,2);
		capacite = atoi(tmp.c_str());

		// Lecture de l'ouverture/fermeture
		tmp = ligne.substr(39,1);
		ouvert = atoi(tmp.c_str());

		// Lecture du temps moyen
		tmp = ligne.substr(41,4);
		tempsMoyen = atoi(tmp.c_str());


		vector<Arc*> tmp;

		// Création de l'arc
		switch(type){
			case 1 : 	{
						arcs.push_back(new Piste(nomArc, ouvert, tempsMoyen, tmp, niveau));
						//cout << piste.getNiveau() << endl;

						break;}
			case 2 : 	{
						arcs.push_back(new Teleski(nomArc, ouvert, tempsMoyen, tmp, niveau, frequence));
						break;}
			case 3 : 	{
						arcs.push_back(new Telesiege(nomArc, ouvert, tempsMoyen, tmp,niveau,frequence, capacite));
						break;}
			case 4 : 	{
						arcs.push_back(new LieuRestauration(nomArc, ouvert, tempsMoyen, tmp,capacite));
						break;}
		}


		for(int i=0;i<arcs.size();i++){
		//	cout << arcs[i]->getNiveau() << endl;
		//	cout << arcs[i]->getNom() << endl;
		}


	}


	/*
	 * On indique maintenant quels sont les arcs suivants de chaque arc
	 */

	// On retourne au debut du fichier
	fichier.clear();
	fichier.seekg(0, ios::beg);

	int nbArc = 0;
	while(getline(fichier,ligne)){
		int tailleLigne = ligne.size();
		int tailleSuivants = tailleLigne - 46;
		string suivants = ligne.substr(46,tailleSuivants);
		// Un arc prend 2 char, suivi d'un espace
		// On simule l'espace a la fin avec le +1
		int nbSuivants = (tailleSuivants+1)/3;
		int suivant;



		for(int i=0;i<nbSuivants;i++){
			tmp = suivants.substr(3*i,2);
			suivant = atoi(tmp.c_str());
			arcs[nbArc]->getSuivants().push_back(arcs[suivant]);
		}


		nbArc++;
	}




	fichier.close();

	arcsDepart.push_back(getArcs()[0]);



}

void Station::deplacerSkieurs(){
/*
	Skieur monSkieur = getSkieur(13);
	cout << monSkieur.getTempsTrajet() << endl;
	cout << monSkieur.getArcActuel()->getNom() << endl;
*/
	int premier = 0;
	if(mode == "Utilisateur"){
		premier = 1;
		skieurs[0].seDeplacer(tempsActuel,"incarner");
	}
	for(int i=premier;i<getNombreDeSkieurs();i++){
		// Si le skieur est arrive il se deplace, sinon rien
		if(getSkieur(i).getHeureArrivee()<=tempsActuel){
			skieurs[i].seDeplacer(tempsActuel,"simuler");
		}

	}
}

bool Station::accueil(){
	afficheTitre("Bienvenue");

	cout << "\nVous êtes :\n1) Administrateur \n2) Utilisateur \n\n0) Quitter" << endl;

	int choix = -1;
	while(choix!=1 && choix!=2 && choix!=0){
		choix = demanderInt(0,2);
	}


	switch(choix){
	case 1 : 	mode = "Administrateur";
				break;
	case 2 :	mode = "Utilisateur";
				break;
	case 0 :	return false;
				break;
	}
	return true;

}

void Station::afficheTitre(string titre){
	cout << string(50, '\n');
	cout << "****" << titre << "****"<< endl;
}

void Station::run(){
	/*
	 * Affichage de l'accueil et lancement du menu suivant selon le mode choisi
	 */
	if(accueil()){
		if(mode=="Utilisateur"){
			modeUtilisateur();
		}
		else{
			modeAdministrateur();
		}
	}
}


int Station::tempsEnSecondes(int h, int m, int s){
	return 60*(60*h+m)+s;
}

vector<int> Station::secondesEnTemps(int s){
	vector<int> res;
	res.push_back(s/3600);
	s %= 3600;
	res.push_back(s/60);
	s %= 60;
	res.push_back(s);
	return res;
}

void Station::modifierNombreDeSkieurs(){
	/*
	 * Affichage
	 */
	string titre = "Mode " + mode + " : Modifier le nombre de skieurs";
	afficheTitre(titre);
	cout << "Veuillez rentrer le nouveau nombre de skieurs (entre " << NB_MIN_SKIEURS << " et "<< NB_MAX_SKIEURS <<") dans la station (Actuellement : " << getNombreDeSkieurs() << ")" << endl;
	int nb = -1;
	/*
	 * Demande du nouveau nombre et mise à jour dans la station
	 */
	while(nb<NB_MIN_SKIEURS || nb>NB_MAX_SKIEURS){
		nb = demanderInt(NB_MIN_SKIEURS,NB_MAX_SKIEURS);
	}
	nombreDeSkieurs = nb;
	/*
	 * Retour au menu précédent
	 */
	if(mode=="Utilisateur"){
		menuModifUtilisateur();
	}
	else{
		//On enregistre les modifications de l'admin dans le fichier des parametres
		sauvegarderParamFichier();
		modeAdministrateur();
	}
}

void Station::modifierDureeOuverture(){
	/*
	 * Affichage
	 */
	string titre = "Mode " + mode + " : Modifier la durée d'ouverture";
	afficheTitre(titre);
	cout << "Veuillez rentrer la nouvelle durée d'ouverture (entre " << DUREE_MIN/3600 << "h et " << DUREE_MAX/3600 << "h) de la station (Actuellement : " << secondesEnTemps(getDureeOuverture())[0] << "h" << secondesEnTemps(getDureeOuverture())[1] << "'" << secondesEnTemps(getDureeOuverture())[2] << "'', soit " << getDureeOuverture() <<" secondes)" << endl;

	int h = -1;
	int m = -1;
	int s = -1;
	/*
	 * Demande de la nouvelle durée et mise à jour dans la station
	 */
	// Heures
	cout << "Nombre d'heures :" << endl;
	while(h<0 || h>DUREE_MAX/3600){
		h = demanderInt(0,DUREE_MAX/3600);
	}
	// Minutes
	cout << "Nombre de minutes :" << endl;
	while(m<0 || m>DUREE_MAX/60 - h*60){
		m = demanderInt(0,DUREE_MAX/60 - h*60);
	}
	// Secondes
	cout << "Nombre de secondes :" << endl;
	while(s<0 || s<DUREE_MIN - (h*60+m)*60 || s>DUREE_MAX - (h*60+m)*60){
		try{
			s = demanderInt(DUREE_MIN - (h*60+m)*60,DUREE_MAX - (h*60+m)*60);
			if(s<0){
				throw string("Valeur incorrecte");
			}
		}
		catch(string & s){
			cout << "ERREUR : " << s << endl;
		}
	}
	dureeOuverture = tempsEnSecondes(h,m,s);
	/*
	 * Retour au menu précédent
	 */
	if(mode=="Utilisateur"){
		menuModifUtilisateur();
	}
	else{
		//On enregistre les modifications de l'admin dans le fichier des parametres
		sauvegarderParamFichier();
		modeAdministrateur();
	}

}

void Station::modifierFrequenceAffichage(){
	/*
	 * Affichage
	 */
	string titre = "Mode " + mode + " : Modifier la fréquence d'affichage";
	afficheTitre(titre);
	cout << "Veuillez rentrer la nouvelle fréquence d'affichage (>" << FREQUENCE_MIN << " secondes) de la station (Actuellement : toutes les " << secondesEnTemps(getFrequenceAffichage())[0] << "h" << secondesEnTemps(getFrequenceAffichage())[1] << "'" << secondesEnTemps(getFrequenceAffichage())[2] << "'', soit " << getFrequenceAffichage() <<" secondes)" << endl;

	int h = -1;
	int m = -1;
	int s = -1;
	/*
	 * Demande de la nouvelle durée et mise à jour dans la station
	 */
	// Heures
	cout << "Nombre d'heures :" << endl;
	while(h<0){
		h = demanderInt();
	}
	// Minutes
	cout << "Nombre de minutes :" << endl;
	while(m<0){
		m = demanderInt();
	}
	// Secondes
	cout << "Nombre de secondes :" << endl;
		while(s<0 || s<FREQUENCE_MIN - (h*60+m)*60){
			s = demanderInt();
		}
	frequenceAffichage = tempsEnSecondes(h,m,s);
	/*
	 * Retour au menu précédent
	 */
	//On enregistre les modifications de l'admin dans le fichier des parametres
	sauvegarderParamFichier();
	modeAdministrateur();

}

void Station::sauvegarderParamFichier(){
	ofstream fichier("fichiers/parametres_par_defaut.txt",ios::out | ios::trunc);
	if(fichier){
		fichier << getNombreDeSkieurs() << endl;
		fichier << getDureeOuverture() << endl;
		fichier << getFrequenceAffichage() << endl;
		fichier.close();
	}
	else{
		cout << "ERREUR : Impossible d'acceder au fichier des parametres" << endl;
	}

}

void Station::simulerStation(){

	if(mode=="Utilisateur"){
		afficheTitre("Mode Utilisateur : Incarner un skieur");
	}
	else{
		afficheTitre("Mode Administrateur : Suivi de la station");
		printf("======================================================================\n");
		printf("|| %8.8s | %25.25s | %7.7s | %15.15s ||\n","Heure","Arcs satures","Skieurs","Attente moyenne");
		printf("======================================================================\n");
	}
	// Tant que la station est ouverture ou qu'il y a encore des skieurs
	while(tempsActuel<=getDureeOuverture()){
		deplacerSkieurs();
		gestionAffichage();
		tempsActuel++;
	}
	printf("======================================================================\n");


}

void Station::gestionAffichage(){
	/*
	 * Si on est en mode Administrateur
	 * Et si c'est le moment d'afficher (d'apres la frequence d'affichage choise)
	 */

	if(mode=="Administrateur" && tempsActuel%getFrequenceAffichage()==0){

		// Detection des arcs satures
		vector<Arc> arcsSatures;
		for(int i=0;i<getArcs().size();i++){
			/*
			if(getArcs()[i].estSature()){
				arcsSatures.push_back(getArcs()[i];
			}*/
		}
		afficheTableauAdmin(arcsSatures,skieursEnStation(),tempsMoyenAttente());

	}
}

int Station::skieursEnStation(){
	int res = 0;
	for(int i=0;i<getNombreDeSkieurs();i++){
		/*
		 * Si le skieur est sur un arc ferme, alors il n'est pas dans la station
		 * Car le seul arc ferme sur lequel il peut se trouver est l'arc construit via le constructeur Arc()
		 * Le skieur se voit atttribuer cet arc uniquement quand il n'est pas dans la station
		 */
		if(getSkieur(i).getArcActuel()->getOuvert() != false){
			res++;
		}
	}
	return res;
}

int Station::tempsMoyenAttente(){
	int somme = 0;
	int compte = 0;
	for(int i=0;i<getNombreDeSkieurs();i++){
		// Si le skieur est deja arrivee
		if(getSkieur(i).getHeureArrivee() <= getTempsActuel()){
			somme += getSkieur(i).getTempsTotalAttente();
			compte++;
		}
	}
	if(compte==0){
		return 0;
	}
	else{
		return somme/compte;
	}

}

void Station::afficheTableauAdmin(vector<Arc> arcsSatures,int nbSkieurs,int tempsMoyenAttente){

	// Le nombre de ligne c'est le nombre d'arcs à écrire
	int nbArcs = arcsSatures.size();

	/*
	 * Premiere ligne
	 */
	// L'heure qu'il est
	printf("|| %02d:%02d:%02d | ",secondesEnTemps(getTempsActuel())[0],secondesEnTemps(getTempsActuel())[1],secondesEnTemps(getTempsActuel())[2]); // 8 caracteres
	// Premier arc sature
	if(nbArcs>0){
		printf("%25.25s | ",arcsSatures[0].getNom().c_str());
	}
	else{
		printf("%25.25s | ","");
	}
	// Nombre de skieurs et temps moyen attente
	printf("%7d | %15d ||\n",nbSkieurs,tempsMoyenAttente);

	/*
	 * Lignes suivantes
	 */
	for(int i=1;i<nbArcs;i++){
		printf("|| %8.8s | %25.25s | %7.7s | %15.15s ||\n","",arcsSatures[i].getNom().c_str(),"","");
	}
	printf("----------------------------------------------------------------------\n");


}




Station::~Station() {
	cout << "Station supprimee" << endl;
}

} /* namespace std */


