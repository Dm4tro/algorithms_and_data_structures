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
            AddBeforeHead(values[i], head);
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

    void AddBack(T value) {
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
    void AddFront(T value) {
        Node<T>* Newnode = new Node<T>(value);
        Node<T>* current = head;
        Node<T>* be_second = current->get_next();

        if (isListEmpty(head)) {
            head->set_next(Newnode) ;
            head->set_previous(Newnode) ;
            Newnode->set_next(head) ;
            Newnode->set_previous(head);

           

            return;

        }

        Newnode->set_next(be_second);
        current->set_next(Newnode);
        be_second->set_previous(Newnode);

    }

    //template<class T>
    static Node<T>* AddBeforeHead(const T& value, Node<T>*& head) {


        if (isListEmpty(head)) {
            Node<T>* newNode = new Node<T>(value, head, head);
            

            return head;
        }else {
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
        if (isListEmpty(head)) {
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


    void DeleteAt(int num) {

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

        Node<T>* current =rhs.head;
        Node<T>* next = NULL;
       
        do
        {

            next = current->get_next();
            delete current;
            current = next;


        } while (current != rhs.head);
        head = nullptr;

        Node<T>* temp = rhs.head->get_next();


        /*head = temp;*/



        do
        {

            AddBack(temp->get_value());
            temp = temp->get_next();


        }       while (temp != rhs.head);
       

        return *this;
    }


    friend ostream& operator<<(ostream& os, const List<T>& rhs)
    {
        Node<T>* temp = rhs.head->get_next();
        if (isListEmpty(rhs.head)) {
            os << "List is empty" << endl;
            return os;
        }

       
        os << "List is:" << endl;
        
        do
        {
            os  << temp->get_value() << " ";
            temp = temp->get_next();


        } while (temp != rhs.head);
        os << endl;
        return os;
    }
        
   void Sort(bool (*comparator)(const T& ,const T& )) {
       if (isListEmpty(head)) {
           cout << "Error, can't compare empty list!!!" << endl;
           return;
       }
       Node<T>* temp1 = head->get_next();
       Node<T>** temporary_head = &temp1;
    
       Node<T>* temp2 = head;
      temp2 = temp2->get_previous();
      temp2->set_next(NULL);
       
       SortListWithMergeSort(temporary_head, comparator);

       Node<T>* repair = *temporary_head;
       Node<T>* temp3=repair;
       head->set_next(temp3);
       while (temp3->get_next()!=NULL)
       {
           temp3 = temp3->get_next();
       }
       temp3->set_next(head);
       
       FixPrevLink();
    }

    private:
        void FixPrevLink() {
            Node<T>* temp_front = head->get_next();
            Node<T>* temp_back = head;
            while (temp_front!=head)
            {
                temp_front->set_previous(temp_back);
                temp_front= temp_front->get_next();
                temp_back = temp_back->get_next();
            }
            head->set_previous(temp_back);

        }
        void SortListWithMergeSort(Node<T>** headRef,  bool (*comparator)(const T&, const T&))
        {
            Node<T>* header = *headRef;
            Node<T>* a;
            Node<T>* b;

            /* Base case -- length 0 or 1 */
            if ((header == NULL) || (header->get_next() == NULL)) {
                return;
            }

            /* Split head into 'a' and 'b' sublists */
            SplitInFrontAndBack(header, &a, &b);

            /* Recursively sort the sublists */
            SortListWithMergeSort(&a, comparator);
            SortListWithMergeSort(&b, comparator);

            /* answer = merge the two sorted lists together */
            *headRef = SortMergedParts(a, b, comparator);
        }

        void SplitInFrontAndBack(Node<T>* source,
            Node<T>** frontRef, Node<T>** backRef)
        {
            Node<T>* fast;
            Node<T>* slow;
            slow = source;
            fast = source->get_next();

            /* Advance 'fast' two nodes, and advance 'slow' one node */
            while (fast != NULL) {
                fast = fast->get_next();
                if (fast != NULL) {
                    slow = slow->get_next();
                    fast = fast->get_next();
                }
            }

            /* 'slow' is before the midpoint in the list, so split it in two
            at that point. */
            *frontRef = source;
            *backRef = slow->get_next();
            slow->set_next(NULL);
        }

        Node<T>* SortMergedParts(Node<T>* a, Node<T>* b, bool (*comparator)(const T&, const T&))
        {
            Node<T>* result = NULL;

            /* Base cases */
            if (a == NULL)
                return (b);
            else if (b == NULL)
                return (a);

            /* Pick either a or b, and recur */
            if (comparator(a->get_value(), b->get_value())) {
                
                result = a;
                result->set_next(SortMergedParts(a->get_next(), b, comparator)) ;
            }
            else {
                result = b;
                result->set_next(SortMergedParts(a, b->get_next(), comparator));
            }
            return (result);
        }

    

    

    Node<T>* head;



protected:
    void copyClass(List rs) {
        Node<T>* current = head;
        Node<T>* next = NULL;
        
        do
        {

            next = current->get_next();
            delete current;
            current = next;


        } while (current != rs.head);
        head = nullptr;
        Node<T>* temp = rs.head;

       
        do
        {

            AddBack(temp->get_value());
            temp = temp->get_next();


        } while (temp != rhs.head);
        /*return *this;*/

    };
};


