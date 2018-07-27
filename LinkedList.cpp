//
//  LinkedList.cpp
//  AddTwoNumbers
//
//  Created by Louie Shi on 7/24/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "LinkedList.h"

using namespace std;

int ListNode::getData()
{
    return data;
}

ListNode* ListNode::getPrev()
{
    return prev;
}

ListNode* ListNode::getNext()
{
    return next;
}

void LinkedList::insert(ListNode* ln)
{
    ListNode* p;
    
    if(head == NULL)    //ADDING TO EMPTY LIST
    {
        head = ln;
        tail = ln;
    }
    else
    {
        for(p = head; p && (p->getData() < ln->getData()); p = p->getNext())
        {
        }
        
        if(p == head) // ADD NODE TO FRONT
        {
            ln->next = head;
            head->prev = ln;
            head = ln;
        }
        else if(p == NULL) //ADD NODE TO END
        {
            tail->next = ln;
            ln->prev = tail;
            tail = ln;
        }
        else //ADD NODE TO MIDDLE
        {
            p->prev->next = ln;
            ln->prev = p->prev;
            p->prev = ln;
            ln->next = p;
        }
    }
}

void LinkedList::insertEnd(ListNode* ln)
{
    if(head == NULL)
    {
        head = ln;
        tail = ln;
    }
    else
    {
        ListNode* p;
        
        for(p = head; p->getNext() != NULL; p = p->getNext())
        {
        }
        p->next = ln;
        ln->prev = p;
        tail = ln;
    }
}

void LinkedList::insertFront(ListNode* ln)
{
    if(head == NULL)
    {
        head = ln;
        tail = ln;
    }
    else
    {
        head->prev = ln;
        ln->next = head;
        head = ln;
    }
}

bool LinkedList::remove(ListNode* ln)
{
    ListNode* p;
    
    for(p = head; p && (p->getData())!= (ln->getData()); p = p->getNext())
    {
        
    }
    
    if(p == NULL)
    {
        return false;
    }
    
    if(p == head)
    {
        if(p->getNext() == NULL)    //Only ONE NODE
        {
            head = NULL;
            tail = NULL;
        }
        else                        //Remove head but more nodes afterwards
        {
            head = head->next;
            head->prev = NULL;
        }
    }
    else if(p == tail)
    {
        tail = tail->getPrev();
        tail->next = NULL;
    }
    else
    {
        p->getNext()->prev = p->getPrev();
        p->getPrev()->next = p->getNext();
    }
    
    return true;
}

void LinkedList::print()
{
    ListNode* p;
    for(p = head; p; p = p->next)
    {
        cout << p->data << endl;
    }
}


