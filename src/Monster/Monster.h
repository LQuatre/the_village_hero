//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__MONSTER_H
#define THE_VILLAGE_HERO__MONSTER_H

#include "iostream"
#include "../Name/Name.h"

class Monster : public Name {
public:
    Monster(int damage, int health);
    ~Monster();

    void takeDamage(int damage);
private:
    int m_damage;
    int m_health;
};


#endif //THE_VILLAGE_HERO__MONSTER_H
