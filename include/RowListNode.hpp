#ifndef RowListNode_hpp
#define RowListNode_hpp
class RowListNode
{
public:
    RowListNode();
    RowListNode(int data);
    ~RowListNode();

    void setNext(RowListNode *next);
    RowListNode *getNext();

    void setPrev(RowListNode *prev);
    RowListNode *getPrev();

    void setData(int data);
    int getData();

    void setCount(int count);
    int getCount();
    
private:
    RowListNode *next;
    RowListNode *prev;
    int data;
    static int count;
};

#endif