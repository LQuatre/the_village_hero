//
// Created by admin on 30/11/2023.
//

#include "Dealer.h"

Dealer::Dealer(std::string name, const std::vector<Weapon *> &weapons) : Building(name), m_weapons(weapons) {

}

Dealer::~Dealer() {

}

bool Dealer::buyWeapon(Character &character, Weapon *weapon) {
    if (weapon->getPrice() <= character.getGold()) {
        character.removeGold(weapon->getPrice());
        character.addWeapon(weapon);
        std::cout << "Vous avez acheté " << weapon->getName() << " pour " << weapon->getPrice() << " pièces d'or" << std::endl;
        return true;
    }
    std::cout << "Vous n'avez pas assez d'argent pour acheter cette arme" << std::endl;
    return false;
}

