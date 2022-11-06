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

    void setManager(int data);
    int getManager();

    void setCount(int count);
    int getCount();

    double getAverage();

private:
    ManagerListNode *next;
    ManagerListNode *prev;
    RowListNode *rowList;
    int data;
    static int count;
};

#endif