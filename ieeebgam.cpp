#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		double ans = (n*1.0)/(n+1.0);
		printf("%.8f\n",ans);
	}
}
