@echo off
mkdir build
cd build
cmake ..
cmake --build .
cd debug
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo Start Programm:
chart.exe
cd ..
cd ..