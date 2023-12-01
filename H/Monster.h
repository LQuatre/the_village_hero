//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__MONSTER_H
#define THE_VILLAGE_HERO__MONSTER_H

#include "iostream"

class Monster {
public:
    Monster(std::string name, int damage, int health);
    ~Monster();

    int takeDamage(int damage);
private:
    std::string m_name;
    int m_damage;
    int m_health;
};


#endif //THE_VILLAGE_HERO__MONSTER_H
