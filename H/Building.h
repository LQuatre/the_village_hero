//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__BUILDING_H
#define THE_VILLAGE_HERO__BUILDING_H

#include <iostream>

class Building {
public:
    Building(std::string name);
    ~Building();

    void setName(const std::string name);
    std::string getName() const;
private:
    std::string m_name;
};


#endif //THE_VILLAGE_HERO__BUILDING_H
