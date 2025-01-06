#include "linklist.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
using namespace std;


// *****************************************************************
// * Function Name: LinkList
// * Description: Default Constructor
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
LinkList::LinkList() {
    head = new PieCake_struct;
    tail = new PieCake_struct;

    head->id = INT_MIN;
    tail->id = INT_MAX;
    head->lname = "";
    tail->lname = string(10, 'Z'); // to keep dummy record at end of list when ordering by lastname
    head->next = tail;
    tail->next = nullptr;
    tail->prev = head;
    head->prev = nullptr;

    current = nullptr;
    count = 0;
}

// *****************************************************************
// * Function Name: ~LinkList
// * Description: Destructor
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
LinkList::~LinkList() {
    PieCake_struct* temp = head;
    while (temp) {
        PieCake_struct* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    count = 0;
}

// *****************************************************************
// * Function Name: Empty
// * Description: True = link list is empty, False otherwise
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
bool LinkList::Empty() {
    return (count == 0);
}

// *****************************************************************
// * Function Name: Size
// * Description: Returns number of records minus head and tail
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
int LinkList::Size() {
    return count;
}

// *****************************************************************
// * Function Name: Find
// * Description: Looks for a record with the id, returns true if  found, false otherwise.
// *  Sets the current to the record found.
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
bool LinkList::Find(const int idnumber) {
    PieCake_struct* temp = head->next;
    while (temp != tail) {
        if (temp->id == idnumber) {
            current = temp;
            return true;
        }
        temp = temp->next;
    }
    current = nullptr;
    return false;
}

// *****************************************************************
// * Function Name: Insert
// * Description: Inserts a record into the list.
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
void LinkList::Insert(PieCake_struct* p) {
    PieCake_struct* temp = head->next;
    while (temp != tail && temp->lname < p->lname) {
        temp = temp->next;
    }

    p->prev = temp->prev;
    p->next = temp;
    temp->prev->next = p;
    temp->prev = p;

    count++;
}

// *****************************************************************
// * Function Name: Delete
// * Description: Deletes current record. Must use Find() to locate the record.
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
bool LinkList::Delete() {
    if (current == nullptr) return false;

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    current = nullptr;
    count--;
    return true;
}

// *****************************************************************
// * Function Name: Print
// * Description: Prints the report.
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
void LinkList::Print() {
    cout << " * * * The Great Cheesecake Survey * * * " << endl;
    cout << setw(5) << "ID" 
         << setw(15) << "First Name" 
         << setw(5) << "MI" 
         << setw(15) << "Last Name" 
         << setw(8) << "Sex" 
         << setw(10) << "Answer" 
         << endl;
    cout << setw(5) << "--" 
         << setw(15) << "----------" 
         << setw(5) << "--" 
         << setw(15) << "----------" 
         << setw(8) << "---" 
         << setw(10) << "------" 
         << endl;

    List();
    cout << "Total who thought cheesecake is pie: " << CountPie() << endl;
    cout << "Total who thought cheesecake is cake: " << CountCake() << endl;
    cout << "Total Number of records: " << count << endl;
}

// *****************************************************************
// * Function Name: List
// * Description: Lists current record to standard output.
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
void LinkList::List() {
    PieCake_struct* temp = head->next;
    while (temp != tail) {
        cout << setw(5) << temp->id 
             << setw(15) << temp->fname 
             << setw(5) << temp->mi 
             << setw(15) << temp->lname 
             << setw(8) << temp->sex 
             << setw(10);

        if(temp->pORc == 'P')
        {
            cout << "Pie" << endl;
        } else {
            cout << "Cake" << endl;
        }
        
        temp = temp->next;
    }
}

// *****************************************************************
// * Function Name: CountPie
// * Description: Returns number of records that thought Cheese Cake is Pie.
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
int LinkList::CountPie() {
    int pieCount = 0;
    PieCake_struct* temp = head->next;
    while (temp != tail) {
        if (temp->pORc == 'P') pieCount++;
        temp = temp->next;
    }
    return pieCount;
}

// *****************************************************************
// * Function Name: CountCake
// * Description: Returns the number of records that thought Cheese Cake is Cake. 
// * Parameter Description: 
// * Date: 24-11-22
// * Author: Isaac Jacques
// * References: 
// ***************************************************************** 
int LinkList::CountCake() {
    int cakeCount = 0;
    PieCake_struct* temp = head->next;
    while (temp != tail) {
        if (temp->pORc == 'C') cakeCount++;
        temp = temp->next;
    }
    return cakeCount;
}
