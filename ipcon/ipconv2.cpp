//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//Programmer:	Giovanni Delacruz
//Instructor:	Dr. Zhao
//Course:	Network Programming FA20
//Project:	#2 Ip to Bit to Decimal conversion
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//Purpose:	This program will prompt the user to unter a 
//		valid ip address to convert. Once validated,
//		the program tokenizes the input into a decimal
//		array and then converts each ip segment to
//		bit form, and then takes the network bit and
//		converts it to a network decimal representation. 
//		The program then prompts the user if they would
//		like to convert another ip address. If yes
//		it will restart the program, else if will 
//		exit.
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>			//used for exponent
using namespace std;

void dec2bin(int[], int[], int);	//prototype for decimal-binary conversion
void bin2nip(int[],unsigned int);	//prototype for binary-networkDec conversion

int main(){

start:
char ip[15];				//user input
int dec[4];				//storage for tokenized input
int a=0;				//utilized for various counting
int bin[32];				//storage for binary ip
unsigned long long int nip=0;		//storage for converted network decimal
char YN;				//yes or no answer


cout << "\nEnter an IPv4 address to convert: ";	//prompt user to enter a valid ip
cin >> ip;
char *cds=strtok(ip,".");			//begin tokenizing
while(cds){
	if(a<4){
		dec[a++]=atoi(cds);		//store tokenized ip segment in array
	}	
	cds = strtok(NULL,".");			
}
	for(int f=0;f<4;f++){			//check that ip address is valid
		if(dec[f]>255||dec[f]<0){
		cout <<"\nThat is not an ip address!!!\nError\nError\nError";
		goto start;			//if invalid, restart
	}
	}					//begin conversion
	cout<<"\nipv4 Address to convert:\t\t";	//print ip address to convert
	for(int i = 0; i<4; i++){
	cout << dec[i];
	if(i<3){
	cout << ".";
	}
	}
	cout << "\nBinary Conversion:\t\t\t";	//print binary conversion of ip
	a=0;
	while(a<4){
	dec2bin(dec,bin,a);			//function call to convert
	if(a<3){
	cout<<".";
	}
	a++;
	}
	a=0;
	cout <<"\nNetwork Decimal Value:\t\t\t";//print network decimal value
	bin2nip(bin,nip);			//function call to convert
	cout<<"\nWOULD YOU LIKE TO DO AGAIN? Y/N\t\t";
	cin >> YN;				//prompt the user to convert again
	if(YN=='y'||YN=='Y'){			//if yes, unconditional goto the beginning
	goto start;
	}
	cout <<"\nTHANKS FOR USING!\n";		//else thank user and exit clean
	return 0;
}

void dec2bin(int dec[], int bin[], int c){	//function definition to convert ip to binary
	for(int i=8*(c+1)-1;i>=8*c;i--){
		bin[i]=dec[c]%2;		//store remainder from dividing by 2
		dec[c]=dec[c]/2;		//update value of ip by dividing by 2
	}
	for(int j=8*c; j<=8*(c+1)-1;j++){
	cout<<bin[j];				//print bit backwards so it is in order
	}
}

void bin2nip( int bin[], unsigned int nip){	//function definition to convert binary to network decimal
	unsigned long long int base=0;		//base is unsigned because it will hold up to 2^31
	for(int k =0; k<32;k++){
	if(bin[k]==1){
		base=pow(2,31-k);
		nip=nip+bin[k]*base;		//update decimal value with the active bits multiplied by base raised to degree
	}
	}
	cout << nip;				//print network decimal when finished
}

