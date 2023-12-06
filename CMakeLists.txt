cmake_minimum_required(VERSION 3.26)
project(The_village_hero_)

set(CMAKE_CXX_STANDARD 17)

add_executable(The_village_hero_ main.cpp
        src/Game/Game.h
        src/Village/Village.h
        src/Player/Player.h
        src/Village/Village.cpp
        src/Player/Player.cpp
        src/Game/Game.cpp
        src/Building/Building.h
        src/Building/Building.cpp
        src/Dealer/Dealer.h
        src/Weapon/Weapon.cpp
        src/Weapon/Weapon.h
        src/Monster/Monster.h
        src/Monster/Monster.cpp
        src/Mine/Mine.h
        src/Mine/Mine.cpp
        src/Dealer/Dealer.cpp
        src/Character/Character.h
        src/Character/Character.cpp
        src/Auberge/Auberge.h
        src/Auberge/Auberge.cpp
        dasmig/namegen.hpp
        dasmig/random.hpp
        src/Name/Name.h
        src/Name/Name.cpp)
