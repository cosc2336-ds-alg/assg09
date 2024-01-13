# source files in this project 
PROJECT_NAME=assg09

assg_src  = AStack.cpp \
	    LStack.cpp \
	    Stack.cpp \
	    StackException.cpp \
	    stack-functions.cpp

test_src  = ${PROJECT_NAME}-AStack-tests.cpp \
	    ${PROJECT_NAME}-LStack-tests.cpp \
	    ${PROJECT_NAME}-stack-functions-tests.cpp \
	    ${assg_src}

sim_src   = ${PROJECT_NAME}-sim.cpp \
	    ${assg_src}

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template_files =

# assignment description documentation
assg_doc  = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include include/Makefile.inc

# assignment header file specific dependencies
${OBJ_DIR}/AStack.o: ${INC_DIR}/AStack.hpp
${OBJ_DIR}/LStack.o: ${INC_DIR}/LStack.hpp
${OBJ_DIR}/Stack.o: ${INC_DIR}/Stack.hpp
${OBJ_DIR}/StackException.o: ${INC_DIR}/StackException.hpp
${OBJ_DIR}/stack-functions.o: ${INC_DIR}/stack-functions.hpp
${OBJ_DIR}/${PROJECT_NAME}-AStack-tests.o: ${SRC_DIR}/${PROJECT_NAME}-AStack-tests.cpp ${INC_DIR}/AStack.hpp ${INC_DIR}/StackException.hpp
${OBJ_DIR}/${PROJECT_NAME}-LStack-tests.o: ${SRC_DIR}/${PROJECT_NAME}-LStack-tests.cpp ${INC_DIR}/LStack.hpp ${INC_DIR}/StackException.hpp
${OBJ_DIR}/${PROJECT_NAME}-stack-functions-tests.o: ${SRC_DIR}/${PROJECT_NAME}-stack-functions-tests.cpp ${INC_DIR}/AStack.hpp ${INC_DIR}/LStack.hpp ${INC_DIR}/Stack.hpp ${INC_DIR}/stack-functions.hpp
${OBJ_DIR}/${PROJECT_NAME}-sim.o: ${SRC_DIR}/${PROJECT_NAME}-sim.cpp ${INC_DIR}/Stack.hpp
