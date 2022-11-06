#include <iostream>
#include <fstream>
#include <sstream>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"
#include "RowListFunctions.hpp"
#include "projectFunctions.hpp"

using namespace std;

int main()
{
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[3] = {6, 7, 8};
    int array3[7] = {9, 10, 11, 12, 13, 14, 15};
    int i = 1;

    ManagerListNode *managerHead = new ManagerListNode();

    while (i < 4)
    {
        RowListNode *head = nullptr;
        if (i == 1)
        {
            for (int j = 0; j < 5; j++)
            {
                addRowListNode(&head, array1[j]);
            }
        }
        else if (i == 2)
        {
            for (int j = 0; j < 3; j++)
            {
                addRowListNode(&head, array2[j]);
            }
        }
        else if (i == 3)
        {
            for (int j = 0; j < 7; j++)
            {
                addRowListNode(&head, array3[j]);
            }
        }

        printRowList(head);
        deleteRowList(&head);
        i++;
    }

    cout << "Program run" << endl;
    return 0;
}