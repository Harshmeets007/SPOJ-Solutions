# include <iostream>
using namespace std;
int main(){
	int t;
	cin >>t;
	for(int i=0; i<t; i++){
		long long x,y,z;
		cin >>x>>y>>z;
		long long n, a ,d;
		n=2*z/(x+y);
		cout<<n<<endl;
		d=(y-x)/(n-5);
		a=x-2*d;
		for(int j=0;j<n; j++){
			cout<<(a+j*d)<<" ";
		}
	}
}
