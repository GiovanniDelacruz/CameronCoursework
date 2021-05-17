/* 
************************************************************************************** 
* file name: bin_recursive.cpp * date: 9/12/2019 * purpose: generates all 
combinations of binary 0-256 
************************************************************************************** 
*/
#include <iostream> 
#define SIZE 8
using namespace std; 
void generate_bin(string&, int); 
void print(string, int, int); 

int main(){
	string s = "00000000";
	int i=0;
	cout <<i<<"\t"<<s<<endl;
	
	while(++i<256){
		cout <<i<<"\t";
		generate_bin(s,SIZE-1);
		//cout<<s<<endl;
		print(s,0,SIZE-1);
		cout <<endl;
	}
	
}
void generate_bin(string &s, int n){
	if(n>=0){
		if(s[n]=='0'){//change the last 0 to 1
			s[n] ='1';
			return;
		}else if(s[n] =='1'){
			s[n] ='0';
			generate_bin(s,n-1);
		}
	}
}
void print(string s, int start, int end){
	if(start <=end){
		cout <<s[start];
		print(s, start+1, end);
	}
}
