cmake_minimum_required(VERSION 3.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(chart)

add_executable(${PROJECT_NAME} src/main.cpp src/candle.cpp src/chart.cpp)


#SFML
set(SFML_DIR "D:/projects/c++_libraries/LIB/SFML/lib/cmake/SFML")
#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIRS})


# copy dll files
set(DLL_PATH "${CMAKE_SOURCE_DIR}/external")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${DLL_PATH} $<TARGET_FILE_DIR:${PROJECT_NAME}>
)