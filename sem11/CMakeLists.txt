cmake_minimum_required(VERSION 3.5)

project(hello)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  	if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.0")
    	message(FATAL_ERROR "Insufficient g++ version")
  	endif()
else()
	message(FATAL_ERROR "Insufficient compiler")
endif()	

add_subdirectory(contest1)
add_subdirectory(contest2)
