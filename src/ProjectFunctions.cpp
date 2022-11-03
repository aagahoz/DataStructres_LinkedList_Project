#include "projectFunctions.hpp"

int getCountOfNumbersAtString(string str)
{
    stringstream sstream(str);
    string word;

    int count = 0;
    while (sstream >> word)
    {
        count++;
    }
    return count;
}