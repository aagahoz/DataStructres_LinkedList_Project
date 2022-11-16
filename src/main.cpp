#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"
#include "projectFunctions.hpp"

using namespace std;

int main()
{
     system("cls");
     // * user inputs created
     // ! delete function not working

     ManagerListNode *headManager = new ManagerListNode();
     int maxOctalNumber = getManageOctalNumber(getDataFromFile(&headManager)) - 1;

     int manageOctalCounter = 0;
     int rowCounter = 0;
     bool k_OnePressed = false;
     bool k_TwoPressed = false;

     int i = 0;
     int test1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
     int test2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
     double test3Averages[8] = {32.5, 63.3, 45.6, 78.9, 90.1, 100.0, 45.6, 78.9};

     for (i = 0; i < 8; i++)
     {
          printWithAdressNoBracket(&test1[i]);
     }
     cout << endl;
     printLine();

     for (i = 0; i < 8; i++)
     {
          cout << " |" << &test2[i] << "|" << setw(8);
     }
     cout << endl;
     printLine();

     for (i = 0; i < 8; i++)
     {
          printWithBracketAverage(test3Averages[i]);
     }
     cout << endl;
     printLine();

     for (i = 0; i < 8; i++)
     {
          printWithBracketAdress(&test2[i]);
     }
     cout << endl;
     printLine();


     // ! int index = 2;
     // ! cout << setw(1) <<  "" << setw(index*19) << "^^^^^^^^^^" << endl;








     while (false)
     {
          char choice;
          cout << "input > ";
          cin >> choice;
          system("cls");

          switch (choice)
          {
          case 'c':
               // cout << "Next Row List Selected" << endl;
               rowCounter += 1;
               if (rowCounter >= headManager->getRowListCount())
               {
                    rowCounter = headManager->getRowListCount() - 1;
               }
               else if (rowCounter > (manageOctalCounter + 1) * 8 - 1)
               {
                    // cout << ">>>> Next Manage List Selected" << endl;
                    rowCounter = (manageOctalCounter + 1) * 8 - 1;
               }
               break;
          case 'z':
               cout << "Previous Row List Selected" << endl;
               rowCounter -= 1;
               if (rowCounter < manageOctalCounter * 8)
               {
                    rowCounter = manageOctalCounter * 8;
               }
               break;

          case 'a':
               cout << "Selected 8 next Manage List" << endl;
               manageOctalCounter++;
               if (manageOctalCounter > maxOctalNumber)
               {
                    manageOctalCounter = maxOctalNumber;
               }
               rowCounter = manageOctalCounter * 8;
               break;
          case 'd':
               cout << "Selected 8 previous Manage List" << endl;
               manageOctalCounter--;
               if (manageOctalCounter < 0)
               {
                    manageOctalCounter = 0;
               }
               rowCounter = manageOctalCounter * 8;
               break;

          case 'k':
               if (k_OnePressed == false)
               {
                    cout << "k_OnePressed, selected random node" << endl;
                    k_OnePressed = true;
               }
               else
               {
                    cout << "k_TwoPressed" << endl;
                    k_TwoPressed = true;
               }

               if (k_OnePressed == true && k_TwoPressed == true)
               {
                    cout << "k_OnePressed and k_TwoPressed" << endl;
                    cout << "one data deleted randomly from Selected Row List " << endl;
                    k_OnePressed = false;
                    k_TwoPressed = false;
               }
               break;

          case 'p':
               cout << "Manage List Node Deleted" << endl;
               break;
          default:
               cout << "Invalid Input" << endl;
               break;
          }

          cout << endl;
          // cout << "Print Window" << endl;
          cout << "Manage Octal Number: " << manageOctalCounter << endl;
          // cout << "Max Octal Number: " << maxOctalNumber << endl;
          cout << "Row Number: " << rowCounter << endl;
          headManager->printListDetailedInRange(manageOctalCounter * 8, manageOctalCounter * 8 + 7, rowCounter);
          // headManager->printDataNodeByManageIndexAndColumnIndex(manageOctalCounter, rowCounter);
     }

     // headManager->printListDetailedInRange(0, lineCount - 1);

     // system("pause");
     return 0;
}
