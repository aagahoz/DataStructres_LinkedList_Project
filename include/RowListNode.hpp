#ifndef RowListNode_hpp
#define RowListNode_hpp
class RowListNode
{
public:
    RowListNode();
    RowListNode(int data);
    ~RowListNode();

    RowListNode *getHead();
    void setHead(RowListNode *head);

    void setNext(RowListNode *next);
    RowListNode *getNext();

    void setPrev(RowListNode *prev);
    RowListNode *getPrev();

    void setData(int data);
    int getData();

    void setCount(int count);
    int getCount();

    void setAverage(float average);
    double getAverage();

    void push_back(int data);
    void printList();
    void cleanList();
    void updateAverage();
    
    int findNodeIndex(int data);
    
    void printDataNodeByIndex(int index);
    
    void deleteNodeByData(int data);
    bool deleteNodeByIndex(int index);

    void printReverseList();

private:
    RowListNode *head;
    RowListNode *next;
    RowListNode *prev;
    int data;
    int count;
    float average;
};

#endif