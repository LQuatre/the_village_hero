//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__BUILDING_H
#define THE_VILLAGE_HERO__BUILDING_H

#include <iostream>
#include "../Name/Name.h"

class Building : public Name {
public:
    Building();
    Building(const std::string& name);
    ~Building();
    std::string getType() const;
private:
};


#endif //THE_VILLAGE_HERO__BUILDING_H
