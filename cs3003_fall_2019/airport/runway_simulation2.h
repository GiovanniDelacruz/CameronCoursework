/* **********************************************************************************
*	Name: 			Giovanni Delacruz
*	Prof: 			Dr. Zhao
*	Course:			Seminar in Data Structures
*	Date:			7 November, 2019
*	Program:		Double-Runway Simulation
*	Description:
*-----------------------------------------------------------------------------------
*		This is the header file (.h) for the dual runway simulation. This  
*	program is structured around the queue template and has one queue for each
*	runway. One runway is used solely for departing planes and the other is
*	for landing aircrafts. The header file contains all the prototypes and methods 
*	to be used in the program, as well as a runway constructor that accepts two
*	integer parameters and two float parameters.
********************************************************************************** */
#ifndef RUN_WAY_H_
#define RUN_WAY_H_

#include <iostream>

class runway
{
	public:
	runway(int, int,float,float);				//constructor
	bool is_airplane_comming_for_landing();			//returns status of incoming
	bool is_airplane_comming_for_takeoff();			//returns status of leaving
	bool is_landing();					//returns status of landing
	bool is_takeoff();					//returns status of departing
	void one_time_unit();					//consumes one value of time
	bool is_runway_busy();					//returns status of runway
	void start_takeoff();					//begins departure
	void start_landing();					//begins landing
	void sum_landing_time(int);				//time to land
	void sum_takeoff_time(int);				//time to depart
	int airplane_landed();					//count of landed flights
	int airplane_takeoff();					//count of departed flights
	float average_wait_time_for_landing();			//average time in land queue
	float average_wait_time_for_takeoff();			//average time in depart queue
	void start_sim();					//begins simulation environment
	
	private:
	float landing_arrivel_rate;				//how often to come
	float takeoff_arrivel_rate;				//how often to come
	int sum_for_landing;					//store total time for landing
	int sum_for_takeoff;					//store total time for takeoff
	int land_time;						//store time used for landing
	int takeoff_time;					//store time used for taking off
	int land_time_left;					//store time left for landing
	int takeoff_time_left;					//store time left for takeoff
	int takeoff_counter;					//store the number of tookeoff
	int landing_counter;					//store the number of landed
};
//#include "runway.cpp"
#endif
