cmake_minimum_required(VERSION 3.29)
project(Circuits)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:\\SFML\\include)
link_directories(C:\\SFML\\lib)

add_executable(Circuits src/main.cpp
        include/graphics/ComponentDrawable.cpp
        include/graphics/ComponentDrawable.h
        include/graphics/DrawableManager.cpp
        include/graphics/DrawableManager.h
        include/graphics/or/ORGateDrawable.cpp
        include/graphics/or/ORGateDrawable.h
        include/graphics/not/NOTGateDrawable.cpp
        include/graphics/not/NOTGateDrawable.h
        include/graphics/and/ANDGateDrawable.cpp
        include/graphics/and/ANDGateDrawable.h
        include/graphics/dot/DotDrawable.cpp
        include/graphics/dot/DotDrawable.h
        include/graphics/wire/WireDrawable.h
        include/graphics/wire/WireDrawable.cpp
        include/UIManager.cpp
        include/UIManager.h)
target_link_libraries(Circuits -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-audio-d)

