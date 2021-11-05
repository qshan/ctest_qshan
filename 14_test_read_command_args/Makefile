#
#
#meaning of specific strings
#*# $@ all of FileNameWithExtension produced
# $* all of FileNameWithoutExtension produced
# $< the FileName of first dependance item
#*# $^ the dependance items with space islated and remove the repeated item
# $+ the dependance items with space islated, but do not remove the repeated item
# $? the dependance items with space islated, but just have the new item
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

#.PHONY: all
#------------------------------
#CC=gcc
#CXX=g++
CC=clang
CXX=clang++
#------------------------------
#set target name
TARGET_EXEC ?= test14
#------------------------------
#set project/code root path
PRO_ROOT_PATH = .
#set the build path, the temp file path
BUILD_DIR ?= $(PRO_ROOT_PATH)/build_make
#------------------------------
#test code
SRC_DIRS ?= $(PRO_ROOT_PATH)/test/src
#libs code
#INC_DIRS							:= $(shell find $(SRC_DIRS) -type d)
#TODO#Add the src by manual
SRC_DIRS += $(PRO_ROOT_PATH)/libs/say_hello/src
#SRC_DIRS += $(PRO_ROOT_PATH)/libs/practice/src
#Add the src by searching
#TODO#conflicted with shared#SRC_DIRS += $(shell find ./libs -type d -iname "*src")
#shared libs code
#get the shared path here
SRC_SHARED_DIRS ?= $(PRO_ROOT_PATH)/libs/shared/src

#log define
BUILD_LOG_FILE ?= $(BUILD_DIR)/$(TARGET_EXEC).log

#share lib name defined
TOP_OBJ_SHARED ?= Test14SharedLib.o

#$(BUILD_LOG_FILE):
#	$(MKDIR_P) $(BUILD_DIR)
#	touch $(BUILD_DIR)/$(TARGET_EXEC).log


#all: $(TARGET_EXEC)

#source code for shared lib
SRC_SHARED  = $(wildcard \
								$(SRC_SHARED_DIRS)/*.c \
								$(SRC_SHARED_DIRS)/*.cpp)
OBJ_SHARED  = $(SRC_SHARED:%=$(BUILD_DIR)/%.o)

#ToCheck
#include/HeadhFile path for shared lib generating info
INC_DIRS_SHARED       := $(PRO_ROOT_PATH)/libs/shared/header
INC_FLAGS_SHARED      := $(addprefix -I,$(INC_DIRS_SHARED))

CFLAGS_SHARED         ?= $(INC_FLAGS_SHARED) -fPIC -shared
CPPFLAGS_SHARED       ?= $(INC_FLAGS_SHARED) -fPIC -shared

#source code info
SRCS                  := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS                  := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS                  := $(OBJS:.o=.d)

#include/HeadhFile path for source code info
INC_DIRS              := $(shell find $(SRC_DIRS) -type d)
INC_DIRS              +=  $(PRO_ROOT_PATH)/test/header \
													$(PRO_ROOT_PATH)/libs/say_hello/header \

#                          $(PRO_ROOT_PATH)/libs/practice/header
INC_DIRS              += $(INC_DIRS_SHARED)
INC_FLAGS             := $(addprefix -I,$(INC_DIRS))

CFLAGS                ?= $(INC_FLAGS) -MMD -MP
CPPFLAGS              ?= $(INC_FLAGS) -MMD -MP

#------------------------------
#compile option here
# '-g' is for dgb support
DEBFLAGS += -g
# '-O0' is optimize for faster compilation and build time
#DEBFLAGS ?= -O0
# '-O3' is optimize for performance
#DEBFLAGS ?= -O3
# '-Omin' is optimize for code size
DEBFLAGS ?= -Omin
# '-Wall' is to enable the all warning
DEBFLAGS += -Wall
# '-Werror' is to make all warnings into errors
DEBFLAGS += -Werror
# '-Wfatal-errors' is to make compile abort when the hit the errors firstly
DEBFLAGS += -Wfatal-errors
#DEBFLAGS ?= -O -g -DSCULL_DEBUG	# "-O" is needed to expand inlines
#------------------------------

#.DEFAULT: compile
.DEFAULT: all

compile : $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/libs/$(TOP_OBJ_SHARED)
	$(info "Here get : " $(BUILD_DIR)/$(TOP_OBJ_SHARED))
#run#	$(BUILD_DIR)/$(TARGET_EXEC)
#compile:  $(BUILD_DIR)/$(TOP_OBJ_SHARED)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(OBJ_SHARED)
	$(CC) $(OBJS) $(OBJ_SHARED) $(DEBFLAGS) -o $@ $(LDFLAGS)
#	$(CXX) $(OBJS) $(OBJ_SHARED) -o $@ $(LDFLAGS)

### shared lib, the name of libs is set by manual.
$(BUILD_DIR)/libs/$(TOP_OBJ_SHARED): $(SRC_SHARED)
	$(MKDIR_P) $(dir $@)
	$(CC) $(SRC_SHARED)  $(CFLAGS_SHARED) $(DEBFLAGS) -o $@
#	$(CC) $(SRC_SHARED) $(CFLAGS)  $(CFLAGS_SHARED) -o $@
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
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEBFLAGS) -c $< -o $@

#.PHONY: compile


#$(info "run $(BUILD_DIR)/$(TARGET_EXEC)")
run:
	$(info "####################")
	$(info "run $(BUILD_DIR)/$(TARGET_EXEC) ..........")
#	$(BUILD_DIR)/$(TARGET_EXEC)
	$(BUILD_DIR)/$(TARGET_EXEC) arg1 arg2 arg3 arg4 arg5 arg6 --port /dev/usb0 --File /home/data/outputdata.txt

#.PHONY: run

#all : clean $(BUILD_DIR)/$(TARGET_EXEC)
#all : clean compile run
all : clean compile run

#.DEFAULT: all
#.PHONY: all

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
