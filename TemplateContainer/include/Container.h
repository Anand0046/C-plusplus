#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using namespace std;

template <class AR>
class Container
{
	private:
		struct Node{
		    AR data;
		    Node* next_Pointer;
		};
		Node* head_Pointer;
	public:
		Container() {head_Pointer = NULL;}//constructor
		~Container();//destructor
		void set_Element(AR);//function to add element to back of list
		void delete_Element(AR);//function to delete specific element
		void display();//display all the data in the list
		AR get_Element(int);//funtion to get the element at particular position
		int get_Size();
};

template<class AR>
Container<AR> :: ~Container(){
   Node* temp_Pointer = head_Pointer;
   Node* prev_pointer;
   while(temp_Pointer){
       prev_pointer = temp_Pointer;
       temp_Pointer = temp_Pointer->next_Pointer;
       delete prev_pointer;
   }
}

template <class AR>
void Container<AR> :: set_Element(AR element){
    Node* newNode = new Node;//create new Node
    newNode->data = element;//copy given data to new node
    newNode->next_Pointer = NULL;
    if(head_Pointer == NULL)
		head_Pointer = newNode;
	else{
		Node* temp_Pointer = head_Pointer;//make a pointer to point head
		while(temp_Pointer->next_Pointer){//to find last node
			temp_Pointer = temp_Pointer->next_Pointer;//move to next node
		}
		temp_Pointer->next_Pointer = newNode;
	}
}

template <class AR>
void Container <AR> :: delete_Element(AR element){
    Node* temp_Pointer  = head_Pointer;//make pointer point to head
    Node* prev_Pointer;
    while(temp_Pointer && temp_Pointer->data != element){
		prev_Pointer = temp_Pointer;//make prev to point temp is pointing
		temp_Pointer = temp_Pointer->next_Pointer;//move to next node
    }
    if(temp_Pointer && temp_Pointer->data == element){
		if(temp_Pointer == head_Pointer){
			head_Pointer = head_Pointer->next_Pointer;//make head point to next node
			delete temp_Pointer;//delete node
		}
		else{
			prev_Pointer->next_Pointer = temp_Pointer->next_Pointer;//make prev pointer point to next node of temp pointer
			delete temp_Pointer;//delete the node
		}
    }
}

template <class AR>
void Container<AR> :: display(){
    Node* temp_Pointer = head_Pointer;//make temp pointer point to head
    while(temp_Pointer != NULL){
		cout<<temp_Pointer->data<<"   ";
		temp_Pointer = temp_Pointer->next_Pointer;
    }
    cout<<endl;
}

template<class AR>
AR Container<AR> :: get_Element(int position){
    Node* temp_Pointer = head_Pointer;
    int count = 0;
    while(temp_Pointer && count < position){
		temp_Pointer = temp_Pointer->next_Pointer;
		count++;
    }
    if(temp_Pointer && count == position)
		return temp_Pointer->data;
}

template<class AR>
int Container<AR> :: get_Size(){
	if(head_Pointer != nullptr){
		Node* temp_Pointer = head_Pointer;
		int size = 0;
		while(temp_Pointer){
			temp_Pointer = temp_Pointer->next_Pointer;
			++size;
		}
		return size;
	}
	else
		return 0;
}



#endif // CONTAINER_H
