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
		LL sum;
		LL mx;
		Node ( LL s , LL m){
			sum =s;
			mx=m;
		}
		
		LL getSum(){
			return sum;
		}
		
};
Node*  merge(Node * lChild, Node * rChild){
	LL sum,mx;
	if(lChild==NULL && rChild==NULL) return NULL;
	else if (lChild==NULL){
		 sum=rChild->sum;
		 mx=rChild->mx;
	}
	else if (rChild==NULL){
		 sum=lChild->sum;
		 mx=lChild->mx;
	}
	else{
		mx = max(lChild->mx, rChild->mx);
		if((lChild->mx + rChild->mx)> max(lChild->sum , rChild->sum)) sum = lChild->mx + rChild->mx;
		else sum = max(lChild->sum , rChild->sum);
	} 
	Node* tmp = new Node(sum , mx);
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
			tree[node]=new Node(arr[i], arr [i]); 
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
			tree[node]= new Node(arr[from], arr [from]);
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
			return result->getSum();
		}
		void update(LL i , LL v){
			update ( 1 , 0 , n-1 , i-1 , v); // in the prob indices are 1 based
		}
		
	
};

int main(){
	LL n;
	scanf("%lld", & n );
	arr = new LL [n];
	for(LL i=0; i<n; i++){
		scanf("%lld", & arr[i] );
	}
	SegTree * seg = new SegTree(n);
	LL m;
	scanf("%lld", & m );
	for(LL i=0; i<2*m; i++){ // dont know why 
		LL x,y;
		char type;
		scanf("%c %lld %lld", & type, & x , &y );
		if(type=='U'){
			seg->update(x, y); // change a[x] to y
		}
		else if (type=='Q'){
			cout<< seg->query(x,y)<<endl; //max of 2 elements b/w x and y 
		}
	}
	
	
}
/*
 * height of tree = length of the longest path from root node to leaf node
 * 
 * path length : number of nodes b/w given two nodes
 */
