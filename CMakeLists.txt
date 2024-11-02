cmake_minimum_required(VERSION 3.29)
project(Circuits)

set(CMAKE_CXX_STANDARD 14)

include_directories(C:\\SFML\\include)
link_directories(C:\\SFML\\lib)

add_executable(Circuits src/main.cpp
        #include/graphics/ComponentDrawable.h
        #include/graphics/and/ANDGateDrawable.cpp
        #include/graphics/ComponentDrawable.cpp
        #include/graphics/DrawableManager.cpp
        #include/graphics/not/NOTGateDrawable.cpp
        #include/graphics/or/ORGateDrawable.h
        #include/graphics/or/ORGateDrawable.cpp
        include/App.cpp
        include/logic/ComponentLogic.cpp
        include/logic/and/ANDGateLogic.h
        include/logic/and/ANDGateLogic.cpp
        include/App.h
        include/logic/ComponentLogic.h
        #include/FileManager.h
        include/logic/LogicManager.cpp
        include/logic/LogicManager.h
        include/logic/or/ORGateLogic.cpp
        include/logic/or/ORGateLogic.h
        include/logic/not/NOTGateLogic.cpp
        include/logic/not/NOTGateLogic.h
        include/logic/wire/WIRELogic.cpp
        include/logic/wire/WIRELogic.h
        #include/graphics/dot/DotDrawable.cpp
        #include/graphics/dot/DotDrawable.h
        #include/graphics/DrawableManager.h
        #include/UIManager.cpp
        )
target_link_libraries(Circuits -lsfml-window-d -lsfml-system-d -lsfml-graphics-d -lsfml-audio-d)

