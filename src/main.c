/*
 * main.c
 *
 *  Created on: Oct 26, 2016
 *      Author: qshan
 */
#include <stdio.h>
#include <practice.h>

int main()
{

	int i;
	int Array[]={10,9,8,2,6,5,4,3,7,1};

#if 0
	unsigned int array[3][2] = {{1,2},{3,4},(5,6)};
	unsigned int *ptr1;
	unsigned int *ptr2;
	unsigned int *ptr3;

	ptr1 = array;
	ptr2 = array[0];
	ptr3 = &array[0][1];
	//printf("array is %x\n", array);
	printf("sizeof(array) is %d \n", (sizeof(array)));
	printf("sizeof(array[0]) is %d \n", (sizeof(array[0])));
	printf("sizeof(array[0][0]) is %d \n", (sizeof(array[0][0])));
	printf("sizeof(ptr1) is %d \n", (sizeof(ptr1)));
	printf("sizeof(ptr2) is %d \n", (sizeof(ptr2)));
	printf("sizeof(ptr3) is %d \n", (sizeof(ptr3)));
	printf("sizeof(*ptr1) is %d \n", (sizeof(*ptr1)));
	printf("sizeof(*ptr2) is %d \n", (sizeof(*ptr2)));
	printf("sizeof(*ptr3) is %d \n", (sizeof(*ptr3)));
#endif
#if 0
	for (i=0;i<10;i++)
	printf("Hell C %d time \n", (i+1));
#endif


#if 0
//just example for my son
/**/
//
	i=0;
	if(i==0)
	{
		//code block
		printf("i=0 is right\n");
	}else
	{
		//code block
		printf("i != 0\n");
		printf("i is really not equal 0\n");
	}

//add in qcavi pc

	printf("the code is end here\n");

#endif


#if 0
//for the enmu test
enum TRAFFIC_TYPE {type_one, type_two, type_three, type_four};

enum TRAFFIC_TYPE sellection;
	sellection = type_three;

switch (sellection)
{
case type_one :
	printf("current is type_one \n");
	break;
case type_two :
	printf("current is type_two \n");
	break;
case type_three :
	printf("current is type_three \n");
	break;
case type_four :
	printf("current is type_four \n");
	break;
default :
	//code here;
	printf("current is default branch \n");
	break;
}

#endif

#if 1
	//printf("sizeof(Array) = %d\n", (sizeof(Array)));
	//printf("sizeof(Array[0]) = %d\n", (sizeof(Array[0])));
	//printf("sizeof(Array)/sizeof(Array[0]) = %d\n", (sizeof(Array)/sizeof(Array[0])));
	print_int_array(Array, (sizeof(Array)/sizeof(Array[0])));
	sort_int(Array, sizeof(Array)/sizeof(Array[0]));
	print_int_array(Array, (sizeof(Array)/sizeof(Array[0])));
#endif


return 0;
}
