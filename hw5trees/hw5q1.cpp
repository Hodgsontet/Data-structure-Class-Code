#include "hw5q1.h"

template <class Process, class Item>
void postorder(Process f, btNode<Item>* nodePtr)
{
	if(nodePtr==NULL)
		return;

    postorder(f,nodePtr->getLeft());
	postorder(f,nodePtr->getRight());
	f(nodePtr->getData());

}

 template <class Process, class Item>
void preorder(Process f, btNode<Item>* nodePtr)
{
	if(nodePtr==NULL)
		return;

    f(nodePtr->getData());
    postorder(f,nodePtr->getLeft());
	postorder(f,nodePtr->getRight());
	

} 

 template <class Process, class Item>
void inorder(Process f, btNode<Item>* nodePtr)
{
	if(nodePtr==NULL)
		return;

    
    postorder(f,nodePtr->getLeft());
    f(nodePtr->getData());
	postorder(f,nodePtr->getRight());
	

} 

template <class Item, class SizeType>
void print(btNode<Item>* nodePtr, SizeType depth)
{
    std::cout << std::setw(4*depth) << ""; // Indentation
    if (nodePtr == NULL)
      { // Fallen off the tree
      std::cout << "[Empty]" << std::endl;
      }
else if (nodePtr->isLeaf( ))
     { // A leaf
      std::cout << nodePtr->getData( );
      std::cout << " [leaf]" <<std::endl;
     }
   else
   { // A nonleaf
    std::cout <<nodePtr->getData( ) << std::endl;
    print(nodePtr->getRight( ), depth+1);
    print(nodePtr->getLeft( ), depth+1);
   }
}

template<class Item> 
void clearTree(btNode<Item>*& rootPtr){
    if(rootPtr == NULL){ 
        return;
    }  
    btNode<Item>* leftChild = rootPtr->getLeft();
    btNode<Item>* rightChild = rootPtr->getRight();
    clearTree(leftChild);
    clearTree(rightChild);
    delete rootPtr;
    rootPtr = NULL;
}

template <class Item>
btNode<Item>* copyTree(const btNode<Item>* rootPtr)
{
	btNode<Item>* left;
	btNode<Item>* right;

	if (rootPtr == NULL) return NULL;

	else
	{
		left = copyTree( rootPtr->getLeft( ) );
        right = copyTree( rootPtr->getRight( ) );

        return new btNode<Item> (rootPtr->getData( ), left, right);
	}

}

template <class Item>
size_t treeSize(const btNode<Item>* nodePtr)
{


if (nodePtr == NULL)
return 0;

else  return  1 + treeSize(nodePtr->getLeft( )) + treeSize(nodePtr->getRight( ));

}

