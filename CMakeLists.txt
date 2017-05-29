cmake_minimum_required(VERSION 3.6)
project(fractol)

file(GLOB SOURCES ./src/*.c)

set(LIB_PATH libft)

#set(CMAKE_CXX_STANDARD 11)
set(HOME_FLAGS "-I /usr/X11/include -g -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit -pthread")
set(MACOS_FLAGS "-lmlx -framework OpenGL -framework AppKit")
set(CMAKE_C_FLAGS ${MACOS_FLAGS})
set(SOURCE_FILES ${SOURCES})
include_directories("./libft/" "./inc")
add_executable(fractol ${SOURCE_FILES})

file(GLOB SOURCES_LIB ${LIB_PATH}/*.c)
add_library(ft STATIC ${SOURCES_LIB}/)

target_link_libraries(fractol ft)