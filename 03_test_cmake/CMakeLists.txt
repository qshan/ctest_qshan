#
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#Project Name
PROJECT (Test03_Hello)


# include path
#INCLUDE_DIRECTORIES(./include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# add file list, SET(SRC_LIST tested01.c testates02.c)
#SET(SRC_LIST ./src/test03.c)

#search source file
FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.c")
#AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src, src1)


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
ADD_EXECUTABLE(Test03_Hello ${SRC_LIST})
#ADD_EXECUTABLE(Test03_Hello ${src1})
