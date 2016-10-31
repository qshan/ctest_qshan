/*
 * main.c
 *
 *  Created on: Oct 26, 2016
 *      Author: qshan
 */

void main()
{
	unsigned int array[][2] = {{1,2},{3,4},(5,6)};
	unsigned int *ptr1;
	unsigned int *ptr2;
	unsigned int *ptr3;
	int i;
#if 0
	ptr1 = array;
	ptr2 = array[0];
	ptr3 = &array[0][1];
	printf("array is %x\n", array);
	printf("sizeof(array) is %x \n", (sizeof(array)));
	printf("sizeof(array[0]) is %x \n", (sizeof(array[0])));
	printf("sizeof(array[0][0]) is %x \n", (sizeof(array[0][0])));
	printf("sizeof(ptr1) is %x \n", (sizeof(ptr1)));
	printf("sizeof(ptr2) is %x \n", (sizeof(ptr2)));
	printf("sizeof(ptr3) is %x \n", (sizeof(ptr3)));
	printf("sizeof(*ptr1) is %x \n", (sizeof(*ptr1)));
	printf("sizeof(*ptr2) is %x \n", (sizeof(*ptr2)));
	printf("sizeof(*ptr3) is %x \n", (sizeof(*ptr3)));
#endif
#if 0
	for (i=0;i<10;i++)
	printf("Hell C %d time \n", (i+1));
#endif
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






}
