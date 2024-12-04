/*
  PRINT THE CALENDER OF AN YEAR
*/

/*
 * To Run
 *   g++ main.cpp calender.cpp -o calender
 *   ./calender
 */

#include "calender.h"

int main()
{
  int date{1};
  int start_day{SAT}; // Set the starting day

  // Give the months
  std::cout << "\t\t   January\n";
  start_day = month_calender(JANUARY, start_day);

  std::cout << "\t\t   February\n";
  start_day = month_calender(FEBRUARY, start_day);

  std::cout << "\t\t   March\n";
  start_day = month_calender(MARCH, start_day);

  std::cout << "\t\t   April\n";
  start_day = month_calender(APRIL, start_day);

  std::cout << "\t\t   May\n";
  start_day = month_calender(MAY, start_day);

  std::cout << "\t\t   June\n";
  start_day = month_calender(JUNE, start_day);

  std::cout << "\t\t   July\n";
  start_day = month_calender(JULY, start_day);

  std::cout << "\t\t   August\n";
  start_day = month_calender(AUGUST, start_day);

  std::cout << "\t\t   September\n";
  start_day = month_calender(SEPTEMBER, start_day);

  std::cout << "\t\t   October\n";
  start_day = month_calender(OCTOBER, start_day);

  std::cout << "\t\t   November\n";
  start_day = month_calender(NOVEMBER, start_day);

  std::cout << "\t\t   December\n";
  start_day = month_calender(DECEMBER, start_day);

  std ::cout << '\n';
  return 0;
}
