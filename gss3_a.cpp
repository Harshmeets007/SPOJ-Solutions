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
int * arr;

class Node{
	
	public:
		int leftSum;
		int rightSum;
		int sum;
		int best;
		Node (int l , int r, int s , int b){
			leftSum=l;
			rightSum=r;
			sum =s;
			best=b;
		}
		
		int getBest(){
			return best;
		}
		
};
Node*  merge(Node * lChild, Node * rChild){
	if(lChild==NULL && rChild==NULL) return NULL;
	else{
		int leftSum=lChild->leftSum;
		if((lChild->sum + rChild->leftSum )>leftSum) leftSum= (lChild->sum + rChild->leftSum );
		int rightSum=rChild->rightSum;
		if((rChild->sum + lChild->rightSum )>rightSum) rightSum= (rChild->sum + lChild->rightSum );
		int best = max(lChild->rightSum + rChild->leftSum, max( lChild->best , rChild->best));
		int sum = lChild->sum + rChild->sum;
		Node* tmp = new Node(leftSum, rightSum, sum , best);
		return tmp;
	} 
}
// query returns max contiguous sum b/w given two indices 

class SegTree{
	int n;
	Node ** tree;
	// creating an array of Node pointers
	
	Node* query(int node, int from ,int to , int i , int j ){
		if(i<=from && j >= to) return tree[node];
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
	}
	void update (int node, int l ,int r , int i , int v ){
		if (l == i && l == r) {
			arr[i]=v;
			tree[node]=new Node(arr[i], arr [i], arr[i], arr[i]); 
		}
		else if (i < l || i > r) return;        
		else 
		{
			int leftChild = 2*node, rightChild = leftChild+1, mid = (l+r)/2;
			update(leftChild, l, mid, i, v);    
			update(rightChild, mid+1, r, i, v); 
			tree[node]=merge(tree[leftChild], tree[rightChild]);
		} 
	} 
	void build(int node , int from , int to ){
		if(from>to) return;
		else if (from==to) {
			tree[node]= new Node(arr[from], arr [from], arr[from], arr[from]);
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
		int query(int i , int j){
			Node * result = query(1 , 0 , n-1 , i-1 , j-1); // returns a copy of the queried node
			return result->getBest();
		}
		void update(int i , int v){
			update ( 1 , 0 , n-1 , i-1 , v); // in the prob indices are 1 based
		}
		
	
};

int main(){
	int n;
	scanf("%d", & n );
	arr = new int [n];
	for(int i=0; i<n; i++){
		scanf("%d", & arr[i] );
	}
	SegTree * seg = new SegTree(n);
	int m;
	scanf("%d", & m );
	for(int i=0; i<m; i++){
		int type,x,y;
		scanf("%d %d %d", & type, & x , &y );
		if(type==0){
			seg->update(x, y);
		}
		else{
			cout<< seg->query(x,y)<<endl;
		}
	}
	
	
}
/*
 * height of tree = length of the longest path from root node to leaf node
 * 
 * path length : number of nodes b/w given two nodes
 */
