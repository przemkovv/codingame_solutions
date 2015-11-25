

C=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11
LDFLAGS=-g -std=c++11
#LDLIBS=$(shell root-config --libs)
SRCS=$(wildcard *.cpp)

OBJS=$(subst .cpp,.o,$(SRCS))
APPS=$(subst .cpp,,$(SRCS))

.PHONY: all clean dist-clean
all: ${APPS}

%: %.o
	$(CXX) $(LDFLAGS) -o $@ $@.o $(LDLIBS)

%.o: %.cpp 
	$(CXX) $(CPPFLAGS) -c $<

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) ${APPS}
