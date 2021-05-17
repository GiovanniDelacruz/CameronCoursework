#include <iostream>
#include <string>
using namespace std;


int getOnes(int n){
	if(n==0){
		return 0;
	}else{
		return (n%2)+getOnes(n/2);
		
	}


}

int EvenSum(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 2;
	}else{
		return n*2+EvenSum(n-1);
	}


}

string isPalindrome(string test){
	if(test.length()==0||test.length()==1){
		return "\n\ntrue";
	}else{
		if(test[0] != test[test.length()-1]){
			return "\n\nfalse";
		}else if(test[0] == test[test.length()-1]){
			return isPalindrome(test.substr(1,test.length()-2));
		}
	}
}


int main(){
int i = 8;

cout <<getOnes(i)<< "\n\n"; 
cout <<EvenSum(i)<< "\n\n";
cout <<isPalindrome("eve") <<"\n\n";
return 0;
}
