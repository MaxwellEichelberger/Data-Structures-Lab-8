#pragma once
#include <iostream>
#include "Item.h"

template <class T>
class List
{
	public:

		List()
		{
			head = nullptr;
			length = 0;
			count = 0;
			previous;
		}

		~List() 
		{
			makeEmpty();
		};

		void AddItem(T* element)
		{
			listNode *newNode;
			listNode *nodePtr;

			newNode = new listNode;
			newNode->value = *element;
			newNode->next = nullptr;

			if (!head)
				head = newNode;
			else
			{
				previous = head->value;
				nodePtr = head;
				while (nodePtr->next)
					nodePtr = nodePtr->next;
				nodePtr->next = newNode;
			}

			length += 1;
		}

		void makeEmpty()
		{
			listNode* nodePtr;
			listNode* nextNode;
			nodePtr = head;

			while (nodePtr != nullptr)
			{
				nextNode = nodePtr->next;
				delete nodePtr;
				nodePtr = nextNode;
			}

			length = 0;
		}
		
		T GetItem(int element)
		{
			class exceptionGetItem{};
			try
			{
				if (isEmpty())
				{

					throw exceptionGetItem();
				}
				else
				{
					listNode* nodePtr;
					listNode* temp;
					nodePtr = head;
					while (nodePtr != nullptr)
					{
						if (nodePtr->value.getSKU() == element)
						{
							temp = nodePtr;
							delete nodePtr;
							return temp->value;
						}
						nodePtr = nodePtr->next;

					}
					throw exceptionGetItem();
				}
			}
			catch (exceptionGetItem t)
			{
				std::cout << "Item Does No Exist in List or the List is Empty";
			}
		}

		bool IsInList(int element)
		{
			listNode* nodePtr;
			nodePtr = head;

			while (nodePtr != nullptr)
			{
				if (nodePtr->value.getSKU() == element)
				{
					return true;
				}
				nodePtr = nodePtr->next;
			}
			return false;
		}

		bool isEmpty()
		{
			if (length == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		int Size()
		{
			return length;
		}

		T SeeAt(int element)
		{
			class exceptionSeeAt{};
			try
			{
				if (element <= length)
				{
					while (head != nullptr)
					{
						if (count == element)
						{
							return (head->value);
						}
						count += 1;
						previous = head->value;
						head = head->next;

					}
					throw exceptionSeeAt();
				}
				else
				{
					throw exceptionSeeAt();
				}
				
			}
			catch (exceptionSeeAt t)
			{
				std::cout << "Element is past the end of list";
			}

		}

		T SeeNext()
		{
			listNode* man = head;
			man = man->next;
			return man->value;
		}

		T SeePrev()
		{
			return previous;
		}

		void Reset()
		{
			listNode* res1 = head;
			listNode* lst = head;
			while (lst)
			{
				lst = lst->next;
			}
			lst = res1;
		}

		
	private:
		struct listNode
		{
			T value;
			struct listNode *next;
		};

		listNode* head;
		int length;
		item previous;
		int count;


};