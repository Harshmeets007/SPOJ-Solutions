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

int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	int c, n , i ,j;
	sd(c); sd(n);
	while( c!=0 && n!=0){
		int fun[n], cost[n];
		for(i=0; i<n;i++){
			cin >> cost[i]>>fun[i];
		}
		int dp [n+1][c+1];
		for(i=0; i<=c ; i++){
			dp[0][i]=0;
		}
		for(i=1; i<=n; i++){
			for(j=0; j<=c ; j++){
				if(cost[i-1]<=j){
					dp[i][j]= max(dp[i-1][j] , fun[i-1]+ dp[i-1][j-cost[i-1]]);
				}
				else{
					dp[i][j]= dp[i-1][j];
				}
			}
			
		}
		int ct;
		for(i=1; i<=c; i++){
			if(dp[n][i]==dp[n][c]){
				 ct=i;
				break;
			 }
		}
		cout<<ct <<" "<<dp[n][c]<<endl;
		sd(c); sd(n);
	}
}

// int(1e6) is equivalent to 10^6
