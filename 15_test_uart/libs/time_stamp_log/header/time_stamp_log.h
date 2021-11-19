#ifndef __TIME_STAMP_LOG_H__
#define __TIME_STAMP_LOG_H__
//time_stamp_log.h
#ifndef PRINT_DEBUG_ENABLE
  #define PRINT_DEBUG_ENABLE 1
#endif

#include <time.h>       /* time - run programs and summarize system resource usage */

//#include <time.h>       /* time - run programs and summarize system resource usage */
//struct timespec start_time[], last_stat[], last_timeout[], last_read[], last_write[];
extern struct timespec current;
extern struct timespec start_time, last_stat, last_timeout, last_read, last_write;

  int init_time_stamp_log();
  int diff_ms(const struct timespec *t1, const struct timespec *t2);
  int check_time_stamp_log_data();

#endif
