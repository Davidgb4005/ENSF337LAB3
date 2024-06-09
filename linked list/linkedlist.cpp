// OLList.cpp
// ENSF 337 Spring 2024 Lab 4 Exercise E and F

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
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be nullptr/0 or point to node after new node
        while(after != nullptr && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

/*This Version of remove will remove all instances of value*/
void OLList::remove(const ListItem& itemA)
{
    Node* cursor = this->headM;
    Node* prev_cursor = nullptr;
    while (cursor != nullptr){
        if (cursor->item == itemA && this->headM->item == cursor->item){
            headM=headM->next;
            delete cursor;
            cursor=headM;
        }
        else if (cursor->item == itemA && cursor->next!=nullptr && this->headM->item != cursor->item){
            prev_cursor->next=cursor->next;
            delete cursor;
            cursor=prev_cursor->next;
        }
        else if (cursor->item == itemA && cursor->next==nullptr){
            prev_cursor->next=nullptr;
            delete cursor;
            cursor=nullptr;
        }
        else{
        prev_cursor = cursor;
        cursor=cursor->next;

    }

    }
}
/*This Version of remove will remove the first instance of value*/
/*
void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == nullptr || itemA < headM->item)
        return;
    
    Node *doomed_node = nullptr;
    
    if (itemA == eheadM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != nullptr && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (maybe_doomed->item == itemA){
            doomed_node=maybe_doomed;
            before->next = maybe_doomed->next;
        }
        // point three
    }
if (doomed_node != nullptr){
    delete doomed_node;
}
}
*/



void OLList::destroy()
{
    Node* cursor = this->headM; 
    Node* prev_cursor = nullptr;
    while (cursor != nullptr){
        prev_cursor=cursor;
        cursor=cursor->next;
        delete prev_cursor;
        prev_cursor=nullptr;
    }
    this->headM=nullptr;
}

void OLList::copy(const OLList& source)
{   
    if (this->headM != source.headM || 1==1){
        Node* cursor = source.headM;
        Node* new_node = nullptr;
        this->headM = new Node;
        headM->item=cursor->item;
        headM->next=nullptr;
        new_node = headM;

        while(cursor->next!=nullptr){
            new_node->next = new Node;
            new_node->item=cursor->item;
            new_node=new_node->next;
            new_node->next=nullptr;
            cursor = cursor->next;
        }
        new_node->item=cursor->item;
        new_node->next=nullptr;
    }
}
