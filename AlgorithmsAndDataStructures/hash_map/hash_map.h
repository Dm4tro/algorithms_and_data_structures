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


#define ll long long int

using namespace std;

template<typename T>
class Iterator_Map;

template<typename T>
class Map_Node;

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

   Hash_Map(const Hash_Map<T>& rhs ) {
       Map_Node<T>** temp = this->column;
       this->arraySize = rhs.arraySize;
       this->column = new Map_Node<T> *[this->arraySize];

       for (int i = 0; i < this->arraySize; i++)
       {
           column[i] = NULL;
       }

       for (int i = 0; i < arraySize; i++)
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

   Iterator_Map<T> begiN() {

       return  Iterator_Map<T>(*this, calculateStart(),startIndex);
   }
   Iterator_Map<T> enD() {
       return  Iterator_Map<T>(*this, calculateEnd());
   }
  

   Hash_Map& operator=(const Hash_Map& rhs) {

       Map_Node<T>** temp = this->column;
       this->arraySize = rhs.arraySize;
       this->column = new Map_Node<T> *[this->arraySize];

       for (int i = 0; i < this->arraySize; i++) 
       {
           column[i] = NULL;
       }

       for (int i = 0; i < arraySize; i++)
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

  

   void rehashing()
   {
       int oldArraySize = this->arraySize;
       Map_Node<T>** temp = this->column; 

       this->arraySize = oldArraySize * 2; 
       this->column = new Map_Node<T> *[this->arraySize]; 

       for (int i = 0; i < this->arraySize; i++)
       {
           column[i] = NULL;
       }
       for (int i = 0; i < oldArraySize; i++) 
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
       bucketIndex = static_cast<int> (sum);
       
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


    void deleteByKey(string targetKey) {


        for (size_t i = 0; i < arraySize; i++)
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
                    return;
                }

                temp_pointer = temp_pointer->get_next_item();
            }


        }

        cout << "Key not found!";

    }

  

    Map_Node<T>* calculateStart() {
        int startIndex = 0;


        while (isEmpty(startIndex))
        {
            ++startIndex;
        }



        Map_Node<T>* temp = this->column[startIndex];
        if (startIndex < arraySize+1 ) {
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
        Map_Node<T>* temp = this->column[endIndex];
        return temp;
    }

    Map_Node<T>** column;
private:   
	int arraySize, elements;
    int endIndex= arraySize + 1, startIndex;
};