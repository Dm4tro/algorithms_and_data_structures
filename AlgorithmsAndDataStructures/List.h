#pragma once
#include <list>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <stdarg.h>

#include "Node.h"
#include "Reverse_Iterator.h"
#include "Iterator.h"
#include "Const_Iterator.h"
#include "Const_Reverse_Iterator.h"

using namespace std;


template<typename T> class List
{
public:

    List() {
        head = new Node<T>();

    }
    List(const T values[], int size) {
        head = new Node<T>();
        //const auto size = sizeof(values) == 0 ? 0 : size;
        for (int i = 0; i < size; ++i)
        {
            add_before_head(values[i], head);
        }

    }

    ~List()
    {
        Node<T>* current = head;
        Node<T>* next = NULL;
        Node<T>* EndOfCycle = head;
        head = NULL;
        
        do {
            next = current->get_next();
            delete current;

            current = next;

        } while (current != EndOfCycle);
        

        counter = 0;


    }

    List(const List<T>& rhs) {
        copyClass(rhs);
    }


    Iterator<T> beginn() {
        return Iterator<T>(head->get_next());
    }
    Iterator<T> end() {
        return Iterator<T>(head);
    }

    Const_Iterator<T> cend() const {
        return Const_Iterator<T>(head);
    }

    Const_Iterator<T> cbeginn() const {
        return Const_Iterator<T>( head->get_next());
    }

    Reverse_Iterator<T> beginnn()  {
        return Reverse_Iterator<T>(head->get_previous());
    }
    Reverse_Iterator<T> endd() {
        return Reverse_Iterator<T> (head);
    }

    Const_Reverse_Iterator<T> cendd() const {
        return Const_Reverse_Iterator<T>( head);
    }

    Const_Reverse_Iterator<T> cbeginnn()  const {
        return Const_Reverse_Iterator<T>( head->get_previous());
    }

    void add_back(T value) {
        Node<T>* Newnode = new Node<T>(value);
        Node<T>* current = head;
        if (head->get_previous() == head && head->get_next() == head) {
            head->set_next(Newnode);
            head->set_previous(Newnode);
            
            Newnode->set_next(head) ;
            Newnode->set_previous (head);
            return;

        }
        Newnode->set_previous(current->get_previous());
        Newnode->set_next(current);
        current->set_previous(Newnode);
        /*do
        {
            current = current->next;
        } while (current->next != head);
        current->next = Newnode;
        head = Newnode;*/
        counter += 1;
    }
    void add_front(T value) {
        Node<T>* Newnode = new Node<T>(value);
        Node<T>* current = head;
        Node<T>* be_second = current->get_next();

        if (head->get_previous() == head && head->get_next() == head) {
            head->set_next(Newnode) ;
            head->set_previous(Newnode) ;
            Newnode->set_next(head) ;
            Newnode->set_previous(head);

            counter += 1;

            return;

        }


        /*do
        {
            current = current->next;
        } while (current->next != head);*/

        Newnode->set_next(be_second);
        current->set_next(Newnode);
        be_second->set_previous(Newnode);

        counter += 1;



    }

    //template<class T>
    static Node<T>* add_before_head(const T& value, Node<T>*& head) {


        if (isListEmpty(head)) {
            Node<T>* newNode = new Node<T>(value, head, head);
            counter += 1;

            return head;
        }
        else {
            Node<T>* newNode = new Node<T>(value, head, head->get_previous());
            counter += 1;

            return head;
        }
        return 0;
    }

    static bool isListEmpty(Node<T>* head) {
        return head->get_next() == head && head->get_previous() == head;
    }




   const void print()const {
        Node<T>* temp = head->get_next();
        if (head->get_next() == head && head->get_previous() == head) {
            cout << "List is empty" << endl;
            return;
        }
        cout << "List is:" << endl;
        do
        {
            cout << temp->get_value() << " ";
            temp = temp->get_next();


        } while (temp != head);

        cout << endl;

    }


    void delete_at(int num) {

        Node<T>* temp1 = head;
        Node<T>* temp2 = NULL;

        while (num-- > 1)
        {
            temp2 = temp1;
            temp1 = temp1->get_next();
        }

        temp2->get_next() = temp1->get_next();
        counter -= 1;

    }
    /*delete temp1;*/
    List<T>& operator=(List<T>& rhs) {

        Node<T>* current = head;
        Node<T>* next = NULL;
        while (current != NULL)
        {
            next = current->get_next();
            delete current;
            current = next;

        }
        head = nullptr;

        Node<T>* temp = rhs.head;


        /*head = temp;*/



        while (temp != NULL)
        {

            add(temp->value);
            temp = temp->get_next();


        }

        return *this;
    }


    friend ostream& operator<<(ostream& os, const List<T>& rhs)
    {
        Node<T>* temp = head;
        os << "THList is:" << endl;
        while (temp != NULL)
        {
            os << temp->get_value() << " ";
            temp = temp->get_next();
        }
        os << endl;
        return os;
    }
        
    
    void l_sort(Node<T>** head, Node<T>** end) {
        Node* HeadRef  = *head;
        Node* EndRef = *end;
        Node* a;
        Node* b ;

        Node* c;
        Node* d= *end;
        

        if ((head->get_next() == end) ||( head==end) {
            return;
        }
        
        FrontBackSplit(HeadRef, &a, &b, &c, &d);
    
            /* Recursively sort the sublists */
            l_sort(&a, &b);
            l_sort(&c, &d);

            /* answer = merge the two sorted lists together */
            *headRef = SortedMerge(a, b,c,d);


     }


      Node<T>* get_start() {
        return head;
    }

    Node<T>* get_end() {
        return head->get_previous();

    }

private:
    bool compare_int (const int first, const int secound) {
        if (first <= secound) {
            return 1;
        }
        else {
            return 0;
        }

    }

    Node* SortedMerge(Node* a, Node* b, Node* c, Node* d)
    {
        Node* result = NULL;

        /* Base cases */
        if (a == b->get_next())
            return (c);
        else if (b == d->get_next())
            return (a);
        
        /* Pick either a or b, and recur */
        if (compare_int(a->get_data(), b->get_data())) {
            result = a;
            result->next = SortedMerge(a->get_next(), b, c, d);
        }
        else {
            result = b;
            result->next =  SortedMerge(a, b,c->get_next(),d);
        }
        return (result);
    }

    void FrontBackSplit(Node* source,
        Node** frontRefStart, Node** frontRefEnd, Node** backRefStart, Node** backRefEnd)
    {
        Node* fast;
        Node* slow;
        slow = source;
        fast = source->get_next();
        


        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != backRefEnd) {
            fast = fast->get_next();
            if (fast != backRefEnd) {
                slow = slow->get_next();
                fast = fast->get_next();
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
        at that point. */
        *frontRefStart = source;
        *backRefStart = slow->next;
        frontRefEnd = slow ;
        backRefEnd = backRefEnd;
    }

    int counter=0;

    Node<T>* head;



protected:
    void copyClass(List rs) {
        Node<T>* current = head;
        Node<T>* next = NULL;
        while (current != NULL)
        {
            next = current->get_next();
            delete current;
            current = next;

        }
        head = nullptr;

        Node<T>* temp = rs.head;


        /*head = temp;*/



        while (temp != NULL)
        {

            add(temp->value);
            temp = temp->get_next();


        }

        /*return *this;*/

    };
};

