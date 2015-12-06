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

typedef  long long LL;
string str;
int arr1[1005];
int arr2[1005];
int arr3[1005];
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	/*
	 * if you want to use : char str[]
	while(scanf("%s", str)==1){ 
		int ln= 
	}
	* scanf returns the number of items succesfully converted  or EOF on error
	*/
	for(int i=0; i<1005; i++){
		if(i%2==0){
			arr1[i]=1;
			arr2[i]=0;
		}
		else{
			arr1[i]=0;
			arr2[i]=1;
		}
	}
	while(getline(cin, str)){ // gets input till end of file 
		for(int i=0; i<(int)str.length(); i++){
			if(isupper(str[i])){
				arr3[i]=1;
			}
			else {
				arr3[i]=0;
			}
		}
		int sum1=0, sum2=0;
		for(int i=0; i<(int)str.length(); i++){
			sum1+=abs(arr1[i]-arr3[i]);
			sum2+=abs(arr2[i]-arr3[i]);
		}
		cout<<min(sum1, sum2)<<endl;
	}
	
	
}

// int(1e6) is equivalent to 10^6
