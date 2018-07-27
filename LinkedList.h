//  Louie Shi's Doubly Linked List Implementation
//
//  LinkedList.h
//  AddTwoNumbers
//
//  Created by Louie Shi on 7/24/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

class ListNode
{
public:
    int data;
    ListNode* prev;
    ListNode* next;
    
    //  Default Constructor
    ListNode()
    {
        data = -1;
        prev = NULL;
        next = NULL;
    }
    
    // Constructor with Data
    ListNode(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
    
    int getData();
    ListNode* getPrev();
    ListNode* getNext();
};

class LinkedList
{
public:
    ListNode* head;
    ListNode* tail;
    
    // Default Constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    
    // Constructor with ListNode
    LinkedList(ListNode* ln)
    {
        head = ln;
        tail = ln;
    }
    
    void insert(ListNode* ln);
    void insertEnd(ListNode* ln);
    void insertFront(ListNode* ln);
    bool remove(ListNode* ln);
    void print();
};


#endif /* LinkedList_h */

