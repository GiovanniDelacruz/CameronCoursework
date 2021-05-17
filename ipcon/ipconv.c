#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char cmd[16];
int* argv[5];
int  argc;
char* token;

void dec2bin(int *[]);
int main(){

MENU:

for(;;){
	printf("\nEnter an IPv4 Address to convert: ");
	fgets(cmd,16,stdin);
	cmd[strlen(cmd)-1]='\0';



	if(strcmp(cmd, "exit") == 0){
	printf("\nGoodbye\n");
	exit(0);
	}

	token = strtok(cmd, ".");
	int k=0;
	while(token!=NULL){
	argv[k]=(int *)token;
	token = strtok(NULL, ".");
	k++;
	}
 
	argv[k]=NULL;
	argc =k;
	int j=0;
	while(j<argc){
	printf("\n%s",(void *)argv[j]);
	j++;
	}
	dec2bin(argv);
	goto MENU;
}
return 0;
}

void dec2bin(int *argv[]){
	int k=0;
	int ip[4];
	char bin[32];
	while(k<4){
		ip[k]=(long int)argv[k];
		printf("\t%s",ip[k]);
		k++;
	}
	k--;
	k=3;
	int j=31;
	while(k>=0&&j>=0){
		if(j==7||j==15||j==23){
			k--;
		}
		bin[j]=ip[k]%2;
		ip[k]=ip[k]/2;
		j--;
	}
	while(j<32){
	printf("%s",bin[j]);
	j++;
	}
	
}
