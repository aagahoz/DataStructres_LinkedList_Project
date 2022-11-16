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

void printWithBracketNumber(double number);
void printWithBracketNumber(int number);

void printWithAdressNoBracket(ManagerListNode *address);
void printWithBracketAdress(ManagerListNode *address);

void printSelectMarker(int index);

void printWithAdressNoBracket(RowListNode *address);
void printWithBracketAdress(RowListNode *address);

void printWithBracketAdress(RowListNode *address, int space);
void printWithBracketNumber(int number, int space);

#endif