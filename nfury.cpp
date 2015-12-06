# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
#include <ctype.h> // for isupper function
// #include <bits/stdc++.h>
using namespace std;

#define sll(n) scanf("%lld", &n);
#define sd(n) scanf("%d" , &n);
#define pd(n) printf("%d" , n);
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

typedef unsigned long long ULL;
typedef  long long LL;
int dp [1001];
int sq [33];
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	int t, i,j;
	sd(t);
	for(i=0; i<33 ;i++){
		sq[i]=i*i;
	}
	dp[0]=0;
	for(i=1; i<1001; i++){
		dp[i]=2000;
	}
	for(i=1; i<1001; i++){
		for(j=0; j*j<=i; j++){
			dp[i]= min(dp[i], 1 + dp[i-sq[j]]);
		}
	} 
	while(t--){
		int a;
		sd(a);
		cout<<dp[a]<<endl;
	}
	
	
}

// int(1e6) is equivalent to 10^6
