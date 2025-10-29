cmake_minimum_required(VERSION 3.10)
project(Clip VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Carpeta de headers
include_directories(include)

# Archivos fuente
add_executable(clip
    src/main.cpp
    src/clip.cpp
    src/todo.cpp       
    src/tasklist.cpp   
    src/task.cpp
)

set_target_properties(
    clip PROPERTIES
    OUTPUT_NAME "clip-0.1.0"
) 
