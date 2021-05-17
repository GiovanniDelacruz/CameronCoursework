/* **********************************************************************************
*       Name:                   Giovanni Delacruz
*       Prof:                   Dr. Zhao
*       Course:                 Seminar in Data Structures
*       Date:                   7 November, 2019
*       Program:                Double-Runway Simulation
*       Description:
*-----------------------------------------------------------------------------------
*               This is the body file (.cpp) for the dual runway simulation. This
*       program is structured around the queue template and has one queue for each
*       runway. One runway is used solely for departing planes and the other is
*       for landing aircrafts. The body file contains all the instances of prototypes 
*	and methods to be used in the program, as well as a runway constructor that 
*	accepts two integer parameters and two float parameters.
********************************************************************************** */


#include "runway_simulation2.h"
#include <assert.h>
#include <cstdlib>
#include <queue>
#include <stdlib.h>

using namespace std;

runway::runway(int takeoff, int landing, float takeoff_rate, float landing_rate)
	{
		landing_arrivel_rate = landing_rate;
		takeoff_arrivel_rate = takeoff_rate;
		land_time = landing;
		takeoff_time = takeoff;
		takeoff_counter = 0;
		landing_counter = 0;
		sum_for_landing = 0;
		sum_for_takeoff = 0;
		land_time_left = 0;
		takeoff_time_left = 0;
							//constructor
	}

	bool runway::is_airplane_comming_for_landing()	//random plane landing
	{
		return (float)rand()/RAND_MAX < landing_arrivel_rate;
	}
	bool runway::is_airplane_comming_for_takeoff() //random plane taking off
	{
		return (float)rand()/RAND_MAX < takeoff_arrivel_rate;
	}
	bool runway::is_landing()			//progress of land
	{
		return land_time_left > 0;
	}
	bool runway::is_takeoff()			//progress of takeoff
	{
		return takeoff_time_left > 0;
	}


	void runway::one_time_unit()			//time cost
	{
		if(is_landing())
			land_time_left--;
		if(is_takeoff())
			takeoff_time_left--;
	}

	void runway::start_landing()			//begins landing
	{
		assert(!is_runway_busy());
		land_time_left = land_time;
		//cout<<"Landing...\n";
	}
	void runway::start_takeoff()			//begins takeoff
	{
		assert(!is_runway_busy());
		takeoff_time_left = takeoff_time;
		//cout<<"Taking Off...\n";
	}


	bool runway::is_runway_busy()			//checks for loaded runway
	{
		if(land_time_left > 0 || takeoff_time_left > 0)
			return true;
		else
			return  false;
	}

	
	void runway::sum_landing_time(int value)	//total landing time during sim
	{
		landing_counter++;
		sum_for_landing += value;
	}
	void runway::sum_takeoff_time(int value)	//total departure time during sim
	{
		takeoff_counter++;
		sum_for_takeoff += value;
	}

	float runway::average_wait_time_for_landing()	//average time spent waiting to land
	{
		if(landing_counter > 0)
		return (sum_for_landing / landing_counter);
	}
	float runway::average_wait_time_for_takeoff()	//average time spent in takeoff
	{
		if(takeoff_counter > 0)
		return (sum_for_takeoff / takeoff_counter);
	}

	int runway::airplane_landed()			//returns value of landed flights
	{
		return landing_counter;
	}
	int runway::airplane_takeoff()			//returns value of departed flights
	{
		return takeoff_counter;
	}
void runway::start_sim(){				//begins the simulation
	queue <int> landing, takeoff;
        int cur, next, land_time, takeoff_time, s_len;
        float land_rate, takeoff_rate;
        char answer[2];

        do
        {
        cout << "--------------------------------------------------------------\n";

        cout<<"\nEnter simulation length:\t\t\t";		//user inputs
        //cin>>s_len;
	 while(!(cin>>s_len)) {
 	cin.clear();
 	cin.ignore(999,'\n');
 	cout<<"Invalid data type! Please enter again\t";
 	}
        cout<<"\nEnter Landing Arrival Rate:\t\t\t";
        //cin >>land_rate;
	while(!(cin>>land_rate)) {
        cin.clear();
        cin.ignore(999,'\n');
        cout<<"Invalid data type! Please enter again\t";
        }

        cout<<"\nEnter Takeoff Arrival Rate:\t\t\t";
        //cin >>takeoff_rate;
	while(!(cin>>takeoff_rate)) {
        cin.clear();
        cin.ignore(999,'\n');
        cout<<"Invalid data type! Please enter again\t";
        }

        cout<<"\nEnter landing time for an airplane:\t\t";
        //cin >> land_time;
	while(!(cin>>land_time)) {
        cin.clear();
        cin.ignore(999,'\n');
        cout<<"Invalid data type! Please enter again\t";
        }

        cout<<"\nEnter takeoff time for an airplane:\t\t";
        //cin >> takeoff_time;
	while(!(cin>>takeoff_time)) {
        cin.clear();
        cin.ignore(999,'\n');
        cout<<"Invalid data type! Please enter again\t";
        }

        cout << "--------------------------------------------------------------\n";


        runway mine(land_time, takeoff_time, land_rate, takeoff_rate);	//landing strip
        runway mine2(land_time, takeoff_time, land_rate, takeoff_rate);	//departing strip


        srand(time(NULL));

        for( cur = 1; cur < s_len; cur++)
        {
                if(mine.is_airplane_comming_for_landing())		//check for landing
		 {
                        //cout<<"\nAn Airplane is comming for landing..."<<endl;
                        landing.push(cur);
                }
                if(mine2.is_airplane_comming_for_takeoff())		//check for takeoff
                {
                        //cout<<"\nAn airplane is comming for taking off..."<<endl;
                        takeoff.push(cur);
                }


                if(!mine.is_runway_busy() && !landing.empty())	//if plane wants to land and strip 
                {						//available
                        next = landing.front();
                        //cout<<endl<<cur<<" "<<next<<endl;
                        landing.pop();
                        mine.sum_landing_time(cur - next);
                        mine.start_landing();
                }
                if(!mine2.is_runway_busy() && !takeoff.empty())//if plane wants to land and strip
                {						//available
                        next = takeoff.front();
                        //cout<<endl<<cur<<" "<<next<<endl;
                        takeoff.pop();
                        mine2.sum_takeoff_time(cur - next);
                        mine2.start_takeoff();
                }


                mine2.one_time_unit();				//consume one value time

                mine.one_time_unit();				//consume one value time
        }

        cout<<"\nAirplanes that departed:\t\t\t"<<mine2.airplane_takeoff()<<endl;
        cout<<"\nAirplanes that landed:\t\t\t\t"<<mine.airplane_landed()<<endl;
        cout<<"\nAverage ground-time for landing:\t\t" << mine.average_wait_time_for_landing()<<endl;
        cout<<"\nAverage ground-time for departure:\t\t"<<mine2.average_wait_time_for_takeoff()<<endl;
	 cout << "--------------------------------------------------------------\n";

        cout<<"\nUnlanded airplanes:"<<endl;
        int cnt_landing = 0;
        while(!landing.empty())
        {
                //cout<<landing.front()<<" ";
                cnt_landing ++;
                landing.pop();
        }
        cout<<"airplanes that were denied for landing:\t\t"<<cnt_landing<<endl;
        int cnt_takeoff = 0;

        while(!takeoff.empty())
        {
                //cout<<takeoff.front()<<" ";
                cnt_takeoff ++;
                takeoff.pop();
        }
        cout<<endl<<"airplanes that were denied for takeoff:\t\t"<<cnt_takeoff<<endl;
        cout << "--------------------------------------------------------------\n";
        cout <<"total successful airplane traffic:\t\t"<< mine2.airplane_takeoff()+mine.airplane_landed()<<endl;
        cout <<"total unsuccessful airplane traffic:\t\t"<<cnt_takeoff+cnt_landing<<endl;

        cout<<"\nDo it again y for yes: ";
        cin >> answer;
        cout<<endl<<endl;

        }while( tolower(answer[0]) == 'y');

        cout << "--------------------------------------------------------------\n";
        cout << "Thank you for using this simulation!\n";
        cout << "--------------------------------------------------------------\n";
	
}
