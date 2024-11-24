cmake_minimum_required(VERSION 3.2)

project(chart)


#SFML
set(SFML_DIR "D:/projects/c++_libraries/LIB/SFML/lib/cmake/SFML")
#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)


#curl

set(CURL_DIR "D:/projects/c++_libraries/LIB/curl/lib/cmake/CURL")

find_package(CURL REQUIRED)


add_executable(${PROJECT_NAME} src/main.cpp src/candle.cpp src/chart.cpp)

#SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIRS})

#CURL
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)
