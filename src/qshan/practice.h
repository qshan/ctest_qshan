/*
 * practice.h
 *
 *  Created on: Nov 4, 2016
 *      Author: qshan
 */

#ifndef SRC_QSHAN_PRACTICE_H_
#define SRC_QSHAN_PRACTICE_H_
#include <stdio.h>

#define NUMBEROFARRAYD1(x)  (sizeof(x)/sizeof(x[0]))

int sort_int(int Array[], int size_array);
void print_int_array(int Array[], int size_array);


#define DataType_dlinst_node int

typedef struct dlist_node{
    DataType_dlinst_node data;
    struct dlist_node *piror, *next;
} qs_dlist_node;

typedef qs_dlist_node (*qs_dlist_ptr);



#endif /* SRC_QSHAN_PRACTICE_H_ */
