cmake_minimum_required(VERSION 2.6)
project (project)

get_filename_component(NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

#app part
 
set (SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(SRC_FILES
	${SOURCE_DIR}/simple_calc.cpp
)

set(SRC_FILES_WITH_MAIN
	${SRC_FILES}
	${SOURCE_DIR}/main.cpp
)
 
#include_directories("${PROJECT_BINARY_DIR}")
add_executable(${NAME} ${SRC_FILES_WITH_MAIN})


#test part


set (TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
 
set(TEST_FILES
	${SRC_FILES}
	${TEST_DIR}/main.cpp 
)

LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/lib")
#include_directories("${PROJECT_BINARY_DIR}")
add_executable(${NAME}_test ${TEST_FILES})

TARGET_LINK_LIBRARIES(${NAME}_test gtest.dll)