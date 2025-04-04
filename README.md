# CMake and ImGui Project

This project is a simple template for using CMake with ImGui, a popular immediate mode GUI library. It provides a basic setup to get started with creating graphical applications using ImGui.

## Project Structure

```
cmake-imgui-project
├── src
│   ├── main.cpp          # Entry point of the application
├── CMakeLists.txt       # CMake configuration file
├── README.md            # Project documentation
└── .gitignore           # Git ignore file
```

## Requirements

- CMake (version 3.10 or higher)
- A C++ compiler that supports C++11 or higher
- ImGui library

## Building the Project

1. Clone the repository:
   ```
   git clone <repository-url>
   cd cmake-imgui-project
   ```

2. Create a build directory:
   ```
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:
   ```
   cmake ..
   ```

4. Build the project:
   ```
   cmake --build .
   ```

## Running the Application

After building the project, you can run the application from the build directory:
```
./cmake-imgui-project
```

## License

This project is licensed under the MIT License. See the LICENSE file for more details.