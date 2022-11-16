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

void printLine()
{
    for (int i = 0; i < 8; i++)
    {
        cout << " ----------" << setw(6);
        cout << "  ";
    }
    cout << endl;
}

void printWithBracketAverage(double average)
{
    cout << setw(2) << "|" << setw(8) << average << "|" << setw(6) << "";
}

void printWithBracketAdress(ManagerListNode *address)
{
    cout << setw(2) << "|" << setw(8) << address <<  "|" << setw(6) << "";
}

void printWithAdressNoBracket(ManagerListNode *address)
{
    cout << setw(2) << "" << address << setw(7) << "";
}

void printSelectMarker(int index)
{
    cout << setw(28 + 17 * (index - 1)) << "^^^^^^^^^^" << endl;
}
