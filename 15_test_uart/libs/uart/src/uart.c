#include <stdio.h>

int uart_api()
{
  #if PRINT_DEBUG_ENABLE
    printf("--------------------------------------------------\n");
    printf("Running the %s() in %s\n" ,__func__ ,__FILE__);
    printf("--------------------------------------------------\n");
  #endif

  printf("hi, test_uart \n");
  printf("--------------------------------------------------\n");
  return 0;
}

int uart_init()
{
  #if PRINT_DEBUG_ENABLE
    printf("--------------------------------------------------\n");
    printf("Running the %s() in %s\n" ,__func__ ,__FILE__);
    printf("--------------------------------------------------\n");
  #endif
  return 0;
}
