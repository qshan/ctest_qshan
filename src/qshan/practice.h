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





//////// function name list here
int sort_int(int Array[], int size_array);
void print_int_array(int Array[], int size_array);

QS_DLIST_PTR qs_dlist_create();
int qs_dlist_insert_R();
int qs_dlist_insert_L();
int qs_dlist_delete();
int qs_dlist_delete_L();
int qs_dlist_delete_R();
int qs_dlist_print();
int qs_dlist_length();
int qs_dlist_find();
int qs_dlist_find_L();
int qs_dlist_find_R();
//int qs_dlist_ListTraverse()

#endif /* SRC_QSHAN_PRACTICE_H_ */
