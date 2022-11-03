/**       
 * @file  ManagerList.hpp
 * @description Programınızın açıklaması ne yaptığına dair. 
 * @course  Dersi aldığınız eğitim türü ve grup 
 * @assignment  Kaçıncı ödev olduğu  
 * @date  Kodu oluşturduğunuz Tarih 
 * @author  Gruptakilerin yazar adları ve mail adresleri  
 */

#ifndef ManagerList_hpp
#define ManagerList_hpp

#include "RowList.hpp"

class ManagerList
{
public:
    ManagerList();
    ~ManagerList();

    void setNext(ManagerList *next);
    ManagerList *getNext();

    void setPrev(ManagerList *prev);
    ManagerList *getPrev();

    void setRowList(RowList *rowList);
    RowList *getRowList();

    void setManager(int data);
    int getManager();

    double getAverage();

private:
    ManagerList *next;
    ManagerList *prev;
    RowList *rowList;
    int data;
};

#endif