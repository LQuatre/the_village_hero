//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__PLAYER_H
#define THE_VILLAGE_HERO__PLAYER_H

#include "Character.h"

class Player {
public:
    Player(const Character& character);
    ~Player();

    void setCharacter(const Character& character);
    Character getCharacter() const;
    const Character* getCharacterPtr();

private:
    Character m_character = Character("Default", 0, 0, nullptr);
};


#endif //THE_VILLAGE_HERO__PLAYER_H
