# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(v) int((v).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

/*
 * Here, 'present()' returns whether the element presents
 *  in the container with member function 'find()'
 *  (i.e. set/map, etc.)
 *  while 'cpresent' is for vector. 
 */
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

typedef   long long LL;

int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	LL t;
	scanf("%lld",&t);
	// using ULL causes an error in the question
	for(LL i=0; i<t; i++){
		LL n, k;
		scanf("%lld %lld",&n,&k);
		LL people[k+1];
		for(LL j=1; j<=k; j++){
			people[j]=0;
		}
		LL sum=0;
		LL terms = (-1+sqrt((double)1.0+8*n))/2.0;
		terms/=k;
		for(LL j=1; j<=k; j++){
			people[j] = terms/2.0*(2*j+(terms-1)*k);
			sum+=people[j];		
		}
		LL remain=n-sum;
		LL start=terms*k+1;
		for(LL j=1; j<=k; j++){
			if(remain-start>=0){
				people[j]+=start;
			}
			else{
				people[j]+=remain;
				break;
			}
			remain-=start;
			start++;
		}
		for(LL j=1; j<=k; j++){
			printf("%lld ",people[j]);
		}
		printf("\n");
	}
}

// int(1e6) is equivalent to 10^6

