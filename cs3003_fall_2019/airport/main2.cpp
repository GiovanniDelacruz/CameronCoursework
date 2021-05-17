/* **********************************************************************************
*       Name:                   Giovanni Delacruz
*       Prof:                   Dr. Zhao
*       Course:                 Seminar in Data Structures
*       Date:                   7 November, 2019
*       Program:                Double-Runway Simulation
*       Description:
*-----------------------------------------------------------------------------------
*               This is the main file (.cpp) for the dual runway simulation. This
*       program creates a runway that contains both runways in the simulation. It
*	also begins the simulation with the start_sim() function.
********************************************************************************** */


#include <time.h>
#include "runway_simulation2.cpp"
#include <queue>
#include <stdlib.h>

using namespace std;

int main()
{
	runway one(0,0,0,0);
	one.start_sim();
	return 0;


 }
