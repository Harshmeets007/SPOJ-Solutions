#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
#define DIFF_SIZE 100000
int myPrimes[DIFF_SIZE];
int count;
void calcPrimesTillRtN(int n){
	bool primeArray[DIFF_SIZE];
	for(int i=2; i<DIFF_SIZE;i++){
		primeArray[i]=true;
		myPrimes[i]=0;
	}
	//cout<<"hekk1\n";

	int sqrtN= (int)sqrt((double)n);
	int k=(int)sqrt((double)sqrtN);
	//TRADITIONAL SIEVE STARTS HERE
	for(int i=2; i<=k; i++){ // need not go till sqrtN
		if(primeArray[i]){
			for (int j=i*i; j<=sqrtN; j+=i){
				primeArray[j]=false; // cutting out multiples
			}
		}
	}

	count=0;
	for(int i=2; i<=sqrtN;i++){ // run the loop over from 2, since they have been marked true from start
								  // or separately mark them aside , and then run the loop from 0
		if(primeArray[i]) myPrimes[count++] = i;
	}

}
int main(){
	int t;
	int p=0;
	scanf("%d",&t);
	bool primesNow[DIFF_SIZE];
	while(t--){
		int n, m; // n is larger and m is smaller
		scanf("%d %d", &m, &n);
		for(int i=0;i<DIFF_SIZE;i++)
		primesNow[i]=true;


		calcPrimesTillRtN(n);
		
		for (int i=0; i<count; i++){
			 p= myPrimes[i]; 
			int multipleBeforeM = m/p;
			multipleBeforeM*=p; // thus we initialise the elements of 
			
			for(int j= multipleBeforeM; j<=n; j+=p){
				if(j<m) continue;
				primesNow[j-m]=false;
			}
		}

		for(int i=0;i<count;i++){     //in the above loop the first prime numbers for example say 2,3 are also set to false                          //hence we need to print them in case they  are within range.
			if(myPrimes[i]>=m && myPrimes[i]<=n) //without this loop you will see that for an range(1,30), 2 and 3 does
			cout<<myPrimes[i]<<endl;         //not get printed
		}

		for(int i=0; i<n-m+1; i++){
			if((primesNow[i]==true)&& (i+m)!=1){
				cout<<i+m<<endl;
			}
		}
	cout<<endl;
	}
}
