#include "linklist.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
using namespace std;

// Inserts a record into the list.
void LinkList::Insert( PieCake_struct * p){
    PieCake_struct * temp = head->next;
    while(temp != tail && temp->lname < p->lname){
        temp = temp->next;
    }
    p->prev=temp->prev;
    p->next=temp;
    temp->prev->next=p;
    temp->prev=p;
}
