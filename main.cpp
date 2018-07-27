// Remove Duplicates
//
//  main.cpp
//  RemoveDups
//
//  Created by Louie Shi on 7/26/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include <set>
#include "LinkedList.h"

using namespace std;

void removeDup(ListNode* ln)
{
    set<int> myset;
    set<int>::iterator itr;
    
    while(ln)
    {
        itr = myset.find(ln->getData());
        
        if(itr == myset.end()) //Did not find, insert new element into set
        {
            myset.insert(ln->getData());
        }
        else    // Remove node from linkedlist
        {
            if(ln->getNext() != NULL)
            {
                ln->getPrev()->next = ln->getNext();
                ln->getNext()->prev = ln->getPrev();
            }
            else
            {
                ln->getPrev()->next = NULL;
            }
        }
        
        ln = ln->getNext();
    }
    
//    Loop through set
    for(itr = myset.begin(); itr!=myset.end(); ++itr)
    {
        cout << *itr << endl;
    }
    
}

int main(int argc, const char * argv[])
{
    LinkedList* l1 = new LinkedList();
    
    ListNode* ln1 = new ListNode(1);
    ListNode* ln2 = new ListNode(2);
    ListNode* ln2A = new ListNode(2);
    ListNode* ln3 = new ListNode(3);
    ListNode* ln4 = new ListNode(4);
    ListNode* ln5 = new ListNode(5);
    ListNode* ln5A = new ListNode(5);
    ListNode* ln5B = new ListNode(5);
    ListNode* ln6 = new ListNode(6);
    
    l1->insertEnd(ln2);
    l1->insertEnd(ln4);
    l1->insertEnd(ln1);
    l1->insertEnd(ln5A);
    l1->insertEnd(ln3);
    l1->insertEnd(ln2A);
    l1->insertEnd(ln5B);
    l1->insertEnd(ln6);
    l1->insertEnd(ln5);
    
    cout << "Initial LinkedList: " << endl;
    l1->print();
    cout << endl;
    
    cout << "Remove Dups: " << endl;
    removeDup(l1->head);
    cout << endl;
    
    cout << "Final LinkedList: " << endl;
    l1->print();
    cout << endl;
    
    return 0;
}
