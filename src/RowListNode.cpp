#include "RowListNode.hpp"
#include <iostream>
using namespace std;

RowListNode::RowListNode()
{
    head = nullptr;
    next = nullptr;
    prev = nullptr;
    data = 0;
}

RowListNode::RowListNode(int data)
{
    head = new RowListNode();
    head->data = data;
    next = nullptr;
    prev = nullptr;
    this->data = data;
}

RowListNode::~RowListNode()
{
    count--;
    cout << "RowListNode destructor called" << endl;
}

void RowListNode::setHead(RowListNode *head)
{
    this->head = head;
}

RowListNode *RowListNode::getHead()
{
    return head;
}

void RowListNode::setNext(RowListNode *next)
{
    this->next = next;
}

RowListNode *RowListNode::getNext()
{
    return head->next;
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

void RowListNode::setAverage(float average)
{
    this->average = average;
}

double RowListNode::getAverage()
{
    return average;
}

int RowListNode::count = 0;

void RowListNode:: push_back(int data)
{
    RowListNode *newNode = new RowListNode(data);

    if (head == NULL)
    {
        RowListNode *newNode = new RowListNode(data);
        head = newNode;
        updateAverage();
        count++;
    }
    else if (head != NULL)
    {
        RowListNode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->setPrev(current);
        updateAverage();
        count++;
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
    cout << endl
         << "Cleaning List...." << endl;
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

void RowListNode::updateAverage()
{
    RowListNode *temp = head;
    int sum = 0;
    int count = 0;
    while (temp != NULL)
    {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    average = (double)sum / count;
}

int  RowListNode::findNodeIndex(int data)
{
    RowListNode *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            cout << "Node Index : " << index << endl;
            break;
        }
        else
        {
            temp = temp->next;
            index++;
        }
    }
    return index;
}

void RowListNode::deleteNode(int data)
{
    RowListNode *temp = head;
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
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (temp->prev == NULL)
                {
                    head = temp->next;
                    temp->next->prev = NULL;
                    delete temp;
                    break;
                }
                else if (temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    delete temp;
                    break;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    break;
                }
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}