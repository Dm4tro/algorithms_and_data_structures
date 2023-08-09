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

#include "List.h"
#include "reverse_iteratorr.h"
#include "Iterator.h"
using namespace std;

template<typename T>

class Node
{
public:

	Node() {
		this->get_next = this;
		this->get_previous = this;
	}

	Node(const T& value, Node<T>* next, Node<T>* previous) {
		this->value = value;

		this->get_next = next;
		this->get_previous = previous;

		previous->get_next = this;
		next->get_previous = this;
	}

	Node(const T& val) {
		this->value = val;
		this->get_next = this;
		this->get_previous = this;
	}



	~Node()
	{

	}

	const Node<T>* get_next()const {
		return next;
	}

	const Node<T>* get_previous()const {
		return previous;
	}

	const T& get_value() const {
		return value;
	}

	void set_value(const T& value) {
		this.value = value;
	}

	void set_next(Node<T>* next) {
		this.next = next;
	}

	void set_value(Node<T>* previous) {
		this.previous = previous;
	}

private:

	T value;
	Node<T>* next;
	Node<T>* previous;

};

