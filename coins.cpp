# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
#include <map>
using namespace std;

#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
typedef unsigned long long ULL;
map <ULL,ULL> dp;

ULL calc(ULL n){
	if(n==0) return 0;
	if( dp[n] == 0){
		//dp[n]=max(dp[n], calc(n/2)+calc(n/3)+ calc(n/4));
		dp[n]= calc(n/2)+calc(n/3)+ calc(n/4);
		if(n>dp[n])dp[n]=n;
		return dp[n];
	}else{
		return dp[n]; 
	}
}
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
		ULL n;
		dp[0]=0;
		while(scanf("%llu",&n)!=EOF){ // or   ==1
			if(n==0) printf("%d\n", 0);
			else {
				calc(n);
				printf("%llu\n", dp[n]);
			}
		}
	}


// int(1e6) is equivalent to 10^6
