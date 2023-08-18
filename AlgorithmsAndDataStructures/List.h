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

           

            return;

        }


        /*do
        {
            current = current->next;
        } while (current->next != head);*/

        Newnode->set_next(be_second);
        current->set_next(Newnode);
        be_second->set_previous(Newnode);





    }

    //template<class T>
    static Node<T>* add_before_head(const T& value, Node<T>*& head) {


        if (isListEmpty(head)) {
            Node<T>* newNode = new Node<T>(value, head, head);
            

            return head;
        }
        else {
            Node<T>* newNode = new Node<T>(value, head, head->get_previous());

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
        
   void sort(bool (*comparator)(const T& ,const T& )) {
       Node<T>* temp = head->get_next();
       Node<T>** hh = &temp;
       Node<T>* p = head->get_previous();
       Node<T>** pp = &p;
       l_sort(hh, pp, comparator );
    }

    private:
        void l_sort(Node<T>** head, Node<T>** end, bool (*comparator)(const T&, const T&)) {
        Node<T>* HeadRef  = *head;
        Node<T>* EndRef = *end;
        Node<T>* a;
        Node<T>* b;

        Node<T>* c;
        Node<T>* d = *end;
        
        //pin_ptr<S> ptest = &test;
        //*ptest = param;
        if ( (HeadRef->get_next() == HeadRef)) {  //||(HeadRef->get_next()->get_next() == *end)) //HeadRef->get_next()->get_next() == HeadRef ||
            return;
        }
        
        FrontBackSplit(HeadRef, &a, &b, &c, &d);
    
            /* Recursively sort the sublists */
            l_sort(&a, &b, comparator);
            l_sort(&c, &d, comparator);

            /* answer = merge the two sorted lists together */
            *head = SortedMerge(a, b,c,d, comparator);
     }

        public:
    Node<T>* get_start() {
        return head;

    }


    Node<T>* get_end() {
        return head->get_previous();

    }

private:
   

    Node<T>* SortedMerge(Node<T>* a, Node<T>* b, Node<T>* c, Node<T>* d, bool (*comparator)(const T&, const T&))
    {
        Node<T>* result = NULL;

        /* Base cases */
        if (a == b->get_next())
            return (c);
        else if (b == d->get_next())
            return (a);
        
        /* Pick either a or b, and recur */
        if (comparator(a->get_value(), c->get_value())) {
           // result = a;
            result = new Node<T>(a->get_value());

          //  result->get_next() = SortedMerge(a->get_next(), b, c, d, comparator);
            result->set_next(SortedMerge(a->get_next(), b, c, d, comparator));
            result->get_next()->set_previous(result); //added
        }
        else {
            result = new Node<T>(c->get_value());
            //result = c;
            result->set_next(SortedMerge(a, b, c->get_next(), d, comparator));
            result->get_next()->set_previous(result);  //added
        }
        return (result);
    }

    void FrontBackSplit(Node<T>* source,
        Node<T>** frontRefStart, Node<T>** frontRefEnd, Node<T>** backRefStart, Node<T>** backRefEnd)
    {
        Node<T>* fast;
        Node<T>* slow;
        slow = source;
        fast = source->get_next();
        


        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != *backRefEnd) {
            fast = fast->get_next();
            if (fast != *backRefEnd) {
                slow = slow->get_next();
                fast = fast->get_next();
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
        at that point. */
        *frontRefStart = source;
        *frontRefEnd = slow;
        
        *backRefStart = slow->get_next();
        fast->set_next(*backRefStart);

        
        *backRefEnd = fast;

        slow->set_next(*frontRefStart);
        /**backRefEnd = fast;*/
    }

    

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


