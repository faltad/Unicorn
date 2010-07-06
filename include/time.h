#ifndef __TIME_H_
#define __TIME_H_

struct date_s {
  unsigned int	year	: 8;
  unsigned int	seconds	: 8;
  unsigned int	minutes : 8;
  unsigned int	hours	: 6;
  unsigned int	day	: 6;
  unsigned int	month	: 4;
}__attribute__((packed));

typedef struct date_s date_t;

/* Returns the current date and time from the RTC */
date_t	date_RTC();

/* Formats and prints a date */
void	print_date(date_t date);

#endif
