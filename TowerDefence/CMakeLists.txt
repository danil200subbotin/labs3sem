cmake_minimum_required(VERSION 3.17)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 14)

add_executable(TowerDefence main.cpp squares/Square.cpp squares/Square.h squares/Castle.cpp squares/Castle.h squares/Lair.cpp squares/Lair.h squares/Road.cpp squares/Road.h squares/Forest.cpp squares/Forest.h activeUnits/Tower.cpp activeUnits/Tower.h "Land/Landscape.cpp" "Land/Landscape.h" activeUnits/TowerSimple.cpp activeUnits/TowerSimple.h activeUnits/TowerMagic.cpp activeUnits/TowerMagic.h activeUnits/Enemy.cpp activeUnits/Enemy.h activeUnits/TowerTrap.cpp activeUnits/TowerTrap.h activeUnits/structs.h Stack.h)




set(SFML_INCLUDE_DIR "/SFML/include")
set(SFML_LIBRARY_DIR "/SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

target_link_libraries (TowerDefence sfml-graphics sfml-window sfml-system)