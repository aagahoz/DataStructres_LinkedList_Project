#include <iostream>
#include <sstream>
#include <cstdlib>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"
#include "projectFunctions.hpp"

using namespace std;

int main()
{
// ! manage list print will be redisagn and row list print will be designed

     system("pause");
 
     ManagerListNode *headManager = new ManagerListNode();
     int maxOctalNumber = getManageOctalNumber(getDataFromFile(&headManager));

     int manageOctalCounter = 0;
     int rowCounter = 0;

     while (true)
     {
          char choice;
          cout << "input > ";
          cin >> choice;

          switch (choice)
          {
               // case 'c':
               //      cout << "Next Row List Selected" << endl;
               //      break;
               // case 'z':
               //      cout << "Previous Row List Selected" << endl;
               //      manageOctalCounter--;
               //      break;

          case 'a':
               cout << "Selected 8 next Manage List" << endl;
               manageOctalCounter++;
               if (manageOctalCounter > maxOctalNumber - 1)
               {
                    manageOctalCounter = 0;
               }
               break;
          case 'd':
               cout << "Selected 8 previous Manage List" << endl;
               manageOctalCounter--;
               if (manageOctalCounter < 0)
               {
                    manageOctalCounter = maxOctalNumber - 1;
               }
               break;

          case 'k':
               break;
          }

          system("cls");
          cout << endl;
          cout << "Print Window" << endl;
          cout << "Manage Octal Number: " << manageOctalCounter << endl;
          
          headManager->printListDetailedInRange(manageOctalCounter*8, manageOctalCounter*8 + 7);
     }

     // headManager->printListDetailedInRange(0, lineCount - 1);

     // system("pause");
     return 0;
}
