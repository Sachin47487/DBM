#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct st
{
    int rollnum;
    char name[20];
    struct st *next;
}SLL;
void add_begin(SLL **ptr);
void print_data(SLL *ptr);
void add_middle(SLL **ptr);
void add_end(SLL **ptr);
int count_nodes(SLL *ptr);
void save_file(SLL *ptr);
void read_file(SLL **ptr);
void  print_rev_rec(SLL *ptr);
void print_rec(SLL *ptr);
void print_rev_U_loop(SLL *ptr);
void print_rev_U_AP(SLL *ptr);
void delete_all_nodes(SLL **ptr);
void delete_node(SLL **ptr);
void rev_link(SLL *ptr);
void rev_link_printing(SLL **ptr);
void sort_data(SLL *ptr);
void merge_SLL(SLL *ptr);
void find_node(SLL *ptr);
void add_last(SLL **ptr);
void print_using_loop(SLL *ptr);
        