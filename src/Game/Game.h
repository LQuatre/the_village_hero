//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__GAME_H
#define THE_VILLAGE_HERO__GAME_H

#include <iostream>
#include <vector>
#include "../Village/Village.h"
#include "../Player/Player.h"

class Game {
public:
    Game();
    ~Game();

    // Getters
    bool IsRunning() const;

    // Setters
    void start();
    void run();

    // Methods
    void ClearTerminal();
    void Input();
    void help();
private:
    bool m_isRunning = false;

    std::vector<Village*> m_villages;
    Village* m_village;
    std::vector<Player*> m_players;
    Player* m_player;
    std::vector<Character*> m_characters;
};


#endif //THE_VILLAGE_HERO__GAME_H