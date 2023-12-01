//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__DEALER_H
#define THE_VILLAGE_HERO__DEALER_H

#include "vector"
#include "Building.h"
#include "Weapon.h"
#include "Character.h"

class Dealer : public Building {
public:
    Dealer(const std::string &name, const std::vector<Weapon*> &weapons);
    ~Dealer();
    bool buyWeapon(Character &character, Weapon* weapon);
private:
    std::vector<Weapon*> m_weapons;
};

#endif //THE_VILLAGE_HERO__DEALER_H
