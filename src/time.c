#include "time.h"
#include "libc.h"

date_t	date_RTC()
{
  int		RTC_address;
  int		RTC_data;
  date_t	date;
  
  RTC_address = 0x70;
  RTC_data    = 0x71;
  asm (
      ".l1:		\n"
      "movb $10 %eax	\n"
      "out %eax, %6	\n"
      "in %7, %eax	\n"
      "test $80, %eax	\n" /* if the clock is updating, wait */
      "jne .l1		\n"

      "movb $0, %eax	\n" /* get seconds */
      "out %eax, %6	\n"
      "in %7, %eax	\n"
      "movb %eax, %0	\n"

      "movb $2, %eax	\n" /* get minutes */
      "out %eax, %6	\n"
      "in %7, %eax	\n"
      "movb %eax, %1	\n"

      "movb $4, %eax	\n" /* get hours */
      "out %eax, %6	\n"
      "in %7, %eax	\n"
      "movb %eax, %2	\n"

      "movb $7, %eax	\n" /* get day */
      "out %eax, %6	\n"
      "in %7, %eax	\n"
      "movb %eax, %3	\n"

      "movb $8, %eax	\n" /* get month */
      "out %eax, %6	\n"
      "in %7, %eax	\n"
      "movb %eax, %4	\n"

      "movb $9, %eax	\n" /* get year */
      "out %eax, %6	\n"
      "in %7, %eax	\n"
      "movb %eax, %5	\n"
      
      : "=r" (date.seconds),
	"=r" (date.minutes),
	"=r" (date.hours),
	"=r" (date.day),
	"=r" (date.month),
	"=r" (date.year)
      : "r" (RTC_address),
	"r" (RTC_data));

  return date;
}

void	print_date(date_t date)
{
  kprintf("%d/%d/20%d %d:%d:%d\n",
	  date.day,
	  date.month,
	  date.year,
	  date.hours,
	  date.minutes,
	  date.seconds);
}
