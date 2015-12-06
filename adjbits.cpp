#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// arr[len][k][b] represents the number of ways to form a string 
// that ends with bit 'b' and is of len l, and adjBitCt is ct
ll arr[110][110][2];
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0; i<110; i++){
			for(int j=0; j<110; j++){
				for(int k=0; k<2; k++){
					arr[i][j][k]=0;
				}
			}
		}
		
		int idx, n, ct;
		cin>>idx>>n>>ct;
		
		arr[1][0][1]=1; 
		arr[1][0][0]=1;
		
		for(int i=2; i<=n; i++){
			for(int j = 0; j<=ct; j++){
				arr[i][j][0] = arr[i-1][j][0] + arr[i-1][j][1];
				
				arr[i][j][1] = arr[i-1][j][0];
				if(j>=1) arr[i][j][1] += arr[i-1][j-1][1];
			}
		}
		int ans = arr[n][ct][0] + arr[n][ct][1];
		cout<<idx<<" "<<ans<<endl;
		
	}
}
