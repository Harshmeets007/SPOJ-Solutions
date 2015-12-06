# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
using namespace std;

#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

typedef  long long LL;
char * arr;

class Node{
	
	public:
		char val;
		Node (char v){
			val=v;
		}
		
		char getVal(){
			return val;
		}
		
};
Node*  merge(Node * lChild, Node * rChild){
	char val;
	if(lChild==NULL && rChild==NULL) val= '\0';
	else if (lChild==NULL){
		val=rChild->val;
	}
	else if (rChild==NULL){
		val=lChild->val;
	}
	else{
		if(lChild->val == '(' && rChild->val==')')val ='\0';
		else val = lChild->val + rChild->val; 
	}
	Node* tmp = new Node(val);
	return tmp; 
}
// query returns max contiguous sum b/w given two indices 

class SegTree{
	int n;
	Node ** tree;
	// creating an array of Node pointers
	
	Node* query(int node, int from ,int to ){
		/*if(i<=from && j >= to) return tree[node];
		else if (i>to || j<from) return NULL;
		else{
			int leftIdx = 2 * node;
			int rightIdx = leftIdx+1;
			int mid = (from+to)/2;
			if(j<=mid){
				return query(node*2, from , mid , i, j);
			}
			if(i>mid){
				return query(node*2+1, mid+1, to , i ,j);
			}
			 
			Node * a = query(leftIdx, from, mid, i, j);    
			Node* b = query(rightIdx, mid+1, to, i, j);
			Node * temp = merge(a, b);
			return temp;
		}
		*/
	}
	void update (int node, int l ,int r , int i  ){
		if (l == i && l == r) {
			if(arr[i]=='(') arr[i]=')';
			else if(arr[i]==')')arr[i]='(';
			tree[node]=new Node(arr[i]); 
		}
		else if (i < l || i > r) return;        
		else 
		{
			int leftChild = 2*node, rightChild = leftChild+1, mid = (l+r)/2;
			update(leftChild, l, mid, i);    
			update(rightChild, mid+1, r, i); 
			tree[node]=merge(tree[leftChild], tree[rightChild]);
		} 
	} 
	void build(int node , int from , int to ){
		if(from>to) return;
		else if (from==to) {
			tree[node]= new Node(arr[from]);
			//cout<< " built @ "<<node<<" with  value as "<<arr[l]<<endl;
			return;
		}
		int leftIdx = 2 * node;
		int rightIdx = leftIdx+1;
		int mid = (from+to)/2;
		build(leftIdx, from, mid);
		build(rightIdx, mid+1, to);
		tree[node]=merge(tree[leftIdx], tree[rightIdx]);
		//cout<< " built "<<node<<" with  value as "<<tree[node]->getValue()<<endl;
	} 
	
	
	public:
		SegTree(int num){
			n = num;
			int height = (int)(ceil(log(num)/log(2))+1); // 2^(h-1) =n 
			int len = (int)pow(2, height); //indexing from 1
			tree = new Node* [len];
			build(1, 0 , num-1);
			//for(int i=1; i<len; i++){
				//cout<<"tree " << i << " "<<tree[i]->getValue()<<" ";
			//} 
		}
		int query(){
			Node * result = query(1 , 0 , n-1 ); // returns a copy of the queried node
			return result->getVal();
		}
		void update(int i ){
			update ( 1 , 0 , n-1 , i-1 ); // in the prob indices are 1 based
		}
		
	
};

int main(){
	int t =10;
	for(int i=1; i<=t; i++){
		
		int n;
		scanf("%d", & n );
		arr = new char [n];
		for(int j=0; j<n; j++){
			scanf("%c", & arr[j] );
		}
		SegTree * seg = new SegTree(n);
		int m;
		scanf("%d", & m );
		
		cout<<"Test "<<i<<":"<<endl;
		
		for(int i=0; i<m; i++){
			int x;
			scanf("%d", & x );
			if(x==0){
				cout<<seg->query()<<endl;
			}
			else{
				seg->update(x);
			}
		}

	}
}
/*
 * height of tree = length of the longest path from root node to leaf node
 * 
 * path length : number of nodes b/w given two nodes
 */
