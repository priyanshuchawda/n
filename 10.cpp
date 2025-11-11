// A Graph-Based Modeling of College Campus using Adjacency List 
// and Adjacency Matrix Representations.

#include <iostream>
#include <vector>
using namespace std;

class Graph{
public:
	vector<vector<int>> adjlist;
	vector<vector<int>> adjmatrix;
	vector<string> vertices;
	int size;

	Graph(int n){
		size=n;
		adjlist.resize(n);
		adjmatrix.assign(n,vector<int>(n,0));
		vertices.resize(n);
	}

	void set(int n, string s){
		vertices[n]=s;
	}

	void insert(int n , int m){
		adjlist[n].push_back(m);
		adjlist[m].push_back(n);

		adjmatrix[m][n]=1;
		adjmatrix[n][m]=1;
	}

	void displaylist(){
		for(int i = 0 ; i <size ; ++i){
			cout<<vertices[i]<<" -> ";
			for(int j = 0 ; j<adjlist[i].size(); ++j){
				cout<<vertices[adjlist[i][j]]<<" ";
			}
			cout<<endl;
		}
	}

	void displaymatrix(){
		cout<<"  ";
		for(int i = 0 ; i <size ; i++){
			cout<<vertices[i][0]<<" ";
		}
		cout<<endl;

		for(int i = 0 ; i < size ; ++i){
			cout<<vertices[i][0]<<" ";
			for(int j = 0 ; j <size ; j++){
				cout<<adjmatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}

};


int main(){

	Graph g(5);
	g.set(0,"canteen");
	g.set(1,"play");
	g.set(2,"priyanshu");
	g.set(3,"ok");
	g.set(4,"school");

	g.insert(1,2);
	g.insert(1,3);
	g.insert(2,4);

	g.displaylist();

	cout<<endl;

	g.displaymatrix();
	return 0;
}