cmake_minimum_required(VERSION 3.7)
project(Fluid_SPH)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Simulation.cpp Simulation.h)
add_executable(Fluid_SPH ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Fluid_SPH ${SFML_LIBRARIES})
endif()