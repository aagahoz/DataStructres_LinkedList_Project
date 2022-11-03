#ifndef RowList_hpp
#define RowList_hpp
class RowList
{
public:
    RowList();
    ~RowList();

    void setNext(RowList *next);
    RowList *getNext();

    void setPrev(RowList *prev);
    RowList *getPrev();

    void setData(int data);
    int getData();

private:
    RowList *next;
    RowList *prev;
    int data;
};

#endif