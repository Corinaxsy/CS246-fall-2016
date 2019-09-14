CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = a3q1.o drone.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = drone

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
