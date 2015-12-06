# include <iostream>
# include <stdio.h>
# include <math.h>
# include <list>
# include <algorithm>
# include <limits>
#include <vector>
#include <ctype.h> // for isupper function
#include <string>      
#include <sstream>  
// #include <bits/stdc++.h>
using namespace std;

#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

typedef  long long LL;
typedef  unsigned long long ULL;

string NumberToString ( LL Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}


LL StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a 
{                               //character array as argument
	stringstream ss(Text);
	LL result;
	return ss >> result ? result : 0;
}
ULL * arr;
int main(){
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	string inp;
	cin>>inp;
	while(inp!="0"){
		arr = new ULL [5011];
		int len = (int)inp.length();
		arr[len+1]=0;
		arr[len]=0;
		if(inp[len-1]=='0'){
			arr[len-1]=0;
		}
		else arr[len-1]=1;
		//cout<<"arr[len-1] = "<<arr[len-1]<<endl;
		/*
		string st = inp.substr(0,2);
		//cout<<st<<endl;
		int temp = StringToNumber(st);
		//cout<<"conv " <<temp<<endl;
		if(temp<=26 && temp>0){
			if(inp[1]=='0'){
				arr[2]=1;
			}
			else{
				arr[2]=2;
			}
		}
		else{
			arr[2]=1;
		}
		//*/
		for(int i=len-2; i>=0; i--){
			//cout<<"inp "<< inp[i]<<endl;
			if(inp[i]=='0')arr[i]=0;
			else{
				arr[i]= arr[i+1];
				int val=((inp[i]-'0')*10 + (inp[i+1]-'0'));
				//cout<< "val "<< val<<endl;
				if(val >=10 && val <27){
					arr[i]+= arr[i+2];
					if((i+2)==len){ // arr[len] is set to 0
 						arr[i]+=1;
					}
				}
				
			}
			//cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
		}
		cout<<arr[0]<<endl;
		cin>>inp;
	}

}

// int(1e6) is equivalent to 10^6
