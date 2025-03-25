/* Exercise 5-8. There is no error checking in day_of_year or month_day. 
  Remedy this defect. */

/* Exercise 5-9. Rewrite the routines day_of_year and month_day with
   pointers instead of indexing. */

#include <stdio.h>

static int DAYS_IN_YEAR = 365;
static int DAYS_IN_LEAP_YEAR = 366;
static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap (int year) {
  return year % 4 == 0 & year % 100 != 0 || year % 400 == 0;
}

int valid_month (int month) {
  return (month >= 1 && month <= 12);
}

int valid_day (int month, int day, int year) {
  return (day >= 1 && day <= *(*(daytab + is_leap(year)) + month));
}

int day_of_year (int year, int month, int day) {
  int i, leap;

  leap = is_leap(year);

  if (!valid_month(month)) {
    printf("error: month must be between 1 and 12\n");
    return -1;
  }

  if (!valid_day(month, day, year)) {
    printf("error: day must be between 1 and %d\n", *(*(daytab + leap) + month));
    return -1;
  }

  for (i = 1; i < month; i++) {
    day += *(*(daytab + leap) + i);
  }

  return day;
}

void month_day (int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  leap = is_leap(year);

  if (yearday < 1 || yearday > leap ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR) {
    printf("error: yearday must be in between 1 and %d\n", leap ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR);
    return;
  }

  for (i = 1; yearday > *(*(daytab + leap) + i); i ++) {
    yearday -= *(*(daytab + leap) + i);
  }

  *pmonth = i;
  *pday = yearday;
}

void main() {
  int *pmonth, *pday;

  day_of_year(2000, 2, 30);
  day_of_year(1999, 2, 29);
  day_of_year(2000, 0, 15);
  day_of_year(2000, 20, 10);
  month_day(1999, 366, pmonth, pday);
  month_day(2000, -1, pmonth, pday);
}