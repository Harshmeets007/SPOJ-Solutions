# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
using namespace std;

int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++){
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		if((c1%2==0)||(c2%2==0)){
			printf("%s\n", "Suresh");
		}else {
			printf("%s\n", "Ramesh");
		}
		
		
	}
}
