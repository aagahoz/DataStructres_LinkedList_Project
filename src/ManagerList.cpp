#include "ManagerList.hpp"
#include <iostream>
using namespace std;

ManagerList::ManagerList()
{
    next = nullptr;
    prev = nullptr;
    data = 0;
}
ManagerList::~ManagerList()
{
    cout << "ManagerList destructor called" << endl;
}

void ManagerList::setNext(ManagerList *next)
{
    this->next = next;
}
ManagerList *ManagerList::getNext()
{
    return next;
}

void ManagerList::setPrev(ManagerList *prev)
{
    this->prev = prev;
}
ManagerList *ManagerList::getPrev()
{
    return prev;
}

void ManagerList::setManager(int data)
{
    this->data = data;
}
int ManagerList::getManager()
{
    return data;
}

void ManagerList::setRowList(RowList *rowList)
{
    this->rowList = rowList;
}

RowList *ManagerList::getRowList()
{
    return rowList;
}

double ManagerList::getAverage()
{
    double sum = 0;
    int count = 0;
    RowList *temp = rowList;
    while (temp != nullptr)
    {
        sum += temp->getData();
        count++;
        temp = temp->getNext();
    }
    return sum / count;
}