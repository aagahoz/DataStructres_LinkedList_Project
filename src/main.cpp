#include <iostream>
#include <sstream>
#include <cstdlib>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"
#include "projectFunctions.hpp"

using namespace std;

int main()
{
     system("cls");

     ManagerListNode *headManager = new ManagerListNode();

     int lineCount = getDataFromFile(&headManager);

     headManager->printListDetailedInRange(0, lineCount - 1);

     // system("pause");
     return 0;
}