/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : 27 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/
//Modifié !!!
//---------- Interface de la classe <Stockage> (fichier Stockage.h) ------
#if ! defined ( STOCKAGE_H_ )
#define STOCKAGE_H_

//--------------------------------------------------- Interfaces utilisées
#include "myvector.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef myvector<char> Mot ;
typedef myvector<Mot*> Texte ;

//------------------------------------------------------------------------
// Rôle de la classe <Stockage>
//
//
//------------------------------------------------------------------------

class Stockage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	bool Inserer_mot(Mot* mot) ;

	int Mot1_inferieur(Mot* mot1 , int endroit_texte , int taille);

	int Trouver_place(Mot* mot) ;

	Mot & Get_mot(int endroit) ;

	void Imprimer(ostream &fichier_sortie) ;

	//------------------------------------------------- Surcharge d'opérateurs
    Stockage & operator = ( const Stockage & unStockage );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Stockage ( const Stockage & unStockage );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Stockage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Stockage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    static const char* fin_texte;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Texte* texte ;

};

//--------------------------- Autres définitions dépendantes de <Stockage>

#endif // STOCKAGE_H_

