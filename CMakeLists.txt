cmake_minimum_required(VERSION 3.29)
project(Circuits)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:\\SFML\\include)
link_directories(C:\\SFML\\lib)

add_executable(Circuits src/main.cpp
        include/ComponentDrawable.h
        include/ANDGateDrawable.cpp
        include/ComponentDrawable.cpp
        include/DrawableManager.cpp)
target_link_libraries(Circuits -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-audio-d)

