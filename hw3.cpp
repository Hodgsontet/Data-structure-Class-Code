#include "hw3.h"

void insertHead(Node*& head, const Node::nodeDatatype& entry)
{
	Node * temp;
	temp = new Node();
	temp->setData(entry);
	temp->setLink(head);
	head = temp;
}
void insertHead(Node*& head, Node*& entry)
{
	entry->setLink(head);
	head = entry;
}

void insertTail(Node*& head, const Node::nodeDatatype& entry)
{
	Node* curr;
	Node * temp;
	temp = new Node;
	temp->setData(entry);
	curr = head;
	while(curr->getLink()!=NULL)
	{
		curr = curr->getLink();

	}
	curr->setLink(temp);
	temp->setLink(NULL);

}

void insertInd (Node*& head, const Node::nodeDatatype& entry, size_t pos)
{
	assert(length(head)>= pos );
	Node* curr;
	curr = head;
	int i = 0;
	
	{

	    while(i< pos-1)
	    {
	    	curr = curr->getLink();
	    	i++;
	    }
	}

curr->setData(entry);

}


size_t length(Node* head)
{
	int count = 1; 
	Node * curr;
	for(curr = head; curr!= NULL; curr = curr->getLink() )
	{
        count++;
	}

return count;

}

bool isCycle(Node* head)
{
	Node* fast = head;
	Node* slow = head->getLink();
	if(head == NULL || head->getLink() == NULL)
	{
		return false;
	}
    while(fast!=NULL && slow!=NULL)
    {
      if(fast ==slow)
      {
      	return true;
      }
       else
       {
         fast = fast->getLink();
    	 slow = slow->getLink() ;
    	}

    }
    return false;

}
bool isEmpty(Node* head)
{
	return(head == NULL);
}
bool isValid(Node* head, size_t pos)
{
	return (length(head)>= pos); 
}

void insert  (Node*  prev, const Node::nodeDatatype& entry)
{
	prev->setData(entry);
}

Node* listLocate (Node* head, size_t position)
{
	if (length(head) == 0 || position > length(head))
	{
		return NULL;
	}


	{
		Node* curr = head;
		
		for(int i = 1; (i<position)&& (curr!=NULL); i++ )
		{
			curr = curr->getLink();
		}
		return curr;
	}
}

const Node* listLocate(const Node* head, size_t pos)
{


   if(head->getLink() != NULL)
	{   const Node* curr = head;
		
		for(int i = 1; (i<pos)&& (curr!=NULL); i++ )
		{
			curr = curr->getLink();
		}
		return curr;
    }
    return NULL;
}

Node* listSearch      (Node* head, const Node::nodeDatatype& target)
{
	if (length(head) == 0 )
	{
		return NULL;
	}
	Node* curr;
	for(curr = head; curr!=NULL; curr = curr->getLink())
	{
		if (target == curr->getData( ))
              return curr;

	}
	return NULL;
}
void removeHead  (Node*& head)
{
	Node* curr = head;
    head = head->getLink();
    delete curr;

}
void remove      (Node*  prev)
{
	Node* curr = prev->getLink();
	prev->setLink(curr->getLink() );
	delete curr;
}

