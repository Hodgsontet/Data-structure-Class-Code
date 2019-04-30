#include "hw5q4.h"

template <class Item>
BST<Item>::BST()
{
	count = 0;
}

template <class Item>
void BST<Item>:: insert(const Item& entry)
{
	tree.shiftToRoot();
	/*****
      this is complex so be carefull


	*****/
	//we check if the tree is empty 
	if(count == 0)   // case 1 when the tree is empty put a new node withe data entry
	{
		tree.createFirstNode(entry);
	}

	bool fin = 0;  // this tells the compiler when to stop;

	while (fin != 1)
	{
		if(entry<=tree.retrieve()) // if the entryis less than the first node
		{
			if(!tree.hasLeft())
			{
				tree.addLeft(entry);   // check if the first node has a left if not slap it there
				fin =1;
			}

			else if(tree.hasLeft()) //else move to the next one
			{
               tree.shiftLeft();
			}
		}

		if(entry >tree.retrieve())
		{
			if(!tree.hasRight())
			{
				tree.addRight(entry); // do what we did on top but to the right;
				fin =1;
			}

			else if(tree.hasRight())
			{
               tree.shiftRight();
			}
		}


	}

	count++;
	

}

template <class Item>
btNode<Item>* BST<Item>::search(const Item& target)
{
	tree.shiftRoot();
	if(count>0)
	{
		while(tree.hasRight() || tree.hasLeft() )
		{
            if(tree.retrieve() ==target)
            {
            	return tree.getNode();
            }

            if(target<=tree.retrieve())
            {
            	tree.shiftLeft();

            }
            else if(target >tree.retrieve())
            {
               tree.shiftRight();
            }
		}
	}
}

template <class Item>
btNode<Item>* BST<Item>::minimum()
{
 if(count>0)
   {
 	tree.shiftRoot();
 	while(tree.getLeft() !=NULL)
 	{
 		tree.shiftLeft();


 	}
 	return tree.getNode();

   }

}

template <class Item>
btNode<Item>* BST<Item>::maximum()
{
	if(count>0)
   {
 	tree.shiftRoot();
 	while(tree.getRight() !=NULL)
 	{
 		tree.shiftRight();


 	}
 	return tree.getNode();

   }
}


template <class Item>
void BST<Item>::transplant(btNode<Item>*& u, btNode<Item>*& v)
{
	if(u.getParent()==NULL)
	{
		u.setRoot(v);
	}

	if(u == u.getParent().getLeft())
	{
		u.shiftUp();
		u.setLeft(v);
	}
	else
	{
		{
		u.shiftUp();
		u.setRight(v);
	}
	}
}
