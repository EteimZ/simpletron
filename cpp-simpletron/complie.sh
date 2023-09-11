#!/bin/bash

folder_name="build"

# Check if the folder exists
if [ ! -d "$folder_name" ]; then
    # If it doesn't exist, create it
    mkdir "$folder_name"
fi

cd "$folder_name"

# generate cmake files
cmake ..

# compile
make