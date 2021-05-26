# source files in this project (for beautification)
VERSION=0.3
BASE_DIR := ../assg-base-$(VERSION)
PROJECT_NAME=assg

assg_src  = Stack.cpp \
	    AStack.cpp \
	    LStack.cpp \
	    StackException.cpp \
	    stack-functions.cpp

test_src  = test-AStack.cpp \
	    test-LStack.cpp \
	    test-stack-functions.cpp \
	    ${assg_src}

debug_src = main.cpp \
	    ${assg_src}

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template_files =

# assignment description documentation
assg_doc  = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include $(BASE_DIR)/include/Makefile.inc
