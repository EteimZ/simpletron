@echo off

set folder_name=build

REM Check if the folder exists
if not exist "%folder_name%" (
    REM If it doesn't exist, create it
    mkdir "%folder_name%"
)

cd "%folder_name%"

REM Generate cmake files
cmake ..

REM Compile
make