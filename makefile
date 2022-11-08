all: compile

compile:
	g++ -I ./include/ -o ./lib/ManagerListNode.o -c ./src/ManagerListNode.cpp
	g++ -I ./include/ -o ./lib/RowListNode.o -c ./src/RowListNode.cpp
	g++ -I ./include/ -o ./lib/RowListFunctions.o -c ./src/RowListFunctions.cpp
	g++ -I ./include/ -o ./lib/ManagerListFunctions.o -c ./src/ManagerListFunctions.cpp
	g++ -I ./include/ -o ./lib/ProjectFunctions.o -c ./src/ProjectFunctions.cpp

	g++ -I ./include/ -o ./bin/main ./lib/ManagerListNode.o ./lib/RowListNode.o ./lib/RowListFunctions.o ./lib/ManagerListFunctions.o ./lib/ProjectFunctions.o -g ./src/main.cpp
