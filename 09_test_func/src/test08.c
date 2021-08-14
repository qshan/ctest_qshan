#include <stdio.h>
#include <string.h>
#include "say_hello_09.h"

int main()
{
  printf("-------------------------------------------------- \n");
  printf("hello test09 \n");
  say_hello09();


  char ustring1[] = "This_is_string1";
  char ustring2[200];
  char ustring3[200];

  char *ustring4[10]; /*pointer array, the element is point to constant string*/
  char *ustring5;     /*char pointer*/

  char (*ustring6[])[] = { &"blah", &"hmm" };  /*pointer point to string array*/// only since you brought up the syntax -

  printf("the contents of string1 is %s \n", ustring1);

  strcpy(ustring2, ustring1);
  //strlcpy(ustring2, ustring1, sizeof(ustring1[]));
  //strlcpy(ustring2, ustring1, 100);
  printf("the contents of string2 is %s \n", ustring2);

  strcpy(ustring3, ustring1);
  //strncpy(ustring3, ustring1, sizeof(ustring1[]));
  printf("the contents of string3 is %s \n", ustring3);

  ustring4[0] = "This_is string4-0";
  ustring4[1] = "This_is string4-1";
  ustring4[2] = "This_is string4-2";
  //ustring4[2] = {'T' ,'h' ,'i' ,'s' ,'_' ,'i' ,'s' ,' ' ,'s' ,'t' ,'r' ,'i' ,'n' ,'g' ,'4' ,'-' ,'2' ,'\0'};
  printf("the contents of string4-0 is %s \n", ustring4[0]);
  printf("the contents of string4-1 is %s \n", ustring4[1]);
  printf("the contents of string4-2 is %s \n", ustring4[2]);

  ustring5 = "This_is string5";
  printf("the contents of string5 is %s \n", ustring5);

  ustring6[0] = &"This_is string6-0";
  ustring6[1] = &"This_is string6-1";
  printf("the contents of string6-0 is %s \n", *ustring6[0]);
  printf("the contents of string6-1 is %s \n", *ustring6[1]);

  printf("Bye test09 \n");
  printf("-------------------------------------------------- \n");
  return 0;

}
