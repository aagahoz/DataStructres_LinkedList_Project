/**
 * @file  ManagerListNode.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course  Dersi aldığınız eğitim türü ve grup
 * @assignment  Kaçıncı ödev olduğu
 * @date  Kodu oluşturduğunuz Tarih
 * @author  Gruptakilerin yazar adları ve mail adresleri
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

    void setCount(int count);
    int getCount();

    void push_back(RowListNode *rowHead);
    void printList();
    void cleanList();
    void sortManageListByRowListAverage();
    ManagerListNode *getManageNodeByIndex(int index);
    void printManageNodeByIndex(int index);

private:
    ManagerListNode *head;
    ManagerListNode *next;
    ManagerListNode *prev;
    RowListNode *rowList;
    static int count;
    double average;
};

#endif