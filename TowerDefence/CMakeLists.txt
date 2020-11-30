cmake_minimum_required(VERSION 3.17)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 14)

add_executable(TowerDefence main.cpp map.h map.cpp squares/Square.cpp squares/Square.h squares/Castle.cpp squares/Castle.h squares/Lair.cpp squares/Lair.h squares/Road.cpp squares/Road.h squares/Forest.cpp squares/Forest.h activeUnits/Tower.cpp activeUnits/Tower.h "Landscape /Landscape.cpp" "Landscape /Landscape.h" activeUnits/TowerSimple.cpp activeUnits/TowerSimple.h activeUnits/TowerMagic.cpp activeUnits/TowerMagic.h activeUnits/Enemy.cpp activeUnits/Enemy.h activeUnits/TowerTrap.cpp activeUnits/TowerTrap.h)