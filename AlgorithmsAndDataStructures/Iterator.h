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
#include "reverse_iteratorr.h"
#include "List.h"
#include "Node.h"
using namespace std;


template<typename T>
class Iterator
{
private:
	Node<T>* curren;
public:
	Iterator() {

	}

	Iterator(Node<T>* node_ptr) {
		curren = node_ptr;
	}

	Iterator& operator++() {
		curren = curren->next;
		return *this;
	}

	Iterator operator++ (int) {
		Node<T>* temp = curren;
		curren = curren->next;
		return Iterator(temp);
	}
	Iterator operator-- (int) {
		Node<T>* temp = curren;
		curren = curren->previosus;
		return Iterator(temp);

	}
	Iterator& operator-- () {
		curren = curren->previosus;
		return *this;
	}
	bool operator== (const Iterator& other) const {
		return curren == other.curren;
	}

	bool operator!= (const Iterator& other) const {
		return !(*this == other);
	}

	T& operator*() const { return curren->val; }
	T* operator->() { return &(curren->val); }


};