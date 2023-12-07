//
// Created by LQuatre on 07/12/2023.
//

#ifndef THE_VILLAGE_HERO__QUETE_H
#define THE_VILLAGE_HERO__QUETE_H
#include <iostream>
#include "../Name/Name.h"

class Quete : public Name {
public:
    Quete(std::string name, std::string description, std::string action, int requireExp, int exp, int gold);
    ~Quete();

    std::string getDescription() const;
    std::string getAction() const;
    int getExp() const;
    int getGold() const;
    int getRequireExp() const;
    void setActive(bool active);

    bool getActive();
    void setFinish(bool finish);
    bool getFinish();

private:
    std::string m_description;
    std::string m_action;
    int m_requireExp;
    int m_exp;
    int m_gold;
    bool m_active = false;
    bool m_finish = false;
};

#endif //THE_VILLAGE_HERO__QUETE_H
