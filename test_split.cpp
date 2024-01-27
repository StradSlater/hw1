/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{


  Node n1(9, nullptr);
  Node n2(8, &n1);
  Node n3(7, &n2);
  Node n4(6, &n3);
  Node n5(5, &n4);
  Node n6(4, &n5);
  Node n7(3, &n6);
  Node n8(2, &n7);
  Node n9(1, &n8);
  

  Node* linkedlist = &n9;
  Node* iterll = linkedlist;
  while(iterll != nullptr){
    std::cout << iterll->value << std::endl;
    iterll = iterll->next;
  }
  std::cout << std::endl;



  Node* evenlist = nullptr;
  Node* oddlist = nullptr;
  split(linkedlist, oddlist, evenlist);

  iterll = linkedlist; 
  while(iterll != nullptr){
    std::cout << iterll->value << std::endl;
    iterll = iterll->next;
  }
  std::cout << std::endl;

  Node* iterel = evenlist;
  while(iterel != nullptr){
    std::cout << iterel->value << std::endl;
    iterel = iterel->next;
  }
  std::cout << std::endl;

  Node* iterol = oddlist;
  while(iterol != nullptr){
    std::cout << iterol->value << std::endl;
    iterol = iterol->next;
  }

}
