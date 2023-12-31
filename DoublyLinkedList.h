/**
 * @file DoublyLinkedList.h
 * @brief A template header file for implementing a doubly linked list in C++.
 *
 * This header defines a template class `DoublyLinkedList` that provides operations to create,
 * manipulate, and manage a doubly linked list. It supports push, pop, size, get_front,
 * get_back, and reverse operations.
 *
 * @note This header should be included and compiled along with the main program.
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList
{
private:
    // Nested struct defining the individual nodes of the linked list
    struct Node
    {
        T data;     // Data stored in the node
        Node *prev; // Pointer to the previous node
        Node *next; // Pointer to the next node
        Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node *head;      // Pointer to the first node in the list
    Node *tail;      // Pointer to the last node in the list
    size_t listSize; // Size of the linked list (number of nodes)

public:
    // Constructor to initialize an empty linked list
    DoublyLinkedList();

    // Destructor to clean up memory when the list is destroyed
    ~DoublyLinkedList();

    // Methods for adding elements to the linked list
    void push_back(const T &value);
    void push_front(const T &value);
    void push(const T &value); // Alias for push_back

    // Methods for removing elements from the linked list
    void pop_back();
    void pop_front();
    void pop(); // Alias for pop_back

    // Methods to retrieve the data of the first and last elements
    T &get_front();
    T &get_back();

    // Method to get the current size of the linked list
    size_t size();

    // Friend function for reversing the linked list
    template <class A>
    friend void reverse(DoublyLinkedList<A> &list);
};

/**
 * @brief Constructor for the DoublyLinkedList class.
 */

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

/**
 * @brief Destructor for the DoublyLinkedList class.
 * Deletes all nodes and releases memory.
 */
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * @brief Adds a new node with the given value to the end of the list.
 * @param value The value to be added.
 */

template <typename T>
void DoublyLinkedList<T>::push_back(const T &value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    listSize++;
}

/**
 * @brief Adds a new node with the given value to the front of the list.
 * @param value The value to be added.
 */

template <typename T>
void DoublyLinkedList<T>::push_front(const T &value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    listSize++;
}

/**
 * @brief Adds a new node with the given value to the end of the list.
 * This is an alias for push_back(const T& value).
 * @param value The value to be added.
 */

template <typename T>
void DoublyLinkedList<T>::push(const T &value)
{
    push_back(value);
}

/**
 * @brief Removes the last node from the list.
 * If the list is empty, does nothing.
 */

template <typename T>
void DoublyLinkedList<T>::pop_back()
{
    if (!head)
        return;

    Node *temp = tail;
    tail = tail->prev;

    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    delete temp;
    listSize--;
}

/**
 * @brief Removes the first node from the list.
 * If the list is empty, does nothing.
 */

template <typename T>
void DoublyLinkedList<T>::pop_front()
{
    if (!head)
        return;

    Node *temp = head;
    head = head->next;

    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;

    delete temp;
    listSize--;
}

/**
 * @brief Removes the last node from the list.
 * This is an alias for pop_back().
 */

template <typename T>
void DoublyLinkedList<T>::pop()
{
    pop_back();
}

/**
 * @brief Returns a reference to the data stored in the first node.
 * @return A reference to the data in the first node.
 */

template <typename T>
T &DoublyLinkedList<T>::get_front()
{
    return head->data;
}

/**
 * @brief Returns a reference to the data stored in the last node.
 * @return A reference to the data in the last node.
 */

template <typename T>
T &DoublyLinkedList<T>::get_back()
{
    return tail->data;
}

/**
 * @brief Returns the current size of the list.
 * @return The size of the list.
 */

template <typename T>
size_t DoublyLinkedList<T>::size()
{
    return listSize;
}

/**
 * @brief Reverses the order of elements in the provided DoublyLinkedList.
 * @param list The list to be reversed.
 */

template <class T>
void reverse(DoublyLinkedList<T> &list)
{
    if (list.size() <= 1)
        return;

    typename DoublyLinkedList<T>::Node *current = list.head;
    while (current)
    {
        typename DoublyLinkedList<T>::Node *temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    typename DoublyLinkedList<T>::Node *temp = list.head;
    list.head = list.tail;
    list.tail = temp;
}

#endif /* DOUBLYLINKEDLIST_H */
