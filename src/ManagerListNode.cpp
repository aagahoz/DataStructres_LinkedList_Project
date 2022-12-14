/**
 * @file ManagerListNode.cpp
 * @description Dinamik Liste kullanımı ve consol tasarımı
 * @course  1.Öğretim C Grubu 
 * @assignment  1.Ödev
 * @date   10.11.2022
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#include "ManagerListNode.hpp"
#include <iostream>
#include "ProjectFunctions.hpp"

using namespace std;

ManagerListNode::ManagerListNode()
{
    head = nullptr;
    next = nullptr;
    prev = nullptr;
    rowList = nullptr;
    average = 0;
    rowListCount = 0;
}
ManagerListNode::ManagerListNode(RowListNode *rowList)
{
    head = new ManagerListNode();
    head->rowList = rowList;
    next = nullptr;
    prev = nullptr;
    this->rowList = rowList;
    average = 0;
    rowListCount = 0;
}
ManagerListNode::~ManagerListNode()
{
    // cout << "[INFO Manage] ManagerListNode destructor called" << endl;
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
}
RowListNode *ManagerListNode::getRowList()
{
    return rowList;
}

void ManagerListNode::setRowListCount(int rowListCount)
{
    this->rowListCount = rowListCount;
}
int ManagerListNode::getRowListCount()
{
    return rowListCount;
}

void ManagerListNode::setAverage(double average)
{
    this->average = average;
}

double ManagerListNode::getAverage()
{
    return average;
}

void ManagerListNode::setHead(ManagerListNode *head)
{
    this->head = head;
}

ManagerListNode *ManagerListNode::getHead()
{
    return head;
}

void ManagerListNode::push_back(RowListNode *rowHead)
{
    if (head == NULL)
    {
        ManagerListNode *newNode = new ManagerListNode(rowHead);
        head = newNode;
        head->setNext(nullptr);
        head->average = rowHead->getAverage();
        rowListCount++;
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
        newNode->prev = temp;
        newNode->average = rowHead->getAverage();
        rowListCount++;
    }
    sortManageListByRowListAverage();
}

void ManagerListNode::printList()
{
    ManagerListNode *temp = head;
    // cout << "[INFO Manage] Manager List Nodes Datas" << endl;
    if (temp == NULL)
    {
        // cout << "[INFO Manage] NULL Nodes" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            // ! temp->rowList->printList(); // there is bug but unused function
            // cout << "Average " << temp->average << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}

void ManagerListNode::cleanList()
{
    ManagerListNode *temp = head;
    cout << endl;
    // cout << "[INFO Manage] Cleaning List...." << endl;
    if (temp == NULL)
    {
        // cout << "[INFO Manage] NULL Nodes" << endl;
    }
    else if (temp->next == NULL)
    {
        // cout << "[INFO Manage] Only One Node : " << temp->rowList << endl;
        delete temp->rowList;
        delete temp;
    }
    else
    {
        ManagerListNode *next = temp->next;
        while (temp != NULL)
        {
            // cout << "Deleted : " << temp->rowList << endl;
            delete temp->rowList;
            delete temp;
            temp = next;
            if (next != NULL)
            {
                next = next->next;
            }
            else
            {
                // cout << "[INFO Manage] Node  Clean" << endl;
                break;
            }
        }
    }
    head = NULL;
}

void ManagerListNode::updateAverage()
{
    ManagerListNode *temp = head;
    while (temp != NULL)
    {
        temp->average = temp->rowList->getAverage();
        temp = temp->next;
    }
}

void ManagerListNode::sortManageListByRowListAverage()
{
    ManagerListNode *temp = head;
    // cout << ">>>>>>  rowlistcount " << rowListCount << endl;
    if (rowListCount > 0)
    {
        ManagerListNode *next = temp->next;
        while (temp != NULL)
        {
            while (next != NULL)
            {
                if (temp->average > next->average)
                {
                    double tempAverage = temp->average;
                    temp->average = next->average;
                    next->average = tempAverage;

                    RowListNode *tempRowList = temp->rowList;
                    temp->rowList = next->rowList;
                    next->rowList = tempRowList;
                }
                next = next->next;
            }
            temp = temp->next;
            if (temp != NULL)
            {
                next = temp->next;
            }
        }
        // cout << "[INFO Manage] Sorted List" << endl;
    }
    else
    {
        // cout << "[INFO Manage] No Node to Sort due to empty manage list" << endl;
    }
}

ManagerListNode *ManagerListNode::getManageNodeByIndex(int index)
{
    ManagerListNode *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == index)
        {
            return temp;
        }
        temp = temp->next;
        i++;
    }
    return NULL;
}

void ManagerListNode::printDataNodeByManageIndexAndColumnIndex(int manageIndex, int rowIndex)
{
    ManagerListNode *temp = head;
    int i = 0;
    // cout << "row list count: " << rowListCount << endl;
    // cout << "manage index: " << manageIndex << endl;
    if (manageIndex < rowListCount)
    {
        while (temp != NULL)
        {
            if (i == manageIndex)
            {
                temp->rowList->printDataNodeByIndex(rowIndex);
                break;
            }
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // cout << "[INFO Manage] Index Out of Range" << endl;
    }
}

void ManagerListNode::deleteNodeByManageIndexAndColumnIndex(int manageIndex, int rowIndex)
{
    ManagerListNode *temp = head;
    int i = 0;
    bool isDeleted = false;
    if (manageIndex < rowListCount)
    {
        while (temp != NULL)
        {
            if (i == manageIndex)
            {
                temp->rowList->deleteNodeByIndex(rowIndex);
                isDeleted = true;
                break;
            }
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // cout << "[INFO Manage] Index Out of Range" << endl;
    }

    if (isDeleted)
    {
        updateAverage();
        sortManageListByRowListAverage();
        // cout << "[INFO Manage] Node Deleted" << endl;
    }
    else
    {
        // cout << "[INFO Manage] Node Not Deleted" << endl;
    }
    sortManageListByRowListAverage();
}

void ManagerListNode::deleteNodeByManageIndex(int manageIndex)
{
    ManagerListNode *temp = head;
    int i = 0;
    bool isDeleted = false;
    if (manageIndex < rowListCount)
    {
        while (temp != NULL)
        {
            if (i == manageIndex)
            {
                if (temp->prev == NULL && temp->next == NULL)
                {
                    // cout << "[INFO Manage] Only One Node : " << temp->rowList << endl;
                    isDeleted = true;
                    rowListCount--;
                    delete temp->rowList;
                    delete temp;
                    head = NULL;
                }
                else if (temp->prev == NULL && temp->next != NULL)
                {
                    head = temp->next;
                    head->prev = NULL;
                    isDeleted = true;
                    rowListCount--;
                    // cout << "[INFO Manage] Deleted : " << temp->rowList << endl;
                    delete temp->rowList;
                    delete temp;
                }
                else if (temp->prev != NULL && temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    isDeleted = true;
                    rowListCount--;
                    // cout << "[INFO Manage] Deleted : " << temp->rowList << endl;
                    delete temp->rowList;
                    delete temp;
                }
                else if (temp->prev != NULL && temp->next != NULL)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    isDeleted = true;
                    rowListCount--;
                    // cout << "[INFO Manage] Deleted : " << temp->rowList << endl;
                    delete temp->rowList;
                    delete temp;
                }
                break;
            }
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // cout << "[INFO] Index Out of Range" << endl;
    }
    if (isDeleted)
    {
        sortManageListByRowListAverage();
        // cout << "[INFO Manage] Node Deleted" << endl;
    }
    else
    {
        // cout << "[INFO Manage] Node Not Deleted" << endl;
    }
}

void ManagerListNode::printListDetailedInRange(int first, int last, int rowIndex)
{
    ManagerListNode *temp = head;
    int i = 0;
    int countList = 0;
    // cout << "first : " << first << endl;
    // cout << "last : " << last << endl;
    // cout << "rowIndex : " << rowIndex << endl
    //      << endl;

    bool isLastPage = false;
    int count = 7;
    if (last - first < 7)
    {
        // cout << "last - first < 7" << endl;
        isLastPage = true;
        count = last - first;
    }

    if (first < rowListCount && last < rowListCount)
    {
        while (temp != NULL)
        {
            if (i >= first && i <= last)
            {
                printWithAdressNoBracket(temp);
            }
            temp = temp->next;
            i++;
        }
        cout << endl;

        printLine(count);

        //--------------------------------

        temp = head;
        i = 0;
        while (temp != NULL)
        {
            if (i >= first && i <= last)
            {
                printWithBracketAdress(temp->next);
            }
            temp = temp->next;
            i++;
        }
        cout << endl;

        printLine(count);

        //--------------------------------

        temp = head;
        i = 0;
        while (temp != NULL)
        {
            if (i >= first && i <= last)
            {
                printWithBracketNumber(temp->average);
            }
            temp = temp->next;
            i++;
        }
        cout << endl;

        printLine(count);

        //--------------------------------

        temp = head;
        i = 0;
        while (temp != NULL)
        {
            if (i >= first && i <= last)
            {
                printWithBracketAdress(temp->prev);
            }
            temp = temp->next;
            i++;
        }
        cout << endl;

        printLine(count);
        cout << endl;

        printSelectMarker(rowIndex % 8);

        printSelectedRowList(rowIndex);
    }
    else if (last > rowListCount)
    {
        int mod = last % rowListCount;
        // cout << "rowListCount: " << rowListCount << endl;
        // cout << "last: " << last << endl;
        // cout << "rowlistcount - mod + 1 " << rowListCount - mod + 1 << endl;
        // cout << "rowlistcount - 1 " << rowListCount - 1 << endl;
        // system("Pause");
        printListDetailedInRange(rowListCount - mod + 1, rowListCount - 1, rowIndex);
    }
    else
    {
        // cout << "[INFO Manage] Index Out of Range" << endl;
    }
}

void ManagerListNode::printSelectedRowList(int index)
{
    ManagerListNode *temp = head;
    int i = 0;
    if (index < rowListCount)
    {
        while (temp != NULL)
        {
            if (i == index)
            {
                temp->rowList->printList(index % 8);
                break;
            }
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // cout << "[INFO Manage] Index Out of Range" << endl;
    }
}

RowListNode *ManagerListNode::getNodebyIndex(int index)
{
    ManagerListNode *temp = head;
    int i = 0;
    if (index < rowListCount)
    {
        while (temp != NULL)
        {
            if (i == index)
            {
                return temp->rowList;
            }
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // cout << "[INFO Manage] Index Out of Range" << endl;
    }
    return NULL;
}