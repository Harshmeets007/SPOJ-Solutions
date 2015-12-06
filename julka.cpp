# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
#include <ctype.h> // for isupper function
#include <string>      
#include <sstream> 
#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define ppb pop_back
#define mp(x,y) make_pair((x),(y))
//#define sd(n) scanf("%d" , &n);
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define maX(a,b)   ( (a) > (b) ? (a) : (b))
#define miN(a,b)   ( (a) < (b) ? (a) : (b))
#define bitcount   __builtin_popcount
#define mset(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forit(it, s) for(typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it) 
#define F first
#define S second
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define LEN(X) strlen(X)

const double pi = acos(-1.0);

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs;
typedef long double ld;
typedef  long long ll;
typedef unsigned long long ull;
string NumberToString ( ll Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}


ll StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a 
{                               //character array as argument
	stringstream ss(Text);
	ll result;
	return ss >> result ? result : 0;
}
int *n,*k;
void printArrs(int * ar, int sz){
	int i=0;
	bool flag=false;
	for( i=0; i<sz; i++){
		if(ar[i]>0)break;
	}
	for(; i<sz; i++){
		cout<<ar[i];
		flag=true;
	}
	if(!flag)cout<<0;
	cout<<endl;
}
void solve(){
	string x, y;
	cin>>x>>y;
	
	int l1=x.size();
	int l2=y.size();
	int sz=maX(l1,l2);
	int x1[sz], y1[sz],sub[sz],div[sz];
	n= new int[sz];
	k=new int[sz];
	for(int i=0; i<(sz-l1); i++){
		x1[i]=0;
	}
	for(int i=sz-l1; i<sz; i++){
		x1[i]=x[i-(sz-l1)]-'0';
	}
	//printArrs(x1,sz);
	for(int i=0; i<(sz-l2); i++){
		y1[i]=0;
	}
	for(int i=sz-l2; i<sz; i++){
		y1[i]=y[i-(sz-l2)]-'0';
	}
	//printArrs(y1,sz);
	for(int i=0;i<sz; i++){
		
		div[i]=-1;
	}
	//cout<<"wedf"<<endl;
	//printArrs(div,sz);
	//cout<<div[0]<<endl;
	for(int i=sz-1; i>=0; i--){
		if(x1[i]>=y1[i]){
			sub[i]=x1[i]-y1[i];
		}
		else{
			int j= i-1;
			while(x1[j]==0){
				j--;
			}
			x1[j]-=1;
			for(int k=j+1; k<=i-1; k++){
				x1[k]+=9;
			}
			x1[i]+=10;
			sub[i]=x1[i]-y1[i];
		}
	}
	//printArrs(sub,sz);
	int p=0;
	for(int i=0; i<sz; i++){
		p=p*10+sub[i];
		div[i]=p/2;
		p%=2;
	}
	int idx =sz-1;
	for(int i=sz-1; i>=0; i--){
		if(div[i]==-1)continue;
		else{
			n[idx]=div[i];
			idx--;
		}
	}
	int carry=0;
	for(int i=sz-1;i>=0; i--){
		k[i]=n[i]+y1[i]+carry;
		carry=0;
		if(k[i]>=10){
			carry+=k[i]/10;
			k[i]%=10;
		}
	}
	printArrs(k,sz);
	printArrs(n,sz);
	
	
	
}
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	
    int t = 10;
    //int t;
    //cin>>t;
    while(t--){
        solve();
    }

}

// int(1e6) is equivalent to 10^6
