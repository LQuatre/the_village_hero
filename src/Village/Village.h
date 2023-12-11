//
// Created by admin on 30/11/2023.
//

#ifndef THE_VILLAGE_HERO__VILLAGE_H
#define THE_VILLAGE_HERO__VILLAGE_H

#include <iostream>
#include "vector"
#include "../Building/Building.h"
#include "../Auberge/Auberge.h"
#include "../Mine/Mine.h"
#include "../Dealer/Dealer.h"

class Village : public Name {
public:
    Village();
    ~Village();

    void addBuilding(Building *building);
    std::vector<Building*> getBuildings() const;

    void generateBuildings();
    void displayBuildings();

    std::vector<Building *> getBuildingsByType(std::string type);

private:
    std::vector<Building*> m_buildings;

    void genBuildingByType(std::string type);
};


#endif //THE_VILLAGE_HERO__VILLAGE_H
