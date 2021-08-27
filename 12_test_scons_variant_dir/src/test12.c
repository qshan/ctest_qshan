#include <stdio.h>
#include "say_hello_12.h"
#include "test12_shared.h"
int main()
{
  printf("\n");
  printf("===================================================\n");
  printf("hello test12 \n");
  printf("\n");

  say_hello12();
  printf("Try to call function_shared_test12(1), get: 0x%x \n"
      , function_shared_test12(1)
      );

  printf("\n");
  printf("Bye test12 \n");
  printf("===================================================\n");
  printf("\n");
  return 0;

}
