cmake_minimum_required(VERSION 3.29)
project(Circuits)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:\\SFML\\include)
link_directories(C:\\SFML\\lib)

add_executable(Circuits src/main.cpp
        include/ComponentDrawable.h
        include/ANDGateDrawable.cpp
        include/ComponentDrawable.cpp
        include/DrawableManager.cpp
        include/NOTGateDrawable.cpp
        include/ORGateDrawable.h
        include/ORGateDrawable.cpp
        include/App.cpp
        include/logic/ComponentLogic.cpp
        include/logic/and/ANDGateLogic.h
        include/logic/and/ANDGateLogic.cpp
        include/App.h
        include/logic/ComponentLogic.h
        include/FileManager.h
        include/logic/LogicManager.cpp
        include/logic/LogicManager.h
        include/logic/or/ORGateLogic.cpp
        include/logic/or/ORGateLogic.h
        include/logic/not/NOTGateLogic.cpp
        include/logic/not/NOTGateLogic.h
        include/logic/wire/WIRELogic.cpp
        include/logic/wire/WIRELogic.h
        include/DotDrawable.cpp
        include/DotDrawable.h
        include/DrawableManager.h
        include/UIManager.cpp)
target_link_libraries(Circuits -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-audio-d)

