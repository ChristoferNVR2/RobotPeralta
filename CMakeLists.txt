cmake_minimum_required(VERSION 3.29)
project(RobotPeralta)

set(CMAKE_CXX_STANDARD 20)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLUT
find_package(GLUT REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/libs/glm")

# Add the executable
add_executable(RobotPeralta main.cpp
        CameraManagement.h)

# Link OpenGL, GLUT, and GLU libraries
target_link_libraries(RobotPeralta
        OpenGL::GL
        GLU  # Add GLU here
        glut
        Xmu
        Xi
)
