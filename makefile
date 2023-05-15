main: main.o Node.o List.o Person.o Dictionary.o
	g++ -o main main.o Node.o List.o Person.o Dictionary.o

tests: tests.o Node.o List.o Person.o Dictionary.o
	g++ -o tests tests.o Node.o List.o Person.o Dictionary.o doctest.h
main.o: main.cpp List.h Person.h Node.h
tests.o: main.cpp List.h Person.h Node.h doctest.h
List.o: List.cpp List.h Node.h Person.h
Node.o: Node.cpp Node.h Person.h
Person.o: Person.cpp Person.h
Dictionary.o: Dictionary.cpp Dictionary.h Person.h Node.h List.h
clean:
	rm -f *.o
