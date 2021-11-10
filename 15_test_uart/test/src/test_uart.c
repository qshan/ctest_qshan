#include <stdio.h>
#include "test13.h"
//#include "say_hello_13.h"
//#include "test13_shared.h"
int main()
{
  printf("\n");
  printf("===================================================\n");
  printf("hello test13 \n");
  printf("\n");

  say_hello13();
  printf("Try to call function_shared_test13(1), get: 0x%x \n"
      , function_shared_test13(1)
      );

  printf("\n");
  printf("Bye test13 \n");
  printf("===================================================\n");
  printf("\n");
  return 0;

}
