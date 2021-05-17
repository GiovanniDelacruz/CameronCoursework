#include <iostream>
using namespace std;



int sumOfDigits(int x){
	if(x < 0){
		x = x *-1;
	}if(x > 0){
		return x%10+sumOfDigits(x/10);
	}
	

}

int lucky7s(int x){
	int count =0;
	if(x<0){
		x*=-1;
	}if(x>0){
		if(x%10==7){
			count +=1;
		}
	return count+lucky7s(x/10);
	}
}

int double8s(int x){
        if(x<0){
                x*=-1;
        }if(x>0){
		if(x%10==8){
			if(x/10%10==8){
				return 2+double8s(x/10);
			}
			return 1+double8s(x/10);
		}
        return double8s(x/10);
        }

}


int main(){
	int x;
 	int y;
	int z;
	cout << "enter a number to add its digits: ";
	cin >> x;
	cout << "sum of " << x << " is " << " " << sumOfDigits(x) << endl;
	cout << "enter a number to check for lucky 7s: ";
        cin >> y;
        cout << "count of sevens is " << " " << lucky7s(y) << endl;
	cout << "enter a number to check for double 8s: ";
        cin >> z;
        cout << "count of eights is " << " " << double8s(z) << endl;



return 0;
}
