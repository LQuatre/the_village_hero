//
// Created by LQuatre on 06/12/2023.
//

#include "Item.h"

Item::Item(const std::string& name, int quantity) : Name(name) {
    m_quantity = quantity;
}

int Item::getQuantity() const {
    return m_quantity;
}