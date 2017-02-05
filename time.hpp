#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <ctime>

using namespace std;

void printDateTime();
int timeSpecConversion(char *buffer, int len, timespec *time);
int nsleep(long nseconds);

#endif
