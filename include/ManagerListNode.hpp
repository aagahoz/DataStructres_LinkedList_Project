/**
 * @file  ManagerListNode.hpp
 * @description Dinamik Liste kullanımı ve consol tasarımı
 * @course  1.Öğretim C Grubu 
 * @assignment  1.Ödev
 * @date   10.11.2022
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef ManagerListNode_hpp
#define ManagerListNode_hpp

#include "RowListNode.hpp"

class ManagerListNode
{
public:
    ManagerListNode();
    ManagerListNode(RowListNode *rowList);
    ~ManagerListNode();

    void setNext(ManagerListNode *next);
    ManagerListNode *getNext();

    void setPrev(ManagerListNode *prev);
    ManagerListNode *getPrev();

    void setRowList(RowListNode *rowList);
    RowListNode *getRowList();

    void setAverage(double average);
    double getAverage();

    void setRowListCount(int count);
    int getRowListCount();

    void setHead(ManagerListNode *head);
    ManagerListNode *getHead();

    void push_back(RowListNode *rowHead);
    void printList();
    void cleanList();
    void updateAverage();
    void sortManageListByRowListAverage();

    ManagerListNode *getManageNodeByIndex(int index);
    void printDataNodeByManageIndexAndColumnIndex(int manageIndex, int rowIndex);

    void deleteNodeByManageIndexAndColumnIndex(int manageIndex, int rowIndex);
    void deleteNodeByManageIndex(int manageIndex);

    void printListDetailedInRange(int first, int last, int rowIndex);

    void printSelectedRowList(int index);

    RowListNode *getNodebyIndex(int index);

private:
    ManagerListNode *head;
    ManagerListNode *next;
    ManagerListNode *prev;
    RowListNode *rowList;
    int rowListCount;
    double average;
};

#endif