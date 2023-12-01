//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__WEAPON_H
#define THE_VILLAGE_HERO__WEAPON_H
#include <iostream>

class Weapon {
public:
    Weapon(const std::string &name, int price, int damage);
    ~Weapon();

    std::string getName();
    void setName(const std::string &name);

    int getPrice() const;
    void setPrice(int price);

    int getDamage() const;
    void setDamage(int damage);
private:
    std::string m_name;
    int m_price;
    int m_damage;
};


#endif //THE_VILLAGE_HERO__WEAPON_H
