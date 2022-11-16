#ifndef ProjectFunctions_hpp
#define ProjectFunctions_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"

using namespace std;

int getDataFromFile(ManagerListNode **head);
int getManageOctalNumber(int totalManageNumber);
void printLine();
void printWithBracketAverage(double average);
void printWithAdressNoBracket(int *address);
void printWithBracketAdress(int *address);



#endif