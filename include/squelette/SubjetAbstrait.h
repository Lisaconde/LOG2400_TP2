#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Destinataire.h"

class SubjetAbstrait {
public:
    virtual ~SubjetAbstrait() = default;

    void attacher(std::shared_ptr<Destinataire> destinataire);
    void detacher(const std::shared_ptr<Destinataire>& destinataire);

protected:
    void notifier(const std::string& nom, double quantite,
                  const std::string& unite, bool faible);

private:
    std::vector<std::shared_ptr<Destinataire>> destinataires_;
};