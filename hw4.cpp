
/*
File name: hw4.cpp

Description: This is the main part of the program.  It creates a 
doubly linked list, with numbers 1 thorugh 9.  It then uses an iterator to output the list, 1 through 9.  It then uses partial_sum function to iterate through the list while displaying the new list.  It then uses prefix_sum function to iterate through the list while displaying the new list. 
In total, 4 lists are displayed.  
*/

#include "nodes.h"
#include "prefix.h"
#include <numeric>

int main()
{
  sList<int> stlList;
  sList<int> myList;
  sList<int>::iterator init; 
  

cout<< "Original myList: " << endl;
for(int i = 1; i < 10; i++)
   { 
    int temp = i;
    myList.push_back(temp);
    cout << i << " ";
   }
cout << endl;



cout<< "Original stlList: " << endl;
for(int i = 1; i < 10; i++)
   { 
    int temp = i;
    stlList.push_back(temp);
    cout << i << " ";
   }
cout << endl;



cout<< "Result list after running myList with STL partial_sum() algorithm" << endl; 
partial_sum(myList.start(), myList.end(), myList.start());
for(init = myList.start(); init != myList.end(); ++init)
{
cout<< *init << " ";
}
cout<< endl;


cout<< "Result after running STL List with my prefix_sum() algorithm" << endl;
prefix_sum(stlList.start(), stlList.end(), stlList.start());
for(init = stlList.start(); init != stlList.end(); ++init)
{
cout<< *init << " ";
}
cout<< endl;

  return 0;
}


