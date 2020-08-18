# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -g

SRC := $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

# ****************************************************
# Targets needed to bring the executable up to date

all: $(OBJS) server

server: $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -f *.o *~
	rm -f server

%.o: %.cpp global.h
