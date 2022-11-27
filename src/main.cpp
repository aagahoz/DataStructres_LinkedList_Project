/**
 * @file  main.cpp
 * @description Dinamik Liste kullanımı ve consol tasarımı
 * @course  1.Öğretim C Grubu 
 * @assignment  1.Ödev
 * @date   10.11.2022
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

#include "ManagerListNode.hpp"
#include "RowListNode.hpp"
#include "projectFunctions.hpp"

using namespace std;

int main()
{
     // * user inputs created
     // ! delete function not working

     ManagerListNode *headManager = new ManagerListNode();
     int maxOctalNumber = getManageOctalNumber(getDataFromFile(&headManager)) - 1;
     RowListNode *selectedManageNode;

     int manageOctalCounter = 0;
     int rowCounter = 0;
     bool k_OnePressed = false;
     bool k_TwoPressed = false;
     srand(time(0));

     while (true)
     {
          char choice;
          cout << " > ";
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
               // cout << "Previous Row List Selected" << endl;
               rowCounter -= 1;
               if (rowCounter < manageOctalCounter * 8)
               {
                    rowCounter = manageOctalCounter * 8;
               }
               break;

          case 'a':
               // cout << "Selected 8 next Manage List" << endl;
               manageOctalCounter++;
               if (manageOctalCounter > maxOctalNumber)
               {
                    manageOctalCounter = maxOctalNumber;
               }
               rowCounter = manageOctalCounter * 8;
               break;
          case 'd':
               // cout << "Selected 8 previous Manage List" << endl;
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
                    // cout << "k_OnePressed, selected random node" << endl;
                    // cout << "manage index: " << rowCounter << endl;
                    
                    selectedManageNode = headManager->getNodebyIndex(rowCounter);
                    // int randomRowIndex = rand() % selectedManageNode->getCount();
                    // cout << "randomRow: " << randomRowIndex << endl;
                    
                    k_OnePressed = true;
               }
               else if (k_OnePressed == true)
               {
                    // cout << "k_TwoPressed" << endl;
                    k_TwoPressed = true;
               }
               else
               {
                    k_OnePressed = false;
                    k_TwoPressed = false;
               }

               if (k_OnePressed == true && k_TwoPressed == true)
               {
                    // cout << "k_OnePressed and k_TwoPressed" << endl;
                    // cout << "one data deleted randomly from Selected Row List " << endl;
                    if (selectedManageNode->getCount() > 0)
                    {
                         int randomRowIndex = rand() % selectedManageNode->getCount();
                         selectedManageNode->deleteNodeByIndex(randomRowIndex);
                         headManager->updateAverage();
                    }
                    else
                    {
                         // cout << "Selected Row List is empty" << endl;
                         headManager->deleteNodeByManageIndex(rowCounter);
                    }
                    // selectedManageNode->deleteNodeByIndex(rand() % selectedManageNode->getCount());
                    // cout << "Selected Row List Count: " << selectedManageNode->getCount() << endl;
                    k_OnePressed = false;
                    k_TwoPressed = false;
               }
               break;

          case 'p':
               // cout << "Manage List Node Deleted" << endl;
               headManager->deleteNodeByManageIndex(rowCounter);
               // cout << "Row Counter : " << rowCounter << endl;
               // cout << "Manage Octal Counter " << manageOctalCounter << endl;
               break;
          default:
               // cout << "Invalid Input" << endl;
               break;
          }

          if (manageOctalCounter == 0 && maxOctalNumber == 0)
          {
               cout << "first";
               cout << "                                                                                                                                         ";
               cout << "last";                            
          }
          else if (manageOctalCounter == 0)
          {
               cout << "first";
               cout << "                                                                                                                                         ";
               cout << "-->";
          }
          else if (manageOctalCounter == maxOctalNumber)
          {
               cout << "<--";
               cout << "                                                                                                                                         ";
               cout << "last";
          }
          else
          {
               cout << "<--";
               cout << "                                                                                                                                         ";
               cout << "-->";
          }

          cout << endl;
          // cout << "Manage Octal Number: " << manageOctalCounter << endl;
          // cout << "rowCounter:  " << rowCounter << endl;
          cout << endl;
          headManager->printListDetailedInRange(manageOctalCounter * 8, manageOctalCounter * 8 + 7, rowCounter);
     }
     return 0;
}
