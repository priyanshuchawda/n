// // 8.Implement a ticket booking system where customers join a queue. 
// The queue is served in the order they arrive (FIFO). 
//  a) Enqeue: New customer books a ticket. 
//   b) Dequeue: Customer is served.
//    c) Display Queue: Show customers waiting.

#include<iostream>
using namespace std;

class queue{
	int front;
	int rear;
	string arr[30];
public:
	queue(){
		 front = -1;
		 rear = -1;
	}

	void enque(string n){
		if (front == rear && front == -1){
			front=0;
			rear=0;
			arr[rear]=n;
		}
		else{
			rear++;
			arr[rear]=n;
		}
	}

	void dequeue(){
		front++;
	}

	void display(){
		for(int i = front ; i <=rear ; i++){
			cout<<arr[i]<<endl;
		}	
	}
};


int main(){
queue q;
string s;

getline(cin,s);

q.enque(s);
q.enque("t");
q.enque("wor");

q.display();

q.dequeue();
q.display();

return 0;
}