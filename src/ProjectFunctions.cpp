/**
 * @file  ProjectFunctions.cpp
 * @description Dinamik Liste kullanımı ve consol tasarımı
 * @course  1.Öğretim C Grubu 
 * @assignment  1.Ödev
 * @date   10.11.2022
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#include <iomanip>
#include "projectFunctions.hpp"

int getDataFromFile(ManagerListNode **head)
{
    ifstream verilerFile("veriler.txt");
    string line;
    int lineCount = 0;
    while (getline(verilerFile, line))
    {
        stringstream s(line);
        string numberChar;

        RowListNode *tempRow = new RowListNode();
        while (s >> numberChar)
        {
            int number = stoi(numberChar);
            tempRow->push_back(number);
        }
        (*head)->push_back(tempRow);

        lineCount++;
        // cout << "lineCount: " << lineCount << endl;
    }
    verilerFile.close();

    return lineCount;
}

int getManageOctalNumber(int totalManageNumber)
{
    int maxOctalNumber = totalManageNumber / 8;
    int remainderOctal = totalManageNumber % 8;

    if (remainderOctal != 0)
    {
        maxOctalNumber++;
    }

    return maxOctalNumber;
}

void printLine(int count)
{
    for (int i = 0; i <= count; i++)
    {
        cout << " -------------" << setw(7);
        cout << "  ";
    }
    cout << endl;
}

void printWithBracketNumber(double number)
{
    cout << setw(3) << "|" << setw(9) << number << "|" << setw(8) << "";
}

void printWithBracketNumber(int number)
{
    cout << setw(2) << "|" << setw(8) << number << "|" << setw(6) << "";
}

void printWithBracketNumber(int number, int space)
{
    cout << setw(space) << "|" << setw(8) << number << "|" << setw(space) << "";
}

void printWithBracketAdress(ManagerListNode *address)
{
    cout << setw(3) << "|" << setw(9) << address << "|" << setw(8) << "";
}

void printWithAdressNoBracket(ManagerListNode *address)
{
    cout << setw(2) << "" << setw(9) << address << setw(10) << "";
}

void printWithAdressNoBracket(RowListNode *address)
{
    cout << setw(2) << "" << address << setw(7) << "";
}

void printWithBracketAdress(RowListNode *address)
{
    cout << setw(2) << "|" << setw(8) << address << "|" << setw(6) << "";
}

void printWithBracketAdress(RowListNode *address, int space)
{
    cout << setw(space) << "|" << setw(8) << address << "|" << setw(6) << "";
}

void printSelectMarker(int index)
{
    cout << setw(14 + 21 * (index)) << "^^^^^^^^^^^^^" << endl;
}
