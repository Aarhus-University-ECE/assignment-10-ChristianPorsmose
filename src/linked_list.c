#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */


#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  if(p->next == NULL) {
    return; //end of list
  }
  else {
    printf(" %d ",p->value); //print current node
    print_list(p->next); //move to next node
  }
}

int sum_squares(node *p) {
  // Add your code for excercise 2
  if (p == NULL) 
    return 0; //base case
  else {
    return p->value*p->value + sum_squares(p->next); //return the element^2 and then find the next element.
  }
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  node *temp = malloc(sizeof(node));

  if (p == NULL) {
    return NULL; //returns NULL, as the new list also needs a null pointer in the end. 
  }
  else {
    temp->value = f(p->value); //make temps value p->value squared
    temp->next = map(p->next,f); //make connection, and send p and function
    return temp; //return pointer for every function call
  }

}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
