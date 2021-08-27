######
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#Project Name
#PROJECT (Test12_Hello)
PROJECT (SayHello12)

# add file list, SET(SRC_LIST tested01.c testates02.c)
#SET(SRC_LIST ./src/test12.c)
FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.c")
###### 打印 SRC_LIST 文件列表
###### MESSAGE(STATUS ${SRC_LIST})

#add the shared source code of the file path
FILE(GLOB SRC_SHARED_LIST "${PROJECT_SOURCE_DIR}/src_shared/*.c")
###### MESSAGE(STATUS ${SRC_SHARED_LIST})

###### 指定头文件目录
#####INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
# include path
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# 指定输出 .so 动态库的目录位置
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libShared)
SET(LIBRARY_OUTPUT_PATH ./libShared)

# 指定生成动态库
#ADD_LIBRARY(SayHello12 SHARED ${SRC_LIST})

ADD_LIBRARY(Test12Shared SHARED ${SRC_SHARED_LIST})

###### 指定生成静态库
#####ADD_LIBRARY(SayHello12 ${SRC_LIST})


#print check the variable content in env
# 输出打印构建目录
MESSAGE(STATUS "This is HELLO_BINARY_DIR " ${HELLO_BINARY_DIR})
# 输出打印资源目录
MESSAGE(STATUS "This is HELLO_SOURCE_DIR " ${HELLO_SOURCE_DIR})
# 输出打印资源目录，与HELLO_SOURCE_DIR 一样
MESSAGE(STATUS "This is PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
# 输出打印 CMake 资源目录，与 PROJECT_SOURCE_DIR 一样
MESSAGE(STATUS "This is CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})

# 生成可执行文件 hello ，${SRC_LIST}是引用变量，也就是源文件 hello.cpp
# gen ext file, list the dependancy file here
ADD_EXECUTABLE(Test12_Hello ${SRC_LIST} ${SRC_SHARED_LIST})
