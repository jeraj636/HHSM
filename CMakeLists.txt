cmake_minimum_required(VERSION 3.20)

project(HHSM)

add_executable(${PROJECT_NAME}
        src/test.cpp
        src/Scene/Glavna.cpp
        src/Scene/Objekt/Objekt.cpp
)
add_subdirectory(src/HenigmaEngine/)
include_directories(${PROJECT_NAME}
            src/HenigmaEngine/src

)

target_link_libraries(${PROJECT_NAME} PRIVATE
        HenigmaEngine
)




