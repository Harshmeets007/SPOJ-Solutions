# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
using namespace std;

#define sz(v) LL((v).size())
#define all(v) (v).begin(), (v).end()

typedef  long long LL;
LL * arr;

class Node{
	
	public:
		LL val;
		
		Node ( LL v){
			val=v;
		}
		
		LL getVal(){
			return val;
		}
		
};
Node*  merge(Node * lChild, Node * rChild){
	LL val;
	if(lChild==NULL && rChild==NULL) return NULL;
	else if (lChild==NULL){
		 val = rChild->val;
	}
	else if (rChild==NULL){
		 val = lChild->val;
	}
	else{
		val = lChild->val < rChild->val? lChild->val:rChild->val ;
	} 
	Node* tmp = new Node(val);
	return tmp;
}
// query returns max contiguous sum b/w given two indices 

class SegTree{
	LL n;
	Node ** tree;
	// creating an array of Node poLLers
	
	Node* query(LL node, LL from ,LL to , LL i , LL j ){
		if(i<=from && j >= to) return tree[node];
		else if (i>to || j<from) return NULL;
		else{
			LL leftIdx = 2 * node;
			LL rightIdx = leftIdx+1;
			LL mid = (from+to)/2;
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
	void update (LL node, LL l ,LL r , LL i , LL v ){
		if (l == i && l == r) {
			arr[i]=v;
			tree[node]=new Node(arr[i]); 
		}
		else if (i < l || i > r) return;        
		else 
		{
			LL leftChild = 2*node, rightChild = leftChild+1, mid = (l+r)/2;
			update(leftChild, l, mid, i, v);    
			update(rightChild, mid+1, r, i, v); 
			tree[node]=merge(tree[leftChild], tree[rightChild]);
		} 
	} 
	void build(LL node , LL from , LL to ){
		if(from>to) return;
		else if (from==to) {
			tree[node]= new Node(arr[from]);
			//cout<< " built @ "<<node<<" with  value as "<<arr[l]<<endl;
			return;
		}
		LL leftIdx = 2 * node;
		LL rightIdx = leftIdx+1;
		LL mid = (from+to)/2;
		build(leftIdx, from, mid);
		build(rightIdx, mid+1, to);
		tree[node]=merge(tree[leftIdx], tree[rightIdx]);
		//cout<< " built "<<node<<" with  value as "<<tree[node]->getValue()<<endl;
	} 
	
	
	public:
		SegTree(LL num){
			n = num;
			LL height = (LL)(ceil(log(num)/log(2))+1); // 2^(h-1) =n 
			LL len = (LL)pow(2, height); //indexing from 1
			tree = new Node* [len];
			build(1, 0 , num-1);
			//for(LL i=1; i<len; i++){
				//cout<<"tree " << i << " "<<tree[i]->getValue()<<" ";
			//} 
		}
		LL query(LL i , LL j){
			Node * result = query(1 , 0 , n-1 , i-1 , j-1); // returns a copy of the queried node
			return result->getVal();
		}
		void update(LL i , LL v){
			update ( 1 , 0 , n-1 , i-1 , v); // in the prob indices are 1 based
		}
		
	
};

int main(){
	LL t;
	scanf("%lld", & t );
	for(LL j=1; j<=t; j++){
		LL n,m;
		scanf("%lld", & n );
		scanf("%lld", & m );
		arr = new LL [n];
		for(LL i=0; i<n; i++){
			scanf("%lld", & arr[i] );
		}
		SegTree * seg = new SegTree(n);
		
		printf("Scenario #%lld:\n\n",j);
		for(LL i=0; i<m; i++){ // dont know why 
			LL x,y;
			scanf("%lld %lld",  & x , &y );
			printf("%lld\n", seg->query(x,y)); //max of 2 elements b/w x and y 
		}
		
	}
}
/*
 * height of tree = length of the longest path from root node to leaf node
 * 
 * path length : number of nodes b/w given two nodes
 */
