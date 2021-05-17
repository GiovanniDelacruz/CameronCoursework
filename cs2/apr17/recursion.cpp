#include <iostream>
using namespace std;


void RecursiveCall(int num){
        if(num < 1 && num >-1){
                cout << "\nrecursion is done\n";
        }else{
                cout << num % 10 << endl;
		RecursiveCall(num/10);
        }
}

int triangle(int num){
	if(num == 0){
	cout << "\nrecursion is done\n";
	}else{
	cout << endl;
	return  triangle(num-1)+num;
	}
}

int count7(int num){
	if(num < 1 && num >-1){
		cout << "\nrecursion is done\n";
	}else if(num % 10 == 7){
	return 1+ count7(num  /10);
	}else{
		count7(num/10);
	}
}

int main(){
        int number;
	int number2;
	int number3;
        cout << "Enter a number to be numerically broken down: ";
        cin >> number;

        RecursiveCall(number);
	cout << "Enter how many rows you want in your triangle: ";
	cin >> number2;
	
	cout << triangle(number2);
	cout << "Enter a number to be searched for sevens: ";
	cin >> number3;
	cout << "/n" << count7(number3);

        return 0;
}

