cmake_minimum_required(VERSION 3.22)
project(ee205-lab10d-animal-farm-2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205-lab10d-animal-farm-2 main.cpp addCats.cpp addCats.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h catDatabase.cpp catDatabase.h config.h newTypeDef.h Cat.h Cat.cpp)
