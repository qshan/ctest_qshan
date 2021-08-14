#include <stdio.h>
#include <string.h>
#include "say_hello_09.h"
#include "test09.h"


int main()
{
  printf("\n");
  printf("===================================================\n");
  printf("hello test09 \n");
  printf("\n");
  say_hello09();

  int (*p2f_1a) (int);


  p2f_1a = function01_test09;

  printf("Try run p2f_1a, get result: 0x%x\n", function01_test09(5));

  printf("\n");
  printf("Bye test09 \n");
  printf("===================================================\n");
  printf("\n");
  return 0;

}

int function01_test09(int arg0)
{
  printf("-------------------------------------------------- \n");
  printf("Run the %s\n", __func__);

  printf("The arg0 0x%x\n", arg0);

  printf("Exit the %s\n", __func__);
  printf("-------------------------------------------------- \n");
  return (arg0+1);
}
