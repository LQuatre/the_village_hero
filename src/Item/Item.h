//
// Created by LQuatre on 06/12/2023.
//

#ifndef THE_VILLAGE_HERO__ITEM_H
#define THE_VILLAGE_HERO__ITEM_H

#include <iostream>
#include <vector>
#include <string>
#include "../Name/Name.h"


class Item : public Name {
public:
    Item(const std::string& name, int quantity);

    int getQuantity() const;
private:
    int m_quantity{};
};


#endif //THE_VILLAGE_HERO__ITEM_H
