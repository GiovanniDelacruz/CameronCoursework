//-------------------------------------------------------------------
//Programmer:			Giovanni Delacruz
//Instructor:			Professor Moinian
//Course:			Algorithm Analysis
//Program:			Prog2/BINGO SEARCH
//
//
//
//Usage:			This program highlights the use of the 
//				brute force method for solving problems.
//The user will enter two 3-digit values, and these values will be
//searched for in the bingo card. If matches are found horizontally or
//vertically, the program will notify the user. At the end, it will
//display the running statistics of the game(s) played
//
//--------------------------------------------------------------------


#include <iostream>
#include <stdlib.h>
#include <cstdlib>	//used for rand()

using namespace std;


const int five=5;	//array dimension
int board[five][five];	//bingo card 
char c[five]={'C','R','A','Z','Y'};	//row bingo header
char b[five]={'B','I','N','G','O'};	//column bingo header
int input[3];				//user input pick 1
int input2[3];				//user input pick 2
int buff;				//buffer to separate pick to digits
char ans;				//yes or no user answer
int tally=0;				//running tally of games played
int compsum=0;				//running tally of total comparisons
int comparisons=0;			//running tally of comparisons made in current game
void populate( int board[five][five]);	//initialize board with random digits prototype
int horizontal(int board[five][five],int input[3],int input2[3]);	//search horizontally prototype
int vertical(int board[five][five],int input[3],int input2[3]);		//search vertically prototype

int main(){
	int hor, ver;							//stores hori and vert return values
	START:								//goto label
	tally++;							//begin printing BINGO
	cout<<"\n\t"<<b[0]<<"_"<<b[1]<<"_"<<b[2]<<"_"<<b[3]<<"_"<<b[4]<<"\t\n------------------------\n";
	populate(board);						//add values to card
	for(int i =0; i < five; i++){					//use loop to print card
		cout<<c[i]<<" |\t";					//hide certain values
		for(int j=0; j < five; j++){
			if(j%2==0&&i%2==0){
				cout <<"* ";
			}else if(j%2==1&&i%2==1){
				cout <<"* ";
			}else{
				cout << board[i][j]<<" ";
			}	 
			
		}
		cout << "\n";
	}
									//ask user to enter 3 digit number
        cout << "\n\nEnter a three-digit number for pick #1: ";
        cin >> buff;
        for(int i =2; i >= 0; i--){
        input[i] = buff%10;
        buff/=10;
        }
        buff=0;
        cout << "\n\nEnter a three-digit number for pick #2: ";		//ask user to enter 3 digit number
        cin >> buff;							//store each digit as an array value
        for(int i =2; i >= 0; i--){
        input2[i] = buff%10;
        buff/=10;
        }
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	hor=horizontal(board,input,input2);				//check for horizontal matches
	ver=vertical(board,input,input2);				//check for vertical matches
	if(hor==0){
		cout<<"\nNo horizontal matches found";			//if hor or ver==0, then no matches were found
	}
	if(ver==0){
		cout<<"\nNo vertical matches found";
	}
	cout<<"\n\n";							//print fully revealled board
        cout<<"\n\t"<<b[0]<<"_"<<b[1]<<"_"<<b[2]<<"_"<<b[3]<<"_"<<b[4]<<"\t\n------------------------\n";
        for(int i =0; i < five; i++){
                cout<<c[i]<<" |\t";
			for(int j =0; j<five; j++){
                                cout << board[i][j]<<" ";
                        }

                
                cout << "\n";
        

	}
	compsum+=comparisons;						//print out stats of running game
	cout<<"\n--------------STATS-------------------\n";
	cout<<"Total No. comparisons made:\t\t"<< compsum;
	cout<<"\nTotal No. comparisons made this game:\t"<<comparisons;
	cout<<"\nAverage No. of compariosons per game:\t"<<compsum/tally;
	cout<<"\nWould you like to go again? y/n? ";
	cin>> ans;
	if(ans=='y'||ans=='Y'){						//ask if user wishes to continue playing
		comparisons=0;
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		goto START;						//if yes, jump to START
	}
	cout<<"\n\nThanks For Using!\n";				//else exit program
	return 0;
}

void populate(int board[five][five]){					//function adds values to bingo card
	srand(time(NULL));						//each value is random and 0-9
	for(int i=0;i<five;i++){
		for(int j=0; j<five; j++){
			board[i][j]= rand()%10;
		}
	}
}

int horizontal(int board[five][five], int input[3], int input2[3]){
	int count=0;							//check for horizontal match using brute force
	for(int i=0;i<five;i++){
		for(int j=0;j<3;j++){					//horizontally, the program will go through all 
		comparisons++;						//rows, but only start max at m-n positions
		if(board[i][j]==input[0]){				//where m is the bound for columns and n is
			comparisons++;					//the bound for the comparison array
			if(board[i][j+1]==input[1]){			//at each conditional statement, comparisons++
				comparisons++;
				if(board[i][j+2]==input[2]){
					cout <<"\nWinner on row "<<c[i]<<", matches pick 1: "<<input[0]<<input[1]<<input[2];
					count=1;
				}
				
			}
		}
		comparisons++;
		if(input2[0]==board[i][j]){				//perform the same thing for the second input
			comparisons++;
                        if(input2[1]==board[i][j+1]){
				comparisons++;
                                if(input2[2]==board[i][j+2]){
                                        cout <<"\nWinner on row "<<c[i]<<", matches pick 2: "<<input2[0]<<input2[1]<<input2[2];
                                	count=1;
				}
				
                        }
                }



	}
}
return count;
}

int vertical(int board[five][five], int input[3], int input2[3]){
	int count=0;							//check for vertical match using brute force
	for(int i =0; i<3;i++){						//vertically, the program will check all columns
		for(int j=0;j<five;j++){				//but will only start check max at m-n location
			comparisons++;					//where m is the bound for bingo and n is bound
			if(input[0]==board[i][j]){			//for user input
				comparisons++;
				if(input[1]==board[i+1][j]){		//each conditional statement adds to comparison count
					comparisons++;
					if(input[2]==board[i+2][j]){
						cout <<"\nWinner on col "<<b[j]<<", matches pick 1: "<<input[0]<<input[1]<<input[2];
						count=1;
					}
					
				}
			}

			comparisons++;
                        if(input2[0]==board[i][j]){			//perform the same procedure on input 2
				comparisons++;	
                                if(input2[1]==board[i+1][j]){
					comparisons++;
                                        if(input2[2]==board[i+2][j]){
                                                cout<<"\nWinner on col "<<b[j]<<", matches pick 2: "<<input2[0]<<input2[1]<<input2[2];
						count=1;
                                        }
					
                                }
                        }



		}
	}
	return count;
}

