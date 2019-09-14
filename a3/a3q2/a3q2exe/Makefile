CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = a3q2.o matrix.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = matrix

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
