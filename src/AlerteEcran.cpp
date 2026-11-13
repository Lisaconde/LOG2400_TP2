#include "AlerteEcran.h"
#include <iostream>

void AlerteEcran::afficherAlerteSeuil(const std::string& nom, double quantite,
                                      const std::string& unite, bool faible){
    std::string etat;
    if (faible){
        etat = "faible";
    }
    else{
        etat = "de nouveau suffisante";
    };
    std::cout << "[Ecran] Réserve de " << nom << " " << etat
              << " : " << quantite << " " << unite << "\n";

}