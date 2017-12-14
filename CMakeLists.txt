cmake_minimum_required (VERSION 3.1.0)
project (Calendar)
add_executable(unittest Tests.cpp Date.cpp DateInterval.cpp)

set_property(TARGET unittest PROPERTY CXX_STANDARD 14)
set_property(TARGET unittest PROPERTY CXX_STANDARD_REQUIRED ON)