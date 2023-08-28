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

#include "Node.h"


using namespace std;

template<typename T>
class Reverse_Iterator
{
private:
	Node<T>* current;
public:
	Reverse_Iterator() {
	}

	Reverse_Iterator(Node<T>* node_ptr) {
		current = node_ptr;
	}

	Reverse_Iterator(const Reverse_Iterator& iter) {
		current = iter.current;
	}

	Reverse_Iterator& operator++() {
		current = current->get_previous();
		return *this;
	}

	Reverse_Iterator operator++ (int) {
		Node<T>* temp = current;
		current = current->get_previous();
		return Reverse_Iterator(temp);
	}
	Reverse_Iterator operator-- (int) {
		Node<T>* temp = current;
		current = current->get_next();
		return Reverse_Iterator(temp);

	}
	Reverse_Iterator& operator-- () {
		current = current->get_next();
		return *this;
	}
	bool operator== (const Reverse_Iterator& other) const {
		return current == other.current;
	}

	bool operator!= (const Reverse_Iterator& other) const {
		return !(*this == other);
	}

	const T& operator*() const { return current->get_value(); }
	 T& operator*() { return current->get_value(); }
	T* operator->() { return &(current->get_value()); }


};

