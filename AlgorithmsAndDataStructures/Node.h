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


using namespace std;

template<typename T>
class Node
{
public:

	Node() {
		this->next = this;
		this->previous = this;
	}

	Node(const T& value, Node<T>* next, Node<T>* previous) {
		this->value = value;

		this->next = next;
		this->previous = previous;

		previous->next = this;
		next->previous = this;
	}

	Node(const T& val) {
		this->value = val;
		this->next = this;
		this->previous = this;
	}



	~Node()
	{

	}

	 Node<T>* get_next() {
		return next;
	}

	const Node<T>* get_next()const {
		return next;
	}

	const Node<T>* get_ref()const {
		return &next;
	}
	 Node<T>* get_ref() {
		return &next;
	}

	Node<T>* get_previous() {
		return previous;
	}

	const Node<T>* get_previous()const {
		return previous;
	}
	

	const T& get_value() const {
		return value;
	}

	 T& get_value()  {
		return value;
	}

	void set_value(const T& value) {
		this.value = value;
	}

	void set_next(Node<T>* next) {
		this.next = next;
	}

	void set_previous(Node<T>* previous) {
		this.previous = previous;
	}
	

private:

	T value;
	Node<T>* next;
	Node<T>* previous;

};

