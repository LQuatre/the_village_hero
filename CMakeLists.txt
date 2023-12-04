cmake_minimum_required(VERSION 3.26)
project(The_village_hero_)

set(CMAKE_CXX_STANDARD 17)

add_executable(The_village_hero_ main.cpp
        H/Game.h
        H/Village.h
        H/Player.h
        CPP/Village.cpp
        CPP/Player.cpp
        CPP/Game.cpp
        H/Building.h
        CPP/Building.cpp
        H/Dealer.h
        CPP/Weapon.cpp
        H/Weapon.h
        H/Monster.h
        CPP/Monster.cpp
        H/Mine.h
        CPP/Mine.cpp
        CPP/Dealer.cpp
        H/Character.h
        CPP/Character.cpp
        H/Auberge.h
        CPP/Auberge.cpp
        dasmig/namegen.hpp
        dasmig/random.hpp)
