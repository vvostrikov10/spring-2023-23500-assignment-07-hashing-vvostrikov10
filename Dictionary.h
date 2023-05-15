#pragma once
#include <iostream>
#include "Person.h"
#include "List.h"
#include "Node.h"
#define SIZE 10
class Dictionary{
 private:
  int size = SIZE;
  List *table[SIZE];
 public:
  Dictionary();
  ~Dictionary();
  void insert(Person *data);
  Person *find(std::string name);
  std::string get_keys();
};