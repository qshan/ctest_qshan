#!/usr/bin/make
#
#meaning of specific strings
#reference info is here: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
#--------------------------------------------------
#*#     $@      The file name of the target of the rule. ‘$@’ is the name of whichever target caused the rule’s recipe
#                 to be run. all of FileNameWithExtension produced
#       $*      all of FileNameWithoutExtension produced
#       $<      the FileName of first dependence item
#*#     $^      the dependency items with space isolated and remove the repeated item
#       $+      the dependency items with space isolated, but do not remove the repeated item
#       $?      the dependency items with space isolated, but just have the new item
#       $|      The names of all the order-only prerequisites, with spaces between them
#--------------------------------------------------
#       $(@D)   The directory part of the file name of the target, with the trailing slash removed.
#                 If the value of ‘$@’ is dir/foo.o then ‘$(@D)’ is dir.
#                 This value is . if ‘$@’ does not contain a slash
#       $(@F)   The file-within-directory part of the file name of the target. If the value of ‘$@’
#                 is dir/foo.o then ‘$(@F)’ is foo.o. ‘$(@F)’ is equivalent to ‘$(notdir $@)’.
#       $(*D)
#       $(*F)   The directory part and the file-within-directory part of the stem; dir and foo in this example.
#       $(%D)
#       $(%F)   The directory part and the file-within-directory part of the target archive member name.
#                 This makes sense only for archive member targets of the form archive(member) and is useful
#                 only when member may contain a directory name. (See Archive Members as Targets.)
#       $(<D)
#       $(<F)   The directory part and the file-within-directory part of the first prerequisite.
#       $(^D)
#       $(^F)   Lists of the directory parts and the file-within-directory parts of all prerequisites.
#       $(+D)
#       $(+F)   Lists of the directory parts and the file-within-directory parts of all prerequisites,
#                 including multiple instances of duplicated prerequisites.
#       $(?D)
#       $(?F)   Lists of the directory parts and the file-within-directory parts of all prerequisites that are newer
#                 than the target.
#--------------------------------------------------
#*#     %   pattern rules, like %.o : %.c
#--------------------------------------------------
##### function about string
# $(subst <from>,<to>,<text> )
# $(patsubst <pattern>,<replacement>,<text> )
# $(strip <string> )
# $(strip a b c )
# $(findstring <find>,<in> )
# $(filter <pattern...>,<text> )
# $(filter-out <pattern...>,<text> )
# $(sort <list> )
# $(word <n>,<text> )
# $(word n,text)
# $(wordlist s,e,text)
# $(words text)
# $(firstword names…)
# $(lastword names…)
#--------------------------------------------------
##### function about operation of filename
# $(dir <names...> )
# $(notdir <names...> )
# $(suffix <names...> )
# $(basename <names...> )
# $(addsuffix <suffix>,<names...> )
# $(addprefix <prefix>,<names...> )
# $(join <list1>,<list2> )
# $(wildcard pattern)
# $(realpath names…)
# $(abspath names…)
#
# $(file op filename[,text])
#--------------------------------------------------
##### function foreach
# $(foreach <var>,<list>,<text> )
#--------------------------------------------------
##### function conditional
# $(if <condition>,<then-part> )
# $(if <condition>,<then-part>,<else-part> )
# $(if condition,then-part[,else-part])
# $(or condition1[,condition2[,condition3…]])
# $(and condition1[,condition2[,condition3…]])

#--------------------------------------------------
##### function call
# $(call <expression>,<parm1>,<parm2>,<parm3>...)
#--------------------------------------------------
##### function origin
# $(origin <variable> )
#--------------------------------------------------
# $(value variable)
#--------------------------------------------------
##### function shell
# $(shell ls *.c)
# files := $(shell ls *.c)
#--------------------------------------------------
##### function control make process
# $(error <text ...> )
# $(warning <text ...> )
# $(info <text ...> )
#--------------------------------------------------
##### rule of Makefile, update a list from a to b
# $(var_name:a=b)
# $(var_name:.o=.c)
# same as
# $(patsubst %a ,%b ,var_name)
#--------------------------------------------------
#
#automatic variables          Descriptions
#*#     $@                    The file name of the target
#       $<                    The name of the first prerequisite
#*#     $^                    The names of all the prerequisites
#       $+                    Prerequisites listed more than once are duplicated in the order
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
#
#.PHONY: all #info#this items is for no dependance item
#------------------------------
#CC=gcc
#CXX=g++
CC=clang
CXX=clang++
#------------------------------
#set target name
TARGET_EXEC ?= test_run
#------------------------------
#set project/code root path
PRO_ROOT_PATH = .
#set the build path, the temp file path
export BUILD_DIR ?= $(PRO_ROOT_PATH)/build_make
$(info "BUILD_DIR is $(BUILD_DIR)")
#export $$BUILD_DIR
#------------------------------
#test code
SRC_DIRS ?= $(PRO_ROOT_PATH)/test_main/src
#libs code
#INC_DIRS							:= $(shell find $(SRC_DIRS) -type d)
#TODO#Add the src by manual
#SRC_DIRS += $(PRO_ROOT_PATH)/libs/say_hello/src
#SRC_DIRS += $(PRO_ROOT_PATH)/libs/practice/src
#Add the src by searching
SRC_DIRS += $(shell find ./libs -type d -iname "*src")
$(info "SRC_DIRS is $(SRC_DIRS)")
#shared libs code
#get the shared path here
#SRC_SHARED_DIRS ?= $(PRO_ROOT_PATH)/libs_shared/shared/src
#SRC_SHARED_DIRS ?= $(PRO_ROOT_PATH)/libs_shared
SRC_SHARED_DIRS ?= $(shell find ./libs_shared -type d -iname "*src")
$(info "SRC_SHARED_DIRS is $(SRC_SHARED_DIRS)")

#log define
BUILD_LOG_FILE ?= $(BUILD_DIR)/$(TARGET_EXEC).log

#share lib name defined
TOP_OBJ_SHARED ?= TestSharedLib.o

#$(BUILD_LOG_FILE):
#	$(MKDIR_P) $(BUILD_DIR)
#	touch $(BUILD_DIR)/$(TARGET_EXEC).log


#all: $(TARGET_EXEC)

#source code for shared lib
SRC_SHARED  = $(wildcard \
								$(SRC_SHARED_DIRS)/*.c \
								$(SRC_SHARED_DIRS)/*.cpp)
$(info "SRC_SHARED is $(SRC_SHARED)")
OBJ_SHARED  = $(SRC_SHARED:%=$(BUILD_DIR)/%.o)

#ToCheck
#include/HeadhFile path for shared lib generating info
#INC_DIRS_SHARED       := $(PRO_ROOT_PATH)/libs_shared/shared/header
INC_DIRS_SHARED       := $(shell find $(PRO_ROOT_PATH)/libs_shared -type d -iname header)
$(info "INC_DIRS_SHARED is $(INC_DIRS_SHARED)")
INC_FLAGS_SHARED      := $(addprefix -I,$(INC_DIRS_SHARED))
$(info "INC_FLAGS_SHARED is $(INC_FLAGS_SHARED)")


CPPFLAGS_SHARED       ?= $(INC_FLAGS_SHARED) -fPIC -shared

#source code info
SRCS                  := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
$(info "SRCS is $(SRCS)")
OBJS                  := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS                  := $(OBJS:.o=.d)

#include/HeadhFile path for source code info
#INC_DIRS              := $(shell find $(SRC_DIRS) -type d -iname header)
INC_DIRS              := $(shell find $(PRO_ROOT_PATH)/libs -type d -iname header)
$(info "INC_DIRS is $(INC_DIRS)")
INC_DIRS              +=  $(PRO_ROOT_PATH)/test_main/header \

#                          $(PRO_ROOT_PATH)/libs/say_hello/header \
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
# '-E' means Stop after the preprocessing stage; do not run the compiler proper.
#DEBFLAGS ?= -E
# '-S' means Stop after the stage of compilation proper; do not assemble
#DEBFLAGS ?= -S
# '-c' means Compile or assemble the source files, but do not link.
#DEBFLAGS ?= -c
# '-save-temps' means Store the usual "temporary" intermediate files permanently;
#                     place them in the current directory and name them based on the source file
#DEBFLAGS+= -save-temps
# '-v' means Print (on standard error output) the commands executed to run the stages of compilation.
#            Also print the version number of the compiler driver program and of the preprocessor
#            and the compiler proper.
#DEBFLAGS ?= -v
# '-Omin' is optimize for code size
DEBFLAGS ?= -Omin
# '-Wall' is to enable the all warning
DEBFLAGS += -Wall
# '-Werror' is to make all warnings into errors
DEBFLAGS += -Werror
# '-Wfatal-errors' is to make compile abort when the hit the errors firstly
DEBFLAGS += -Wfatal-errors
#
#DEBFLAGS ?= -O -g -DSCULL_DEBUG	# "-O" is needed to expand inlines

#TODO#worked
DEBFLAGS += -DPRINT_DEBUG_ENABLE=1
#DEBFLAGS += -DPRINT_DEBUG_ENABLE=0
#------------------------------

#.DEFAULT: compile
.DEFAULT: all

#TODO set here to select the compile option
USE_LIBS_LINK=ENABLE_1
#USE_LIBS_LINK=DISABLE_0

compile : $(BUILD_DIR)/$(TARGET_EXEC) $(BUILD_DIR)/libs_shared/$(TOP_OBJ_SHARED)
	$(info "Here get : " $(BUILD_DIR)/$(TOP_OBJ_SHARED))
#run#	$(BUILD_DIR)/$(TARGET_EXEC)
#compile:  $(BUILD_DIR)/$(TOP_OBJ_SHARED)

ifeq ($(USE_LIBS_LINK),ENABLE_1)
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(BUILD_DIR)/libs_shared/$(TOP_OBJ_SHARED)
	$(CC) $(OBJS) $(BUILD_DIR)/libs_shared/$(TOP_OBJ_SHARED) $(DEBFLAGS) -o $@ $(LDFLAGS)
else
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(OBJ_SHARED)
	$(CC) $(OBJS) $(OBJ_SHARED) $(DEBFLAGS) -o $@ $(LDFLAGS)
#	$(CXX) $(OBJS) $(OBJ_SHARED) -o $@ $(LDFLAGS)
endif

### shared lib, the name of libs is set by manual.
$(BUILD_DIR)/libs_shared/$(TOP_OBJ_SHARED): $(SRC_SHARED)
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
	$(BUILD_DIR)/$(TARGET_EXEC)

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

# LOG_INFO ?= | tee -a fshan_log.txt
# $(LOG_INFO)
