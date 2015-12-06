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
LL arr[1001];
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	LL t;
	scanf("%lld",&t);
	
	for(LL i=0; i<t; i++){
		LL n;
		scanf("%lld",&n);
		for(LL j=0; j<n; j++){
			scanf("%lld", &arr[j]);
		}
		LL p;
		scanf("%lld", &p);
		
		sort(arr, arr+n);
		int flag=0;
		for( LL j=0; j<n && flag==0; j++){
			LL req_sum=p-arr[j]; 
			//cout<<"req_sum "<<req_sum<<endl;
			for(LL k=0, l=n-1; k<l; ){
				LL temp =arr[k]+arr[l];
				//cout<<"temp "<<temp<<endl;
				if(temp==req_sum && j!=k && j!=l){
					flag=1;
					break;
				}
				else if (j==k){
					k++;
				}
				else if (j==l){
					l--;
				}
				else if (temp>req_sum){
					l--;
				}
				else if (temp<req_sum){
					k++;
				}
			}
		}
		if(flag==1){
				cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
}

// int(1e6) is equivalent to 10^6
