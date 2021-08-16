#
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#Project Name
PROJECT (Test09_Hello)

#Add -D define flags to the compilation of source files.
ADD_DEFINITIONS( -DMacroName=1 -DMacroName)

#Add options to the compilation of source files.
ADD_COMPILE_OPTIONS(-Wall -g)

# include path
#INCLUDE_DIRECTORIES(./include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# add file list, SET(SRC_LIST tested01.c testates02.c)
#SET(SRC_LIST ./src/test03.c)

#search source file
######FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.c")
######check the contents got after searching
######MESSAGE(STATUS "Get SRC_LIST is " ${SRC_LIST})
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src src6)
#check the contents got after searching
MESSAGE(STATUS "Get src3 is " ${src6})


#print check the variable content in env
# 输出打印构建目录
MESSAGE(STATUS "This is HELLO_BINARY_DIR " ${HELLO_BINARY_DIR})
# 输出打印资源目录
MESSAGE(STATUS "This is HELLO_SOURCE_DIR " ${HELLO_SOURCE_DIR})
# 输出打印资源目录，与HELLO_SOURCE_DIR 一样
MESSAGE(STATUS "This is PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
# 输出打印 CMake 资源目录，与 PROJECT_SOURCE_DIR 一样
MESSAGE(STATUS "This is CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})

MESSAGE(STATUS "This is PROJECT " ${PROJECT})

# 生成可执行文件 hello ，${SRC_LIST}是引用变量，也就是源文件 hello.c
######ADD_EXECUTABLE(Test09_Hello ${SRC_LIST})
ADD_EXECUTABLE(Test09_Hello ${src6})
