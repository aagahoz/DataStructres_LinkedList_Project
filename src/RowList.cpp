#include "RowList.hpp"
#include <iostream>
using namespace std;

RowList::RowList()
{
    next = nullptr;
    prev = nullptr;
    data = 0;
}

RowList::~RowList()
{
    cout << "RowList destructor called" << endl;
}

void RowList::setNext(RowList *next)
{
    this->next = next;
}

RowList *RowList::getNext()
{
    return next;
}

void RowList::setPrev(RowList *prev)
{
    this->prev = prev;
}

RowList *RowList::getPrev()
{
    return prev;
}

void RowList::setData(int data)
{
    this->data = data;
}

int RowList::getData()
{
    return data;
}
