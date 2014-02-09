/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 27 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ------
#if ! defined ( CONTROLEUR_H_ )
#define CONTROLEUR_H_

//--------------------------------------------------- Interfaces utilisées
#include "myvector.h"
#include <fstream>
using std::ofstream;

//------------------------------------------------------------- Constantes
//
//------------------------------------------------------------------ Types
class Stockage ;
typedef myvector <char> Mot ;

//------------------------------------------------------------------------
// Rôle de la classe <Controleur>
//
//
//------------------------------------------------------------------------

class Controleur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	bool Trouver_mot(char caractere) ;

	void Imprimer(ofstream &fichier_sortie) ;

//------------------------------------------------- Surcharge d'opérateurs
    Controleur & operator = ( const Controleur & unControleur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Controleur ( const Controleur & unControleur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
    static const char* virgule ;
	static const char* fin_mot ;
	static const char* point ;
	static const char* deuxpoints ;
	static const char* pointvirgule ;
	static const char* pointexclamation ;
	static const char* pointinterogation ;
	static const char* espace ;
	static const char* rien ;
	static const char* saut_de_ligne ;
	static const char* apostrophe ;
	static const int taille_max_mot ;



protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Stockage* stockage ;
    Mot* mot_courant ;
    bool mot_nouveau ;
    int taille_courante ;
};

//--------------------------- Autres définitions dépendantes de <Controleur>

#endif // CONTROLEUR_H_

