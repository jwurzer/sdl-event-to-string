
cmake_minimum_required(VERSION 3.0.0)

cmake_policy(VERSION 3.0.0)
project(SDL-Evt-to-Str)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/Modules/")

set(CMAKE_CXX_STANDARD 11)

set(SDL2_PATH "C:/Development/Library")
set(SDL2_IMAGE_PATH "C:/Development/Library")

find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)

if (CMAKE_COMPILER_IS_GNUCXX)
	set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Winit-self -Wstrict-aliasing -Wfloat-equal -Wno-comment -Wno-missing-field-initializers -Wno-unused -fPIC -felide-constructors -Wreorder")
	set (CMAKE_CXX_FLAGS_DEBUG "-ggdb -O0")
	set (CMAKE_CXX_FLAGS_RELEASE  "-O3")
endif ()

file(GLOB_RECURSE PRJ_HEADERFILES cpp_version/*.h)
file(GLOB_RECURSE PRJ_SOURCEFILES cpp_version/*.cpp examples/*.cpp)

file(GLOB_RECURSE PRJ_C_HEADERFILES c_version/*.h)
file(GLOB_RECURSE PRJ_C_SOURCEFILES c_version/*.c examples/*.c)



add_executable(cpp-example ${PRJ_HEADERFILES} ${PRJ_SOURCEFILES})

target_include_directories(cpp-example PRIVATE "${CMAKE_SOURCE_DIR}/cpp_version")
target_include_directories(cpp-example PRIVATE ${SDL2_INCLUDE_DIR})

target_link_libraries(cpp-example ${SDL2_LIBRARY})



add_executable(c-example ${PRJ_C_HEADERFILES} ${PRJ_C_SOURCEFILES})

target_include_directories(c-example PRIVATE "${CMAKE_SOURCE_DIR}/c_version")
target_include_directories(c-example PRIVATE ${SDL2_INCLUDE_DIR})

target_link_libraries(c-example ${SDL2_LIBRARY})

