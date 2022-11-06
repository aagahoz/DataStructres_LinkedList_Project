#include <iostream>
#include "RowListFunctions.hpp"

using namespace std;

RowListNode *createRowListNode(int data)
{
    RowListNode *newNode = new RowListNode();
    newNode->setData(data);
    return newNode;
}

void addRowListNode(RowListNode **head, int data)
{
    RowListNode *newNode = createRowListNode(data);
    *head = insertNode(*head, newNode);
}

void printRowList(RowListNode *head)
{
    RowListNode *temp = head;
    // if row list is null
    cout << "[Row List] : ";
    while (temp != nullptr)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

RowListNode *insertNode(RowListNode *head, RowListNode *newNode)
{
    RowListNode *temp = head;
    if (temp == nullptr)
    {
        head = newNode;
        return head;
    }
    else if (temp->getData() > newNode->getData())
    {
        newNode->setNext(temp);
        temp->setPrev(newNode);
        head = newNode;
        return head;
    }
    else
    {
        while (temp->getNext() != nullptr && temp->getNext()->getData() < newNode->getData())
        {
            temp = temp->getNext();
        }
        newNode->setNext(temp->getNext());
        if (temp->getNext() != nullptr)
        {
            temp->getNext()->setPrev(newNode);
        }
        temp->setNext(newNode);
        newNode->setPrev(temp);
        return head;
    }
}

void deleteRowList(RowListNode **head_ref)
{
    RowListNode *current = *head_ref;
    RowListNode *next = NULL;

    int i = 0;
    while (current != NULL)
    {
        next = current->getNext();
        free(current);
        current = next;
        i++;
    }
    cout << i << " node deleted List" << endl;
    *head_ref = NULL;
}