/**
 * @file  ProjectFunctions.hpp
 * @description Dinamik Liste kullanımı ve consol tasarımı
 * @course  1.Öğretim C Grubu 
 * @assignment  1.Ödev
 * @date   10.11.2022
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef ProjectFunctions_hpp
#define ProjectFunctions_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"

using namespace std;

int getDataFromFile(ManagerListNode **head);
int getManageOctalNumber(int totalManageNumber);

void printLine(int count);

void printWithBracketNumber(double number);
void printWithBracketNumber(int number);

void printWithAdressNoBracket(ManagerListNode *address);
void printWithBracketAdress(ManagerListNode *address);

void printSelectMarker(int index);

void printWithAdressNoBracket(RowListNode *address);
void printWithBracketAdress(RowListNode *address);

void printWithBracketAdress(RowListNode *address, int space);
void printWithBracketNumber(int number, int space);

#endif