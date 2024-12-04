#include "calender.h"


/// @brief Setup each months calender
/// @param month : Enum of each month
/// @param start_day : Starting weekday of the month
/// @return Next months start_day
int set_month(e_month month, int start_day)
{
  print_month_name(month);
  return month_calender(MONTH[month], start_day);
}


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


/// @brief Prints each month name based on the enum value
/// @param month Enum of month
void print_month_name(e_month month)
{
  switch (month) {
  case JAN:
    std::cout << "\t\t   January\n";
    break;
  case FEB:
    std::cout << "\t\t   February\n";
    break;
  case MAR:
    std::cout << "\t\t   March\n";
    break;
  case APR:
    std::cout << "\t\t   April\n";
    break;
  case MAY:
    std::cout << "\t\t   May\n";
    break;
  case JUN:
    std::cout << "\t\t   June\n";
    break;
  case JUL:
    std::cout << "\t\t   July\n";
    break;
  case AUG:
    std::cout << "\t\t   August\n";
    break;
  case SEP:
    std::cout << "\t\t   September\n";
    break;
  case OCT:
    std::cout << "\t\t   October\n";
    break;
  case NOV:
    std::cout << "\t\t   November\n";
    break;
  case DEC:
    std::cout << "\t\t   December\n";
    break;
  default:
    std::cout << "INVALID MONTH\n";
    break;
  }
}
