#ifndef RUN_WAY_H_
#define RUN_WAY_H_

#include <iostream>

class runway
{
	public:
	runway(int, int,float,float);//constructor
	bool is_airplane_comming_for_landing();
	bool is_airplane_comming_for_takeoff();
	bool is_landing();
	bool is_takeoff();
	void one_time_unit();
	bool is_runway_busy();
	void start_takeoff();
	void start_landing();
	void sum_landing_time(int);
	void sum_takeoff_time(int);
	int airplane_landed();
	int airplane_takeoff();
	float average_wait_time_for_landing();
	float average_wait_time_for_takeoff();
	
	private:
	float landing_arrivel_rate;//how often to come
	float takeoff_arrivel_rate;//how often to come
	int sum_for_landing;//store total time for landing
	int sum_for_takeoff;//store total time for takeoff
	int land_time;//store time used for landing
	int takeoff_time;//store time used for taking off
	int land_time_left;//store time left for landing
	int takeoff_time_left;//store time left for takeoff
	int takeoff_counter;//store the number of tookeoff
	int landing_counter;//store the number of landed
};
//#include "runway.cpp"
#endif
