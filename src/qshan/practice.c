/*
 * practice.c
 *
 *  Created on: Nov 4, 2016
 *      Author: qshan
 */
#include <stdio.h>
#include <stdlib.h>

int sort_int(int Array[], int size_array)
{
    printf("\nHello from sort function!\n");
    int i,j;
    int temp;

//    for (i=1; i<(sizeof(Array)/sizeof(Array[0]));i++)
    for (i=1; i<(size_array);i++)
    {
        temp = Array[i];
        for(j=i-1;j>=0;j--)
        {
            if (temp < Array[j])
            {
                Array[j+1] = Array[j];
            }else
            {
                Array[j+1] = temp;
                break;
            }

            if(j==0)
            {
                Array[j] = temp;
            }
        }
    }
    return 0;
}

void print_int_array(int Array[], int size_array)
{
    int i=0;
    printf("Array is {");
    for (i=0; i<(size_array);i++)
    {
        printf("%d, ", Array[i]);
    }
    printf("}");
}
