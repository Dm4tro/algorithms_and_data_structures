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
#include "Iterator.h"
#include "List.h"
#include "Node.h"


using namespace std;

template<typename T>
class reverse_iteratorr
{
private:
	Node<T>* current;
public:
	reverse_iteratorr() {

	}

	reverse_iteratorr(Node<T>* node_ptr) {
		current = node_ptr;
	}

	reverse_iteratorr& operator++() {
		current = current->next;
		return *this;
	}

	reverse_iteratorr operator++ (int) {
		Node<T>* temp = current;
		current = current->next;
		return reverse_iteratorr(temp);
	}
	reverse_iteratorr operator-- (int) {
		Node<T>* temp = current;
		current = current->previosus;
		return reverse_iteratorr(temp);

	}
	reverse_iteratorr& operator-- () {
		current = current->previosus;
		return *this;
	}
	bool operator== (const reverse_iteratorr& other) const {
		return current == other.current;
	}

	bool operator!= (const reverse_iteratorr& other) const {
		return !(*this == other);
	}

	T& operator*() const { return current->val; }
	T* operator->() { return &(current->val); }


};

