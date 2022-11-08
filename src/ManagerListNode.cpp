#include "ManagerListNode.hpp"
#include <iostream>
using namespace std;

ManagerListNode::ManagerListNode()
{
    next = nullptr;
    prev = nullptr;
    rowList = nullptr;
    average = 0;
    count++;
}
ManagerListNode::ManagerListNode(RowListNode *rowList)
{
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
