/*************************************************************************
                           myvector  -  description
                             -------------------
    début                : 30 janv. 2014
    copyright            : (C) 2014 par jeje
*************************************************************************/

//---------- Interface de la classe <myvector> (fichier myvector.h) ------
#if ! defined ( MYVECTOR_H_ )
#define MYVECTOR_H_

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std ;

//------------------------------------------------------------- Constantes 
const int TAILLE_DEPART = 100 ;

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <myvector>
//Stocker comme un vector classique des types T dans un tableau de taille
//dynamique.
//------------------------------------------------------------------------ 
template <class T>
class myvector
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	T * Print(){
		for (int i = 0 ; i<taille ; i++)
		{
			cout << tableau[i] ;
		}
		cout << endl ;
		return tableau ;}
	int size(){return taille ;}

	bool empty(){return taille==0 ? true:false ;}

	void erase(){taille = 0 ;}

	bool insert(T element , int endroit)
	{
		if (endroit > taille)
		{
			cout << endroit << " : la taille du vector n'est que de " << taille << endl ;
			return false ;
		}
		else
		{
			if((taille+1)>taille_max)
			{
				Faire_place() ;
			}
			//faire une place au milieu.
			int i = endroit ;

			T buffer1 = *(tableau+i);
			T buffer2 ;
			while (i<taille)
			{
				buffer2 = *(tableau+i+1) ;
				*(tableau+i+1) = buffer1 ;
				buffer1 = buffer2 ;
				i++ ;
			}
			//Insertion pure du mot dans sa place nouvellement libérée

			tableau[endroit] = element ;
			taille++ ;
			return true;
		}
	}

	void push_back(T &element)
	{
		if((taille+1)>taille_max)
		{
			Faire_place() ;
		}
		//Ajout pur de l'élément.
		tableau[taille++] = element ;
	}


//------------------------------------------------- Surcharge d'opérateurs
	T & operator [] ( int element_voulu)
	{
		return *(tableau + element_voulu) ;
	}

	ostream &operator << ( ostream &os )
	{
		for (int i = 0 ; i<taille ; i++)
		{
			os << tableau[i] ;
		}
		os << endl ;
		return os ;
	}




	/*ostream & operator << ( ostream &os )
	{
		//cout << "je ne sais pas afficher." << endl ;
		for(unsigned int i = 0 ; i<taille ; i++)
		{
			os << *(tableau+i) ;
		}
		return os ;
	}

	ostream & operator<< ( ostream &os , char cmyvector<char>::)
	{
		for(unsigned int i = 0 ; i<taille ; i++)
		{
			os << *(tableau+i) ;
		}
		os << endl ;
		return os ;
	}*/

	myvector operator = ( const myvector & unmyvector )
	{
		//copie en profondeur.
		myvector* vect = new myvector ;
		vect->taille = unmyvector.taille ;
		vect->taille_max = unmyvector.taille_max ;
		vect->tableau = new T [taille] ;
		for(unsigned int i=0 ; i<unmyvector.taille ; i++)
		{
			vect->tableau[i] = unmyvector.tableau[i] ;
		}
		return *vect ;
	}


//-------------------------------------------- Constructeurs - destructeur
    myvector ( const myvector & unmyvector )
    {
		taille = unmyvector.taille ;
		taille_max = unmyvector.taille_max ;
		tableau = new T [taille] ;
		for(unsigned int i=0 ; i<unmyvector.taille ; i++)
		{
			tableau[i] = unmyvector.tableau[i] ;
		}
    }
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    myvector (int taille0 = TAILLE_DEPART){
    	taille_max = taille0 ;
    	taille = 0 ;
    	tableau = new T [taille] ;
    }
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~myvector ( ){delete tableau ;}
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int taille ;
    int taille_max ;
    T* tableau ;

private :
    //--------------------------------------------------- Méthodes privées

    bool Faire_place()
    {
    	taille_max += taille_max ;
		T* new_tableau = new T [taille_max] ;
		//Copie en profondeur
		for(unsigned int i=0 ; i<taille ; i++)
		{
			new_tableau[i] = tableau[i];
		}
		//Changer le pointeur de tableau au nouveau.
		delete [] tableau ;
		tableau = new_tableau ;
		return true ;
    }
};

//--------------------------- Autres définitions dépendantes de <myvector>
/*
template<> class myvector<char>
{
	//----------------------------------------------------------------- PUBLIC

	public:
	//----------------------------------------------------- Méthodes publiques
	    // type Méthode ( liste des paramètres );
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //
		char * Print(){return tableau ;}
		int size(){return taille ;}

		bool empty(){return taille==0 ? true:false ;}

		void erase(){taille = 0 ;}

		bool insert(char &element , int endroit)
		{
			if (endroit > taille)
			{
				cout << endroit << " : la taille du vector n'est que de " << taille << endl ;
				return false ;
			}
			else
			{
				if((taille+1)>taille_max)
				{
					Faire_place() ;
				}
				//faire une place au milieu.
				int i = endroit ;

				char buffer1 = tableau[i];
				char buffer2 ;
				while (i<taille)
				{
					buffer2 = tableau[i+1] ;
					tableau[i+1] = buffer1 ;
					buffer1 = buffer2 ;
					i++ ;
				}
				//Insertion pure du mot dans sa place nouvellement libérée
				tableau[i] = element ;
				return true;
			}
		}

		void push_back(char &element)
		{
			if((taille+1)>taille_max)
			{
				Faire_place() ;
			}
			//Ajout pur de l'élément.
			tableau[taille++] = element ;
		}


	//------------------------------------------------- Surcharge d'opérateurs
		char & operator [] ( int element_voulu)
		{
			return *(tableau + element_voulu) ;
		}


		ostream& operator << ( ostream &os )
		{
			for(int i = 0 ; i<taille ; i++)
			{
				os << tableau[i] ;
			}
			os << endl ;
		return os ;
		}


		myvector operator = ( const myvector & unmyvector )
		{
			//copie en profondeur.
			myvector vect ;
			vect.taille = unmyvector.taille ;
			vect.taille_max = unmyvector.taille_max ;
			for(int i=0 ; i<unmyvector.taille ; i++)
			{
				vect.push_back(unmyvector.tableau[i]) ;
			}
			return vect ;
		}


	//-------------------------------------------- Constructeurs - destructeur
	    myvector ( const myvector & unmyvector )
	    {
			taille = unmyvector.taille ;
			taille_max = unmyvector.taille_max ;
			for(int i=0 ; i<unmyvector.taille ; i++)
			{
				push_back(unmyvector.tableau[i]) ;
			}
	    }
	    // Mode d'emploi (constructeur de copie) :
	    //
	    // Contrat :
	    //

	    myvector (int taille0 = TAILLE_DEPART){
	    	taille_max = taille0 ;
	    	taille = 0 ;
	    	tableau = new char [taille] ;
	    }
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

	    virtual ~myvector ( ){delete tableau ;}
	    // Mode d'emploi :
	    //
	    // Contrat :
	    //

	//------------------------------------------------------------------ PRIVE

	protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	    int taille ;
	    int taille_max ;
	    char* tableau ;

	private :
	    //--------------------------------------------------- Méthodes privées

	    bool Faire_place()
	    {
	    	taille_max += taille_max ;
			char* new_tableau = new char [taille_max] ;
			//Copie en profondeur
			for(int i=0 ; i<taille ; i++)
			{
				new_tableau[i] = tableau[i];
			}
			//Changer le pointeur de tableau au nouveau.
			delete [] tableau ;
			tableau = new_tableau ;
			return true ;
	    }
};
*/


#endif // MYVECTOR_H_

