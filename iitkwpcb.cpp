#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

long long gcd(long long a,long long b) {
	if(b==0)
		return a;
	if(a==b)
		return a;
	else
		return gcd(b,a%b);
}
int main() {
	int cases;scanf("%d",&cases);
	while(cases--) {
		long long n;
		scanf("%lld",&n);
		for(long long i=n/2; i>0; i--) {
			if(gcd(n,i)==1) {
				printf("%lld\n",i);
				break;
			}
		}
	}
	return 0;
}
