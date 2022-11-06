#include "ManagerListNode.hpp"
#include <iostream>
using namespace std;

ManagerListNode::ManagerListNode()
{
    next = nullptr;
    prev = nullptr;
    data = 0;
    count++;
}
ManagerListNode::ManagerListNode(RowListNode *rowList)
{
    next = nullptr;
    prev = nullptr;
    this->rowList = rowList;
    data = 0;
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

void ManagerListNode::setManager(int data)
{
    this->data = data;
}
int ManagerListNode::getManager()
{
    return data;
}

void ManagerListNode::setRowList(RowListNode *rowList)
{
    this->rowList = rowList;
}
RowListNode *ManagerListNode::getRowList()
{
    return rowList;
}

double ManagerListNode::getAverage()
{
    double sum = 0;
    int count = 0;
    RowListNode *temp;
    while (temp != nullptr)
    {
        sum += temp->getData();
        count++;
        temp = temp->getNext();
    }
    return sum / count;
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