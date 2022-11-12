#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
 

  if(t == NULL) { //tree/subtree is empty

    /*make new node, and make the pre node point to it*/
    struct tree_node* new = malloc(sizeof(struct tree_node));
    new->item = x;
    new ->right = NULL;
    new->left = NULL;
    t = new; 
  }
  else if(x > t->item) {
    t->right = Insert(x,t->right); //if x is go greater than root, go to right subtree. 
  }
  else {
    t->left = Insert(x,t->left); //else go to left subtree. 
  }

  return t; //return tree. 
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
  if(t == NULL)
   return t; //tree/subtree is empty 


	else if(x < t->item) {
    t->left = Remove(x,t->left); } //search left tree, making root->left root/t. 


	else if (x > t->item) {

    t->right = Remove(x,t->right);  //search right tree, making root->right the root/t. 
  }
	
  //if both cases above fail, x has been found
	else {

		if(t->left == NULL && t->right == NULL) {  //if node is a leaf. 
			free(t); //free node
      return NULL;  //return NULL, to make pre node point to this?
		}
		
		else if(t->left == NULL) { //if node has no left child. 
			struct tree_node *temp = t; 
			t = t->right; //make t->right the "new" t. 
			free(temp); //free node
      return t; //return "new" t
      		}
		else if(t->right == NULL) { //if node has no right child
			struct tree_node* temp = t;
			t = t->left;
			free(temp);
      return t;
		}
		
		else {  //2 children. 
    struct tree_node* temp = t->right;
    while(temp->left != NULL) {
      temp = temp->left; //find lowest value in right subtree. 
    }
    t->item = temp->item; //this makes the value to be removed, one of the to cases above. 
    t->right = Remove(temp->item,t->right); //call function to remove the lowest value. 
		}
	}
	return t;
}

int Contains(int x, struct tree_node *t) {
  if(t == NULL) {
    return false; //if not found
  }

	if (t->item == x) {  //item found
	return true;
	}
	
	else if (t->item > x) { 
		return Contains(x,t->left); //search right subtree for x.
	}

	else if (t->item <= x ) {
		return Contains(x,t->right); //search left subtree for x
	}
}

struct tree_node *Initialize(struct tree_node *t) {
  t = NULL; //tree is empty so t points to nothing. 
  return t; 
}

int Empty(struct tree_node *t) {
  if (t == NULL) {
    return true;
  }
  // Test if empty
  return false;
}

int Full(struct tree_node *t) {
  // Test if full
  return false; //tree is never full 
}
