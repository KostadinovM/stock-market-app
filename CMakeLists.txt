project(stock-market-app)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/libs/imgui)
include_directories(${CMAKE_SOURCE_DIR}/libs/implot) # Include ImPlot headers

# Include ImGui backends directory
include_directories(${CMAKE_SOURCE_DIR}/libs/imgui/backends)

file(GLOB SOURCES "src/*.cpp")

# ImGui source files
file(GLOB IMGUI_SOURCES
    ${CMAKE_SOURCE_DIR}/libs/imgui/*.cpp
)

# ImPlot source files
file(GLOB IMPLOT_SOURCES
    ${CMAKE_SOURCE_DIR}/libs/implot/*.cpp
)

# ImGui backend source files
file(GLOB IMGUI_BACKEND_SOURCES
    ${CMAKE_SOURCE_DIR}/libs/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/libs/imgui/backends/imgui_impl_opengl3.cpp
)

add_executable(stock-market-app ${SOURCES} ${IMGUI_SOURCES} ${IMPLOT_SOURCES} ${IMGUI_BACKEND_SOURCES})

# Find and link libcurl
find_package(CURL REQUIRED)
target_link_libraries(stock-market-app PRIVATE CURL::libcurl)

# Link ImGui and ImPlot (no additional libraries needed for these)
target_link_libraries(stock-market-app PRIVATE CURL::libcurl)

# Find and link GLFW
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Link GLFW and OpenGL
target_link_libraries(stock-market-app PRIVATE glfw OpenGL::GL)

# Add this line to ensure the executable is generated
set_target_properties(stock-market-app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)