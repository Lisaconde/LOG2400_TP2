#include "SubjetAbstrait.h"

#include <algorithm>

void SubjetAbstrait::attacher(std::shared_ptr<Destinataire> destinataire)
{
    destinataires_.push_back(std::move(destinataire));
}

void SubjetAbstrait::detacher(const std::shared_ptr<Destinataire>& destinataire)
{
    destinataires_.erase(
        std::remove(destinataires_.begin(), destinataires_.end(), destinataire),
        destinataires_.end());
}

void SubjetAbstrait::notifier(const std::string& nom, double quantite,
                             const std::string& unite, bool faible)
{
    for (const auto& d : destinataires_) {
        d->afficherAlerteSeuil(nom, quantite, unite, faible);
    }
}