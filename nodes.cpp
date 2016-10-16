/*
File name: nodes.cpp

Description: This is the implementation file for the doubly linked 
list. It includes nodes.h and will pair with the tester file, hw4.cpp
*/

/*Function to clear the list*/
	template<class T>
void sList<T>::clear()
{
	node<T>* curr;
	node<T>* temp;
	curr = head-> next;
	while (curr != head) 
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}
}

/*Function that will insert a node at the front of the list*/
	template<class T>
void sList<T>::push_front(T dataNum)
{
	node<T> *np;
	np = new node<T>;
	np -> data = dataNum;
	np -> next = head-> next;
	np -> prev = head;
	head -> next = np;
	np -> next-> prev = np;
}

/*Function that will insert a node at the end of the list*/
	template<class T>
void sList<T>::push_back(T dataNum) 
{

	node<T> *np;
	np = new node<T>;
	np -> data = dataNum;
	np -> next = head;
	np -> prev = head->prev;
	head -> prev = np;
	np-> prev -> next = np;
}

/*Function that will return the size of the list*/
	template<class T>
int sList<T>:: size()
{
	int count = 0;
	node<T> *temp;
	temp = head-> next;
	while (temp != head)
	{
		count++;
		temp = temp -> next;
	}
	return count;
}



/*Function that displays the entire list with all of its data members*/
	template<class T>
void sList<T>::display()
{
	node<T> *temp;
	temp= head-> next;

	while (temp != head)
	{
		cout <<temp -> data << " : ";
		temp = temp -> next;
	}
	cout << endl;
}

/*Function that returns 0 if the list is NOT empty, and 
  returns 1 if is empty.*/
	template<class T>
bool sList<T>::empty()
{
	return (head-> next == head);
}

/*Copy constructor implementation*/
	template<class T>
sList<T>:: sList(const sList<T>& obj)
{
	head = new node<T>;
	head -> next = head;
	head -> prev = head;

	node<T> *temp;
	for (temp = obj.head->next; temp != obj.head; temp = temp->next)
		push_back(temp->data);
}


/*Destructor implementation*/
	template<class T>
sList<T>::~sList()
{
	clear();
	delete head;
}

/*Overloaded assignment operator implementation*/
	template<class T>
sList<T>& sList<T>:: operator =(const sList<T>& obj)
{
	if(this != &obj)
	{
		clear(); 
		head = new node<T>;
		head -> next = head;
		head -> prev = head;
		node<T> *temp;
		for (temp = obj.head->next; temp != obj.head; temp = temp->next)
		push_back(temp->data);
	}

	return *this;
}

/*Implementation for find function
  Finds a data element(the parameter passed in)
  in the list and returns a pointer to that 
  element.  Will return a pointer to head 
  if data element is not found.*/
	template<class T>
node<T>* sList<T>:: find(T dataNum)
{
	node<T> *front;
	front = head -> next;
	while(front -> data != dataNum && front != head)
	{
		front = front -> next;
	}

	return front;
}

/*Implementation for erase function.
  Erase an element from the list at the passed in 
  parameter location(a node pointer) */
	template<class T>
void sList<T>:: erase(node<T>* point)
{
	if(point != head)
	{
		point -> prev -> next = point -> next;
		point -> next -> prev = point -> prev;
		delete point; 
	}
}


