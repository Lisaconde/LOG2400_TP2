#include "Reserve.h"

#include <iostream>


Reserve::Reserve()
{
    creerStock("eau",    2000, 500, "mL", "Eau",       "d'eau");
    creerStock("vert",   20,   10,  "g",  "Thé vert",  "de thé vert");
    creerStock("noir",   20,   10,  "g",  "Thé noir",  "de thé noir");
    creerStock("oolong", 20,   10,  "g",  "Thé oolong","de thé oolong");
}

void Reserve::creerStock(const std::string& cle, double quantite, double seuil,
                         const std::string& unite, const std::string& affichage,
                         const std::string& libelle)
{
    elements_[cle] = Stock{quantite, seuil, unite, affichage, libelle};
    ordre_.push_back(cle);
}

void Reserve::afficherReserve() const
{
    for (const auto& cle : ordre_) {
        const Stock& s = elements_.at(cle);
        std::cout << s.affichage << " : " << s.quantite
                  << " " << s.unite << "\n";
    }
}

void Reserve::ajouter(const std::string& nom, double quantite)
{
    const double ancienne = elements_.at(nom).quantite;
    elements_.at(nom).quantite += quantite;
    verifierSeuil(nom, ancienne);
}

void Reserve::retirer(const std::string& nom, double quantite)
{
    const double ancienne = elements_.at(nom).quantite;
    elements_.at(nom).quantite -= quantite;
    verifierSeuil(nom, ancienne);
}

bool Reserve::estSuffisant(const std::string& nom, double quantite) const
{
    return elements_.at(nom).quantite >= quantite;
}

double Reserve::getQuantite(const std::string& nom) const
{
    return elements_.at(nom).quantite;
}

void Reserve::verifierSeuil(const std::string& nom, double ancienneQuantite)
{
    const Stock& s = elements_.at(nom);
    const bool etaitFaible = ancienneQuantite < s.seuil;
    const bool estFaible = s.quantite < s.seuil;
    if (etaitFaible != estFaible) {
        notifier(s.libelle, s.quantite, s.unite, estFaible);
    }
}