cmake_minimum_required(VERSION 2.8)

# Project
project(boost-dll-002-factory-method)

# Search Boost
find_package(Boost REQUIRED COMPONENTS filesystem)

# Check Boost
if(Boost_FOUND)
  message ("Boost Found")
else()
  message (FATAL_ERROR "Cannot Find Boost")
endif()

# Directories
set(example_BIN_DIR bin)
set(example_INC_DIR include)
set(example_LIB_DIR lib)
set(example_SRC_DIR src)

# Code files
set(plugin_SOURCES ${example_SRC_DIR}/plugin.cpp ${example_SRC_DIR}/plugin_base.cpp)
set(plugin_HEADERS ${example_INC_DIR}/plugin.hpp ${example_INC_DIR}/plugin_base.hpp)
set(executable_SOURCES ${example_SRC_DIR}/main.cpp)

# Add plugin to project
add_library(plugin SHARED ${plugin_SOURCES})

# Include directories
target_include_directories(plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${example_INC_DIR})

# Add executable to project
add_executable(executable ${executable_SOURCES})

# Linking
target_link_libraries(executable PRIVATE ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} dl)

# Include directories
target_include_directories(executable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${example_INC_DIR})

# Install
install(TARGETS executable DESTINATION ${example_BIN_DIR})
install(TARGETS plugin DESTINATION ${example_LIB_DIR})
install(FILES ${plugin_HEADERS} DESTINATION ${example_INC_DIR})
