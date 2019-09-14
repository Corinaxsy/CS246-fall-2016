CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = main.o cell.o grid.o subject.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q3a

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
