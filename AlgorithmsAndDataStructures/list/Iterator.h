#pragma once

#include <iostream>
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

#include "Node.h"
using namespace std;


template<typename T>
 class Iterator
{
private:
	Node<T>* current;
public:
	Iterator() {

	}

	Iterator(Node<T>* node_ptr) {
		current = node_ptr;
	}

	Iterator(const Iterator& iter) {
		current = iter.current;
	}


	Iterator& operator++() {
		current = current->get_next();
		return *this;
	}

	Iterator operator++ (int) {
		Node<T>* temp = current;
		current = current->get_next();
		return Iterator(temp);
	}
	Iterator operator-- (int) {
		Node<T>* temp = current;
		current = current->get_previous();
		return Iterator(temp);

	}
	Iterator& operator-- () {
		current = current->get_previous();
		return *this;
	}
	bool operator== (const Iterator& other) const {
		return current == other.current;
	}

	bool operator!= (const Iterator& other) const {
		return !(*this == other);
	}

	const T& operator*() const { return current->get_value(); }
	T& operator*()  { return current->get_value(); }


	T* operator->() { return &(current->get_value());}


};