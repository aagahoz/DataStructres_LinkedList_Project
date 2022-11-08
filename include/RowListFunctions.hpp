#ifndef RowListFunctions_hpp
#define RowListFunctions_hpp

#include "RowListFunctions.hpp"
#include "RowListNode.hpp"

void addToRowListNode(RowListNode **FirstNode, int data);
int getRowListNodesCount(RowListNode *FirstNode);
void printRowListDatas(RowListNode *FirstNode);
void cleanRowListNodes(RowListNode **FirstNode);

#endif