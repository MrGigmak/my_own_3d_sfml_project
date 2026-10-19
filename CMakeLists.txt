cmake_minimum_required(VERSION 3.24)
project(MO3SP LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        3.1.0
    GIT_SHALLOW    ON
    EXCLUDE_FROM_ALL
    SYSTEM
)

set(FETCHCONTENT_QUIET ON CACHE INTERNAL "")

set(SFML_BUILD_NETWORK OFF CACHE INTERNAL "")

set(SFML_BUILD_AUDIO OFF CACHE INTERNAL "")

# Отключаем лишний мусор
set(SFML_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(SFML_BUILD_TESTS OFF CACHE INTERNAL "")
set(SFML_BUILD_DOC OFF CACHE INTERNAL "")
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")

# Скачиваем и подключаем
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SFML::Graphics
    SFML::Window
    SFML::System
)
