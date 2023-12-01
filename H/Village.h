//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__VILLAGE_H
#define THE_VILLAGE_HERO__VILLAGE_H

#include <iostream>
#include "vector"
#include "Building.h"

class Village {
public:
    Village(std::string name);
    ~Village();

    void setName(std::string name);
    std::string getName() const;

private:
    std::string m_name;
    std::vector<Building*> m_buildings;
};


#endif //THE_VILLAGE_HERO__VILLAGE_H
