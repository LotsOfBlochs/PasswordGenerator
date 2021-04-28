# CMakeList.txt : CMake project for PasswordGenerator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PasswordGenerator")

# Add source to this project's executable.
add_executable (PasswordGenerator   "Constants.cpp" "Constants.h" "PasswordGenerator.cpp" "PasswordGenerator.h")

# TODO: Add tests and install targets if needed.
