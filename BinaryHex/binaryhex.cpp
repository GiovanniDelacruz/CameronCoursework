//BINARYHEX.CPP
//---------------------------------------------------------
//This is the binaryhex.cpp function definitions file that 
//defines all of the functions declared in the header file
//and allows them to be executed in the binaryhex_main.cpp
//file
//---------------------------------------------------------

#include <iostream>


using namespace std;

//generates binary for the given number

void generate_bin_string(int s[], int n, int SIZE){
	while (SIZE>=0){	
		s[SIZE-1]=n%2;	//it returns the remainder
		n=n/2;		//after dividing 2 backwards
		SIZE--;		
	}
	SIZE=8;			//resets size because its designed
				//to be used in a loop
}

//prints the binary result and separates it into two 4-bit columns

void print_binary(int s[], int n, int SIZE){ 
	
		while(n!=SIZE){ 		//n is a global counter
			cout << s[n];		//print bit
			n++;
			if(n==4){		//add space after 4th bit
			cout << " ";
		}
		}
		n=0;
}

//converts binary into hexadecimal and prints it
void convert_bin_hex(int s[], int n, int m){
	
	
	n= s[0]*8 + s[1]*4 + s[2]*2 + s[3]*1;	//first four bits 
	m= s[4]*8 + s[5]*4 + s[6]*2 + s[7]*1;	//last four bits
	
	
	if(n==15){				//prints out hex by bit value
		cout << "\tF";
	}else if(n==14){
		cout << "\tE";
	}else if(n==13){
		cout << "\tD";
	}else if(n==12){
		cout << "\tC";
	}else if(n==11){
		cout << "\tB";
	}else if(n==10){
		cout << "\tA";
	}else{
		cout <<"\t"<<n;
	}

	if(m==15){				//prints out hex by bit value
                cout << "F\n";
        }else if(m==14){
                cout << "E\n";
        }else if(m==13){
                cout << "D\n";
        }else if(m==12){
                cout << "C\n";
        }else if(m==11){
                cout << "B\n";
        }else if(m==10){
                cout << "A\n";
        }else{
                cout << m<<endl;
        }


}

