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

class Map_Node
{
public:

	Map_Node() {

		this->next_item = NULL;

	}

	Map_Node(string& key, T& data) {

		this->key = key;
		this->data = data;
		this->next_item = NULL;
		this->previous_item = NULL;

	}

	/*~Map_Node() 
	{
		Map_Node<T>* head = this;
		

		while (head != NULL)
		{
			Map_Node<T>* currNode  = head;
			head = head->next_item;
			delete currNode;
		}
	}*/

	Map_Node<T>* get_next_item() {
		return next_item;
	}

	const Map_Node<T>* get_next_item()const {
		return next_item;
	}

	const Map_Node<T>* get_ref()const {
		return &next_item;
	}
	Map_Node<T>* get_ref() {
		return &next_item;
	}

	Map_Node<T>* get_previous_item() {
		return previous_item;
	}

	const Map_Node<T>* get_previous_item()const {
		return previous_item;
	}

	const T& get_data() const {
		return data;
	}

	T& get_data() {
		return data;
	}

	void set_data(const T& data) {
		this->data = data;
	}

	void set_next_item(Map_Node<T>* next_item) {
		this->next_item = next_item;
	}

	void set_previous_item(Map_Node<T>* previous_item) {
		this->previous_item = previous_item;
	}

	string& get_key() {
		return key;
	}
	const string& get_key() const {
		return key;
	}

	void set_key() {
		this->key = key;
	}

private:

	T data;
	Map_Node<T>* next_item;
	Map_Node<T>* previous_item;
	string key;

};

