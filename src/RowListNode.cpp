#include "RowListNode.hpp"
#include <iostream>
using namespace std;

RowListNode::RowListNode()
{
    head = nullptr;
    next = nullptr;
    prev = nullptr;
    data = 0;
    count = 0;
}

RowListNode::RowListNode(int data)
{
    head = new RowListNode();
    head->data = data;
    next = nullptr;
    prev = nullptr;
    this->data = data;
    count = 0;
}

RowListNode::~RowListNode()
{
    cout << "[INFO] RowListNode destructor called" << endl;
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

void RowListNode::setAverage(float average)
{
    this->average = average;
}

double RowListNode::getAverage()
{
    return average;
}

void RowListNode::setCount(int count)
{
    this->count = count;
}

int RowListNode::getCount()
{
    return count;
}

void RowListNode::push_back(int data)
{
    RowListNode *newNode = new RowListNode(data);

    if (head == NULL)
    {
        RowListNode *newNode = new RowListNode(data);
        head = newNode;
        head->next = NULL;
        head->prev = NULL;
        count++;
        updateAverage();
    }
    else if (head != NULL)
    {
        RowListNode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
        count++;
        newNode->setPrev(current);
        updateAverage();
    }
}

void RowListNode::printList()
{
    RowListNode *temp = head;
    cout << "[INFO] Row List Nodes Datas :   ";
    if (temp == NULL)
    {
        cout << "[INFO] NULL Nodes" << endl;
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
    cout << endl;
    cout << "[INFO] Cleaning List...." << endl;
    if (count > 0)
    {
        if (temp == NULL)
        {
            cout << "[INFO] NULL Nodes" << endl;
        }
        else if (temp->next == NULL)
        {
            cout << "[INFO] Only One Node : " << temp->data << endl;
            count--;
            delete temp;
        }
        else
        {
            RowListNode *next = temp->next;
            while (temp != NULL)
            {
                cout << "[INFO] Deleted : " << temp->data << endl;
                count--;
                delete temp;
                temp = next;
                if (next != NULL)
                {
                    next = next->next;
                }
                else
                {
                    cout << "[INFO] Node  Clean" << endl;
                    break;
                }
            }
        }
        head = NULL;
    }
    else
    {
        cout << "[INFO] No Nodes to Clean" << endl;
    }
}

void RowListNode::updateAverage()
{
    RowListNode *temp = head;
    int sum = 0;
    int i = 0;
    if (temp == NULL)
    {
        cout << "[INFO] NULL Nodes" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            sum += temp->data;
            temp = temp->next;
            i++;
        }
        average = (float)sum / i;
    }
}

int RowListNode::findNodeIndex(int data)
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

void RowListNode::printDataNodeByIndex(int index)
{
    RowListNode *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == index)
        {
            cout << "Node Data : " << temp->data << endl;
            break;
        }
        else
        {
            temp = temp->next;
            i++;
        }
    }
}

void RowListNode::deleteNodeByData(int data)
{
    RowListNode *temp = head;
    bool found = false;
    if (temp == NULL)
    {
        cout << "[INFO] NULL Nodes" << endl;
    }
    else if (temp->next == NULL)
    {
        cout << "Only One Node : " << temp->data << endl;
        count--;
        found = true;
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
                    count--;
                    cout << "Deleted : " << temp->data << endl;
                    found = true;
                    delete temp;
                    break;
                }
                else if (temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    count--;
                    cout << "Deleted : " << temp->data << endl;
                    found = true;
                    delete temp;
                    break;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    count--;
                    cout << "Deleted : " << temp->data << endl;
                    found = true;
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

    if (found == false)
    {
        cout << "[INFO] Node Not Found" << endl;
    }
}

bool RowListNode::deleteNodeByIndex(int index)
{
    RowListNode *temp = head;
    int i = 0;
    // cout << "index: " << index << endl;
    cout << "count: " << count << endl;

    if (index < count)
    {

        if (temp == NULL)
        {
            cout << "[INFO] NULL Nodes" << endl;
        }
        else if (temp->next == NULL)
        {
            cout << "Only One Node : " << temp->data << endl;
            count--;
            delete temp;
            updateAverage();
            return true;
        }
        else
        {
            while (temp != NULL)
            {
                if (i == index)
                {
                    if (temp->prev == NULL)
                    {
                        head = temp->next;
                        temp->next->prev = NULL;
                        count--;
                        delete temp;
                        updateAverage();
                        return true;
                        break;
                    }
                    else if (temp->next == NULL)
                    {
                        temp->prev->next = NULL;
                        count--;
                        delete temp;
                        updateAverage();
                        return true;
                        break;
                    }
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        count--;
                        delete temp;
                        updateAverage();
                        return true;
                        break;
                    }
                }
                else
                {
                    temp = temp->next;
                    i++;
                }
            }
        }
    }
    else
    {
        cout << "[INFO] Index is out of rowlist range" << endl;
    }
    return false;
}