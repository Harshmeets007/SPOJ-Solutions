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
	int left;
	int right;
	int val;
	public:
		Node(int l , int r){
			left=l;
			right=r;
		}
		Node(int l , int r, int v){
			left=l;
			right=r;
			val=v;
		}
		void merge(Node * lChild, Node * rChild){
			if(lChild==NULL && rChild==NULL) return;
			else if (lChild==NULL){
				val=rChild->val; // take that element if it is positive
			}
			else if (rChild==NULL){
				val=lChild->val;
			}
			else{
				if(lChild-> val >0 && rChild->val>0 ) val= lChild-> val + rChild->val;
				else if(lChild-> val >0 || rChild->val>0 ){
					if(lChild->val>0) val= lChild->val;
					if(rChild->val>0) val= rChild->val;
				}
				else{ // if both negative 
					val	= max(lChild-> val , rChild->val);
				}
				
			} 
		}
		void setValue(int v){
			val=v;
		}
		int getValue(){
			return val;
		}
};
// query returns max sum b/w given two indices 
class SegTree{
	int n;
	Node ** tree;
	// creating an array of Node pointers
	
	int query(int node, int l ,int r , int i , int j ){
		if(i<=l && j>= r) return tree[node]->getValue();
		else if (i>r || j<l) return -1000000;
		else{
			int leftIdx = 2 * node;
			int rightIdx = leftIdx+1;
			int mid = (l+r)/2; 
			Node * a = new Node(-1,-1,query(leftIdx, l, mid, i, j));    
			Node* b = new Node(-1,-1,query(rightIdx, mid+1, r, i, j));
			Node * temp = new Node(-1,-1);
			temp->merge(a, b);
			return temp->getValue();
		}
	}
	void update (int node, int l ,int r , int i , int v ){
		if (l == i && l == r) tree[node]->setValue(v); 
		else if (i < l || i > r) return;        
		else 
		{
			int leftChild = 2*node, rightChild = leftChild+1, mid = (l+r)/2;
			update(leftChild, l, mid, i, v);    
			update(rightChild, mid+1, r, i, v); 
			tree[node]->merge(tree[leftChild], tree[rightChild]);
		} 
	} 
	void build(int node , int l , int r ){
		if(l>r) return;
		else if (l==r) {
			tree[node]= new Node(l,r);
			tree[node]->setValue( arr[l]);
			//cout<< " built @ "<<node<<" with  value as "<<arr[l]<<endl;
			return;
		}
		int leftIdx = 2 * node;
		int rightIdx = leftIdx+1;
		int mid = (l+r)/2;
		build(leftIdx, l, mid);
		build(rightIdx, mid+1, r);
		tree[node]=new Node(l,r);
		tree[node]->merge(tree[leftIdx], tree[rightIdx]);
		//cout<< " built "<<node<<" with  value as "<<tree[node]->getValue()<<endl;
	} 
	
	
	public:
		SegTree(int num){
			n = num;
			int height = (int)(ceil(log(num)/log(2))+1); // 2^(h-1) =n 
			int len = (int)pow(2, height); //indexing from 1
			tree = new Node* [len];
			build(1, 0 , num-1);
			for(int i=1; i<len; i++){
				cout<<"tree " << i << " "<<tree[i]->getValue()<<" ";
			} 
		}
		int query(int i , int j){
			int result = query(1 , 0 , n-1 , i-1 , j-1); // returns a copy of the queried node
			return result;
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
