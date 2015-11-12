

C=gcc 
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11
LDFLAGS=-g -std=c++11
#LDLIBS=$(shell root-config --libs) 
SRCS=skynet.cpp
OBJS=$(subst .cpp,.o,$(SRCS)) 

all: skynet 

skynet: $(OBJS) 
	$(CXX) $(LDFLAGS) -o skynet $(OBJS) $(LDLIBS) 

%.o: %.cpp $(CXX) $(CPPFLAGS) -c $<

clean: 
	$(RM) $(OBJS) 

dist-clean: clean 
	$(RM) skynet
