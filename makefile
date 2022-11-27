all: compile run

compile:
	g++ -I ./include/ -o ./lib/ManagerListNode.o -c ./src/ManagerListNode.cpp
	g++ -I ./include/ -o ./lib/RowListNode.o -c ./src/RowListNode.cpp
	g++ -I ./include/ -o ./lib/ProjectFunctions.o -c ./src/ProjectFunctions.cpp

	g++ -I ./include/ -o ./bin/main ./lib/ManagerListNode.o ./lib/RowListNode.o ./lib/ProjectFunctions.o -g ./src/main.cpp

run:
	./bin/main