#include <stdio.h>
#include "test_uart.h"
//#include "say_hello_uart.h"
//#include "test_uart_shared.h"

//  extern int _fd;
//  extern char *_cl_port;
//unsigned char * _write_data;

#include <time.h>       /* time - run programs and summarize system resource usage */
//struct timespec start_time[], last_stat[], last_timeout[], last_read[], last_write[];
struct timespec current;
struct timespec start_time, last_stat, last_timeout, last_read, last_write;
//TODO//clock_gettime(CLOCK_MONOTONIC, &current);
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



int main()
{
  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("===================================================\n");
    printf("hello test_uart \n");
    printf("\n");
  #endif

  #if 1
    say_hello_uart();
    printf("Try to call function_shared_test_uart(1), get: 0x%x \n"
        , function_shared_test_uart(1)
        );
  #endif

  int uart_api();

  #if 1
    //uart operation here start
    char serial_port_name[]="/dev/ttyUSB1";
    int serial_speed = B115200;

    #if PRINT_DEBUG_ENABLE
      printf("check %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif
    //init the port
    setup_serial_port(serial_port_name, serial_speed);
    #if PRINT_DEBUG_ENABLE
      printf("open %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif
    //clear the status of serial
    clear_custom_speed_flag();

    #if 1
    //for time_log check here
    init_time_stamp_log();
    #endif
    //try to write hello string
    write_hello_string();

    //try to read the data from serial port
    read_one_time_string();

    #if 1
    //for time_log check here
    check_time_stamp_log_data();
    #endif

    atexit(&exit_handler);
  #endif


  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("Bye test_uart \n");
    printf("===================================================\n");
    printf("\n");
  #endif
  return 0;
}
