# source files in this project (for beautification)
VERSION=0.3
BASE_DIR := ../assg-base-$(VERSION)
PROJECT_NAME=assg

test_src  = $(PROJECT_NAME)-tests-AStack.cpp \
	    $(PROJECT_NAME)-tests-LStack.cpp \
	    $(PROJECT_NAME)-tests-stack-functions.cpp \
	    Stack.cpp \
	    AStack.cpp \
	    LStack.cpp \
	    StackException.cpp \
	    stack-functions.cpp
debug_src = $(PROJECT_NAME)-main.cpp \
	    Stack.cpp \
	    AStack.cpp \
	    LStack.cpp \
	    StackException.cpp \
	    stack-functions.cpp

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template_files =

# assignment description documentation
assg_doc  = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include $(BASE_DIR)/include/Makefile.inc
