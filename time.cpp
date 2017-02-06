#include "time.hpp"

#include <time.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// function to print current date and time in expected format:
//YYYY/MM/DD hh:mm:ss.nnnnnnnnn
void printDateTime(){
	int clkID = CLOCK_REALTIME; 						// clkID is set to current time
	int len = 30;
	char buffer[len];

	timespec time;
	clock_gettime(clkID, &time); 						// get time specified by clkID, set timespec time to clkID time

	if(timeSpecConversion(buffer, len, &time) != 0){ 	// format timespec time into expected output
		cout << "timeSpecConversion failed"; 			// if 0 is not returned, an error occurred
		return;
	}
	else{
		cout << buffer;
	}

	return;
}

// function to convert timespec struct containing current time seconds and nanoseconds
// into years, months, days, etc. and then format them into expected format
int timeSpecConversion(char *buffer, int len, timespec *time){
	int check;
	tm t;
													//http://pubs.opengroup.org/onlinepubs/009695399/functions/localtime.html
	tzset(); 										// set the time-zone to break time->tv_sec down according to
	if(localtime_r(&(time->tv_sec), &t) == NULL){ 	// then break time->tv_sec into years, months, days, etc (localtime_r)
		return 1; 									// if 0 is not returned by localtime_r,
	}												//something went wrong when breaking down time->tv_sec

															// http://en.cppreference.com/w/cpp/chrono/c/strftime
	check = strftime(buffer, len, "%Y/%m/%d %H:%M:%S", &t); // put time/date into buffer (strftime), still will need to put in nanoseconds
	if(check == 0){											// if strftime returns 0,
		return 2; 											// something went wrong with formating time/date
	}

																				//http://www.cplusplus.com/reference/cstdio/snprintf/
	check = snprintf(&buffer[strlen(buffer)], len, ".%09ld", time->tv_nsec); 	// appends 9 digit long nanosecond value to buffer (snprintf)
	if(check < 0){																// if strftime returns a negative number,
		return 3; 																// something went wrong with formating nanoseconds
	}

	return 0;
}

//Execute nanosleep
int nsleep(long nseconds) {
	struct timespec tim, tim2;
	tim.tv_sec = 0;
	tim.tv_nsec = nseconds;
	
	if (nanosleep(&tim, &tim2) < 0){
		cout << "Nano sleep failed" << endl;
		return -1;
	}
	
	cout << "Nano sleep successful" << endl;
	return (0);
}