#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

//A linked list influenced by Gaddis; Starting out with C++ 9th Ed.

class NumberList
{
    private:
    struct Listnode
    {
        //Holds double values
        double value;
        //Points to the next node in the linked list
        struct Listnode *next;
    };
    //begining of the linked list
    Listnode *head;
    //Number of elements in the set
    int num_elements;

    public:
    //ctor
    NumberList();
    //copy ctor
    NumberList(const NumberList& copy);
    
    //dtor
    ~NumberList();

    //Assignment Opertator
    //const NumberList operator=(const NumberList& right);

    //Linked List Operations
    void appendNode(const double new_value);
    void insertNode(const double new_value);
    void deleteNode(const double erase_value);
    void displayList();
    int size();
    bool isEmpty();
    void report();
    void sortAscending(); //has weird after effects
    void clear();
    double sum();
    double sum_evens();
};

#include "number_list.cpp"
#endif