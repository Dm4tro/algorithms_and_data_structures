#pragma once

#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cctype>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib> 
#include <cctype> 
#include <stdarg.h>
#include <list>
#include <cstdarg>


#include "Map_Node.h"
#include "Iterator_Map.h"
#include "Reverse_Iterator_Map.h"
#include "Const_Iterator_Map.h"
#include "Const_Reverse_Iterator_Map.h"

#define ll long long int

using namespace std;

template<typename T>
class Map_Node;

template<typename T>
class Const_Iterator_Map;

template<typename T>
class Iterator_Map;

template<typename T>
class Const_Reverse_Iterator_Map;

template<typename T>
class Reverse_Iterator_Map;


template<typename T>

class Hash_Map {
public:

    Hash_Map() {
        this->arraySize = 5;
        this->elements = 0;
        this->column = new Map_Node<T> *[this->arraySize+2];
        string key1 = "Startkey";
        T data1 = 1;
        Map_Node<T>* newNode1 = new Map_Node<T>(key1, data1);
        string key2 = "Endkey";
        T data2 = 9;
        Map_Node<T>* newNode2 = new Map_Node<T>(key2, data2);

        column[0] = newNode1;
        column[arraySize +1] = newNode2;
        for (int i = 1; i < this->arraySize+1; i++)
        {
            column[i] = NULL;
        }
    }

   ~Hash_Map() {
       
         
           for (int i = 0; i < this->arraySize+2; ++i) {
               Map_Node<T>* front = column[i];
               while (front != NULL) {
                   Map_Node<T>* prev = front;
                  front = front->get_next_item();
                   delete prev;
               }
               column[i] = NULL;
           }
           
           delete[] column;
  
    }

   Hash_Map(const Hash_Map<T>& rhs ) {
       Map_Node<T>** temp = this->column;
       this->arraySize = rhs.arraySize;
       this->column = new Map_Node<T> *[this->arraySize+2];
       string key1 = "Startkey";
       T data1 = 1;
       Map_Node<T>* newNode1 = new Map_Node<T>(key1, data1);
       string key2 = "Endkey";
       T data2 = 9;
       Map_Node<T>* newNode2 = new Map_Node<T>(key2, data2);
       
       column[0] = newNode1;
       column[arraySize + 1] = newNode2;
       for (int i = 1; i < this->arraySize+1; i++)
       {
           column[i] = NULL;
       }

       for (int i = 1; i < arraySize+1; i++)
       {
           Map_Node<T>* currBucketHead = rhs.column[i];

           while (currBucketHead != NULL)
           {
               this->insertWithoutChangingElementSize(currBucketHead->get_key(), currBucketHead->get_data());
               currBucketHead = currBucketHead->get_next_item();
           }
       }
       elements = rhs.elements;

   }

   friend ostream& operator<<(ostream& os, const Hash_Map<T>& rhs)
   {

       for (int i = 1; i < rhs.arraySize+1; ++i)
       {
           Map_Node<T>* temp_pointer = rhs.column[i];
           os << i << " Row:";

           while (temp_pointer != NULL)
           {
               os << "-> " << temp_pointer->get_data() << " Key: " << temp_pointer->get_key() << " ";

               temp_pointer = temp_pointer->get_next_item();

           }

           os << "-> NULL" << endl;
       }
       return os;
   }

   friend istream& operator>>(istream& is, Hash_Map<T>& rhs)
   {
       string  keyWord;
       T value;
       is >> keyWord >> value;

       rhs.insert(keyWord, value);

       return is;
   }

   Hash_Map& operator=(const Hash_Map& rhs) {

       Map_Node<T>** temp = this->column;
       this->arraySize = rhs.arraySize;
       this->column = new Map_Node<T> *[this->arraySize+2];

       string key1 = "Startkey";
       T data1 = 1;
       Map_Node<T>* newNode1 = new Map_Node<T>(key1, data1);
       string key2 = "Endkey";
       T data2 = 9;
       Map_Node<T>* newNode2 = new Map_Node<T>(key2, data2);

       column[0] = newNode1;
       column[arraySize + 1] = newNode2;
       for (int i = 1; i < this->arraySize+1; i++)
       {
           column[i] = NULL;
       }

       for (int i = 1; i < arraySize+1; i++)
       {
           Map_Node<T>* currBucketHead = rhs.column[i];

           while (currBucketHead != NULL)
           {
               this->insertWithoutChangingElementSize(currBucketHead->get_key(), currBucketHead->get_data());
               currBucketHead = currBucketHead->get_next_item();
           }
       }
       elements = rhs.elements;
       return *this;
   }

   Iterator_Map<T> begiN() {

       return  Iterator_Map<T>(*this, calculateStart(),startIndex);
   }
   Iterator_Map<T> enD() {
       return  Iterator_Map<T>(*this, calculateEnd());
   }
  
   Reverse_Iterator_Map<T> rbegiN() {

       return  Reverse_Iterator_Map<T>(*this, calculateRStart(), rStartIndex);
   }
   Reverse_Iterator_Map<T> renD() {
       return  Reverse_Iterator_Map<T>(*this, calculateREnd());
   }

   Const_Iterator_Map<T> cbegiN() {

       return  Const_Iterator_Map<T>(*this, calculateStart(), startIndex);
   }
   Const_Iterator_Map<T> cenD() {
       return  Const_Iterator_Map<T>(*this, calculateEnd());
   }

   Const_Reverse_Iterator_Map<T> crbegiN() {

       return  Const_Reverse_Iterator_Map<T>(*this, calculateRStart(), rStartIndex);
   }
   Const_Reverse_Iterator_Map<T> crenD() {
       return  Const_Reverse_Iterator_Map<T>(*this, calculateREnd());
   }

  

   void rehashing()
   {
       int oldArraySize = this->arraySize;
       Map_Node<T>** temp = this->column; 

       this->arraySize = oldArraySize * 2; 
       this->column = new Map_Node<T> *[this->arraySize+2]; 

       
       for (int i = 1; i < this->arraySize+1; i++)
       {
           column[i] = NULL;
       }

       string key1 = "Startkey";
       T data1 = 1;
       Map_Node<T>* newNode1 = new Map_Node<T>(key1, data1);
       string key2 = "Endkey";
       T data2 = 9;
       Map_Node<T>* newNode2 = new Map_Node<T>(key2, data2);

       column[0] = newNode1;
       column[arraySize + 1] = newNode2;

       for (int i = 1; i < oldArraySize+1; i++) 
       {
           Map_Node<T>* currBucketHead = temp[i];
           while (currBucketHead != NULL) 
           {
               this->insertWithoutChangingElementSize(currBucketHead->get_key(), currBucketHead->get_data());
               currBucketHead = currBucketHead->get_next_item();
           }
       }
       delete[] temp; 
       return;
   }

   bool isEmpty(int bucketIndex) {
       return this->column[bucketIndex] == NULL;
   }

   void insertWithoutChangingElementSize(string key, T value)
   {
       while (this->getLoadFactor() > 0.5f) // factor > 0.5
       {
           this->rehashing();
       }

       int bucketIndex = this->hashFunction(key);
       if (isEmpty(bucketIndex))
       {
           Map_Node<T>* newNode = new Map_Node<T>(key, value);
           column[bucketIndex] = newNode;
          
       }
       else
       {
           Map_Node<T>* tempNode = this->column[bucketIndex];
           Map_Node<T>* newNode = new Map_Node<T>(key, value);
           newNode->set_next_item(this->column[bucketIndex]);
           tempNode->set_previous_item(newNode);
           this->column[bucketIndex] = newNode;
           
       }
       return;
   }

   
   void insert(string key, T value)
   {
       while (this->getLoadFactor() > 0.5f) // factor > 0.5
       {
           this->rehashing();
       }

       int bucketIndex = this->hashFunction(key);
       if (isEmpty(bucketIndex))
       {
           Map_Node<T>* newNode = new Map_Node<T>(key, value);
           column[bucketIndex] = newNode;
           this->elements++;
           newNode->set_previous_item(NULL);
       }
       else 
       {
           Map_Node<T>* tempNode = this->column[bucketIndex];
           Map_Node<T>* newNode = new Map_Node<T>(key, value);
           newNode->set_next_item(this->column[bucketIndex]) ;
           tempNode->set_previous_item(newNode);
           this->column[bucketIndex] = newNode;
           this->elements++;
       }
       return;
   }

   int hashFunction(string key) 
   {
       int bucketIndex;
       ll sum = 0, factor = 31;
       for (int i = 0; i < key.size(); i++)
       {
           // sum = sum + (ascii value of character * (prime number ^ x)) % total number of buckets
           // factor = factor * prime number i.e. prime number ^ x
           sum = ((sum % this->arraySize) + ((int(key[i])) * factor) % this->arraySize) % this->arraySize;
           factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX;
       }
       bucketIndex = static_cast<int> (sum)+1;
       
      


       return bucketIndex;
   }

    float getLoadFactor()
    {
        float res = (float)(this->elements + 1) / (float)(this->arraySize);
        return res;
    }


    void print() {


        for (int i = 1; i < arraySize+1; ++i)
        {
            Map_Node<T>* temp_pointer = this->column[i];
            cout << i << " Row:";

            while (temp_pointer !=NULL)
            {
                cout << "-> " << temp_pointer->get_data()<<" Key: "<<temp_pointer->get_key()<<" ";

                temp_pointer = temp_pointer->get_next_item();

            }

            cout<<"-> NULL" << endl;
        }
    }


    void deleteByKey(string targetKey) {


        for (size_t i = 1; i < arraySize+1; i++)
        {
            Map_Node<T>* temp_pointer = this->column[i];
            
            while (temp_pointer != NULL)
            {

                if (temp_pointer->get_key()==targetKey)
                {

                    if (temp_pointer->get_previous_item()==NULL)
                    {
                        
                        if (temp_pointer->get_next_item()==NULL)
                        {
                            this->column[i] = NULL;
                        }
                        else {
                            temp_pointer->get_next_item()->set_previous_item(NULL);
                            this->column[i] = temp_pointer->get_next_item();
                        }
                        
                    }
                    else {
                        temp_pointer->get_previous_item()->set_next_item(temp_pointer->get_next_item());

                    }

                    delete  temp_pointer;
                    this->elements--;
                    return;
                }

                temp_pointer = temp_pointer->get_next_item();
            }


        }

        cout << "Key not found!";

    }

  

    Map_Node<T>* calculateStart() {
        this->startIndex = 1;


        while (isEmpty(startIndex))
        {
            startIndex++;
        }



        Map_Node<T>* temp = this->column[startIndex];
        if (startIndex >= arraySize+2 ) {
            temp = NULL;
            return temp;
        }


        /*while (temp->get_next_item() != NULL)
        {
            temp = temp->get_next_item();
        }*/


        return temp;
    }

    Map_Node<T>* calculateEnd() {

        //column[arraySize-1]
        Map_Node<T>* temp = this->column[arraySize + 1];
        return temp;
    }

    Map_Node<T>* calculateRStart() {
        this->rStartIndex = this->arraySize;


        while (isEmpty(rStartIndex))
        {
            rStartIndex--;
        }
        Map_Node<T>* temp = this->column[rStartIndex];
        if (rStartIndex <= 0) {
            temp = NULL;
            return temp;
        }

        if (temp->get_next_item() != NULL) {
            while (temp->get_next_item() != NULL)
            {
                temp = temp->get_next_item();
            }

        }

        return temp;
    }

    Map_Node<T>* calculateREnd() {
        Map_Node<T>* temp = this->column[0];
        return temp;
    }


    Map_Node<T>** column;
private:   
	int arraySize, elements;
    int  startIndex,rStartIndex;
};