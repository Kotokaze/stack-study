#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

class Stack
{
private:
  int ptr;
  int heep_size;
  int* data0;
  int* data1;
  bool strict;

public:
  Stack(const bool flag = true, const int heep = 8);
  ~Stack();

  void push(int item);
  int pop();
  int getPtr();
  void getData();
};

#endif  // _STACK_H_
