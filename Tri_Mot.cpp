/*
 * Tri_Mot.cpp
 *
 *  Created on: 27 janv. 2014
 *      Author: jeje
 */

#include "Controleur.h"
#include <iostream>
#include <fstream>
using namespace std ;


int main(int argc , char* argv[]){
	if(argc == 3){
		ifstream fichier_entree(argv[1] , ios::in);
		ofstream fichier_sortie(argv[2] , ios::out | ios::ate);
		if (fichier_entree && fichier_sortie)
		{
			Controleur controleur ;

			char caractere ;
			while(fichier_entree.get(caractere)){
				cout << "merde" << endl ;
				controleur.Trouver_mot(caractere) ;
			}
			//cout << mot <<endl ;

			/*Impression des données dans le fichier de sortie.*/
			cout << "Voici tous les mots triés du texte : " << endl ;
			controleur.Imprimer(fichier_sortie) ;
		}
		else
		{
			cout << "erreur de lecture de " << (fichier_entree?argv[2]:argv[1])  << endl ;

		}
		return 0 ;
	}
	else{
		cout << "Erreur : les paramètres à donner sont le fichier à charger et"
				"le fichier de sortie." << endl ;
		return 1;
	}
}

