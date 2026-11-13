#pragma once
#include <string>

class Destinataire {
public:
    virtual ~Destinataire() = default;

    virtual void afficherAlerteSeuil(const std::string& nom, double quantite,
                                     const std::string& unite, bool faible) = 0;
};