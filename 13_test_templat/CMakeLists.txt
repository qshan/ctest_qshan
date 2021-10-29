######
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#Project Name
#PROJECT (Test13_Hello)
#PROJECT (SayHello13)
#PROJECT (Test13)
PROJECT (Test13 VERSION 1.0)

#------------------------------
#set here or set in the cmake argument in shell, one time is enough
SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_BUILD_TYPE RelWithDebInfo)
#SET(CMAKE_BUILD_TYPE Release)
#SET(CMAKE_BUILD_TYPE MinSizeRel)

SET(CMAKE_CXX_FLAGS_DEBUG   "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#ADD_COMPILE_OPTIONS(-Wall -g)
#------------------------------
SET(CMAKE_CXX_STANDARD   11)
SET(CMAKE_CXX_STANDARD_REQUIRED   True)
#------------------------------

# add file list, SET(SRC_LIST tested02.c testates02.c)
#FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.c" "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.s ${PROJECT_SOURCE_DIR}/libs/*/src/*.c" "${PROJECT_SOURCE_DIR}/libs/*src/*.cpp" "${PROJECT_SOURCE_DIR}/libs/*src/*.s")
FILE(GLOB SRC_LIST
  "${PROJECT_SOURCE_DIR}/test/src/*.c"
  "${PROJECT_SOURCE_DIR}/test/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/test/src/*.s"
  "${PROJECT_SOURCE_DIR}/libs/*/src/*.c"
  "${PROJECT_SOURCE_DIR}/libs/*/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/libs/*/src/*.s")
###### print SRC_LIST for debug
##### MESSAGE(STATUS ${SRC_LIST})

#add the shared source code of the file path
FILE(GLOB SRC_SHARED_LIST
  "${PROJECT_SOURCE_DIR}/libs/shared/src/*.c"
  "${PROJECT_SOURCE_DIR}/libs/shared/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/libs/shared/src/*.s")
###### MESSAGE(STATUS ${SRC_SHARED_LIST})

# include path for project
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/libs/*/header)
INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}/test/header
  #     ${PROJECT_SOURCE_DIR}/libs/practice/header
#TODO#  ${PROJECT_SOURCE_DIR}/libs/*/header
  ${PROJECT_SOURCE_DIR}/libs/say_hello/header)
# include path for shared
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/libs/shared/header)

# 指定输出 .so 动态库的目录位置
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libShared)
SET(LIBRARY_OUTPUT_PATH ./libShared)

# 指定生成动态库
#ADD_LIBRARY(SayHello13 SHARED ${SRC_LIST})

ADD_LIBRARY(Test13Shared SHARED ${SRC_SHARED_LIST})
#ADD_LIBRARY(Test13Shared STATIC ${SRC_SHARED_LIST})
#ADD_LIBRARY(Test13Shared MODULE ${SRC_SHARED_LIST})
#TARGET_INCLUDE_DIRECTORIES(Test13Shared PRIVATE ${PROJECT_SOURCE_DIR}/libs/shared/header)
#TARGET_INCLUDE_DIRECTORIES(Test13Shared PUBLIC ${PROJECT_SOURCE_DIR}/libs/shared/header)

###### 指定生成静态库
#####ADD_LIBRARY(SayHello13 ${SRC_LIST})


#print check the variable content in env
MESSAGE(STATUS "This is PROJECT             "   ${PROJECT})
MESSAGE(STATUS "This is PROJECT_NAME        "   ${PROJECT_NAME})
MESSAGE(STATUS "This is CMAKE_PROJECT_NAME  "   ${CMAKE_PROJECT_NAME})
# 输出打印构建目录
MESSAGE(STATUS "This is HELLO_BINARY_DIR    "   ${HELLO_BINARY_DIR})
# 输出打印资源目录
MESSAGE(STATUS "This is HELLO_SOURCE_DIR    "   ${HELLO_SOURCE_DIR})
# 输出打印资源目录，与HELLO_SOURCE_DIR 一样
MESSAGE(STATUS "This is PROJECT_SOURCE_DIR  "   ${PROJECT_SOURCE_DIR})
# 输出打印 CMake 资源目录，与 PROJECT_SOURCE_DIR 一样
MESSAGE(STATUS "This is CMAKE_SOURCE_DIR "      ${CMAKE_SOURCE_DIR})
MESSAGE(STATUS "This is CXXFLAGS            "   ${CXXFLAGS})
MESSAGE(STATUS "This is CMAKE_CXX_FLAGS_DEBUG"   ${CMAKE_CXX_FLAGS_DEBUG})
MESSAGE(STATUS "This is CXX_FLAGS_RELEASE   "   ${CXX_FLAGS_RELEASE})

# 生成可执行文件 hello ，${SRC_LIST}是引用变量，也就是源文件 hello.cpp
# gen ext file, list the dependancy file here
#ADD_EXECUTABLE("${PROJECT_NAME}" ${SRC_LIST} ${SRC_SHARED_LIST})
ADD_EXECUTABLE(
#  Test13
  ${PROJECT_NAME}
  ${SRC_LIST}
  ${SRC_SHARED_LIST})
