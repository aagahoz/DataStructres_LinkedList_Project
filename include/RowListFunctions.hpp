#ifndef RowListFunctions_hpp
#define RowListFunctions_hpp

#include "RowListFunctions.hpp"
#include "RowListNode.hpp"

RowListNode *createRowListNode(int data);
void addRowListNode(RowListNode **head, int data);
void printRowList(RowListNode *head);
void deleteRowList(RowListNode *head);
RowListNode *insertNode(RowListNode *head, RowListNode *newNode);
void deleteRowList(RowListNode** head_ref);


#endif