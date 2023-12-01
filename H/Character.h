//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__CHARACTER_H
#define THE_VILLAGE_HERO__CHARACTER_H

#include <iostream>
#include <vector>
#include "Weapon.h"

class Character {
public:
    Character(std::string name, int health, int gold, Weapon* weapon);
    ~Character();

    void setName(std::string name);
    std::string getName() const;

    void setHealth(int health);
    int getHealth() const;
    void heal(int health);

    void takeDamage(int damage);

    void setGold(int gold);
    void addGold(int gold);
    void removeGold(int gold);
    int getGold() const;

    void setWeapon(Weapon* weapon);
    Weapon* getWeapon() const;
    void addWeapon(Weapon* weapon);

private:
    std::string m_name;
    int m_health;
    int m_gold{};
    Weapon* m_weapon;
    std::vector<Weapon*> m_weapons;
};


#endif //THE_VILLAGE_HERO__CHARACTER_H
