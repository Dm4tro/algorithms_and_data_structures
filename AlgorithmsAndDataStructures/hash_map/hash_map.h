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
#include <map>
#include <stdarg.h>
#include <list>
#include <cstdarg>

#include "Map_Node.h"
#define ll long long int
using namespace std;

template<typename T>

class Hash_Map {
public:

    Hash_Map() {
        this->arraySize = 5;
        this->elements = 0;
        this->column = new Map_Node<T> *[this->arraySize];
        
        for (int i = 0; i < this->arraySize; i++)
        {
            column[i] = NULL;
        }
    }

   ~Hash_Map() {
       
         
           for (int i = 0; i < this->arraySize; ++i) {
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

   void rehashing()
   {
       int oldCapacity = this->arraySize;
       Map_Node<T>** temp = this->column; 

       this->arraySize = oldCapacity * 2; 
       this->column = new Map_Node<T> *[this->arraySize]; 

       for (int i = 0; i < this->arraySize; i++)
       {
           column[i] = NULL;
       }
       for (int i = 0; i < oldCapacity; i++) 
       {
           Map_Node<T>* currBucketHead = temp[i];
           while (currBucketHead != NULL) 
           {
               this->rehashingInsert(currBucketHead->get_key(), currBucketHead->get_data());
               currBucketHead = currBucketHead->get_next_item();
           }
       }
       delete[] temp; 
       return;
   }

   bool isEmpty(int bucketIndex) {
       return this->column[bucketIndex] == NULL;
   }

   void rehashingInsert(string key, T value)
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

       bucketIndex = sum;
       return bucketIndex;
   }

    float getLoadFactor()
    {
        float res = (float)(this->elements + 1) / (float)(this->arraySize);
        return res;
    }


    void print() {


        for (int i = 0; i < arraySize; ++i)
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


private:
	Map_Node<T>** column;
	int arraySize, elements;
};