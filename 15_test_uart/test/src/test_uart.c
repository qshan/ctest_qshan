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

  #if 1
    //uart operation here start
    char serial_port_name[]="/dev/ttyUSB1";
    int serial_speed = B115200;

    #if PRINT_DEBUG_ENABLE
      printf("check %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif
    setup_serial_port(serial_port_name, serial_speed);
    #if PRINT_DEBUG_ENABLE
      printf("open %s, get _fd is %d\n" ,_cl_port ,_fd);
    #endif

    clear_custom_speed_flag();

    write_hello_string();

    read_one_time_string();

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
