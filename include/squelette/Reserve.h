#pragma once

#include <map>
#include <string>
#include <vector>

#include "SubjetAbstrait.h"

class Reserve : public SubjetAbstrait {
public:
    Reserve();

    void afficherReserve() const;
    void ajouter(const std::string& nom, double quantite);
    void retirer(const std::string& nom, double quantite);
    bool estSuffisant(const std::string& nom, double quantite) const;
    double getQuantite(const std::string& nom) const;

private:
    struct Stock {
        double quantite;
        double seuil;
        std::string unite;
        std::string affichage;   // "Eau", "Thé vert"...
        std::string libelle;     // "d'eau", "de thé vert"...
    };
    void creerStock(const std::string& cle, double quantite, double seuil,
                    const std::string& unite, const std::string& affichage,
                    const std::string& libelle);
    void verifierSeuil(const std::string& nom, double ancienneQuantite);

    std::map<std::string, Stock> elements_;
    std::vector<std::string> ordre_;
};