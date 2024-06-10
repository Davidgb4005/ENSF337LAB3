/*
* File Name: Lab4Vector.cpp
* Assignment: Lab 4 Exercise D
* Lab section: Summer
* Completed by: David Burgoin
* Development Date: May 31/2024
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "h.h"


OLList::OLList()
: headM(nullptr)
{
}


OLList::OLList(const OLList& source)
{
    copy(source); 
}

// Assignment operator
OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}


OLList::~OLList()
{
    destroy();
}

// Print function
void OLList::print() const
{
    cout << '[';
    if (headM != nullptr) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != nullptr; p = p->next)
            cout << ", " << p->item; 
    }
    cout << " ]\n";
}

// Insert function
void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == nullptr || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else { 
        Node *before = headM;
        Node *after = headM->next;
        while(after != nullptr && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}
/*
// Remove function that removes all instances of itemA
void OLList::remove(const ListItem& itemA)
{
    Node* cursor = this->headM;
    Node* prev_cursor = nullptr;
    while (cursor != nullptr){
        if (cursor->item == itemA && this->headM->item == cursor->item){ // If the item to remove is the head item
            headM = headM->next; // Update the head
            delete cursor; // Delete the node
            cursor = headM; // Move the cursor to the new head
        }
        else if (cursor->item == itemA && cursor->next != nullptr && this->headM->item != cursor->item){ // If the item is in the middle of the list
            prev_cursor->next = cursor->next; // Update the previous node's next pointer
            delete cursor; // Delete the node
            cursor = prev_cursor->next; // Move the cursor to the next node
        }
        else if (cursor->item == itemA && cursor->next == nullptr){ // If the item is the last node
            prev_cursor->next = nullptr; // Update the previous node's next pointer
            delete cursor; // Delete the node
            cursor = nullptr; // End the loop
        }
        else {
            prev_cursor = cursor; // Move the previous cursor to the current cursor
            cursor = cursor->next; // Move the cursor to the next node
        }
    }
}
*/
/* This version of remove will remove the first instance of itemA */

void OLList::remove(const ListItem& itemA)
{
    // If the list is empty, do nothing
    if (headM == nullptr || itemA < headM->item)
        return;
    
    Node *doomed_node = nullptr;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next; 
    }
    else { // Will only iterate till it hits the first instance of ItemA
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != nullptr && itemA > maybe_doomed->item) { // Traverse the list to find the node
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (maybe_doomed->item == itemA){ // If the node is found
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next; // Update the previous node's next pointer
        }
        // point three
    }
    if (doomed_node != nullptr){
        delete doomed_node; // Delete the node
    }
}

// Destroy function to delete all nodes in the list
void OLList::destroy()
{
    Node* cursor = this->headM; 
    Node* prev_cursor = nullptr;
    while (cursor != nullptr){
        prev_cursor = cursor; // Move the previous cursor to the current cursor
        cursor = cursor->next; // Move the cursor to the next node
        delete prev_cursor; // Delete the previous cursor
        prev_cursor = nullptr; // Set the previous cursor to nullptr
    }
    this->headM = nullptr; // Set the head to nullptr
}

// Copy function to copy the source list to the current list
void OLList::copy(const OLList& source)
{   
    if (this->headM != source.headM || 1 == 1){ // Check if the source list is different from the current list
        Node* cursor = source.headM;
        Node* new_node = nullptr;
        this->headM = new Node; // Create a new node for the head
        headM->item = cursor->item; // Copy the item
        headM->next = nullptr; // Set the next pointer to nullptr
        new_node = headM;

        while(cursor->next != nullptr){ // Traverse the source list
            new_node->next = new Node; // Create a new node
            new_node->item = cursor->item; // Copy the item
            new_node = new_node->next; // Move to the next node
            new_node->next = nullptr; // Set the next pointer to nullptr
            cursor = cursor->next; // Move the cursor to the next node
        }
        new_node->item = cursor->item; // Copy the last item
        new_node->next = nullptr; // Set the next pointer to nullptr
    }
}
