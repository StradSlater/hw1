/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  Node* in_t = in;
  in = nullptr;
  /* Add code here */
// WRITE YOUR CODE HERE
//empty list
  if (in_t == nullptr){
    ;
  }
//list has one value
  else if (in_t->next == nullptr){
    if ((in_t->value % 2) == 0){
      evens = in_t;
    }
    else{
      odds = in_t;
    }
  }
//list has multiple values
  else {
    split(in_t->next, odds, evens);
    in_t->next = nullptr;
    if ((in_t->value % 2) == 0){
      Node* temp = evens;
      evens = in_t;
      in_t->next = temp;
    }
    else{
      Node* temp = odds;
      odds = in_t;
      in_t->next = temp;
    }
    }
  }


/* If you needed a helper function, write it here */
