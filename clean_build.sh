#!/bin/bash

echo "Startin Clean and Build Process..."

sudo rm -rf build
mkdir build
cd build
cmake ..
make

echo "Completed Clean and Build Process..."
