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


    headRow1->push_back(42);
    headRow1->push_back(23);
    headRow1->push_back(33);
    headRow1->push_back(15);

    headRow1->printList();

    headRow1->deleteNode(33);
    headRow1->printList();

    cout << "Found at index " << headRow1->findNodeIndex(15) << endl;

    RowListNode *headRow2 = new RowListNode();
    headRow2->push_back(5);
    headRow2->push_back(6);

    RowListNode *headRow3 = new RowListNode();
    headRow3->push_back(7);
    headRow3->push_back(8);

    ManagerListNode *headManager = new ManagerListNode();


    cout << endl << endl << endl;
    headManager->push_back(headRow2);
    headManager->push_back(headRow1);
    headManager->push_back(headRow3);
    headManager->printList();

    headManager->sortManageListByRowListAverage();
    
    cout << endl << endl << endl;
    
    headManager->printList();

    // headManager->cleanList();

    RowListNode *headRow4 = new RowListNode();

    headRow4->push_back(1);
    headRow4->push_back(1);
    headRow4->push_back(1);
    headRow4->push_back(1);
    headManager->push_back(headRow4);
    cout << endl << endl << endl;

    headManager->printList();

    

    system("pause");
    return 0;
}