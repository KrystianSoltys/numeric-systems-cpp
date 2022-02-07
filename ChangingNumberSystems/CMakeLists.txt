# CMakeList.txt : CMake project for numeric-systems-calculator-cmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (ChangingNumberSystems  "ChangingNumberSystems.cpp" "calculator.hpp" "log.hpp" "options.hpp" "ui.hpp" "calculator.cpp" "log.cpp" "options.cpp" "ui.cpp")

# TODO: Add tests and install targets if needed.
