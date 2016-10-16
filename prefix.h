#ifndef PREFIX_H
#define PREFIX_H
/*
Title of file:  prefix.h
A header file with the prefix_sum function included.  
Date modified: 12.12.15

This function takes arguments of iterator type.  The first parameter will point to the beginning of the range in the container that will be iterated.  The second parameter will be the end of the range in the iterator to be iterated.  The 3rd parameter will point to the location one node later to the end of the range of the iteration and return that iterator. 
*/
template<typename IIterator, typename OIterator>
OIterator prefix_sum(IIterator first, IIterator last, OIterator d_last)
                        {
                        typedef typename iterator_traits<IIterator>::value_type value_type;
                        if (first==last)
                                return d_last;
                        value_type vt = *first;
			*d_last = vt;
                        while(++first !=  last)
                        {                       
			vt = vt + *first;
                        *++d_last = vt;
                        }
                        return ++d_last;
                        }



#endif

