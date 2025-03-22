#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	
	while(b!=0){
		int temp=b;
		b=a%b;
		a=temp;
		
	}
	return a;
}

int LCM(int a,int b){
	return (a/gcd(a,b))*b;
}
int main(){
	
	//taking the input of the direction that we move
	string movement;
	cout<<"enter the paath of direction that you move :";
	cin>>movement;
	
	
	//part1
	
	
	//taking the input of node and its left,right child 
	string node;
	string left;
	string right;
	
	//hashmap for store the node and its left,right child
	unordered_map<string,pair<string,string>> mp;
	cout<<"enter the graph and after give the graph enter ctrl+z for run the code";
	while(true){
		
		cin>>node;
		if(node=="end") break;
		cin>>left>>right;
		mp[node]={left,right};
		
	}
	
	//finding the steps for going from AAA to ZZZ
	string currnode="AAA";
	int count=0;
	int n=movement.size();
//	if()
	//using a hashmap for checking infinite loop is present or not by visiting the repition of the node
	unordered_set<string> visited;
	while(currnode!="ZZZ"){ //if count>size -> it means that ZZZ is not present in the entire graph
	if (visited.count(currnode)) {
            cout << "Cycle detected! The goal ZZZ is not reachable.\n :"<<currnode;
            return 0;
        }
        visited.insert(currnode);		
		char nextdir=movement[count%n];//if(count==n) then we need to start from the start position of the movement string

        currnode = (nextdir == 'L') ? mp[currnode].first : mp[currnode].second;
        count++;
	}
	 if (currnode == "ZZZ") {
        cout << "Steps to reach the goal node ZZZ: " << count << endl;
    } else {
        cout << "The goal ZZZ is not reachable from AAA with the given movement pattern.\n";
    }
	
	
	//part 2
	
	vector<string> startA;
	for(auto ele: mp){
		if(ele.first[2]=='A'){
			startA.push_back(ele.first);
		}
	}
	
	vector<int> cycle_length;
	for(int i=0;i<startA.size();i++){
		string curr=startA[i];
		int count=0;
		while(curr[2]!='Z'){
			char ch=movement[count%n];
			if(ch=='L'){
				curr=mp[curr].first;
			}
			else {
				curr=mp[curr].second;
			}
			count++;
		}
		cycle_length.push_back(count);
	}
	
	//finding the LCM of the cycle of the each node such that we can find at which cycle length all node at node end with 'Z'
	
	int result=cycle_length[0];
	for(int i=1;1<cycle_length.size();i++){
		result=LCM(result,cycle_length[i]);
	}
	
	cout<<"steps to reach at Z simultaneuosly is : "<<result;
	
	
	
}