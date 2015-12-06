
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

void solve(){
	
}
#ifdef DEBUGIT
  #define DEBUG(X) cerr << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << X << endl
#else
  #define DEBUG(X) (void)0
#endif

ll pow_mod(ll x, ll m, ll p){
	if (m==0)return 1;
	else if (m==1) return x;
	else {
		ll tem = pow_mod(x, m/2,p);
		ll ans = (tem * tem)%p;
		if(m&1)ans = (ans * x) %p;
		return ans;
	}
}
ll pow_mod1(ll x, ll m, ll p){
	if (m==0)return 1;
	else if (m==1) return x;
	else {
		ll a=1, b=x;
		while(m>0){
			if(m&1){ // ultimately the result is merged at 1 
				a = (a*b)%p;
			}
			b=(b*b)%p;
			m>>=1;
		}
		return a;
	}
}
ll inv_mod(ll x, ll p){
	return pow_mod1(x,p-2, p);
}
int main(){
	std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	
    int t ;
    cin>>t;
    while(t--){
		
		ll n,p;	
		cin>>n>>p;
		if(n>=p) cout<<0<<endl;
		else {
			if(n==(p-1))cout<<(p-1)<<endl;
			else {
				ll ans1 =1, ans2=1, ans=1;
				for (ll i= n+1 ; i<=p-2; i++){
					ans1  = ( ans1 * i )% p;
				}
				ans = inv_mod(ans1,p);
				 
				//ans = (ans * (p-1))%p;
				cout<<ans<<endl;
			}
		}
	}

}

// int(1e6) is equivalent to 10^6
