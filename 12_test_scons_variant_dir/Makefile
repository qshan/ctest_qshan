#
#
# detail here: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
#meaning of specific strings
#*# $@ all of FileNameWithExtension produced
# $* all of FileNameWithoutExtension produced
# $< the FileName of first dependance item
#*# $^ the dependance items with space islated and remove the repeated item
# $+ the dependance items with space islated, but do not remove the repeated item
# $? the dependance items with space islated, but just have the new item
# $| The names of all the order-only prerequisites, with spaces between them.
# %
#
#automatic variables          descriptions
#       $@                    The file name of the target
#       $<                    The name of the first prerequisite
#       $^                    The names of all the prerequisites
#       $+                    prerequisites listed more than once are duplicated in the order
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
#update_content#DEPS = say_hello_12.h
#update_content#
#update_content#TARGET=test12
#update_content#
#update_content##all: test12
#update_content#all: $(TARGET)
#update_content#
#update_content##test12 : ./src/say_hello_12.c ./src/test12.c
#update_content#$(TARGET): ./src/say_hello_12.c ./src/test12.c
#update_content#  $(CC) -g -o $@ $^  $(CFLAGS)
#update_content##	$(CC) -o test12 ./src/say_hello_12.c ./src/test12.c  $(CFLAGS)
#update_content##	gcc -o test12 ./src/say_hello_12.c ./src/test12.c -I ./include
#update_content#
#update_content#clean:
#update_content##	rm test12
#update_content#  rm $(TARGET)

#.PHONY: all

#CC=gcc
CC=clang

TARGET_EXEC ?= test12


BUILD_DIR ?= ./build_make
SRC_DIRS ?= ./src
#log define
BUILD_LOG_FILE ?= $(BUILD_DIR)/$(TARGET_EXEC).log

#share lib name defined
TOP_OBJ_SHARED ?= Test12SharedLib.o

#$(BUILD_LOG_FILE):
#	$(MKDIR_P) $(BUILD_DIR)
#	touch $(BUILD_DIR)/$(TARGET_EXEC).log


#all: $(TARGET_EXEC)

#source code info
#SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
SRCS := $(shell find $(SRC_DIRS)  -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

#source code for shared lib
SRC_SHARED  = $(wildcard src_shared/*.c)
#OBJ_SHARED  = $(SRC:.c=.o)
OBJ_SHARED  = $(SRC_SHARED:%=$(BUILD_DIR)/%.o)


#include/HeadhFile path info
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_DIRS += ./include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

CFLAGS          ?= $(INC_FLAGS) -MMD -MP
CFLAGS_SHARED   ?= -fPIC -shared

#DEBFLAGS ?= -O2 -g
DEBFLAGS ?= -O -g -Wall # "-O" is needed to expand inlines
#DEBFLAGS ?= -O -g -DSCULL_DEBUG # "-O" is needed to expand inlines

.DEFAULT: compile

compile : $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/libs/$(TOP_OBJ_SHARED)
	echo "Here get : " $(BUILD_DIR)/$(TOP_OBJ_SHARED)
	$(BUILD_DIR)/$(TARGET_EXEC)
#compile:  $(BUILD_DIR)/$(TOP_OBJ_SHARED)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(OBJ_SHARED)
	$(CC) $(OBJS) $(OBJ_SHARED) -o $@ $(LDFLAGS)

### shared lib, the name of libs is set by manual.
$(BUILD_DIR)/libs/$(TOP_OBJ_SHARED): $(SRC_SHARED)
	$(MKDIR_P) $(dir $@)
	$(CC) $(SRC_SHARED)  $(CFLAGS_SHARED) -o $@
#	$(CC) $(SRC_SHARED) $(CFLAGS)  $(CFLAGS_SHARED) -o $@
#	$(CC) $(SRC_SHARED) -o $@ -fPIC -shared
#	$(CC) $(OBJ_SHARED) -o $@ $^ $(LDFLAGS)
#	$(MKDIR_P) $(dir $@)
##	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEBFLAGS) -c $< -o $@

# assembly
$(BUILD_DIR)/%.s.o : %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
#$(BUILD_DIR)/%.c.o: %.c
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC)  $(CFLAGS) $(DEBFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

#.PHONY: compile


#$(info "run $(BUILD_DIR)/$(TARGET_EXEC)")
run:
#	echo "run $(BUILD_DIR)/$(TARGET_EXEC) .........."
	$(BUILD_DIR)/$(TARGET_EXEC)

#.PHONY: run

#all : clean $(BUILD_DIR)/$(TARGET_EXEC)
#all : clean compile run
all : clean compile

#.DEFAULT: all
#.PHONY: all

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
