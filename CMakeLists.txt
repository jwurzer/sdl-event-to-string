
cmake_minimum_required(VERSION 3.0.0)

cmake_policy(VERSION 3.0.0)
project(SDL-Evt-to-Str)

set(WIN_SDL2_PATH "C:/Development/Library/SDL2-2.24.1")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/Modules/")

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
	set(SDL2_PATH ${WIN_SDL2_PATH})
endif ()

find_package(SDL2 REQUIRED)

if (CMAKE_COMPILER_IS_GNUCXX)
	set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Winit-self -Wstrict-aliasing -Wfloat-equal -Wno-comment -Wno-missing-field-initializers -Wno-unused -fPIC -felide-constructors -Wreorder")
	set (CMAKE_CXX_FLAGS_DEBUG "-ggdb -O0")
	set (CMAKE_CXX_FLAGS_RELEASE  "-O3")
endif ()

file(GLOB_RECURSE PRJ_HEADERFILES evt2str/*.h)
file(GLOB_RECURSE PRJ_SOURCEFILES evt2str/*.cpp examples/*.cpp)

file(GLOB_RECURSE PRJ_C_HEADERFILES evt2str/*.h)
file(GLOB_RECURSE PRJ_C_SOURCEFILES evt2str/*.c examples/*.c)



add_executable(cpp-example ${PRJ_HEADERFILES} ${PRJ_SOURCEFILES})

target_include_directories(cpp-example PRIVATE "${CMAKE_SOURCE_DIR}/evt2str")
target_include_directories(cpp-example PRIVATE ${SDL2_INCLUDE_DIR})

target_link_libraries(cpp-example ${SDL2_LIBRARY})



add_executable(c-example ${PRJ_C_HEADERFILES} ${PRJ_C_SOURCEFILES})

target_include_directories(c-example PRIVATE "${CMAKE_SOURCE_DIR}/evt2str")
target_include_directories(c-example PRIVATE ${SDL2_INCLUDE_DIR})

target_link_libraries(c-example ${SDL2_LIBRARY})

