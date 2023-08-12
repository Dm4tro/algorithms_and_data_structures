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
class Const_Reverse_Iterator
{
private:
	Node<T>* current;
public:
	Const_Reverse_Iterator() {
	}

	Const_Reverse_Iterator(Node<T>* node_ptr) {
		current = node_ptr;
	}

	Const_Reverse_Iterator(const Const_Reverse_Iterator& iter) {
		current = iter.current;
	}

	Const_Reverse_Iterator& operator++() {
		current = current->get_previous();
		return *this;
	}

	Const_Reverse_Iterator operator++ (int) {
		 Node<T>* temp = current;
		current = current->get_previous();
		return Const_Reverse_Iterator(temp);
	}
	Const_Reverse_Iterator operator-- (int) {
		Node<T>* temp = current;
		current = current->get_next();
		return Const_Reverse_Iterator(temp);

	}
	Const_Reverse_Iterator& operator-- () {
		current = current->get_next();
		return *this;
	}
	bool operator== (const Const_Reverse_Iterator& other) const {
		return current == other.current;
	}

	bool operator!= (const Const_Reverse_Iterator& other) const {
		return !(*this == other);
	}

	const T& operator*() const { return current->get_value(); }
	
	const T* operator->() const { return &(current->get_value()); }



};

