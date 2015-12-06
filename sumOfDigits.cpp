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

typedef unsigned long long ULL;
typedef long long LL;

LL leftSum(LL n){
	LL sum=0;
	n/=10;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;	
}
LL sumTillN(LL n){
	if(n%2==0){
		return (n/2)*(n+1);
	}else if ((n+1)%2==0){
		return n* ((n+1)/2);
	}else return (n*(n+1))/2;
}
LL leftPart(LL n){
	return n/10;
}
LL lastDigit(LL n){
	return n%10;
}
LL solve(LL n , LL multi){
	if(n/10 ==0) return sumTillN(n)*multi;
	
	return sumTillN(lastDigit(n))*multi + leftSum(n)*(lastDigit(n)+1)*multi + leftPart(n)*45*multi + solve(leftPart(n)-1, multi*10); 	
}

int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	
	LL a,b;
    cin>>a>>b;
    while(a!=-1 || b!=-1){
        cout<<solve(b,1)-solve(a-1,1)<<endl;
        cin>>a>>b;
    }
	
}
// 78 80 gave -24
// int(1e6) is equivalent to 10^6
