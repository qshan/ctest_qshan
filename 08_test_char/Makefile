#
#
#meaning of specific strings
#*# $@ all of FileNameWithExtension produced
# $* all of FileNameWithoutExtension produced
# $< the FileName of first dependance item
#*# $^ the dependance items with space islated and remove the repeated item
# $+ the dependance items with space islated, but do not remove the repeated item
# $? the dependance items with space islated, but just have the new item
#
# define a variable, Var=xx , and the methods of using variable is $(Var)
#
#search path
# VPATH = src include
# vpath %.c src
# vpath %.h include
#
#match standard
# %.o: %.c
#
# %.o: %.c
#   gcc -g -o $@ -c $<
#
#update_content#CC=gcc
#update_content#CFLAGS = -I ./include
#update_content#DEPS = say_hello_08.h
#update_content#
#update_content#TARGET=test08
#update_content#
#update_content##all: test08
#update_content#all: $(TARGET)
#update_content#
#update_content##test08 : ./src/say_hello_08.c ./src/test08.c
#update_content#$(TARGET): ./src/say_hello_08.c ./src/test08.c
#update_content#  $(CC) -g -o $@ $^  $(CFLAGS)
#update_content##	$(CC) -o test08 ./src/say_hello_08.c ./src/test08.c  $(CFLAGS)
#update_content##	gcc -o test08 ./src/say_hello_08.c ./src/test08.c -I ./include
#update_content#
#update_content#clean:
#update_content##	rm test08
#update_content#  rm $(TARGET)


CC?=gcc
#CC?=clang
DEBFLAGS ?= -O -g -m64 -Wall
#Wall    : Warning all
#Werror  : Warning error
# $(DEBFLAGS)

DEBUG_TOOL?=gdb64

DEBUG_TOOL_FLAGS+= -tui

TARGET_EXEC ?= test08


#BUILD_DIR ?= ./build_gcc
#for Makefile
BUILD_DIR ?= ./buildm
SRC_DIRS ?= ./src

#all: $(TARGET_EXEC)

#source code info
#SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
SRCS := $(shell find $(SRC_DIRS)  -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

#include/HeadhFile path info
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_DIRS += ./include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

compile: $(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) $(DEBFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEBFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEBFLAGS) -c $< -o $@

.PHONY: compile

run:
	$(BUILD_DIR)/$(TARGET_EXEC)
.PHONY: run

all : clean compile run

.PHONY: all


clean:
	$(RM) -r $(BUILD_DIR)
.PHONY: clean

debug:
	$(DEBUG_TOOL) $(DEBUG_TOOL_FLAGS) $(BUILD_DIR)/$(TARGET_EXEC)
#	$(DEBUG_TOOL) $(BUILD_DIR)/$(TARGET_EXEC)
.PHONY: debug

-include $(DEPS)

MKDIR_P ?= mkdir -p
