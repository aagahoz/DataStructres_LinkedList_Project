#include "RowListNode.hpp"
#include <iostream>
using namespace std;

RowListNode::RowListNode()
{
    head = nullptr;
    next = nullptr;
    prev = nullptr;
    data = 0;
    count++;
}

RowListNode::RowListNode(int data)
{
    head = new RowListNode();
    head->data = data;
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

void RowListNode::push_back(int data)
{
    if (head == NULL)
    {
        RowListNode *newNode = new RowListNode(data);
        head = newNode;
    }
    else if (head != NULL)
    {

        RowListNode *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }

        RowListNode *newNode = new RowListNode(data);

        temp->setNext(newNode);
    }
}

void RowListNode::printList()
{
    RowListNode *temp = head;
    cout << "[Row List Nodes Datas] :   ";
    if (temp == NULL)
    {
        cout << "[NULL Nodes]" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void RowListNode::cleanList()
{
    RowListNode *temp = head;
    cout << endl << "Cleaning List...." << endl;
    if (temp == NULL)
    {
        cout << "NULL Nodes" << endl;
    }
    else if (temp->next == NULL)
    {
        cout << "Only One Node : " << temp->data << endl;
        delete temp;
    }
    else
    {
        RowListNode *next = temp->next;
        while (temp != NULL)
        {
            cout << "Deleted : " << temp->data << endl;
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