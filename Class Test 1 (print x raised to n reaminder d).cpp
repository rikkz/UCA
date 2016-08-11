#include<iostream>
using namespace std;
struct node
{
	int data;
	node *link;
};
node* reverse(node *start , int k )
{
	int count = 0;
	node *next = NULL , *prev = NULL , *current = start ;
	while( current != NULL & count < k  )
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next ;
		count++;
	}
	if( next != NULL )
		start->link = reverse(next,k);
	return prev;
}
node* push_data( node *head , int value )
{
	node *temp = new node();
	temp->data = value;
	temp->link = NULL;
	if( head == NULL)
	{
		head = temp;
		return head;
	}
	else
	{
		node *temp1 = head;
		while( temp1->link != NULL  )
			temp1 = temp1->link;
		temp1->link = temp; 
	}
	return head;
}
void print( node *head )
{
	while( head != NULL)
	{
		cout<<head->data<<" ";
		head = head->link;	
	}		
}
int main()
{
	node *head = NULL;
	int n;
	cin>>n;
	while( n-- )
	{
		int temp;
		cin>>temp;
		head = push_data( head , temp );
	}
	int k;
	cin>>k;
	head = reverse( head , k );
	print( head );
}	
