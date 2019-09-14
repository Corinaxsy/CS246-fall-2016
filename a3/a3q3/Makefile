CXX = g++-5
CXXFLAGf (switch == 0 && token.kind == "REG") {
                    numreg += 1
                    switch = 1
                    } else if ( switch == 1 && token.kind == "COMMA") {
                      switch = 0
                      if (numreg == 2) switch = 2
                      }
                    else if (switch == 2 && (token.kind == "HEXINT" || token.kind == "INT" || token.kind == "ID")) {
                      i = 3
                    } 
                    else {
                      System.err.println(s"ERROR: The Token is incorrect: kind is ${token.kind}")
                      System.exit(0)
                    }S = -std=c++14 -Wall -MMD
OBJECTS = a3q3.o group.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = emailgroups

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
