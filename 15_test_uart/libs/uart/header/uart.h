#ifndef __UART_H__
#define __UART_H__

#ifndef PRINT_DEBUG_ENABLE
  #define PRINT_DEBUG_ENABLE 1
#endif

  int uart_api();
  int uart_init();

  #include <stdio.h>
  #include <stdlib.h>     /*  */
  #include "test_uart.h"
  #include <unistd.h>     /* UNIX Standard Definitions         */
  #include <termios.h>    /* POSIX Terminal Control Definitions */
  #include <sys/file.h>   /*  */
  #include <fcntl.h>      /* File Control Definitions           */
  #include <sys/ioctl.h>  /* ioctl - control device */
  #include <linux/serial.h> /*  */
  #include <errno.h>      /* ERROR Number Definitions           */
  #include <sys/types.h>  /*  */
  #include <sys/stat.h>   /* stat - display file or file system status */
  #include <strings.h>    /* strings - print the strings of printable characters in files */
  #include <string.h>     /* string operations */
  #include <poll.h>       /* poll, ppoll - wait for some event on a file descriptor */

  extern int _fd;
  extern char *_cl_port;

  int setup_serial_port(char port_name[], int serial_speed);
  void clear_custom_speed_flag();
  int write_hello_string();
  int read_one_time_string();
  void exit_handler();

#endif
