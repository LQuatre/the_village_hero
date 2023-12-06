//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__MINE_H
#define THE_VILLAGE_HERO__MINE_H

#include <iostream>
#include <vector>

#include "../Building/Building.h"
#include "../Monster/Monster.h"
#include "../Player/Player.h"

class Mine : public Building {
public:
    Mine(std::string name, int givingGold, std::vector<Monster*> monsters);
    ~Mine();

    void setGiveGold(int gold);

    void setMonster(Monster* monster);
    void addMonster(Monster* monster);
    void delMonster(Monster* monster);
private:
    int m_givingGold;
    std::vector<Monster*> m_monsters;
    Monster* m_monster{};
};


#endif //THE_VILLAGE_HERO__MINE_H
