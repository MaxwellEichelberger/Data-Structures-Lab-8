
#include <iostream>
#include "List.h"
#include "Item.h"
#include <vector>

int main()
{
    bool a = true;
    List<item>* obj = new List<item>();
    item array[100];
    int x = 0;
    int i = 0;
    while (a == true)
    {
        std::cout << "What process would you like to perform? Input the number for your process \n";
        std::cout << "1 for Adding an Item, 2 for Making the List Empty, 3 for Getting an Item, 4 for Seeing if an Item is the List, 5 for Checking If the List is Empty \n";
        std::cout << "6 for the List's Size, 7 for putting the List at a Specific Element, 8 for seeing the Next Item, 9 for Seeing the Previosu Item, and 10 to Reset the List to the front\n";
        std::cout << "Process Number: ";
        std::cin >> x;
        std::cout << std::endl;

        if (x == 1)
        {
            int sku;
            std::string desc;
            double price;
            std::string uom;
            int qoh;

            std::cout << "Please input information about your item. \n";
            std::cout << "Stock Keeping Number: ";
            std::cin >> sku;
            std::cout << "Description: ";
            std::cin >> desc;
            std::cout << "Price: ";
            std::cin >> price;
            std::cout << "Unit of Measure: ";
            std::cin >> uom;
            std::cout << "Quantity on Hand: ";
            std::cin >> qoh;

            item obj2(sku, desc, price, uom, qoh);

            array[i] = obj2;

            obj->AddItem(&(array[i]));

            i += 1;

            std::cout << "Item ";
            std::cout << sku;
            std::cout <<" Added \n";
        }
        else if (x == 2)
        {
            obj->makeEmpty();
            std::cout << "List is now Empty";
        }
        else if (x == 3)
        {
            int sku;
            std::cout << "What is the SKU of the item you want to remove?";
            std::cin >> sku;
            item obj3 = obj->GetItem(sku);
            std::cout << "Item Removed:";
            obj3.getPartInfo();
        }
        else if (x == 4)
        {
            int sku;
            std::cout << "What is the SKU of the item you want to Check?";
            std::cin >> sku;
            bool b = obj->IsInList(sku);

            if (b == true)
            {
                std::cout << "Item ";
                std::cout << sku;
                std::cout << " is in the List";
            }
            else
            {
                std::cout << "Item ";
                std::cout << sku;
                std::cout << " is not in the List";
            }
        }
        else if (x == 5)
        {
          bool c = obj->isEmpty();

          if (c == true)
          {
              std::cout << "List is Empty";
          }
          else
          {
              std::cout << "List is not Empty";
          }
        }
        else if (x == 6)
        {
          int len = obj->Size();
          std::cout << "The Size of the List is ";
          std::cout << len;
        }

        else if (x == 7)
        {
            int element;
            std::cout << "What is the element you want the List to be at";
            std::cin >> element;

            item seen = obj->SeeAt(element);
            std::cout << "Item at this location: ";
            std::cout << seen.getPartInfo();
        }

        else if (x == 8)
        {
          item next = obj->SeeNext();
          std::cout << "Next Item: ";
          std::cout << next.getPartInfo();
        }

        else if (x == 9)
        {
            item prev = obj->SeePrev();
            std::cout << "Previous Item: ";
            std::cout << prev.getPartInfo();
        }

        else if (x == 10)
        {
            obj->Reset();
            std::cout << "List in now Reset";
        }

        std::cout << std::endl;
        std::string choice;
        std::cout << "Would you like to perform another process? (Y/N): ";
        std::cin >> choice;

        if (choice == "y" or choice == "Y")
        {
            a = true;
        }
        else
        {
            a = false;
        }
        std::cout << std::endl;
        
    }
}