CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3


INCLUDES = $(shell echo *.h)
EXECS    = day2

# Students will need to add other .o files
#day1part1: main.o day1part1.o
day2part1: main.o day2part1.o
    ${CXX} ${LDFLAGS} $^ -o $@
    
%.o: %.cpp ${INCLUDES}
    ${CXX} ${CXXFLAGS} -c -o $@ $<

.PHONY: clean
clean:
    rm -f ${EXECS} *.o *.dSYM./
