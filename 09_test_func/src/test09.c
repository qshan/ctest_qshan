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

  int (*p2f_1a) (int); /*define a pointer point to a function*/
  int (*p2f_2a[5]) (int, int); /*define a array of pointer point to a function with two arguments*/

  //p2f_1a = function01_test09;
  p2f_1a = &function01_test09;

  p2f_2a[0] = &function02_test09;

  printf("Try run p2f_1a, get result: 0x%x\n", p2f_1a(5));

  printf("Try run p2f_2a[0], get result: 0x%x\n", p2f_2a[0](5, 1));

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

int function02_test09(int arg0, int arg1)
{
  printf("-------------------------------------------------- \n");
  printf("Run the %s\n", __func__);

  printf("The arg0 0x%x\n", arg0);
  printf("The arg1 0x%x\n", arg1);

  printf("Exit the %s\n", __func__);
  printf("-------------------------------------------------- \n");
  return (arg0 + arg1 + 1);
}
