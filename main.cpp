#include "maillage.hpp"

#include <iostream>     // Entrée/sortie standard
#include <string>       // Type "string"
#include <vector>       // Conteneur "vector" (stockage dynamique)
#include <cmath>        // Fonctions cos, sin, etc
#include <cstdlib>      // Fonction rand
#include <fstream>      // Lecture/écriture de fichiers
#include <ctime>        // Fonction time (utile pour rand)
#include <algorithm>    // Algorithmes génériques de la bibliothèque standard, comme std::find

using namespace std ;   // Utiliser les classes et fonctions de la bibliothèque standard C++ sans le préfixe "std::"

int main() {

    // Maillage rectangle régulier
    MaillageRectangle maillageRegulier(5.0, 3.0, 8, 12) ;

    // Maillage rectangle non régulier
    vector<double> abscisses = {0.0, 1.0, 1.9, 2.5, 3.8, 4.0, 5.0} ;
    vector<double> ordonnees = {0.0, 0.7, 1.7, 2.0, 2.3, 2.9, 3.0} ;
    MaillageRectangle maillageNonRegulier(5.0, 3.0, abscisses, ordonnees) ;

    // Maillage secteur angulaire
    double angle = M_PI * 5 / 4 ;
    MaillageSecteurAngulaire maillageAngle(6.0, angle, 50) ;
    //double angle = M_PI / 4 ;
    //MaillageSecteurAngulaire maillageAngle(6.0, angle, 7) ;
/*
    double angle = M_PI / 4 ;
    MaillageSecteurAngulaire maillageAngle(6.0, angle, 7) ;
    maillageAngle.symetrieAxeOblique(0.0, 0.0, M_PI * 5 / 8) ;
*/

    // Conversions en fichiers txt lisibles sur MATLAB
    maillageRegulier.exportMATLAB("maillage_regulier.txt") ;
    maillageNonRegulier.exportMATLAB("maillage_nonregulier.txt") ;
    maillageAngle.exportMATLAB("maillage_secteurangulaire.txt") ;

    return 0;
}