/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : 27 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Réalisation de la classe <Stockage> (fichier Stockage.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Stockage.h"
//------------------------------------------------------------- Constantes
const char* Stockage::fin_texte = "\0";
const int TAILLE_TEXTE_DEFAUT = 10000 ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Stockage::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Stockage::Inserer_mot(Mot* mot){
	int place = this->Trouver_place(mot);
	cout << "Place décidée : " << place << endl ;
	if(place == texte->size())
	{
		Mot* mot_a_ajouter = new Mot(*mot) ;
		//cout << "Gueule du pointeur : " << mot_a_ajouter << endl ;
		//mot_a_ajouter->operator<<(cout) ;
		//mot_a_ajouter->operator<<(cout) ;
		texte->push_back(mot_a_ajouter);
		//cout << "Impression : " << endl ;
		//Imprimer(cout) ;
	}
	else if (place==-1)
	{
		return true ;
	}
	else
	{
		//On insère l'élément à sa place voulue.
		Mot* mot_a_ajouter = new Mot(*mot) ;
		cout << "Avant insertion : " << endl ;
		//mot_a_ajouter->operator<<(cout) ;
		Imprimer(cout);
		cout << "Gueule du pointeur dans Stockage : " << mot_a_ajouter << endl ;
		texte->insert(mot_a_ajouter,place) ;
		cout << "Après insertion : " << endl ;
		Imprimer(cout);
		//cout << "Impression : " << endl ;
		//Imprimer(cout) ;
	}
	return true ;
}

/*bool Stockage::Decaler_texte(int place)
{

}*/

int Stockage::Mot1_inferieur(Mot* mot1 , int endroit_texte , int taille)
{
	cout << "Rentrée dans Mot1_inférieur." << endl ;
	bool egal = false;
	for(int i=0 ; i<taille ; i++)
	{
		char lettre1 = mot1->operator[](i) ;
		//cout << "encore" << mot2->size() << endl ;
		//cout << "merde1" << endl ;
		cout << "Mot avant d'incrémenter dans Mot1_Inferieur : " << texte->size() << endl ;
		Imprimer(cout) ;
		if (endroit_texte == 5 ){
		texte->operator[](endroit_texte-1)->operator<<(cout) ;
		}
		cout << "Fin de l'impression dans Mot1_Inferieur." << endl ;
		char lettre2 = texte->operator[](endroit_texte)->operator[](i) ;
		//cout << "merde2" << endl ;
		if(lettre1 > lettre2)
		{
			/*Le mot1 à insérer est supérieur.*/
			cout << "Le mot_courant est supérieur" << endl ;
			return 0 ;
		}
		else if(lettre1==lettre2)
		{
			egal = true;
		}
		else
		{
			/*Le mot1 est inférieur.*/
			cout << "Le mot_courant est inférieur" << endl ;
			return 1 ;
		}
	}
	if(egal)
	{
		/*Les mots sont égaux.*/
		return -1;
	}
	else return 2 ; /*L'algorithme ne devrait jamais atteindre ce stade.*/
}

int Stockage::Trouver_place(Mot* mot){
	int i=0 ;
	int j ;
	cout << "Texte avant toute insertion." << endl ;
	Imprimer(cout);
	int taille_du_texte = texte->size() ;
	while (i<taille_du_texte)
	{
		if(mot->size() == texte->operator[](i)->size())
		{
			/*Il faut maintenant classer par ordre alphabétique les
			 * éléments de même taille.*/
			j = i;
			i = taille_du_texte ;
			cout << mot->size() << endl ;
			while(j<taille_du_texte)// && mot->size() == texte->operator[](j)->size())
			{
				cout << "Valeur de j en entrant dans le while : " << j << endl ;
				//cout << "Element en vue : " ;texte->operator[](taille_du_texte-1)->operator<<(cout) ;
				int condition = Mot1_inferieur( mot , j ,mot->size());
				cout << "Condition : " << condition << endl ;
				if(condition == 1)
				{
					/*Le mot à placer est inférieur à son suivant du moment, on va l'insérer à
					 * l'endroit où il est maintenant.*/
					return j;
				}
				else if(condition == -1)
				{
					//Les mots sont égaux : pas besoin de réinsérer.
					return -1 ;
				}
				else if(condition == 0)
				{
					/*Le mot à insérer est supérieur, donc on continue à parcourir le tableau*/
					cout << "Mot avant d'incrémenter j : " << endl ;
					texte->operator[](j)->operator<<(cout) ;
					j++ ;
					cout << "Valeur de j : " << j << " ; taille du texte : " << taille_du_texte << endl ;
					//cout << "TAille du mot examiné par le prochain while : " << texte->operator[](taille_du_texte-1)->size() << endl ;
				}
				else return 2;

			}
			cout << "Sortie du while ; " << endl ;
			/*Le mot est alphabétiquement dernier parmi ceux de sa
			 * taille.*/
			return j ;
		}
		else if(mot->size() > texte->operator[](i)->size())
		{
			//On continue à parcourir
			i++;
		}
		else
		{
			/*Le mot à insérer a une taille inférieur à celui qu'il est en train de pointer,
			 * donc on l'insère à cet endroit et on décale le reste du tableau.*/
			return i;
		}
	}
	/*Si on sort de ce while, la taille du mot à insérer est supérieur à celle de tous les mots déjà présents,
	 * il suffit de l'insérer à la fin du tableau*/
	return taille_du_texte ;
}
/*
Mot & Stockage::Get_mot(int endroit)
{
	return texte->operator[](endroit) ;
}
*/

void Stockage::Imprimer(ostream &fichier_sortie)
{
	int i = 0;
	while ( i < texte->size())
	{
		//texte[i].operator<<(fichier_sortie) ;
		//Mot* mot = texte->operator[](i);
		//Mot* mot_a_afficher = texte[i] ;
		//cout <<  mot->operator<<(cout) << endl;
		texte->operator[](i)->operator<<(fichier_sortie) ;
		i++ ;
	}
}
//------------------------------------------------- Surcharge d'opérateurs
/*Stockage & Stockage::operator = ( const Stockage & unStockage )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur


Stockage::Stockage ( )
// Algorithme :
//
{
	texte = new Texte(TAILLE_TEXTE_DEFAUT) ;
#ifdef MAP
    cout << "Appel au constructeur de <Stockage>" << endl;
#endif
} //----- Fin de Stockage


Stockage::~Stockage ( )
// Algorithme :
//
{
	delete texte ;
#ifdef MAP
    cout << "Appel au destructeur de <Stockage>" << endl;
#endif
} //----- Fin de ~Stockage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

