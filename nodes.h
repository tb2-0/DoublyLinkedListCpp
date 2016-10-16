/*
Author:  Tristan Beyer
Course:  Cs219 - Dr. Liu - TH 6:20pm
Version: 11/27/15
File name: nodes.h


Description:This program implements a doubly linked list.  
This part of the program has a structure named node  that has
the data and a pointer to the next node, as well as pointer 
to the previous node in the list.  This file is called nodes.h 
Other files in this package include nodes.cpp and hw4.cpp

*/

#ifndef NODES_H
#define NODES_H

#include <iostream>
#include <cstdlib>

using namespace std;

/*structure named node*/
template <class T>
struct node
{
	T data;

	node<T> *next;
	node<T> *prev;
};

/*Class for list named sList*/
template<class T>
class sList{

	public:

	/*constructor*/
		sList(): head(0)
	{
		head = new node<T>;
		head -> next = head;
		head -> prev = head;
	};


		/*destructor*/
		virtual ~sList();

		/*copy constructor*/
		sList(const sList& obj);

		/*overloaded assignment operator*/
		sList &operator =(const sList &other);

		/*check if the list is empty*/
		bool empty();

		/*insert node at the front of the list*/
		void push_front(T dataNum);

		/*insert node at the back of the list*/
		void push_back(T dataNum);

		/*returns the size of the list*/
		int size();

		/*returns all elements in the list*/
		void display();

		/*clears the list*/
		void clear();

		/*Erase an element at the given parameter(a node 
		  pointer) from the list */
		void erase(node<T>* point);

		/*Finds a data element in the list and returns
	  	a pointer to that element.  Will return a pointer
	  	to head if data element is not found.*/
	
		node<T>* find(T dataNum);


	class iterator
{
         public:

		typedef bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T * pointer; 
		typedef T &reference;

		iterator() : ptr(0) {} 

		iterator(node<T>* setIt){ptr = setIt; }

                bool operator ==(const iterator& first) const
			{ return (ptr == first.ptr);}
		
		bool operator !=(const iterator& first) const
			{return (ptr != first.ptr);}		
 
	        iterator& operator ++()
			{
			ptr = ptr -> next;
			return *this;
			}

	        iterator& operator --()
			{
			return iterator(ptr->prev);
			}

		 T& operator* () 
			{
			return ptr->data;
			}

        private:
               node<T>* ptr;
	 };

	iterator end() {return iterator (head);}

	iterator start() {return iterator(head-> next);}

	private:
	node<T>* head;
};

#include "nodes.cpp"
#endif

