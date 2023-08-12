/**
 * @file main.cpp
 * @brief A demonstration of using the DoublyLinkedList header for implementing a doubly linked list in C++.
 *
 * This program showcases the features of the DoublyLinkedList template class, which includes push, pop, size,
 * get_front, get_back, and reverse operations for a doubly linked list. It demonstrates the usage of these
 * operations on an integer-based linked list.
 *
 * @note Make sure to compile this file along with the DoublyLinkedList.h header.
 */

#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main()
{
    // Create an instance of DoublyLinkedList with integer elements
    DoublyLinkedList<int> myList;

    // Add elements to the list
    myList.push_back(10);
    myList.push_front(5);
    myList.push(7);


    // Display information about the list
    cout << "List size: " << myList.size() << endl;
    cout << "Front element: " << myList.get_front() << endl;
    cout << "Back element: " << myList.get_back() << endl;

    // Remove elements from the list
    myList.pop_back();
    myList.pop_front();

    // Display list size after pops
    cout << "List size after pops: " << myList.size() << endl;

    // Add more elements to the list
    myList.push(15);
    myList.push_back(20);

    // Display list size after pushes
    cout << "List size after pushes: " << myList.size() << endl;

    // Reverse the list
    reverse(myList);
    cout << "Reversed list size: " << myList.size() << endl;

    return 0;
}
