/*
 * practice.h
 *
 *  Created on: Nov 4, 2016
 *      Author: qshan
 */

#ifndef SRC_QSHAN_PRACTICE_H_
#define SRC_QSHAN_PRACTICE_H_
#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFARRAYD1(x)  (sizeof(x)/sizeof(x[0]))

int sort_int(int Array[], int size_array);
void print_int_array(int Array[], int size_array);






#if 1
#define data_dlinst_node int
struct dlist_node{
    data_dlinst_node data;
    struct dlist_node *piror, *next;
};
typedef struct dlist_node QS_DLIST_NODE;
typedef struct dlist_node *QS_DLIST_PTR;
//typedef QS_DLIST_NODE *QS_DLIST_PTR;

#else

typedef struct dlist_node{
    data_dlinst_node data;
    struct dlist_node *piror, *next;
} QS_DLIST_NODE, *QS_DLIST_PTR;
#endif

//declare a struct
//QS_DLIST_NODE struct_customer_name;
//declare a pointer of struct
//QS_DLIST_PTR struct_customer_pointer;
//QS_DLIST_NODE *struct_customer_pointer;




#endif /* SRC_QSHAN_PRACTICE_H_ */
