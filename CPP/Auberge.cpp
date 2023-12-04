//
// Created by admin on 30/11/2023.
//

#include "../H/Auberge.h"

Auberge::Auberge(std::string name, int price, int givingCare) : Building(name) {
    this->m_price = price;
    this->m_givingCare = givingCare;
}

Auberge::~Auberge() {

}

bool Auberge::BuyHeal(Character &character) {
    if (character.getGold() >= this->m_price) {
        character.removeGold(this->m_price);
        this->healPlayer(character, this->m_givingCare);
        std::cout << "Vous avez été soigné de " << this->m_givingCare << " points de vie." << std::endl;
        return true;
    }
    std::cout << "Vous n'avez pas assez d'argent pour vous faire soigner." << std::endl;
    return false;
}

void Auberge::healPlayer(Character &character, int care) {
    character.heal(care);
}

void Auberge::setGiveCare(int care) {
    this->m_givingCare = care;
}