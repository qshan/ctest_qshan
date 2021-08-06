######
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
#####
#####
#####PROJECT (MATH)
#Project Name
#PROJECT (Test04_Hello)
PROJECT (SayHello04)


###### 把当前工程目录下的 src 目录的下的所有 .cpp 和 .c 文件赋值给 SRC_LIST
###### AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC_LIST)
#####FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.cpp")
# add file list, SET(SRC_LIST tested01.c testates02.c)
#SET(SRC_LIST ./src/test04.c)
FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.c")
###### 打印 SRC_LIST 文件列表
###### MESSAGE(STATUS ${SRC_LIST})

###### 指定头文件目录
#####INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
# include path
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# 指定输出 .so 动态库的目录位置
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 指定生成动态库
ADD_LIBRARY(SayHello04 SHARED ${SRC_LIST})
###### 指定生成版本号，VERSION指代动态库版本，SOVERSION指代API版本
###### SET_TARGET_PROPERTIES(math PROPERTIES VERSION 1.2 SOVERSION 1)





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
ADD_EXECUTABLE(Test04_Hello ${SRC_LIST})
