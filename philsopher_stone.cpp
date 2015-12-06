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
#define sz(v) LL((v).size())
#define all(v) (v).begin(), (v).end()

typedef  long long LL;

int main(){
	LL t;
	sll(t);
	while(t--){
		LL r , c  , i, j;
		sll(r); sll(c);
		LL arr[r][c] , dp[r][c];
		for(i=0; i<r; i++){
			for( j=0; j<c; j++){
				sll(arr[i][j]);
			}
		}
		
		for(i=0; i<c; i++){
			dp[r-1][i]= arr[r-1][i];
			//cout<<"dp[r-1]["<<i<<"]=" << dp[r-1][i]<<endl;
		}
		for(i=r-2; i>=0; i--){
			for(j=0; j<c; j++){
				LL val =  dp[i+1][j];
				if(j>=1){
					val= val>(dp[i+1][j-1])? val:(dp[i+1][j-1]);
				}
				if(j<c-1){
					val=  val>(dp[i+1][j+1])? val:(dp[i+1][j+1]);
				}
				dp[i][j]=arr[i][j]+val;
				//cout<<"dp["<<i<<"]["<<j<<"]=" << dp[i][j]<<endl;
			}
		}
		LL mx=dp[0][0];
		for(i=1; i<c; i++){
			mx=mx>dp[0][i]?mx:dp[0][i];
		}
		printf("%lld\n",mx);
	}
}
