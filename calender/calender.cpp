#include "calender.h"

/// @brief Print the Calender of a Month
/// @param total_days : No.of days in that month
/// @param start_day : Which day the month is starting
/// @return : The next month starting day
int month_calender(int total_days, int start_day)
{
  int copy_start_day{WEEK_DAYS - start_day};
  int date{1};
  int index{};

  std ::cout << "Sun\t" << "Mon\t" << "Tues\t" << "Wed\t" << "Thur\t" << "Fri\t"
             << "Sat\t" << '\n';

  // Adding spaces
  while (copy_start_day > 0 && start_day) {
    std ::cout << "\t";
    copy_start_day--;
  }

  // Printing dates
  while (date <= total_days) {
    std ::cout << date << '\t';

    start_day = (start_day == WEEK_DAYS) ? 0 : start_day;

    if (date % WEEK_DAYS == start_day) {
      std ::cout << '\n';
      index = 0;
    }
    date++;
    index++;
  }
  std ::cout << "\n\n";
  return (WEEK_DAYS - (index - 1));
}