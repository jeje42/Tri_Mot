/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 27 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Controleur> (fichier Controleur.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//
//------------------------------------------------------ Include personnel
#include "Controleur.h"
#include "Stockage.h"

//------------------------------------------------------------- Constantes
const char* Controleur::fin_mot = "\0";
const char* Controleur::virgule = "," ;
const char* Controleur::point = ".";
const char* Controleur::deuxpoints = ":";
const char* Controleur::pointvirgule = ";";
const char* Controleur::pointexclamation = "!" ;
const char* Controleur::pointinterogation = "?" ;
const char* Controleur::apostrophe = "'" ;
const char* Controleur::saut_de_ligne = "\n" ;
const char* Controleur::espace = " " ;
const char* Controleur::rien = "" ;
const int Controleur::taille_max_mot = 30 ;	/*A adapter pour la rapidité
si le texte contient des mots scientifiques :)*/

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Controleur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Controleur::Trouver_mot(char caractere)
{
	//Tri selon le caractere :
	if(caractere != *(Controleur::espace) &&
		caractere != *(Controleur::point) &&
		caractere != *(Controleur::deuxpoints) &&
		caractere != *(Controleur::pointvirgule) &&
		caractere != *(Controleur::pointexclamation) &&
		caractere != *(Controleur::pointinterogation) &&
		caractere != *(Controleur::virgule) &&
		caractere != *(Controleur::apostrophe) &&
		caractere != *(Controleur::saut_de_ligne))
	{
		mot_courant->push_back(caractere) ;
	}
	else
	{
		//Fin du mot courant
		mot_nouveau = true ;
	}

	if(mot_nouveau && !mot_courant->empty()) //la seconde condition vérifie dans le cas de ... ou "  ".
    {
		cout << "Mot en train d'être ajouté : " ;
		mot_courant->operator<<(cout) ;
		/*Il faut ajouter ce mot au tableau texte de stockage.*/
		stockage->Inserer_mot(mot_courant) ;
		cout << "Impression depuis Controleur : " ;
		stockage->Imprimer(cout) ;
		/*Initialisation pour le prochain mot.*/
		cout << "Impression depuis Controleur après initialisation: " ;
		stockage->Imprimer(cout) ;
		cout << "Gueule du pointeur dans le controleur : " << mot_courant << endl ;
		mot_courant = new Mot();
		cout << "Gueule du pointeur dans le controleur : " << mot_courant << endl ;
		//mot_courant->erase() ;

		mot_nouveau = false ;


    }
	return true ;
}

void Controleur::Imprimer(ofstream &fichier_sortie)
{
	cout << "Impression ..." << endl ;
	stockage->Imprimer(fichier_sortie) ;
}
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Controleur::Controleur ( )
// Algorithme :
//
{
	mot_courant = new Mot();
	stockage = new Stockage() ;
	taille_courante = 0;
	mot_nouveau = false ;
	//mot_courant = Mot() ;
#ifdef MAP
    cout << "Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur


Controleur::~Controleur ( )
// Algorithme :
//
{
	delete mot_courant ;
	delete stockage ;
#ifdef MAP
    cout << "Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

