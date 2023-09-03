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
//#include <map>
#include <stdarg.h>
#include <list>
#include <cstdarg>

#include "Map_Node.h"
#include "Hash_Map.h"

template<typename T>
class Hash_Map;

template<typename T>
class Map_Node;

using namespace std;

template<typename T>

class Const_Iterator_Map
{
private:
	Map_Node<T>* current_item;
	int index;
	Hash_Map<T>& hash_map;
public:
	Const_Iterator_Map() {

	}

	Const_Iterator_Map(Hash_Map<T>& map_, Map_Node<T>* node_ptr, int ind) : hash_map(map_), index(ind) {


		current_item = node_ptr;

	}

	Const_Iterator_Map(Hash_Map<T>& map_, Map_Node<T>* node_ptr) : hash_map(map_) {


		current_item = node_ptr;

	}

	Const_Iterator_Map(const Const_Iterator_Map& iter) {
		current_item = iter.current_item;
	}


	Const_Iterator_Map& operator++() {
		/*current_item = current_item->get_next_item();*/
		if (current_item->get_next_item() == NULL)
		{
			current_item = current_item->get_next_item();
			while (current_item == NULL)
			{
				++index;
				current_item = hash_map.column[index];

			}


		}
		else
		{
			current_item = current_item->get_next_item();
		}

		return *this;
	}


	Const_Iterator_Map operator++ (int) {
		Map_Node<T>* temp = current_item;

		if (current_item->get_next_item() == NULL)
		{
			current_item = current_item->get_next_item();

			while (current_item == NULL)
			{
				++index;
				current_item = hash_map.column[index];

			}


		}
		else
		{
			current_item = current_item->get_next_item();
		}
		return Const_Iterator_Map(hash_map, temp);
	}


	Const_Iterator_Map operator-- (int) {
		Map_Node<T>* temp = current_item;
		current_item = current_item->get_previous_item();
		return Const_Iterator_Map(temp);

	}

	Const_Iterator_Map& operator-- () {
		current_item = current_item->get_previous_item();
		return *this;
	}

	bool operator== (const Const_Iterator_Map& other) const {
		return current_item == other.current_item;
	}

	bool operator!= (const Const_Iterator_Map& other) const {
		return !(*this == other);
	}

	const T& operator*() const { return current_item->get_data(); }
	 /*T& operator*()  { return current_item->get_data(); }*/


	const T* operator->() const { return &(current_item->get_data()); }

};


