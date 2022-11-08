#include <iostream>
#include "RowListFunctions.hpp"

using namespace std;

void addToRowListNode(RowListNode **FirstNode, int data)
{
    if (*FirstNode == NULL)
    {
        RowListNode *newNode = new RowListNode(data);
        *FirstNode = newNode;
    }
    else if (*FirstNode != NULL)
    {
        RowListNode *temp = *FirstNode;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }

        RowListNode *newNode = new RowListNode(data);

        temp->setNext(newNode);
    }
}

int getRowListNodesCount(RowListNode *FirstNode)
{
    int count = 0;
    RowListNode *temp = FirstNode;
    if (temp == NULL)
    {
        cout << "[NULL Nodes]" << endl;
    }
    else if (temp != NULL)
    {
        while (temp != NULL)
        {
            count++;
            cout << "data " << temp->getData() << endl;
            temp = temp->getNext();
        }
    }
    return count;
}

void printRowListDatas(RowListNode *FirstNode)
{
    RowListNode *temp = FirstNode;
    cout << "[Row List Nodes Datas] :   ";
    if (temp == NULL)
    {
        cout << "[NULL Nodes]" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
}

void cleanRowListNodes(RowListNode **FirstNode)
{
    RowListNode *temp = *FirstNode;
    if (temp == NULL)
    {
        cout << "NULL Nodes" << endl;
    }
    else if (temp->getNext() == NULL)
    {
        cout << "Only One Node : " << temp->getData() << endl;
        delete temp;
    }
    else
    {
        RowListNode *next = temp->getNext();
        while (temp != NULL)
        {
            cout << "Deleted : " << temp->getData() << endl;
            delete temp;
            temp = next;
            if (next != NULL)
            {
                next = next->getNext();
            }
            else
            {
                cout << "[Node  Finished]" << endl;
                break;
            }
        }
    }
    *FirstNode = NULL;
}