#ifndef __UART_H__
#define __UART_H__

#ifndef PRINT_DEBUG_ENABLE
  #define PRINT_DEBUG_ENABLE 1
#endif

  int uart_api();
  int uart_init();

  #include <stdio.h>
  #include <stdlib.h>     /*  */
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
//  #include <time.h>

  //UART decode format
  //bit[7:0] is from sw view, remove the start and end of serial package
  //
  //bit[3:0]  -> 1:csr ,2:spi ,3:efuse
  //
  //bit[4]    -> 0:wirte ,1:read
  //bit[7:4]  -> 0/2/3/5/(6+end):wirte ,1/4/(7+end):read

  //read 32 bit addr, 32 bit data
  #define CMD_CODE_READ             0x11
  #define CMD_READ_PACKAGE_LEN      0x5
  //#define CMD_READ_PACKAGE_LEN      0x1024
  //write 32 bit addr, 32 bit data
  #define CMD_CODE_WRITE            0x01
  #define CMD_WRITE_PACKAGE_LEN     0x9

  //read 16 bit addr, 8 bit data
  #define CMD_CODE_READ16           0x13
  #define CMD_READ16_PACKAGE_LEN    0x3
  //write 16 bit addr, 8 bit data
  #define CMD_CODE_WRITE16          0x03
  #define CMD_WRITE16_PACKAGE_LEN   0x4

  //#define BUFFER_RECEIVED_SIZE      1024
  #define BUFFER_RECEIVED_SIZE      200

  //for returned hander of serial port open
  extern int _fd;
  //for the port name on pc hardware view, like"/dev/ttyUSB0"
  extern char *_cl_port;

  int setup_serial_port_01(char port_name[], int serial_speed);
  unsigned int write_out_hex_with_reorder_01(int addr ,int data);
  unsigned int read_in_hex_with_reorder_01(int addr);
  unsigned int poll_data_one_time_without_while_01();
  unsigned int or_write_register(int addr ,int data);
  unsigned int ir_read_register(int addr);
  void exit_handler();

  int setup_serial_port(char port_name[], int serial_speed);
  void clear_custom_speed_flag();
  int write_hello_string();
  unsigned int write_order_hex();
  unsigned int write_out_hex_with_reorder(int addr ,int data);
  unsigned int read_one_time_string();
  unsigned int read_in_hex_with_reorder(int addr);
  unsigned int poll_data_one_time_without_while();
  unsigned int read_in_hex_with_reorder(int addr);

#endif
