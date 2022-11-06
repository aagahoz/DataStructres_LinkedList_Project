#include "RowListNode.hpp"
#include <iostream>
using namespace std;


RowListNode::RowListNode()
{
    next = nullptr;
    prev = nullptr;
    data = 0;
    count++;
}

RowListNode::RowListNode(int data)
{
    next = nullptr;
    prev = nullptr;
    this->data = data;
    count++;
}

RowListNode::~RowListNode()
{
    count--;
    cout << "RowListNode destructor called" << endl;
}

void RowListNode::setNext(RowListNode *next)
{
    this->next = next;
}

RowListNode *RowListNode::getNext()
{
    return next;
}

void RowListNode::setPrev(RowListNode *prev)
{
    this->prev = prev;
}

RowListNode *RowListNode::getPrev()
{
    return prev;
}

void RowListNode::setData(int data)
{
    this->data = data;
}

int RowListNode::getData()
{
    return data;
}

void RowListNode::setCount(int count)
{
    this->count = count;
}

int RowListNode::getCount()
{
    return count;
}

int RowListNode::count = 0; 