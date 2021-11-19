#include <stdio.h>
#include "time_stamp_log.h"

//#include <time.h>       /* time - run programs and summarize system resource usage */
//struct timespec start_time[], last_stat[], last_timeout[], last_read[], last_write[];
struct timespec current;
struct timespec start_time, last_stat, last_timeout, last_read, last_write;
//get the current time//clock_gettime(CLOCK_MONOTONIC, &current);

int init_time_stamp_log()
{
  //struct timespec current;
  //struct timespec start_time, last_stat, last_timeout, last_read, last_write;
  clock_gettime(CLOCK_MONOTONIC, &current);
  start_time    = current;
  last_stat     = current;
  last_timeout  = current;
  last_read     = current;
  last_write    = current;
  return 0;
}


int diff_ms(const struct timespec *t1, const struct timespec *t2)
{
  //ToCheck
  struct timespec diff;
  ///* POSIX.1b structure for a time value.  This is like a `struct timeval' but
  //   has nanoseconds instead of microseconds.  */
  //struct timespec
  //  {
  //    __time_t tv_sec;		/* Seconds.  */
  //    __syscall_slong_t tv_nsec;	/* Nanoseconds.  */
  //  };

  //clock_gettime(CLOCK_MONOTONIC, &current);

  diff.tv_sec = t1->tv_sec - t2->tv_sec;
  diff.tv_nsec = t1->tv_nsec - t2->tv_nsec;
  if (diff.tv_nsec < 0) {
    diff.tv_sec--;
    diff.tv_nsec += 1000000000;
  }
  //the unit is second
  return (diff.tv_sec * 1000 + diff.tv_nsec/1000000);
}

int check_time_stamp_log_data()
{
  //struct timespec current;
  //struct timespec start_time, last_stat, last_timeout, last_read, last_write;
  clock_gettime(CLOCK_MONOTONIC, &current);
  //start_time    = current;
  //last_stat     = current;
  //last_timeout  = current;
  //last_read     = current;
  //last_write    = current;
  printf("start_time   diff is  %.1fs.\n", (double)diff_ms(&current, &start_time   ) / 1000);
  printf("last_stat    diff is  %.1fs.\n", (double)diff_ms(&current, &last_stat    ) / 1000);
  printf("last_timeout diff is  %.1fs.\n", (double)diff_ms(&current, &last_timeout ) / 1000);
  printf("last_read    diff is  %.1fs.\n", (double)diff_ms(&current, &last_read    ) / 1000);
  printf("last_write   diff is  %.1fs.\n", (double)diff_ms(&current, &last_write   ) / 1000);

  return 0;
}
