#include"hw5q3.h"
#include<iostream>







int main()
{

binaryTreeDA<int> ruler;

ruler.createFirstNode(7);
ruler.addRight(4);
ruler.addLeft(8);
cout<<ruler.retrieve()<<"curr val in curr"<<"\n";
ruler.shiftLeft();
cout<<ruler.retrieve()<<"curr val in curr"<<"\n";

ruler.addRight(45);

int i;
cout<<ruler.hasParent()<<"\n";
cout<<ruler.size()<<"\n";


/*for(i = 0; i<30; i++)
{
	if(ruler.tree[i]!=NULL)
	{
		cout<<ruler.tree[i]<<endl;
	}
	else
		cout<<"[]"<<'\n';
	cout<<ruler.tree[i]<<endl;

}*?


  


	/*btNode<int>* tree;
	tree = new btNode<int>;
	tree->setData(1);
	tree->setRight(createnode(3));
	tree->setLeft(createnode(2));
	tree->getLeft()->setLeft(createnode(4));
	tree->getLeft()->setRight(createnode(5));
	
	tree->getRight()->setLeft(createnode(6));
	tree->getRight()->setRight(createnode(7));

   cout<<"size is"<<treeSize<int>(tree)<<endl;
	//preorder(f,tree);
	clearTree<int>(tree);
	 cout<<"size is"<<treeSize<int>(tree)<<endl;
	//preorder(f,tree);
	//clearTree(&tree);
	//preorder(f,tree);


	
	//for(btNode<int>* p = tree; p!=NULL; p = p->getLeft())
	//{
	//	cout<<p->getData()<<endl;
	//}
    /*btNode<int> * p = tree;
	while(1)
	{
		while(p!=NULL)
		{
			s.push(p);
			cout<<p->getData()<<endl;
			p = p->getLeft();
		}
      if(s.empty()) break;
		p = s.top();
		s.pop();
		p = p->getRight();

	}
    

    */

	return 0;
}