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
    system("cls");

    RowListNode *headRow1 = new RowListNode();
    headRow1->push_back(42);
    headRow1->push_back(23);
    headRow1->push_back(332);
    headRow1->push_back(3343);
    headRow1->push_back(332);
    headRow1->push_back(35);
    headRow1->push_back(15);

    RowListNode *headRow2 = new RowListNode();
    headRow2->push_back(5);
    headRow2->push_back(6);

    RowListNode *headRow3 = new RowListNode();
    headRow3->push_back(4);
    headRow3->push_back(18);

    ManagerListNode *headManager = new ManagerListNode();
    headManager->push_back(headRow1);
    headManager->push_back(headRow2);
    headManager->push_back(headRow3);
    headManager->print();

    RowListNode *headRow4 = new RowListNode();
    headRow4->push_back(1);
    headRow4->push_back(1);
    headRow4->push_back(1);
    headRow4->push_back(1);

    headManager->push_back(headRow4);
    cout << endl << endl << endl;

    headManager->printList();
    headManager->deleteNodeByManageIndexAndColumnIndex(2, 1);
    cout << endl << endl << endl;
    headManager->printList();

    headRow1->cleanList();
    headRow1->printList();

    // system("pause");
    return 0;
}