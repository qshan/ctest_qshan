#include <stdio.h>
#include <string.h>
#include <stdarg.h> /*for va_list*/
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
  p2f_2a[1] = &function03_test09;

  printf("Try run p2f_1a, get result: 0x%x\n", p2f_1a(5));

  printf("Try run p2f_2a[0], get result: 0x%x\n", p2f_2a[0](5, 1));
  printf("Try run p2f_2a[1], get result: 0x%x\n", p2f_2a[1](5, 2));

  printf("Try run function04_d_var_test09(1, 1), get result: 0x%x\n", function04_d_var_test09(1, 1));
  printf("Try run function04_d_var_test09(2 ,1 ,1), get result: 0x%x\n", function04_d_var_test09(2 ,1 ,1));
  printf("Try run function04_d_var_test09(3 ,1 ,1 ,1), get result: 0x%x\n", function04_d_var_test09(3 ,1 ,1 ,1));

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

int function03_test09(int arg0, int arg1)
{
  printf("-------------------------------------------------- \n");
  printf("Run the %s\n", __func__);

  printf("The arg0 0x%x\n", arg0);
  printf("The arg1 0x%x\n", arg1);

  printf("Exit the %s\n", __func__);
  printf("-------------------------------------------------- \n");
  return (arg0 + arg1 + 1);
}


/*
Macros Defined in header <stdarg.h>

va_start   enables access to variadic function arguments (function macro)
va_arg     accesses the next variadic function argument (function macro)
va_copy    (C99) makes a copy of the variadic function arguments (function macro)
va_end     ends traversal of the variadic function arguments (function macro)
Type
va_list    holds the information needed by va_start, va_arg, va_end, and va_copy (typedef)

typedef void *va_list;
#define va_arg(ap,type) (*((type *)(ap))++) //获取指针ap指向的值，然后ap=ap+1，即ap指向下一个值，
                                               其中<u>type</u>是 变参数的类型，可以是char(cter), int(eger), float等。
#define va_start(ap,lastfix) (ap=…)
#define va_end(ap) // 清理/cleanup 指针ap

in linux
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)

*/

int function04_d_var_test09(int arg0, ...)
{
  /*add arguments as a example*/
  printf("-------------------------------------------------- \n");
  printf("Run the %s\n", __func__);

  printf("The arg0 0x%x\n", arg0);
  int i;
  int sum =0;
  va_list argptr;
  /*void va_start(va_list argptr, lastparam);*/
  va_start (argptr, arg0);
  //for(i=0;i<arg0;++i)
  for(i=0;i<arg0;i++)
  {
    /*type va_arg(va_list argptr, type);*/
    sum += va_arg(argptr, int);
  }
  /*void va_end(va_list argptr);*/
  va_end(argptr);

  printf("Exit the %s\n", __func__);
  printf("-------------------------------------------------- \n");
  return sum;
}