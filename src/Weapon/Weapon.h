//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__WEAPON_H
#define THE_VILLAGE_HERO__WEAPON_H
#include <iostream>
#include "../Name/Name.h"

class Weapon : public Name {
public:
    Weapon(int price, int damage);
    ~Weapon();

    int getPrice() const;
    void setPrice(int price);

    int getDamage() const;
    void setDamage(int damage);
private:
    int m_price;
    int m_damage;
};


#endif //THE_VILLAGE_HERO__WEAPON_H
