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
string rev(string in){
	string temp="";
	int len = in.length();
	for(int i=len-1;i>=0; i--){
		temp+=in[i];
	}
	return temp;
}
string omitZero(string in){
	string temp="";
	int len = in.length();
	int idx=0;
	for(int i=0; i<len; i++){
		if(in[i]!='0'){
			idx=i;
			break;
		}
	}
	for(; idx<len; idx++){
		temp+=in[idx];
	}
	return temp;
}
void solve(){
	ll c,d;
	string x, y;
	cin>>c>>d;
	x=NumberToString(c);
	y=NumberToString(d);
	// reverse the numbers
	x=rev(x);
	y=rev(y);
	// delete zeroes from front
	x=omitZero(x);
	y=omitZero(y);
	// add the numbers
	ll a, b;
	a= StringToNumber(x);
	b = StringToNumber(y);
	a+=b;
	// delete trailing zeroes
	while(a%10==0){
		a/=10;
	}
	// convert to string and reverse
	cout<<rev(NumberToString(a))<<endl;
}
ll rev1(ll n){
	ll temp=0;
	while(n>0){
		temp=temp*10 + n%10;
		n/=10;
	}
	return temp;
}
void solve1(){
	ll a, b;
	cin>>a>>b;
	cout<<rev1(rev1(a)+rev1(b))<<endl;

}
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	
    //int t = 1;
    int t;
    cin>>t;
    
    while(t--){
        solve1();
    }

}

// int(1e6) is equivalent to 10^6
