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

  // Print all 12 months
  for (int i = 0; i < TOTAL_MONTHS; i++) {
    start_day = set_month(static_cast<e_month>(i), start_day);
  }

  std ::cout << '\n';
  return 0;
}
