#include "hw5q3.h"
/*
This object creates a 1d world in our memory where our tree lies we already 
an object for our nodes so this object is our tree as a whole 
      
  --> 0    ---|
      |       |
     / \  3    | this is what the binaryTree does
    0   0     | -->represents the curr and root ptr;
    /\  /\ ---|  3 represents the count 

but this in array has to always be in a linear form and so instead of pointer we have
a contigious block of memory [0|1 | 2| 3|4 |5 |6 |7]
                             [                     ]

a simple way to keep track of empty elements is to put NULL there.


*/
template<class Item>
binaryTreeDA<Item>::binaryTreeDA( )
{
// our first constructor has 4 member functions 
	capacity = DEF_CAP ;
	curr = 0;
	count = 0;
	tree = new Item [capacity];
	for(size_t i = 0; i<capacity; i++)
	{
		tree[i] = NULL;
	}

}

template<class Item>
binaryTreeDA<Item>::binaryTreeDA(const binaryTreeDA& source)
{
	capacity = DEF_CAP ;
	curr = source.curr;
	count = source.count;
	for(size_t i = 0; i<source.count; i++)
	{
		tree[i] = source.tree[i];
	}
	
}

template<class Item>
binaryTreeDA<Item>::~binaryTreeDA( )
{
	curr = 0;
	count = 0;
	delete [] tree;
}
/*****
we are done with all the constructors and destructors and we will now create an array abstraction

******/
template<class Item>
void binaryTreeDA<Item>::createFirstNode(const Item& entry)
{
	if(count == 0)
		{
			curr = 0;
			tree[curr] = entry;
			count++;
		}
}

template<class Item>
void binaryTreeDA<Item>::addLeft(const Item& entry)
{
   
   if(count != 0 && (2*curr+1) <= 30)
		{
			tree[2*curr+1] = entry;
			count++;
		}	
}

template<class Item>
void binaryTreeDA<Item>::addRight(const Item& entry)
{
   
   if(count != 0 && (2*curr+2) <= 30)
		{
			tree[2*curr+2] = entry;
			count++;
		}	
}


/**now we turn to shifting functions**/
template<class Item>
 void binaryTreeDA<Item>::shiftToRoot( )
 {
 	if(count != 0)
		{
			curr = 0;
		}	
 }
     template<class Item>
    void binaryTreeDA<Item>::shiftUp( )
    {
       if(count != 0 && int((curr-1)/2) <30)
		{
			curr = int((curr-1)/2);
		}
    }
    template<class Item>
    void binaryTreeDA<Item>::shiftLeft( )
    {
    	if(count != 0 && int(2*curr+1)<30)
		{
			curr = int(2*curr+1);
		}
    }
    template<class Item>
    void binaryTreeDA<Item>::shiftRight( )
    {
    		if(count != 0 && int(2*curr+2) <30)
		{
			curr = int(2*curr+2);
		}
    }
    template<class Item>
    void binaryTreeDA<Item>::shiftInd(const size_t& ind)
    {
    		if(count != 0 && ind <30)
		{
			curr = ind;
		}
    }
    template<class Item>
    void binaryTreeDA<Item>::change(const Item& newEntry)
    {
    	if(count != 0 )
		{
			tree[curr] = newEntry;
		}
    }
    

    /****
now time for our remove functions since we cannot remove actual values in c++ from an array 
we will reduce the count;
   ******/
    template<class Item>
 void binaryTreeDA<Item>::removeLeft( )
 {
 	if(count != 0 && int(2*curr+1)<30)
		{
			count--;
		}
 }
 template<class Item>
    void binaryTreeDA<Item>::removeRight( )
    {
    	if(count != 0 && int(2*curr+2)<30)
		{
			count--;
		}
    }
/*****
we now create functions to check if our array has chlildren to the left and right
******/
 template<class Item>
bool binaryTreeDA<Item>::hasLeft( ) const
{
	if(tree[curr]!=NULL && count >0 && 2*curr+1<capacity)
	{
	   return tree[2*curr+1]!= NULL;
    }
}

 template<class Item>
bool binaryTreeDA<Item>::hasRight( ) const
{
	if(2*curr+2<capacity)
   {  
	    if(tree[curr]!=NULL && count >0)
	    {
	       return tree[2*curr+2]!= NULL;
        }
    }   
}

 template<class Item>
bool binaryTreeDA<Item>::hasParent( ) const
{
	if(tree[curr]!=NULL && count >0 && int((curr-1)/2) <capacity)
	{
	   return tree[int((curr-1)/2)]!= NULL;
    }
}

template<class Item>
size_t binaryTreeDA<Item>::size( ) const
{
	return count;
}
     
     template<class Item>
    Item binaryTreeDA<Item>::retrieve( ) const
    {
       return tree[curr];
    }