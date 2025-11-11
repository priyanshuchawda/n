//9.A Dictionary stores keywords & its meanings. 
//Provide facility for adding new keywords, deleting keywords, updating values of any entry.
// Provide facility to display whole data sorted in ascending/ Descending order.
// Also find how many maximum comparisons may require for finding any keyword. 
//Use Binary Search Tree for implementation.

#include <iostream>
using namespace std;

struct node{
	string key;
	string meaning;
	node* right;
	node* left;
};

class Bst{
public:
	node* root;
	Bst(){
		root=nullptr;
	}
	node* insert(node* root , string k , string m){
		node* newnode=new node{k,m,nullptr,nullptr};
		if(root==nullptr) {
			root=newnode;
			return root;
		}
		else if(root->key < k){
			root->right=insert(root->right,k,m);
		}
		else{
			root->left=insert(root->left,k,m);
		}
	return root;
	}

	void dfs(node* root){
		if(root==nullptr) return;
		dfs(root->left);
		cout<<root->key<<endl;
		dfs(root->right);
	}

	int height(node* root){
		if(root==nullptr) return 0;
		return 1+max(height(root->left), height(root->right));
	}

	node* mostleft(node* root){
		if(root==nullptr) return nullptr;
		while(root->left){
			root=root->left;
		}
		return root;
	}

	node* deleteNode(node* root , string k){
		if(root==nullptr) return nullptr;
		if(root->key<k){
			root->right=deleteNode(root->right,k);
			return root;
		}
		else if(root->key>k){
			root->left=deleteNode(root->left,k);
			return root;
		}
		else{
			if(!root->left && !root->right){
				delete root;
				return nullptr;
			}
			else if(!root->left){
				node* temp = root->right;
				delete root;
				return temp;
			}
			else if(!root->right){
				node* temp = root->left;
				delete root;
				return temp;
			}
			else{
				node* temp = mostleft(root->right);
				root->key=temp->key;
				root->meaning=temp->meaning;
				root->right=deleteNode(root->right,temp->key);
			}
		}
		return root;
	}
};
int main(){
Bst b1;
node* root=nullptr;
root = b1.insert(root,"ok","please");
root= b1.insert(root,"no", "okk");
root= b1.insert(root,"plo", "oskk");
root= b1.insert(root,"nwsho", "ofkk");

root=b1.deleteNode(root,"plo");
b1.dfs(root);

cout<<"  "<<b1.height(root);

return 0;}