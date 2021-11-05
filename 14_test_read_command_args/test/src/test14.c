#include <stdio.h>
#include "test14.h"
//#include "say_hello_14.h"
//#include "test14_shared.h"
int main(int argc, char *argv[])
{
  int i, j;//for arg print control
  int value_returned=0;

  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("===================================================\n");
    printf("hello test14 \n");
    printf("\n");
  #endif

  #if 0
    say_hello14();
  #endif

  #if 0
    printf("Try to call function_shared_test14(1), get: 0x%x \n"
        , function_shared_test14(1)
        );
  #endif

  #if 1
  {
    printf("------------------------------\n");
    //printf("#####Get argument is %s\n", *argv);
    printf("#####Get argc is %d\n"    , argc);
    printf("#####Get argv is ");
    for(i=0;i<argc;i++)
    {
      printf(" %s" , argv[i]);
    }
    printf("\n");

    printf("------------------------------\n");

    for(i=0;i<argc;i++)
    {
      printf("#####Get argv[%d] is %s\n" ,i ,argv[i]);
    }
  }
  #endif

  #if 0
  {
    printf("------------------------------\n");

    for(i=1;i<argc;)
    {
      if ((strcmp (argv[i], "--port") == 0))
      {
        printf("#####get --port info: %s\n", argv[i+1]);
      }

      if ((strcasecmp (argv[i], "--file") == 0))
      {
        printf("#####get --file info: %s\n", argv[i+1]);
      }

      i=i+2;
    }

  }
  #endif

  #if 1
  {
    #define MAX_STRING_LENGTH 100
    //char input_arg_list[30][100]=
    char input_arg_list[][2][MAX_STRING_LENGTH]=
    {
       {"--port", "need_input"}
      ,{"--file", "need_input"}
      ,{"--end--", "--end--"}
    };
    printf("------------------------------\n");

    for(i=1;i<argc;)
    {
      //printf("##### Check argv[%d] info: %s\n" ,i ,argv[i]);
      for (j=0;;j++)
      {
        //printf("##### Check input_arg_list[%d][0] info: %s\n" ,i ,input_arg_list[j][0]);
        if ((strcasecmp (input_arg_list[j][0], "--end--") == 0)){break;}

        //if (!strcmp (argv[i], "--file"))
        if ((strcasecmp (argv[i], input_arg_list[j][0]) == 0))
        {
          //printf("#####get input_arg_list[j][0] info: %s\n", argv[i+1]);
          //strcpy(input_arg_list[j][1], argv[i+1]);
          //strncpy(input_arg_list[j][1], argv[i+1] ,100);
          strncpy(input_arg_list[j][1], argv[i+1] ,strlen(argv[i+1]));
          printf("#####Get %s info: %s\n" ,input_arg_list[j][0] ,input_arg_list[j][1]);
        }
      }
      i=i+2;
    }

  }
  #endif

  #if PRINT_DEBUG_ENABLE
    printf("\n");
    printf("Bye test14 \n");
    printf("===================================================\n");
    printf("\n");
    #endif

  printf("value_returned is %d\n" ,value_returned);
  return value_returned;

}
