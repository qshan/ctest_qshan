######
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
#####
#####
#####PROJECT (MATH)
#Project Name
PROJECT (Test05_Hello)


###### 把当前工程目录下的 src 目录的下的所有 .cpp 和 .c 文件赋值给 SRC_LIST
###### AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC_LIST)
#####FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.cpp")
# add file list, SET(SRC_LIST tested01.c testates02.c)
#SET(SRC_LIST ./src/test04.c)
#FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.c")
#SET(SRC_LIST ./src/test05.c)
###### 打印 SRC_LIST 文件列表
###### MESSAGE(STATUS ${SRC_LIST})

###### 指定头文件目录
#####INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
# include path
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)


#添加共享库搜索路径
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)
#生成可执行文件
ADD_EXECUTABLE(Test05_Hello ./src/test05.c)
#为hello添加共享库链接
TARGET_LINK_LIBRARIES(Test05_Hello SayHello04)
