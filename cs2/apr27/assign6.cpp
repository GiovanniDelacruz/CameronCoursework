#include <iostream>
using namespace std;



void revers(char *s, int len){
		if(len <= 1 || *s == '\0'){
			return;
		}else{
			revers(s+1,len);
			cout << *s;
		}
	



}
int main(){
	char stringme[30];
	int length;
	cout << "enter a word that is less than 30 characters long: ";
	cin >> stringme;
	cout << "\nenter how many letters are in your word: ";
	cin >> length;
	cout << endl;
	revers(stringme,length);
	cout << endl; 
	return 0;
}
