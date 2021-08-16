#include <stdio.h>
#include "say_hello_10.h"
#include "test10_shared.h"
int main()
{
  printf("\n");
  printf("===================================================\n");
  printf("hello test10 \n");
  printf("\n");

  say_hello10();
  printf("Try to call function_shared_test10(1), get: 0x%x \n"
      , function_shared_test10(1)
      );

  printf("\n");
  printf("Bye test10 \n");
  printf("===================================================\n");
  printf("\n");
  return 0;

}
