#include <stdio.h>
#include "test_uart.h"
//#include "say_hello_uart.h"
//#include "test_uart_shared.h"
int main()
{
  printf("\n");
  printf("===================================================\n");
  printf("hello test_uart \n");
  printf("\n");

  say_hello_uart();
  printf("Try to call function_shared_test_uart(1), get: 0x%x \n"
      , function_shared_test_uart(1)
      );

  printf("\n");
  printf("Bye test_uart \n");
  printf("===================================================\n");
  printf("\n");
  return 0;

}
