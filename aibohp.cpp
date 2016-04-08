#include<bits/stdc++.h>
using namespace std;
int dp[6110][6110];
string getReverse(string x){
	string ans = "";
	for(int i=0; i<x.size(); i++){
		ans = x[i] + ans;
	}
	return ans;
}
int getLcs(string a, string b){
	int size_a = a.size();
	int size_b = b.size();

	for(int i=0; i<=size_a; i++){
		dp[0][i]=0;
	}

	for(int i=0; i<=size_b; i++){
		dp[i][0]=0;
	}

	for(int i=1; i<=size_b; i++){
		for(int j=1; j<=size_a; j++){
			if(a[j-1]==b[i-1]){
				dp[i][j]= dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[size_b][size_a];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int lcsSize = getLcs(str, getReverse(str));
		int ans = str.size() -  lcsSize;
		cout<<ans<<endl;
	}
}