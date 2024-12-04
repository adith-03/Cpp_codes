
#include <iostream>

// For setting the start day
enum week_days { SAT = 1, FRI, THUR, WED, TUES, MON, SUN };

#define WEEK_DAYS 7

#define JANUARY   31
#define FEBRUARY  29 // Adjust according to leap year or not
#define MARCH     31
#define APRIL     30
#define MAY       31
#define JUNE      30
#define JULY      31
#define AUGUST    31
#define SEPTEMBER 30
#define OCTOBER   31
#define NOVEMBER  30
#define DECEMBER  31

// Print each month
int month_calender(int total_days, int start_day);
