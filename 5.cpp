// Implement a menu-driven program to perform insertion, deletion, and search operations
// on a doubly linked list.
#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
    node* prev;
};

class ll{
public:
    node* head;
    ll(){
        head=nullptr;
    }
    void insert(int n){
        node* newnode= new node{n,nullptr,nullptr};
        if(head==nullptr) head=newnode;
        else{
            node* temp = head;
            node* p = nullptr;
            while(temp->next!=nullptr){
                p=temp;
                temp=temp->next;
            }
            p=temp;
            temp->next=newnode;
            temp=temp->next;
            temp->prev=p;
            temp->next=nullptr;
        }
    }

    void deletion(int n){

        if(head==nullptr) {
            cout<<"none"<<endl;
        }
        else if(head->val==n && head->next==nullptr) delete head;
        else if(head->val == n){
           
            node* temp = head;
            head=head->next;
            head->prev=nullptr;
            delete temp;

        }
            else{
            node* temp = head;
            node *p = nullptr;
            while(temp->val!=n){
                p=temp;
                temp=temp->next;
            }
            if(temp->next==nullptr){
                cout<<"check1"<<endl; 
                 p->next=nullptr;
                delete temp;
                cout<<"check1"<<endl; 
            }
            else{
                p->next=temp->next;
                node* tt = temp;
                temp=temp->next;
                temp->prev=p;
                delete tt;
                cout<<"check2"<<endl; 
            }
        }
        }

    

    void search(int n){
        node* temp = head;
        int c = 0;
        while(temp->next!=nullptr){
            if(temp->val==n) {
                cout<<"val found"<<endl;
                c=1;
            }
            temp=temp->next;
        }
        if(temp->val==n) {
            c=1;
            cout<<"val found"<<endl;
        }
        if(c==0) cout<<"not found"<<endl;
    }

    void print(){
        node* temp = head;
        while(temp->next!=nullptr){
            cout<<temp->val<<endl;
            temp=temp->next;
        }
        cout<<temp->val<<endl;
           
    }
};

int main(){
    ll menu;
    node* head = nullptr;

    int choice=0;
    while(true){
        cout << endl << "--- Student Management Menu ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int l;
            cin>>l;
            menu.insert(l);
            cout<<"inserted"<<endl;
    }
        else if (choice ==2 ){
            int l;
            cin>>l;
            menu.deletion(l);
        }
        else if(choice == 3){
            int l;
            cin>>l;
            menu.search(l);
            cout<<"searched"<<endl;
        }
        else if(choice == 4){
            menu.print();
        }
        else{
            break;
        }
    }
    return 0;
}


