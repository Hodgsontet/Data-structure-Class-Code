#include "hw5q2.h"
/*
This object creates a 2d world in our memory where our tree lies we already 
an object for our nodes so this object is our tree as a whole 
      
  --> 0    ---|
      |       |
     / \  3    | this is what the binaryTree does
    0   0     | -->represents the curr and root ptr;
    /\  /\ ---|  3 represents the count 
*/
/*
the create node function creates the first living thing in
our memory the first Node and sets it to entry
*/
template<class Item>
  void binaryTree<Item>::createFirstNode(const Item& entry) 
  {
  	
  	root = new btNode<Item>;
  	root->setData(entry);
  	curr = root;
  	count++;

  }
  /*
in case we ever want to change the data type of any node this change function d
does it for us. To make this work we simply make use of the already made setData()
function in our Node class and u must always check if what u want exists

  */
template<class Item>
 void  binaryTree<Item>::change(const Item& newEntry)
 {
    if(curr !=NULL)
    {
    	curr->setData(newEntry);
    }
 }

 /*
 we may want to check if the object has left or right functions for various
 reasons so we create has functions.
 */
 template<class Item>
bool binaryTree<Item>::hasParent( ) const
{
	if(curr!=NULL)
	{
	   return curr->getParent()!= NULL;
    }
}
/********************/
template<class Item>
bool binaryTree<Item>::hasLeft( ) const
{
	if(curr!=NULL)
	{
	   return curr->getLeft()!= NULL;
    }
}
/********************/
template<class Item>
bool binaryTree<Item>::hasRight( ) const
{
	if(curr!=NULL)
	{
	   return curr->getRight()!= NULL;
    }
}
/******
We now want to add other Nodes to our functions to do
this we create add--functions which add more nodes to our first node
1.we first check if our first node exists
2.nothing is in our left or right 
4.insert
********/
template<class Item>
 void binaryTree<Item>::addRight(const Item& entry)
{
   if(this->curr!=NULL && hasRight()==0)
	{
		btNode<Item>* temp;
	   temp = new btNode<Item>;
	   temp->setData(entry);
	   temp->setParent(curr);
	   curr->setRight(temp);
	   count++;
    }
}

template<class Item>
 void binaryTree<Item>::addLeft(const Item& entry)
{
   if(this->curr!=NULL && hasLeft()==0)
	{
		btNode<Item>* temp;
	   temp = new btNode<Item>;
	   temp->setData(entry);
	   temp->setParent(curr);
	   curr->setLeft(temp);
	   count++;
    }
}
/************
Now we need to create a function to count nos of nodes present
*****************/
template<class Item>
 size_t binaryTree<Item>:: size( ) const
{

	return count;
}

/***

now we create fuunctions to remove nodes only if these nodes are leafs



***/

template<class Item>
 void binaryTree<Item>::removeLeft( )
      {
               if(size() > 0 && curr->getLeft()->isLeaf() ==1 && hasLeft() ==1 )
               {
               	delete curr->getLeft();
               	curr->setLeft(NULL);
               	count--;
               }
       }


       template<class Item>
 void binaryTree<Item>::removeRight( )
      {
               if(size() > 0 && curr->getRight()->isLeaf() ==1 && hasRight() ==1 )
               {
               	delete curr->getRight();
               	curr->setRight(NULL);
               	count--;
               }
       }

/***

  -->[R]    ---[NR]   we want to replace [NR] with [R] as head root
      |       
     / \  3    in order to do that we connect the left and right children to NR and delete NR
    0   0     
    /\  /\ ---


****/
       template<class Item>
 void binaryTree<Item>::setRoot( btNode<Item>* newRoot )
 {
 	if(size()> 0)
 	{
 	btNode<Item>* temp = root; //temp stands for the old root
 	btNode<Item>* lfkid = root;
 	btNode<Item>* rtkid = root;

 	lfkid = root->getLeft();
 	rtkid = root->getRight();

     newRoot->setRight(rtkid);
     newRoot->setLeft(lfkid);
     lfkid->setParent(newRoot);
     rtkid->setParent(newRoot);
     root = newRoot;
     delete temp;



    }

 }

template<class Item>
binaryTree<Item>::binaryTree()
{
	btNode<Item>* root = NULL;
	btNode<Item>* curr = NULL;
	count = 0;

}

template<class Item>
binaryTree<Item>::binaryTree(const binaryTree& source)
{

	btNode<Item>* root = source->root;
	btNode<Item>* curr = source->curr;
	count = source->count;

}

template<class Item>
binaryTree<Item>::~binaryTree( )
{
	clearTree(root);
	count = 0;

}



  template<class Item>
    void binaryTree<Item>::shiftToRoot( )
    {
    	if(size >0)
    	{
    		root = curr;
    	}
    }

    template<class Item>
    void binaryTree<Item>::shiftUp( )
    {
    	if(this->hasParent()!= NULL)
    	{
            curr = curr->setParents();
    	}
    }


    template<class Item>
    void binaryTree<Item>::shiftLeft( )
    {
    	if(this->hasLeft() != NULL)
    	{
            curr = curr->setLeft();
    	}
    }

    template<class Item>
    void binaryTree<Item>::shiftRight( )
    {
    	if(this->hasRight()!= NULL)
    	{
            curr = curr->setRight();
    	}
    }

size_t size( ) const;
    Item retrieve( ) const;

    