CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = a3q3.o group.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = emailgroups

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
