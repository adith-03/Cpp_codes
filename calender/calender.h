#include <iostream>
#include <array>

// For setting the start day
enum week_days { SAT = 1, FRI, THUR, WED, TUES, MON, SUN };

const int WEEK_DAYS = 7;

typedef enum {
  JAN,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC,
  TOTAL_MONTHS
} e_month;

const std ::array<int, TOTAL_MONTHS> MONTH{
  31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


/// @brief Setup each months calender
/// @param month : Enum of each month
/// @param start_day : Starting weekday of the month
/// @return Next months start_day
int set_month(e_month month, int start_day);


/// @brief Print the Calender of a Month
/// @param total_days : No.of days in that month
/// @param start_day : Which day the month is starting
/// @return : The next month starting day
int month_calender(int total_days, int start_day);


/// @brief Prints each month name based on the enum value
/// @param month Enum of month
void print_month_name(e_month month);