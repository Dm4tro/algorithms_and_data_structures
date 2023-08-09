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
#include "reverse_iteratorr.h"
#include "Iterator.h"

using namespace std;

template<typename T>
class List
{
public:
	template <typename T>
	using Reverse_iteratorr = reverse_iteratorr<T>;
	template <typename T>
	using iterator = Iterator<T>;



public:

	List() {
		head = new Node<T>();

	}
	List(const T values[], int size) {
		head = new Node<T>();
		//const auto size = sizeof(values) == 0 ? 0 : size;
		for (int i = 0; i < size; ++i)
		{
			add_before_head(values[i], head);
		}

	}

	~List()
	{
		Node<T>* current = head;
		Node<T>* next = NULL;

		do {
			next = current->get_next;
			delete current;
			current = next;

		} while (current != head);
		delete head;
		head = NULL;

	}

	List(const List<T>& rhs) {
		copyClass(rhs);

	}


	iterator<T> beginn() {
		return iterator<T>(head->get_next);
	}
	iterator<T> end() {
		return iterator<T>(head);
	}
	reverse_iteratorr<T> beginnn() {
		return reverse_iteratorr<T>(head->get_previous);
	}
	reverse_iteratorr<T> endd() {
		return reverse_iteratorr<T>(head);
	}


	void add_back (T value) {
		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;
		if (head->get_previous == head && head->get_next == head) {
			head->get_next = Newnode;
			head->get_previous = Newnode;
			Newnode->get_next = head;
			Newnode->get_previous = head;
			return;

		}
		Newnode->get_previous = current->get_previous;
		Newnode->get_next = current;
		current->get_previous = Newnode;
		/*do
		{
			current = current->next;
		} while (current->next != head);
		current->next = Newnode;
		head = Newnode;*/

	}
	void add_front(T value) {
		Node<T>* Newnode = new Node<T>(value);
		Node<T>* current = head;
		Node<T>* be_second = current->get_next;

		if (head->get_previous == head && head->get_next == head) {
			head->get_next = Newnode;
			head->get_previous = Newnode;
			Newnode->get_next = head;
			Newnode->get_previous = head;
			return;

		}


		/*do
		{
			current = current->next;
		} while (current->next != head);*/
		
		Newnode->get_next = be_second;
		current->get_next = Newnode;
		be_second->previous = Newnode;

		


	}

	//template<class T>
	static Node<T>* add_before_head(const T& value, Node<T>*& head) {


		if (isListEmpty(head)) {
			Node<T>* newNode = new Node<T>(value, head, head);

			return head;
		}
		else {
			Node<T>* newNode = new Node<T>(value, head, head->get_previous);

			return head;
		}
		return 0;
	}

	static bool isListEmpty(Node<T>* head) {
		return head->get_next == head && head->get_previous == head;
	}




	void print()const {
		Node<T>* temp = head->get_next;
		if (head->get_next == head && head->get_previous == head) {
			cout << "List is empty" << endl;
			return;
		}
		cout << "List is:" << endl;
		do
		{
			cout << temp->value << " ";
			temp = temp->get_next;


		} while (temp != head);

		cout << endl;

	}


	void delete_at(int num) {

		Node<T>* temp1 = head;
		Node<T>* temp2 = NULL;

		while (num-- > 1)
		{
			temp2 = temp1;
			temp1 = temp1->get_next;
		}

		temp2->get_next = temp1->get_next;

	}
	/*delete temp1;*/
	List<T>& operator=(List<T>& rhs) {

		Node<T>* current = head;
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->get_next;
			delete current;
			current = next;

		}
		head = nullptr;

		Node<T>* temp = rhs.head;


		/*head = temp;*/



		while (temp != NULL)
		{

			add(temp->value);
			temp = temp->get_next;


		}

		return *this;
	}


	friend ostream& operator<<(ostream& os, const List<T>& rhs)
	{
		Node<T>* temp = head;
		os << "THList is:" << endl;
		while (temp != NULL)
		{
			os << temp->val << " ";
			temp = temp->next;
		}
		os << endl;
		return os;
	}



private:
	Node<T>* head;

protected:
	void copyClass(List rs) {
		Node<T>* current = head;
		Node<T>* next = NULL;
		while (current != NULL)
		{
			next = current->get_next;
			delete current;
			current = next;

		}
		head = nullptr;

		Node<T>* temp = rs.head;


		/*head = temp;*/



		while (temp != NULL)
		{

			add(temp->value);
			temp = temp->get_next;


		}

		/*return *this;*/

	}
};

