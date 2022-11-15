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