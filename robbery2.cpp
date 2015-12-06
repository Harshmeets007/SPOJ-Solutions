# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(v) int((v).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

/*
 * Here, 'present()' returns whether the element presents
 *  in the container with member function 'find()'
 *  (i.e. set/map, etc.)
 *  while 'cpresent' is for vector. 
 */
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

typedef  long long LL;

int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	int t;
	scanf("%d",&t);
	
	for(int i=0; i<t; i++){
		int n, k;
		scanf("%d %d",&n,&k);
		int people[k];
		for(int j=0; j<k; j++){
			people[j]=0;
		}
		int count=1;
		int idx=0;
		while(1){// if you check : n>0 , tle
			if(n<count ||n==0){
				people[(idx++)%k]+=n;
				break;
			}
			people[(idx++)%k]+=count;
			n-=count++;
			//count+=1;
			//idx+=1;
		}
		//ULL divider= k;
		//ULL divsn = (n/divider);
		//cout<<"divsn "<<divsn<<endl;
		//ULL common;
		//if(divsn%2==0){
			//common= (divsn/2)*(divsn-1);
		//}else {
			//common= ((divsn-1)/2)*divsn;
		//}
		//common*=k;
		//cout<<"common "<<common<<endl;
		//for(ULL j=1; j<=k; j++){
			//ULL ans = common + divsn*j;		
			//if(j<= n%k) ans += (divsn*divider) +j;
			////printf("%llu ", ans);
			//cout<<ans<<" ";
		//}
		//cout<<endl;
		for(int j=0; j<k; j++){
			printf("%d ",people[j]);
		}
		printf("\n");
	}
}

// int(1e6) is equivalent to 10^6
