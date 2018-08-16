cmake_minimum_required(VERSION 2.8)

# Project
project(boost-dll-003-alias)

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
set(plugin_1_SOURCES ${example_SRC_DIR}/plugin_1.cpp ${example_SRC_DIR}/plugin_base.cpp)
set(plugin_1_HEADERS ${example_INC_DIR}/plugin_1.hpp ${example_INC_DIR}/plugin_base.hpp)
set(plugin_2_SOURCES ${example_SRC_DIR}/plugin_2.cpp ${example_SRC_DIR}/plugin_base.cpp)
set(plugin_2_HEADERS ${example_INC_DIR}/plugin_2.hpp ${example_INC_DIR}/plugin_base.hpp)
set(executable_SOURCES ${example_SRC_DIR}/main.cpp)

# Add plugin to project
add_library(plugin_1 SHARED ${plugin_1_SOURCES})
add_library(plugin_2 SHARED ${plugin_2_SOURCES})

# Include directories
target_include_directories(plugin_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${example_INC_DIR})
target_include_directories(plugin_2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${example_INC_DIR})

# Add executable to project
add_executable(executable ${executable_SOURCES})

# Linking
target_link_libraries(executable PRIVATE ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} dl)

# Include directories
target_include_directories(executable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${example_INC_DIR})

# Install
install(TARGETS executable DESTINATION ${example_BIN_DIR})
install(TARGETS plugin_1 DESTINATION ${example_LIB_DIR})
install(TARGETS plugin_2 DESTINATION ${example_LIB_DIR})
install(FILES ${plugin_1_HEADERS} DESTINATION ${example_INC_DIR})
install(FILES ${plugin_2_HEADERS} DESTINATION ${example_INC_DIR})
