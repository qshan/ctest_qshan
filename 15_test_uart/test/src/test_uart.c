#include <stdio.h>
#include "test_uart.h"
//#include "say_hello_uart.h"
//#include "test_uart_shared.h"

//  extern int _fd;
//  extern char *_cl_port;
//unsigned char * _write_data;


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

  //todo
  //uart and timestamp
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
    //write_hello_string();
    //write_order_hex();
    //write_out_hex_with_reorder(0x7654321 ,0xfedcba98);

    //TODO//worked
    #if 0
    write_out_hex_with_reorder(0x01234567 ,0x89abcdef);
    #endif

    //TODO//worked?????
    #if 1
    read_in_hex_with_reorder(0x01234567);
    #endif


    //try to read the data from serial port
    //TODO//read_one_time_string();

    #if 1
    clock_gettime(CLOCK_MONOTONIC, &last_timeout);
    //for time_log check here
    check_time_stamp_log_data();
    #endif

    atexit(&exit_handler);
  #endif

  #if 0
  //file operation files
  #include <stdio.h>
  //file_init_func()
  {
    //return the file handler
    FILE *fp;
    //FILE *fopen(char *filename, char *mode);
    fp = fopen("test_uart_file_test.txt", "a+");
  }
  //file_write_func()
  {
    //file write case
    //open, write and close
  }
  //file_read_func()
  {
    //file read and write case
  }
  #endif


  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("Bye test_uart \n");
    printf("===================================================\n");
    printf("\n");
  #endif
  return 0;
}
