#include "ManagerListNode.hpp"
#include <iostream>
using namespace std;

ManagerListNode::ManagerListNode()
{
    head = nullptr;
    next = nullptr;
    prev = nullptr;
    rowList = nullptr;
    average = 0;
    count++;
}
ManagerListNode::ManagerListNode(RowListNode *rowList)
{
    head = new ManagerListNode();
    head->rowList = rowList;
    next = nullptr;
    prev = nullptr;
    this->rowList = rowList;
    average = 0;
    count++;
}
ManagerListNode::~ManagerListNode()
{
    count--;
    cout << "ManagerListNode destructor called" << endl;
}

void ManagerListNode::setNext(ManagerListNode *next)
{
    this->next = next;
}
ManagerListNode *ManagerListNode::getNext()
{
    return next;
}

void ManagerListNode::setPrev(ManagerListNode *prev)
{
    this->prev = prev;
}
ManagerListNode *ManagerListNode::getPrev()
{
    return prev;
}

void ManagerListNode::setRowList(RowListNode *rowList)
{
    this->rowList = rowList;
    cout << "RowList set to ManagerNode" << endl;
}
RowListNode *ManagerListNode::getRowList()
{
    return rowList;
}

int ManagerListNode::count = 0;

void ManagerListNode::setCount(int count)
{
    this->count = count;
}
int ManagerListNode::getCount()
{
    return count;
}

void ManagerListNode::setAverage(double average)
{
    this->average = average;
}

double ManagerListNode::getAverage()
{
    return average;
}

void ManagerListNode::push_back(RowListNode *rowHead)
{
    if (head == NULL)
    {
        ManagerListNode *newNode = new ManagerListNode(rowHead);
        head = newNode;
    }
    else if (head != NULL)
    {

        ManagerListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        ManagerListNode *newNode = new ManagerListNode(rowHead);

        temp->next = newNode;
    }
}

void ManagerListNode::printList()
{
    ManagerListNode *temp = head;
    cout << "[Manager List Nodes Datas]" << endl;
    if (temp == NULL)
    {
        cout << "[NULL Nodes]" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            temp->rowList->printList();
            temp = temp->next;
        }
        cout << endl;
    }
}

void ManagerListNode::cleanList()
{
    ManagerListNode *temp = head;
    cout << endl
         << "Cleaning List...." << endl;
    if (temp == NULL)
    {
        cout << "NULL Nodes" << endl;
    }
    else if (temp->next == NULL)
    {
        cout << "Only One Node : " << temp->rowList << endl;
        delete temp->rowList;
        delete temp;
    }
    else
    {
        ManagerListNode *next = temp->next;
        while (temp != NULL)
        {
            cout << "Deleted : " << temp->rowList << endl;
            delete temp->rowList;
            delete temp;
            temp = next;
            if (next != NULL)
            {
                next = next->next;
            }
            else
            {
                cout << "[Node  Clean]" << endl;
                break;
            }
        }
    }
    head = NULL;
}

void ManagerListNode::push_by_RowList_Average(RowListNode *rowHead)
{
    if (head == NULL)
    {
        ManagerListNode *newNode = new ManagerListNode(rowHead);
        head = newNode;
    }
    else if (head != NULL)
    {

        ManagerListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        ManagerListNode *newNode = new ManagerListNode(rowHead);

        temp->next = newNode;
    }
}