#!/bin/bash

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
  echo "Creating build directory..."
  mkdir build
fi

# Move into the build directory
cd build || exit

# Run CMake to configure the project
echo "Configuring the project with CMake..."
cmake ..

# Check if CMake succeeded
if [ $? -eq 0 ]; then
  echo "CMake configuration successful."
else
  echo "CMake configuration failed."
  exit 1
fi

# Build the project
echo "Building the project..."
cmake --build . --config Release

# Check if the build succeeded
if [ $? -eq 0 ]; then
  echo "Build successful."
else
  echo "Build failed."
  exit 1
fi