####################################################
# 												   #
# FEDERAL UNIVERSITY OF LAVRAS					   #
# ALGORITHMS IN GRAPH DISCIPLINE				   #
# TOUR GUIDE PROBLEM PRATICAL PROJECT			   #
# 												   #
# SOURCE CODE LANGUAGE: C++						   #
# A makefile written for compile all C++ source	   #
# files of this project.						   #
####################################################
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SOURCE_FILES = $(call rwildcard, , *.cpp)
OBJECT_FILES = $(SOURCE_FILES:.cpp=.o)

all: build build/main clean_objects

build:
	mkdir -p build

build/main: $(OBJECT_FILES)
	mpic++  $^ -std=c++11 -o $@

%.o: %.cpp
	mpic++  -std=c++11 -c $^ -o $@

prim.o: prim.cpp
	mpic++ $(CFLAGS) $^ -I$(LOCAL_INC_PATH)

clean_objects: $(OBJECT_FILES)
	rm $^
