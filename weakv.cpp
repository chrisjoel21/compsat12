#include<iostream>
using namespace std;

//max no of nodes
const int n_max=20;

int main(){
//2d array to store the graph
int graph[n_max][n_max];
//bool array to mark the weak nodes
bool nodes[n_max];
//int n to take the no of nodes
int n;
//take input to n
cin>>n;
//receive input till n is not -1
while(n!=-1){
	//take input to the graph
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
			}
		}
    //to find a weak node
    //iterate through each node
    //take every possible combination of its neighbours and check if they are neighbours
    //if any one such combination of nodes are neighbours then it is not weak mark
    //the node as not a weak node
    //else mark the node as weak node
    //the time complexity of the algorithm is O(n^3)
     
	for(int i=0;i<n;i++){
		//initialize ok as false
		bool ok=false;
		//iterate through each neighbour of the i node
		for(int j=0;j<n && ok==false;j++){
			if(graph[i][j]==1 && j!=i){
				for(int k=0;k<n;k++){
					if(graph[i][k]==1 && k!=i && k!=j){
					//take every possible combination of neighbours of node i
					//check if they are neighbours
						if(graph[j][k]==1){
							ok=true;
							//if yes break
							break;		
							}
						}
					}
				}
			}
		//mark the node	
		nodes[i]=ok;	
		}
	//print the weak node	
	for(int i=0;i<n;i++){
		if(nodes[i]==false) cout<<i<<" ";
		}
	cout<<"\n";
	//take input for next n
	cin>>n;	
	}		
}