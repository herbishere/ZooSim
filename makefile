
CXX = g++
CXXFLAGS = -Wall
CXXFLAGS = -pedantic_errors
CXXFLAGS = -g

SRCS = main.cpp Menu.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp Bear.cpp Zoo.cpp

HEADERS = Menu.hpp P2Constants.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Bear.hpp Zoo.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} $(CXXFLAGS) -o main

clean:
	rm -f main
