######
# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
#####
#####PROJECT (MATH)
#Project Name
PROJECT (Test05_Hello)

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
