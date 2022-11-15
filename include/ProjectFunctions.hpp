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

#endif