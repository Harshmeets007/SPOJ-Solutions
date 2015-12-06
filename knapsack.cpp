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
LL*val;
LL*weight;
LL s,n;
LL**dp;
LL knapsack(LL n, LL s){
	// the first row corresponding to zero weights
	for(LL i=0; i<s; i++){
		dp[0][i]=0;
	}
	for (LL i=1; i<=n; i++){
		for(LL j=0; j<=s; j++){
			if(weight[i-1]<=j){
				dp[i][j]=max(dp[i-1][j], val[i-1]+ dp[i-1][j-weight[i-1]]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][s]; 	
}
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	
	scanf("%lld",&s);
	scanf("%lld",&n);
	val = new LL[n];
	weight= new LL[n];
	
	dp = new LL*[n+1];
	for(LL i=0; i<(n+1); i++){
		dp[i]= new LL[s+1];
	}
	 
	for(LL i=0; i<n; i++){
		
		scanf("%lld",&weight[i]);
		scanf("%lld",&val[i]);
	}
	printf("%lld \n",knapsack(n, s));
	
}

// int(1e6) is equivalent to 10^6
