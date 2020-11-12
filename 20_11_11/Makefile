CPP := $(wildcard *.cpp)
all : $(subst .cpp,.o,$(CPP))
%.o : %.cpp
	g++ -o $@ $<
