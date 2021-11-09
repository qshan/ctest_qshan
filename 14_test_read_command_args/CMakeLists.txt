######
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#Project Name
#PROJECT (Test14_Hello)
#PROJECT (SayHello14)
#PROJECT (Test14)
PROJECT (test14 VERSION 1.0)


#------------------------------
#SET(OutputPathQshan    build_cmake_cmake)
#MAKE_DIRECTORY(${OutputPathQshan})
#SET(PROJECT_BINARY_DIR ${OutputPathQshan})
#set(CMAKE_BUILD_DIR ${OutputPathQshan})
#set(CMAKE_BINARY_DIR ${OutputPathQshan})
#------------------------------
SET(CMAKE_C_COMPILER    clang)
SET(CMAKE_CPP_COMPILER  clang++)
#set(CMAKE_C_COMPILER    iccarm)
#set(CMAKE_CPP_COMPILER  iccarm)
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
  ${PROJECT_SOURCE_DIR}/libs/arg_read/header
  ${PROJECT_SOURCE_DIR}/libs/say_hello/header)
# include path for shared
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/libs/shared/header)

# 指定输出 .so 动态库的目录位置
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libShared)
SET(LIBRARY_OUTPUT_PATH ./libShared)

# 指定生成动态库
#ADD_LIBRARY(SayHello14 SHARED ${SRC_LIST})

ADD_LIBRARY(Test14Shared SHARED ${SRC_SHARED_LIST})
#ADD_LIBRARY(Test14Shared STATIC ${SRC_SHARED_LIST})
#ADD_LIBRARY(Test14Shared MODULE ${SRC_SHARED_LIST})
#TARGET_INCLUDE_DIRECTORIES(Test14Shared PRIVATE ${PROJECT_SOURCE_DIR}/libs/shared/header)
#TARGET_INCLUDE_DIRECTORIES(Test14Shared PUBLIC ${PROJECT_SOURCE_DIR}/libs/shared/header)

###### 指定生成静态库
#####ADD_LIBRARY(SayHello14 ${SRC_LIST})


#print check the variable content in env
MESSAGE(STATUS "------------------------------------------------------------")
MESSAGE(STATUS "Check/confirm variable the status")
MESSAGE(STATUS "{PROJECT}               "   ${PROJECT})
MESSAGE(STATUS "{PROJECT_NAME}          "   ${PROJECT_NAME})
MESSAGE(STATUS "{PROJECT_VERSION}       "   ${PROJECT_VERSION})
MESSAGE(STATUS "{CMAKE_PROJECT_NAME}    "   ${CMAKE_PROJECT_NAME})
#------------------------------
MESSAGE(STATUS "{HELLO_SOURCE_DIR}      "   ${HELLO_SOURCE_DIR})
#------------------------------
MESSAGE(STATUS "{PROJECT_BINARY_DIR}    "   ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "{PROJECT_SOURCE_DIR}    "   ${PROJECT_SOURCE_DIR})
#------------------------------
MESSAGE(STATUS "{CMAKE_BINARY_DIR}      "   ${CMAKE_BINARY_DIR})
MESSAGE(STATUS "{CMAKE_SOURCE_DIR}      "   ${CMAKE_SOURCE_DIR})
MESSAGE(STATUS "{CMAKE_BUILD_TOOL}      "   ${CMAKE_BUILD_TOOL})
#------------------------------
MESSAGE(STATUS "{CMAKE_C_COMPILER}      "   ${CMAKE_C_COMPILER})
MESSAGE(STATUS "{CMAKE_CPP_COMPILER}    "   ${CMAKE_CPP_COMPILER})
#------------------------------
MESSAGE(STATUS "{CXXFLAGS}              "   ${CXXFLAGS})
MESSAGE(STATUS "{CMAKE_CXX_FLAGS_DEBUG} "   ${CMAKE_CXX_FLAGS_DEBUG})
MESSAGE(STATUS "{CXX_FLAGS_RELEASE}     "   ${CXX_FLAGS_RELEASE})
MESSAGE(STATUS "------------------------------------------------------------")
#------------------------------

# 生成可执行文件 hello ，${SRC_LIST}是引用变量，也就是源文件 hello.cpp
# gen ext file, list the dependancy file here
#ADD_EXECUTABLE("${PROJECT_NAME}" ${SRC_LIST} ${SRC_SHARED_LIST})
ADD_EXECUTABLE(
#  Test14
  ${PROJECT_NAME}
  ${SRC_LIST}
  ${SRC_SHARED_LIST})
