
#pragma once
#include "Destinataire.h"   

class AlerteDistant : public Destinataire {
public:
    void afficherAlerteSeuil(const std::string& nom, double quantite,
                             const std::string& unite, bool faible) override;
};