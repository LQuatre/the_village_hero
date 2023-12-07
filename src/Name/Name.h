//
// Created by lucas on 05/12/2023.
//

#ifndef THE_VILLAGE_HERO__NAME_H
#define THE_VILLAGE_HERO__NAME_H

#include <iostream>
#include "../../dasmig/namegen.hpp"

// For convenience.
using ng = dasmig::ng;

class Name {
public:
    Name();
    Name(std::string name);
    ~Name();
    void setName(std::string name);
    std::string getName() const;
    std::string generateName();
protected:
    std::string m_name;
    std::string generateName(dasmig::ng::gender sexe, dasmig::ng::culture culture);
};


#endif //THE_VILLAGE_HERO__NAME_H
