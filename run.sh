#!/bin/bash

# Path to the executable
EXECUTABLE="build/bin/stock-market-app"

# Check if the executable exists
if [ -f "$EXECUTABLE" ]; then
  echo "Running the application..."
  "$EXECUTABLE"
else
  echo "Executable not found. Please build the project first."
  exit 1
fi
