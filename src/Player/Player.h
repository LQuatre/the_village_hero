//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__PLAYER_H
#define THE_VILLAGE_HERO__PLAYER_H

#include "../Character/Character.h"

class Player {
public:
    Player();
    ~Player();

    void setCharacter(const Character& character);
    Character getCharacter() const;
    Character * getCharacterPtr();
    void setAdmin(bool admin);
    bool getAdmin() const;
private:
    Character m_character = *new Character(100, 10, nullptr);
    bool m_admin = false;
};


#endif //THE_VILLAGE_HERO__PLAYER_H
