// Implement a simple music playlist manager using circular linked list 
// where songs can be played in  loop, with options to add/delete songs dynamically.

#include <iostream>
using namespace std;

struct node{
	string name;
	node* next;
};

class Music{
public:
	node* head = nullptr;
	Music(){
		head=nullptr;
	}
	void insert(string n){
		node* newnode = new node{n,nullptr};
		if(head==nullptr){
			head=newnode;
			head->next=head;
		}
		else{
			node* temp = head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=head;
		}
	}

		void deletion(string n){
			node* temp = head;
			node* prev = nullptr;
			if(head->name==n){
				node* todelete = head;
				
				while(temp->next!=head){
					temp=temp->next;
				}
				head=head->next;
				temp->next=head;
				delete todelete;
			}
			else{
				while(temp->name!=n){
					prev=temp;
					temp=temp->next;
				}
				prev->next=temp->next;
				delete temp;
			}
		}

		void display(){
			node* temp = head;
			while(temp->next!=head){
				cout<<temp->name<<endl;
				temp=temp->next;
			} 
			cout<<temp->name<<endl;
		}
	
};



int main(){

Music m;

m.insert("new");
m.insert("old");
m.insert("down");



m.deletion("down");

m.display();

	return 0;
}