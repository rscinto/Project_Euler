#include<iostream>

//CTOR 
NumberList::NumberList()
{
	head = nullptr;
	num_elements = 0;
}


//copy ctor
NumberList::NumberList(const NumberList& copy)
{
	//When the copy object is empty
	if (copy.num_elements == 0)
	{
		Listnode* newNode = new Listnode;
		head = newNode;
		head->next = nullptr;
		head->value = NULL;

		num_elements = 0;
	}
	else
	{
		//bring in the number of elements
		num_elements = copy.num_elements;

		//Bring in the old list
		Listnode* copyListPtr = copy.head;

		//create the new list head
		Listnode* newListPtr = new Listnode;
		head = newListPtr;

		//default fill of first element
		newListPtr->value = copyListPtr->value;
		newListPtr->next = nullptr;

		//Iterating to the next ptr in the list to be copied
		copyListPtr = copyListPtr->next;

		while (copyListPtr)
		{
			Listnode* newNode = new Listnode;
			newListPtr->next = newNode;
			newNode->value = copyListPtr->value;
			newNode->next = nullptr;

			//refresh the copylistptr until it reaches the end
			copyListPtr = copyListPtr->next;

			//connects the chain to the next node if their is 
			//a value in the copylistptr after refresh
			if (copyListPtr)
			{
				newListPtr = newNode;
			}
		}
	}
}


//DTOR
NumberList::~NumberList()
{
	clear();
}

//Assignment Operator
/*
const NumberList NumberList::operator=(const NumberList& right)
{
	if (this != &right)
	{
		delete[] this; //probablly not


	}
}
*/

//Linked List Operations
void NumberList::appendNode(const double new_value)
{
	//Points to new node
	Listnode* newNode;
	//Iterates through list
	Listnode* nodePtr;

	//Allocate memory
	newNode = new Listnode;
	newNode->value = new_value;
	newNode->next = nullptr;

	//Increment the number of elements
	num_elements++;

	//appended value is the only value
	if (!head)
	{
		head = newNode;
	}
	else //Otherwise, place the node at the end
	{
		//Prime the iterator to point to the beginning
		nodePtr = head;

		//Keeps going until the tell tale nullptr is found(the end)
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		//end is found
		//place new node a the end  by pointing to it
		nodePtr->next = newNode;
	}
}


/*
@pre: The elements in the list are already sorted in ascending order
@post: The element will be added to the list, preserving ascending order.
*/
void NumberList::insertNode(const double new_value)
{
	//Points to new node
	Listnode* newNode;
	//Iterates through list
	Listnode* nodePtr;
	Listnode* previousNodePtr = nullptr;

	newNode = new Listnode;
	newNode->value = new_value;
	newNode->next = nullptr;

	//First element to be added
	if (isEmpty())
	{
		head = newNode;
		//Increment the number of elements
		num_elements++;
	}
	else//Otherwise, insert the element;
	{
		nodePtr = head;

		previousNodePtr = nullptr;

		//performs search to find a greater value or the end
		//this will place the value before the greater value, or at the end
		while (nodePtr != nullptr && nodePtr->value < new_value)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		//inserting at the front of the list, or as the only element in list
		if (previousNodePtr == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else//insert after previous pointer
		{
			previousNodePtr->next = newNode;
			newNode->next = nodePtr;
		}
		//Increment the number of elements
		num_elements++;
	}
}


void NumberList::deleteNode(const double erase_value)
{
	Listnode* nodePtr = nullptr;
	Listnode* prevPtr = nullptr;

	if (!head)
	{
		//Nothing to do here, no items to delete
	}
	else if (head->value == erase_value)//check the first element, delete it
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		//Decrement the number of elements
		num_elements--;
	}
	else //we have to go hunting for the element, Big-O(n)
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != erase_value)
		{
			prevPtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			prevPtr->next = nodePtr->next;
			delete nodePtr;
			//Decrement the number of elements
			num_elements--;
		}
		else
		{
			std::cout << "Delete Failed: Element not found" << std::endl;
		}
	}
}


void NumberList::displayList()
{
	//Iterates through list
	Listnode* nodePtr;
	//Prime the iterator to point to the beginning
	nodePtr = head;

	//if the list is empty then this is a nullptr
	if (!head)
	{
		std::cout << "Cannot Display: The list is empty" << std::endl;
	}
	else
	{
		//Keeps going until the tell tale nullptr is found(the end)
		while (nodePtr)
		{
			//prints the primed value
			std::cout << nodePtr->value << std::endl;
			nodePtr = nodePtr->next;
		}
	}
}


int NumberList::size()
{
	return num_elements;
}


bool NumberList::isEmpty()
{
	bool is_Empty = false;

	if (num_elements == 0)
	{
		is_Empty = true;
	}

	return is_Empty;
}


void NumberList::report()
{
	if (isEmpty())
	{
		std::cout << "This list is empty" << std::endl;
	}
	else
	{
		std::cout << "This list is not empty" << std::endl;
	}
	std::cout << "This list has " << size() << " elements" << std::endl;
}


/*
@pre: This function will take a NumberList object that is empty or filled
@post: The function will have performed an insertion sort on a new NumberList's contents
and then deletes the old contents.
*/
void NumberList::sortAscending()
{
	double* rawArrayPtr = new double[size()];
	Listnode* nodePtr = head;
	//Listnode* HeadCPY = head;
	Listnode* TEMPnodePtr = nullptr;

	if (size() == 0)
	{
		std::cout << "Sort Failed: No items in list." << std::endl;
	}
	else if (size() == 1)
	{
		//Do nothing. 
	}
	else if (size() >= 2)
	{
		//Load the NumberList values into a dynamic array
		for (int i = 0; i < size(); i++)
		{
			rawArrayPtr[i] = nodePtr->value;
			TEMPnodePtr = nodePtr;
			nodePtr = nodePtr->next;
			delete TEMPnodePtr;
		}

		//Selection Sort Routine for the array
		for (int outside = 0; outside < size(); outside++)
		{
			int smallestIndex = 0;
			double temp = NULL;
			double smallest = rawArrayPtr[outside];
			bool swapRequired = false;

			for (int inside = outside; inside < size(); inside++)
			{
				//If something smaller is found, record value and location
				if (rawArrayPtr[inside] < smallest)
				{
					smallestIndex = inside;
					temp = rawArrayPtr[inside];
					swapRequired = true;
				}
			}
			//make the swap
			if (swapRequired)
			{
				rawArrayPtr[smallestIndex] = smallest;
				rawArrayPtr[outside] = temp;
			}
		}//end selection sort

		//refilling the object with sorted values
		head = new Listnode;
		//This feels like it coule be a problem. 
		//Or is it just moving the dynamic object
		//head = HeadCPY;//To this old spot....?
		head->value = rawArrayPtr[0];
		head->next = nullptr;

		if (size() >= 2)
		{
			Listnode* currPtr = head;
			for (int i = 1; i < size(); i++)
			{
				Listnode* newNode = new Listnode;

				if (i == 1)
				{
					head->next = newNode;
				}
				else
				{
					currPtr->next = newNode;
				}

				newNode->value = rawArrayPtr[i];
				newNode->next = nullptr;
				currPtr = newNode;
			}
		}
		delete[] rawArrayPtr;
	}
}



void NumberList::clear()
{
	Listnode* nodeToDeletePtr = head;

	while (head)
	{
		//prepare the element for deletion
		nodeToDeletePtr = head;

		//get next element, if present, for deletion
		head = head->next;

		// Return node to the system
		nodeToDeletePtr->next = nullptr;
		delete nodeToDeletePtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr

	num_elements = 0;

	/*
	//start the pointer at the beginning fo iteration
	Listnode* currPtr = head;
	Listnode* tempPtr = nullptr;

	while (currPtr)
	{
		//save the object at the current ptr
		tempPtr = currPtr;
		//refresh while loop condition
		currPtr = currPtr->next;
		//delete the list object
		delete tempPtr;
	}
	//reset element count
	num_elements = 0;
	head->value = NULL;
	head->next = nullptr;
	*/
}


double NumberList::sum()
{
	Listnode* currPtr = head;
	double sum = 0;

	while (currPtr)
	{
		sum += currPtr->value;
		currPtr = currPtr->next;
	}


	return sum;
}

double NumberList::sum_evens()
{
	Listnode* currPtr = head;
	double sum = 0;

	while (currPtr)
	{
		int tester = currPtr->value;
		if ((tester % 2) == 0)
		{
			sum += currPtr->value;
		}
		currPtr = currPtr->next;
	}
	return sum;
}

