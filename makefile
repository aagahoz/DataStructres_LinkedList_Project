all: compile run

compile:
	g++ -I ./include/ -o ./lib/ManagerList.o -c ./src/ManagerList.cpp
	g++ -I ./include/ -o ./lib/RowList.o -c ./src/RowList.cpp
	g++ -I ./include/ -o ./bin/main ./lib/ManagerList.o ./lib/RowList.o ./src/main.cpp

run:
	./bin/main
