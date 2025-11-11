// Intelligent Route Tracing System:
//  Implementation of Depth First Search (DFS) Algorithm on a 
// Graph Represented Using Adjacency Matrix 
//  for Exploring Connected Locations in a Smart Campus Environment.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph{
public:
	vector<vector<int>> adjmatrix;
	vector<string> vertices;
	int size;

	Graph(int n){
		size=n;
		adjmatrix.assign(n,vector<int>(n,0));
		vertices.resize(n);
	}

	void set(int n, string s){
		vertices[n]=s;
	}

	void insert(int n , int m){

		adjmatrix[m][n]=1;
		adjmatrix[n][m]=1;
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

	void dfs(int start){
		vector<int> visited(size,0);
		stack <int> st;

		st.push(start);
		while(!st.empty()){
			int temp = st.top();
			st.pop();
			if(visited[temp]==0){
				visited[temp]=1;
				cout<<vertices[temp]<<" ";
			}
			for(int i = 0 ; i<size ; i++){
				if(adjmatrix[temp][i]==1 && !visited[i]){
					st.push(i);
				}
			}
		}
		cout<<endl;

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
	g.displaymatrix();

	cout<<endl;

	g.dfs(1);


	return 0;
}