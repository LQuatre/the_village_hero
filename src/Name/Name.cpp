//
// Created by lucas on 05/12/2023.
//

#include "Name.h"

Name::Name() {
    m_name = generateName(ng::gender::m, ng::culture::french);
}

Name::Name(std::string name) {
    if (name == "") {
        name = generateName(ng::gender::m, ng::culture::french);
    }
    m_name = name;
}

Name::~Name() {}

void Name::setName(std::string name) {
    m_name = name;
}

std::string Name::getName() const {
    return m_name;
}

std::string Name::generateName(ng::gender sexe, ng::culture culture) {
    ng::instance().load("../resources");
    std::wstring franch_name = ng::instance().get_name(sexe, culture);
//    std::wcout << franch_name << std::endl;
    std::string name;
    name.assign(franch_name.begin(), franch_name.end());
    return name;
}

std::string Name::generateName() {
    return generateName(ng::gender::m, ng::culture::french);
}
