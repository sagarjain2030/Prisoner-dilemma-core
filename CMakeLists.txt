# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)
project(PrisonerDilemmaCore)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Check if SRC_FILES is empty
if(SRC_FILES)
    # Add executable for the main project
    add_executable(PrisonerDilemma ${SRC_FILES})
else()
    message(FATAL_ERROR "No source files found in src directory")
endif()

find_package(Boost REQUIRED COMPONENTS system beast)

# If Boost is found, link it
if (Boost_FOUND)
    target_include_directories(PrisonerDilemma PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(PrisonerDilemma PRIVATE ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost libraries not found. Please make sure Boost is installed and accessible.")
endif()

# Find GTest package for testing
find_package(GTest CONFIG REQUIRED)

# Add tests
enable_testing()
add_executable(PrisonerDilemmaTests tests/test_main.cpp)

# Link GTest and Boost libraries to your test executable
target_link_libraries(PrisonerDilemmaTests PRIVATE GTest::gtest GTest::gtest_main ${Boost_LIBRARIES})

# Register tests
add_test(NAME PrisonerDilemmaTests COMMAND PrisonerDilemmaTests)
