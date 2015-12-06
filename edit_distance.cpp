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

#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
int dp [2002][2002];
typedef  long long LL;
string given , pattern;
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	//int t=10;
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		cin>>pattern>>given;
		int p_len= (int)pattern.length();
		int g_len=(int)given.length();
		
		dp[0][0]=0;
		for(int j=0; j<=p_len; j++){
			dp[j][0]=j;
		}
		for(int j=0; j<=g_len; j++){
			dp[0][j]=j;
		}
		for(int j=1; j<=p_len; j++){
			for(int k=1; k<=g_len; k++){
				int temp;
				if(pattern[j-1]==given[k-1]){
					temp=dp[j-1][k-1];
				}
				else{
					temp=dp[j-1][k-1]+1;
				}
				dp[j][k]=min(temp, min(dp[j-1][k]+1, dp[j][k-1]+1));
			}
		}
		cout<<dp[p_len][g_len]<<endl;
		
	}
}

// int(1e6) is equivalent to 10^6
