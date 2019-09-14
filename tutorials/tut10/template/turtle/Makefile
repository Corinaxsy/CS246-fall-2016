CXX = g++-5
CXXFLAGS = -std=c++14 -MMD -L/usr/X11R6/lib -lX11 -g
EXEC = turtle
OBJECTS = turtle.o ../window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
