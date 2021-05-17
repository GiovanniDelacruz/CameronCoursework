//###########################################################
//Programmer:			Giovanni Delacruz
//Instructor:			Dr. Zhao
//Course:			Operating Systems
//Term:				FA2020
//Date:				22 November 2020
//Program Name:			Giovanni_Delacruz_Project4.c
//Purpose:			This program simulates three
//				different scheduling algorithms
//				and displays the Average 
//				Waiting Time and Average 
//				Turnaround Time. Each 
//				algorithm simulates 100 
//				processes and will run 100
//				times. The overall AWT and ATT
//				of all algorithms are displayed 
//				in a final report.
//				Simulated Algorithms:
//				FCFS, SJF, RR Quantum 4,
//				RR Quantum 8
//###########################################################

//import libraries, time needed for rng init
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//SIZE refers to number of processes 
#define SIZE 100

//RUNS refers to number of simulations
#define RUNS 100

//this 2D Array holds AWT and ATT of all algorithms
float awtatt[4][2];

//Determines which algorithm is being simulated
int count;

//simulated process structure, process id and CPU Burst
struct job{
	int id;
	int cpu;
};

//Used for qsort to sort simulations by CPU Burst for SJF
int compare(const void *a, const void *b){
	struct job x= *(struct job*)a;
	struct job y= *(struct job*)b;
	return x.cpu-y.cpu;
}

//Function Prototype to calculate AWT ATT
void cal_awt_att(struct job[]);

//Function Prototype to calculate AWT ATT for RR
void rr(struct job jobs[], int);

//Function Prototype to print final report
void print();

//Function Prototype to generate 100 random processes
void init(struct job[]);

//main driver code
int main(){
	//create 100 processes
	struct job jobs[SIZE];
	//create a loop variable
	int i;
	//seed random value
	srand(time(NULL));
	
	//This loop is the simulation loop
	for(i=0; i<RUNS; i++){
		//separate runs and display simulation number
		printf("\n---------------------------");
		printf("\nRun %d",i+1);

		//initialize job values
		init(jobs);
		
		//for FCFS and SJF, print the name of the algorithm
		//Then calculate and print AWT ATT
		printf("\nFCFS\t");
		cal_awt_att(jobs);

		//For RR, print algorithm name with quantum
		//Then calculate and print AWT ATT
		printf("\nRR Quantum= 4\t");
		rr(jobs,4);
                printf("\nRR Quantum= 8\t");
		rr(jobs,8);
		
		//Qsort is used to organize the processes by 
		//CPU Burst Time for SJF Simulation
		printf("\nSJF\t");
		qsort(jobs,SIZE,sizeof(struct job), compare);
		cal_awt_att(jobs);
	}
	//Once all simulations are complete, generate the final report
	printf("\n!!!!!Schedules Are Completed!!!!!\n");
	print();
	return 0;
}

//This Function simulates 100 process structures
void init(struct job jobs[]){
	int i;
	//randomize job data
	srand(time(NULL));
	for(i=0;i<SIZE;i++){

		//set job id 1-100
		jobs[i].id=i+1;

		//set random cpu burst time
		jobs[i].cpu= rand()%20+1;
		
	}
}

//This function prints the final report with AWT and ATT for all simulations
void print(){
	printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
        printf("Final Report\n");
        printf("FCFS:\t\t\tAWT: %f\t\tATT: %f\n",awtatt[0][0]/SIZE, awtatt[0][1]/SIZE);
        printf("RR Quantum 4:\t\tAWT: %f\t\tATT: %f\n",awtatt[1][0]/SIZE, awtatt[1][1]/SIZE);
        printf("RR Quantum 8:\t\tAWT: %f\t\tATT: %f\n",awtatt[2][0]/SIZE, awtatt[2][1]/SIZE);
        printf("SJF:\t\t\tAWT: %f\t\tATT: %f\n",awtatt[3][0]/SIZE, awtatt[3][1]/SIZE);
}

//This function calculates the AWT and ATT for FCFS and SJF
void cal_awt_att(struct job jobs[]){
	
	//Running total for wait and CPU times
	int total_wait=0;
	int total_cpu=0;
	
	//Using float for AWT and ATT to keep precision
	float awt=0.0;
	float att=0.0;
	int i;
	
	//Summation Loop adds all wait times and cpu burst times
	for(i=0;i<SIZE;i++){
		total_wait += total_cpu;
		total_cpu += jobs[i].cpu;
	}
		//After loop is finished, print AWT and ATT
		printf("\t\tAWT: %f", (float)total_wait/SIZE);
		printf("\t\tATT: %f\n", (float)(total_wait+total_cpu)/SIZE);

	//If count=0, then is it FCFS, else count=3 and it is SJF
	//This logic is used to detemine where to store the AWT and ATT value
	if(count==0){
		//FCFS
		awtatt[0][0]+=(float)total_wait/SIZE;
		awtatt[0][1]+=(float)(total_wait+total_cpu)/SIZE;

		//The next time this function is called for SJF
		count=3;
	}else{
		//SJF
                awtatt[3][0]+=(float)total_wait/SIZE;
                awtatt[3][1]+=(float)(total_wait+total_cpu)/SIZE;

		//The next time this function is called for FCFS
		count=0;	
	}

}

//Function that simulates RR with a quantum
void rr(struct job jobs[],int quantum){
	//Fin used to break inner loop and begin next iteration of outer loop
	int fin=0;
	
	//used to denote active cpu calculation
	int cur_cpu=0;

	//running tally of wait and cpu times
	int tot_w=0;
	int tot_c=0;

	//separate job structure used to keep original structure intact
	struct job temp[SIZE];

	//float precision to store AWT and ATT
	float awt=0.0;
	float att=0.0;

	//Signals whether or not RR has finished
	int done=0;
	int i;

	//Loop copies all data from original to a temp job array
	for(i=0;i<SIZE;i++){
		temp[i].id=jobs[i].id;
		temp[i].cpu=jobs[i].cpu;
		tot_c += jobs[i].cpu;
	}

	//begins RR calculation
	while(!done){
		for(i=0;i<SIZE;i++){

			//if current job has a burst time greater than 0
			if(temp[i].cpu>0){

				//if cpu burst time or job exceeds quantum
				if(temp[i].cpu>quantum){

					//calculate remaining burst time of the job
					cur_cpu+=quantum;
					temp[i].cpu-=quantum;

				//If remaining cpu burst is within the quantum
				//update wait time signal finish of job schedule
				}else if(temp[i].cpu>0&&temp[i].cpu<=quantum){
					cur_cpu+= temp[i].cpu;
					tot_w += cur_cpu-jobs[i].cpu;
					temp[i].cpu=0;
					fin++;
					if(fin>=SIZE){
						done=1;
						break;
					}
				}
			}
		}
	}

	//calculate AWT and ATT of RR
	awt=(float)tot_w/SIZE;
	att=(float)(tot_c+tot_w)/SIZE;
	printf("\tAWT: %f		ATT: %f\n",awt, att);

	//store AWT ATT in its respective array location
        if(quantum==4){
		//store RR Q=4 on 2nd row of array
                awtatt[1][0]+=(float)tot_w/SIZE;
                awtatt[1][1]+=(float)(tot_w+tot_c)/SIZE;
        }else{
		//store RR Q=8 on 3rd row of array
                awtatt[2][0]+=(float)tot_w/SIZE;
                awtatt[2][1]+=(float)(tot_w+tot_c)/SIZE;
        }

}
