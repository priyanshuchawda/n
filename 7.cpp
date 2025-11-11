// Implement a stack using array and use it to convert 
//an infix expression to postfix and evaluate the result.

#include <iostream>
using namespace std;

class Stack{
public:
	char arr[30];
	int top = -1;

	void push(char c){
		top++;
		arr[top]=c;
	}
	char pop(){
		char temp = arr[top];
		top--;
		return temp;
	}
	char peek(){
		return arr[top];
	}

	bool isempty(){
		if(top==-1) return true;
		else return false;
	}
};

class convert{
public:

	Stack st;
	int prec(char c){
		if(c=='^') return 4;
		else if (c=='/'||c=='*') return 3;
		else if (c=='+' || c=='-') return 2;
		else return 0;
	}

	string conversion(string s){
		string ans;
			for(int i = 0 ; i < s.size(); i++){
			char c = s[i];

			if(isalnum(c)){
				ans+=c;
			
			}

			else if(c=='('){
				st.push(c);
			}
			else if(c==')'){
				while(!st.isempty() && st.peek()!='('){
					ans+=st.pop();
					
				}
				st.pop();
			}

			else{
				while(!st.isempty() && prec(st.peek())>prec(c)){
					ans+=st.pop();
				}
				st.push(c);
			}
		}

		while(!st.isempty()){
			ans+=st.pop();
		}
		return ans;
	}

};

int main(){
	convert c;

string s = "(A+B)*C-D/E";
cout<<c.conversion(s)<<endl;
	return 0;
}
