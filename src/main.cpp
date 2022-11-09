#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"
#include "projectFunctions.hpp"

using namespace std;

int main()
{
    int newArray[5] = {1, 2, 3, 4, 5};

    RowListNode *headRow1 = new RowListNode();
    RowListNode *headRow2 = new RowListNode();
    RowListNode *headRow3 = new RowListNode();

    headRow1->push_back(1);
    headRow1->push_back(2);

    headRow2->push_back(3);
    headRow2->push_back(4);
    headRow3->push_back(5);
    headRow3->push_back(6);

    ManagerListNode *headManager = new ManagerListNode();

    headManager->push_back(headRow1);
    headManager->push_back(headRow2);
    headManager->push_back(headRow3);
    headManager->printList();

    headManager->cleanList();

    system("pause");
    return 0;
}